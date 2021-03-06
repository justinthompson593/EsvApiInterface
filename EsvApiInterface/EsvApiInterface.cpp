//
//  EsvApiInterface.cpp
//  EsvApiInterface
//
//  Created by Justin Thompson on 7/19/17.
//  Copyright © 2017 Justin Thompson. All rights reserved.
//

#include "EsvApiInterface.hpp"


EsvApiInterface::EsvApiInterface(){
	
}

EsvApiInterface::EsvApiInterface(string direc){
	setDirectory(direc);
}

void EsvApiInterface::setDirectory(string direc){
	directory = direc;
}

string EsvApiInterface::getDirectory(){
	return directory;
}

string EsvApiInterface::getCSS(){
	string out = "";
	
	return out;
}

void EsvApiInterface::setKey(string newKey){
	key = "?key=";
	key += newKey;
}

void EsvApiInterface::setHTMLOutputOptions(int ESV_HTML_OPTIONS_ENUM, bool value){
	switch (ESV_HTML_OPTIONS_ENUM) {
  case ESV_HTML_OPTIONS_PASSAGE_REFS:
		{
			if(value){
				passageRefs.at(passageRefs.size()-1) = '1';
			}
			else{
				passageRefs.at(passageRefs.size()-1) = '0';
			}
		}
			break;
  case ESV_HTML_OPTIONS_VERSE_NUMS:
		{
			if(value){
				verseNums.at(verseNums.size()-1) = '1';
			}
			else{
				verseNums.at(verseNums.size()-1) = '0';
			}
		}
			break;
  case ESV_HTML_OPTIONS_FOOTNOTES:
		{
			if(value){
				footnotes.at(footnotes.size()-1) = '1';
			}
			else{
				footnotes.at(footnotes.size()-1) = '0';
			}
		}
			break;
  case ESV_HTML_OPTIONS_FOOTNOTE_LINKS:
		{
			if(value){
				footnoteLinks.at(footnoteLinks.size()-1) = '1';
			}
			else{
				footnoteLinks.at(footnoteLinks.size()-1) = '0';
			}
		}
			break;
  case ESV_HTML_OPTIONS_HEADINGS:
		{
			if(value){
				headings.at(headings.size()-1) = '1';
			}
			else{
				headings.at(headings.size()-1) = '0';
			}
		}
			break;
  case ESV_HTML_OPTIONS_SUBHEADINGS:
		{
			if(value){
				subHeadings.at(subHeadings.size()-1) = '1';
			}
			else{
				subHeadings.at(subHeadings.size()-1) = '0';
			}
		}
			break;
  case ESV_HTML_OPTIONS_RED_LETTER:
		{
			if(value){
				redLetter = true;
			}
			else{
				redLetter = false;
			}
		}
		break;
			
  default:
			break;
	}
}

void EsvApiInterface::includeCss(bool True_False){
	includeCssInHtml = True_False;
}

void EsvApiInterface::setCssType(int ESV_CSS_OPTIONS_ENUM){
	cssType = ESV_CSS_OPTIONS_ENUM;
}

void EsvApiInterface::setRedLetter(bool true_false){
	redLetter = true_false;
}

void EsvApiInterface::openMp3(string passage, bool save){
	char bashOut[ESV_BUFFER_SIZE];
	sprintf(bashOut, "open %spassageQuery%s\\&passage=%s\\&output-format=mp3", url.c_str(), key.c_str(), passage.c_str());
	system(bashOut);
	
	if(save){
		saveMp3(passage);
	}
}

void EsvApiInterface::saveMp3(string passage){
	char bashOut[ESV_BUFFER_SIZE];
	sprintf(bashOut, "echo \"$(curl %spassageQuery%s\\&passage=%s\\&output-format=mp3)\" > %s.mp3", url.c_str(), key.c_str(), passage.c_str(), passage.c_str());
	system(bashOut);
}

void EsvApiInterface::openPassage(string passage, bool save){
	char bashOut[ESV_BUFFER_SIZE];
	
	savePassage(passage);
	
	if(save){
		sprintf(bashOut, "open %s.html", passage.c_str());
	}
	else{
		sprintf(bashOut, "open %s.html && sleep 1 && rm %s.html", passage.c_str(), passage.c_str());
	}
	
	system(bashOut);
}

string EsvApiInterface::processScope(string bookName){
	string out = "";
	
	if( bookName == "Acts" || bookName == "ACT" || bookName == "Act"){
		out = "Acts";
	}
	else if( bookName == "Amos" || bookName == "AMO" || bookName == "Amo"){
		out = "Amos";
	}
	else if( bookName == "Chronicles1" || bookName == "CH1" || bookName == "Ch1" || bookName == "1Chr" || bookName == "1 Chr"){
		out = "1 Chronicles";
	}
	else if( bookName == "Chronicles2" || bookName == "CH2" || bookName == "Ch2" || bookName == "2Chr" || bookName == "2 Chr"){
		out = "2 Chronicles";
	}
	else if( bookName == "Colossians" || bookName == "COL" || bookName == "Col"){
		out = "Colossians";
	}
	else if( bookName == "Corinthians1" || bookName == "CO1" || bookName == "1Corinthians" || bookName == "1COR" || bookName == "Co1" || bookName == "1Cor" || bookName == "1 Cor"){
		out = "1 Corinthians";
	}
	else if( bookName == "Corinthians2" || bookName == "CO2" || bookName == "2Corinthians" || bookName == "2COR" || bookName == "Co2" || bookName == "2Cor" || bookName == "2 Cor"){
		out = "2 Corinthians";
	}
	else if( bookName == "Daniel" || bookName == "DAN" || bookName == "Dan"){
		out = "Daniel";
	}
	else if( bookName == "Deuteronomy" || bookName == "DEU" || bookName == "Deu"){
		out = "Deuteronomy";
	}
	else if( bookName == "Ecclesiastes" || bookName == "ECC" || bookName == "Ecc"){
		out = "Ecclesiastes";
	}
	else if( bookName == "Ephesians" || bookName == "EPH" || bookName == "Eph"){
		out = "Ephesians";
	}
	else if( bookName == "Esther" || bookName == "EST" || bookName == "Est"){
		out = "Esther";
	}
	else if( bookName == "Exodus" || bookName == "EXO" || bookName == "Exo"){
		out = "Exodus";
	}
	else if( bookName == "Ezekiel" || bookName == "EZE" || bookName == "Eze"){
		out = "Ezekiel";
	}
	else if( bookName == "Ezra" || bookName == "EZR" || bookName == "Ezr"){
		out = "Ezra";
	}
	else if( bookName == "Galatians" || bookName == "GAL" || bookName == "Gal"){
		out = "Galatians";
	}
	else if( bookName == "Genesis" || bookName == "GEN" || bookName == "Gen"){
		out = "Genesis";
	}
	else if( bookName == "Habakkuk" || bookName == "HAB" || bookName == "Hab"){
		out = "Habakkuk";
	}
	else if( bookName == "Haggai" || bookName == "HAG" || bookName == "Hag"){
		out = "Haggai";
	}
	else if( bookName == "Hebrews" || bookName == "HEB" || bookName == "Heb"){
		out = "Hebrews";
	}
	else if( bookName == "Hosea" || bookName == "HOS" || bookName == "Hos"){
		out = "Hosea";
	}
	else if( bookName == "Isaiah" || bookName == "ISA" || bookName == "Isa"){
		out = "Isaiah";
	}
	else if( bookName == "James" || bookName == "JAM" || bookName == "Jam"){
		out = "James";
	}
	else if( bookName == "Jeremiah" || bookName == "JER" || bookName == "Jer"){
		out = "Jeremiah";
	}
	else if( bookName == "Job" || bookName == "JOB" ){
		out = "Job";
	}
	else if( bookName == "Joel" || bookName == "JOE" || bookName == "Joe"){
		out = "Joel";
	}
	else if( bookName == "John" || bookName == "JOH" || bookName == "Joh"){
		out = "John";
	}
	else if( bookName == "1John" || bookName == "JO1" || bookName == "Jo1" || bookName == "1Joh" || bookName == "1 Joh"){
		out = "1 John";
	}
	else if( bookName == "2John" || bookName == "JO2" || bookName == "Jo2" || bookName == "2Joh" || bookName == "2 Joh"){
		out = "2 John";
	}
	else if( bookName == "3John" || bookName == "JO3" || bookName == "Jo3" || bookName == "3Joh" || bookName == "3 Joh"){
		out = "3 John";
	}
	else if( bookName == "Jonah" || bookName == "JON" || bookName == "Jon"){
		out = "Jonah";
	}
	else if( bookName == "Joshua" || bookName == "JOS" || bookName == "Jos"){
		out = "Joshua";
	}
	else if( bookName == "Jude" || bookName == "JDE" || bookName == "Jde"){
		out = "Jude";
	}
	else if( bookName == "Judges" || bookName == "JUD" || bookName == "JDG" || bookName == "Jdg"){
		out = "Judges";
	}
	else if( bookName == "Kings1" || bookName == "KNG1" || bookName == "1Kings" || bookName == "1KNG" || bookName == "KG1" || bookName == "1KG" || bookName == "Kg1" || bookName == "1Kin" || bookName == "1 Kin"){
		out = "1 Kings";
	}
	else if( bookName == "Kings2" || bookName == "KNG2" || bookName == "2Kings" || bookName == "2KNG" || bookName == "KG2" || bookName == "2KG" || bookName == "Kg2" || bookName == "2Kin" || bookName == "2 Kin"){
		out = "2 Kings";
	}
	else if( bookName == "Lamentations" || bookName == "LAM" || bookName == "Lam"){
		out = "Lamentations";
	}
	else if( bookName == "Leviticus" || bookName == "LEV" || bookName == "Lev"){
		out = "Leviticus";
	}
	else if( bookName == "Luke" || bookName == "LUK" || bookName == "Luk"){
		out = "Luke";
	}
	else if( bookName == "Malachi" || bookName == "MAL" || bookName == "Mal"){
		out = "Malachi";
	}
	else if( bookName == "Mark" || bookName == "MAR" || bookName == "Mar"){
		out = "Mark";
	}
	else if( bookName == "Matthew" || bookName == "MAT" || bookName == "Mat"){
		out = "Matthew";
	}
	else if( bookName == "Micah" || bookName == "MIC" || bookName == "Mic"){
		out = "Micah";
	}
	else if( bookName == "Nahum" || bookName == "NAH" || bookName == "Nah"){
		out = "Nahum";
	}
	else if( bookName == "Nehemiah" || bookName == "NEH" || bookName == "Neh"){
		out = "Nehemiah";
	}
	else if( bookName == "Numbers" || bookName == "NUM" || bookName == "Num"){
		out = "Numbers";
	}
	else if( bookName == "Obadiah" || bookName == "OBA" || bookName == "Oba"){
		out = "Obadiah";
	}
	else if( bookName == "Peter1" || bookName == "PE1" || bookName == "1Peter" || bookName == "1PET" || bookName == "Pe1" || bookName == "1Pet" || bookName == "1 Pet"){
		out = "1 Peter";
	}
	else if( bookName == "Peter2" || bookName == "PE2" || bookName == "2Peter" || bookName == "2PET" || bookName == "Pe2" || bookName == "2Pet" || bookName == "2 Pet"){
		out = "2 Peter";
	}
	else if( bookName == "Philemon" || bookName == "PLM" || bookName == "Plm"){
		out = "Philemon";
	}
	else if( bookName == "Philippians" || bookName == "PHI" || bookName == "Phi"){
		out = "Philippians";
	}
	else if( bookName == "Proverbs" || bookName == "PRO" || bookName == "Pro"){
		out = "Proverbs";
	}
	else if( bookName == "Psalms" || bookName == "PSA" || bookName == "Psa"){
		out = "Psalms";
	}
	else if( bookName == "Revelation" || bookName == "REV" || bookName == "Rev"){
		out = "Revelation";
	}
	else if( bookName == "Romans" || bookName == "ROM" || bookName == "Rom"){
		out = "Romans";
	}
	else if( bookName == "Ruth" || bookName == "RUT" || bookName == "Rut"){
		out = "Ruth";
	}
	else if( bookName == "Samuel1" || bookName == "SA1" || bookName == "1Samuel" || bookName == "1SAM" || bookName == "Sa1" || bookName == "1Sam" || bookName == "1 Sam"){
		out = "1 Samuel";
	}
	else if( bookName == "Samuel2" || bookName == "SA2" || bookName == "2Samuel" || bookName == "2SAM" || bookName == "Sa2" || bookName == "2Sam" || bookName == "2 Sam"){
		out = "2 Samuel";
	}
	else if( bookName == "SongOfSolomon" || bookName == "SOL" || bookName == "Sol"){
		out = "Song of Solomon";
	}
	else if( bookName == "Thessalonians1" || bookName == "TH1" || bookName == "1Thessalonians" || bookName == "1THE" || bookName == "Th1" || bookName == "1The" || bookName == "1 The"){
		out = "1 Thessalonians";
	}
	else if( bookName == "Thessalonians2" || bookName == "TH2" || bookName == "2Thessalonians" || bookName == "2THE" || bookName == "Th2" || bookName == "2The" || bookName == "2 The"){
		out = "2 Thessalonians";
	}
	else if( bookName == "Timothy1" || bookName == "TI1" || bookName == "1Timothy" || bookName == "1TIM" || bookName == "Ti1" || bookName == "1Tim" || bookName == "1 Tim"){
		out = "1 Timothy";
	}
	else if( bookName == "Timothy2" || bookName == "TI2" || bookName == "2Timothy" || bookName == "2TIM" || bookName == "Ti2" || bookName == "2Tim" || bookName == "2 Tim"){
		out = "2 Timothy";
	}
	else if( bookName == "Titus" || bookName == "TIT" || bookName == "Tit"){
		out = "Titus";
	}
	else if( bookName == "Zechariah" || bookName == "ZEC" || bookName == "ZAC" || bookName == "Zac" || bookName == "Zec"){
		out = "Zechariah";
	}
	else if( bookName == "Zephaniah" || bookName == "ZEP" || bookName == "Zep"){
		out = "Zephaniah";
	}
	else{
		out = bookName;
	}
	
	return out;
}

void EsvApiInterface::search(string stringToFind, string scopeIn, bool save){
	char bashOut[ESV_BUFFER_SIZE];
	
	string fileName = processSearchName(stringToFind);
	saveSearch(stringToFind, scopeIn);

	if(save)
		sprintf(bashOut, "open %s.html", fileName.c_str());
	else
		sprintf(bashOut, "open %s.html && sleep 1 && rm %s.html", fileName.c_str(), fileName.c_str());
	
	
	
	system(bashOut);
	
}

string EsvApiInterface::processSearchName(string searchStr){
	string out = "";
	
	for(int i=0; i<searchStr.length(); i++){
		if( searchStr.at(i) != ' ' )
			out += searchStr.at(i);
		else
			out += "+";
	}
	
	return out;
}

void EsvApiInterface::saveSearch(string stringToFind, string scopeIn){
	char bashOut[ESV_BUFFER_SIZE];
	
	string scope = processSearchName(processScope(scopeIn));
	string str = processSearchName(stringToFind);
	
	
	if(includeCssInHtml){
		
		switch (cssType) {
			case ESV_CSS_OPTIONS_TYPE_DEFAULT:
			{
				sprintf(bashOut, "echo \"<LINK REL=StyleSheet HREF=\"http://static.esvmedia.org/legacy/css/text.css\" TYPE=\"text/css\" MEDIA=all>\" > %s.html && ", str.c_str());
			}
    break;
			case ESV_CSS_OPTIONS_TYPE_DARK:
			{
				if(redLetter){
					sprintf(bashOut, "echo \"<head><style>\" > %s.html && ", str.c_str());
					sprintf(bashOut, "%secho \"$(<%sdark_redLetter.css)\" >> %s.html && ", bashOut, directory.c_str(),str.c_str());
					sprintf(bashOut, "%secho \"</style></head>\" >> %s.html && ", bashOut, str.c_str());
				}
				else{
					sprintf(bashOut, "echo \"<head><style>\" > %s.html && ", str.c_str());
					sprintf(bashOut, "%secho \"$(<%sdark.css)\" >> %s.html && ", bashOut, directory.c_str(),str.c_str());
					sprintf(bashOut, "%secho \"</style></head>\" >> %s.html && ", bashOut, str.c_str());
				}
				
			}
    break;
			default:
			{
				sprintf(bashOut, "echo \"<LINK REL=StyleSheet HREF=\"http://static.esvmedia.org/legacy/css/text.css\" TYPE=\"text/css\" MEDIA=all>\" > %s.html && ", str.c_str());
			}
    break;
		}
		
		
	}
	
	
	
	if(scope == ""){
		sprintf(bashOut, "%secho \"$(curl %squery%s\\&q=%s)\" >> %s.html", bashOut, url.c_str(), key.c_str(), str.c_str(), str.c_str());
	}
	else{
		sprintf(bashOut, "%secho \"$(curl %squery%s\\&q=%s\\&scope=%s)\" >> %s.html", bashOut, url.c_str(), key.c_str(), str.c_str(), scope.c_str(), str.c_str());
	}
	
	system(bashOut);
}

void EsvApiInterface::savePassage(string passage){
	char bashOut[ESV_BUFFER_SIZE] = "";
	if(includeCssInHtml){
		
		switch (cssType) {
			case ESV_CSS_OPTIONS_TYPE_DEFAULT:
			{
				sprintf(bashOut, "echo \"<LINK REL=StyleSheet HREF=\"http://static.esvmedia.org/legacy/css/text.css\" TYPE=\"text/css\" MEDIA=all>\" > %s.html && ", passage.c_str());
			}
    break;
			case ESV_CSS_OPTIONS_TYPE_DARK:
			{
				if(redLetter){
					sprintf(bashOut, "echo \"<head><style>\" > %s.html && ", passage.c_str());
					sprintf(bashOut, "%secho \"$(<%sdark_redLetter.css)\" >> %s.html && ", bashOut, directory.c_str(),passage.c_str());
					sprintf(bashOut, "%secho \"</style></head>\" >> %s.html && ", bashOut, passage.c_str());
				}
				else{
					sprintf(bashOut, "echo \"<head><style>\" > %s.html && ", passage.c_str());
					sprintf(bashOut, "%secho \"$(<%sdark.css)\" >> %s.html && ", bashOut, directory.c_str(),passage.c_str());
					sprintf(bashOut, "%secho \"</style></head>\" >> %s.html && ", bashOut, passage.c_str());
				}
			}
    break;
			default:
			{
				sprintf(bashOut, "echo \"<LINK REL=StyleSheet HREF=\"http://static.esvmedia.org/legacy/css/text.css\" TYPE=\"text/css\" MEDIA=all>\" > %s.html && ", passage.c_str());
			}
    break;
		}
		
		
	}
	sprintf(bashOut, "%secho \"$(curl %spassageQuery%s\\&passage=%s%s%s%s%s%s%s%s)\" >> %s.html", bashOut, url.c_str(), key.c_str(), passage.c_str(), passageRefs.c_str(), verseNums.c_str(), footnotes.c_str(), footnoteLinks.c_str(), headings.c_str(), subHeadings.c_str(), audioFormat.c_str(), passage.c_str());
	
	system(bashOut);
}


void EsvApiInterface::copyText(string passage){
#if defined(__APPLE__) && defined(__MACH__)
	char buff[ESV_BUFFER_SIZE];
	sprintf(buff, "echo \"$(curl %spassageQuery%s\\&passage=%s%s%s%s%s%s%s%s\\&output-format=plain-text)\" | pbcopy", url.c_str(), key.c_str(), passage.c_str(), passageRefs.c_str(), verseNums.c_str(), footnotes.c_str(), footnoteLinks.c_str(), headings.c_str(), subHeadings.c_str(), audioFormat.c_str());
	system(buff);
#elif defined(__unix__) || defined(__linux__)
	char buff[ESV_BUFFER_SIZE];
	sprintf(buff, "echo \"$(curl -o toClip %spassageQuery%s\\&passage=%s%s%s%s%s%s%s%s\\&output-format=plain-text)\" && xsel --clipboard < toClip && rm toClip", url.c_str(), key.c_str(), passage.c_str(), passageRefs.c_str(), verseNums.c_str(), footnotes.c_str(), footnoteLinks.c_str(), headings.c_str(), subHeadings.c_str(), audioFormat.c_str());
	system(buff);
#endif
}

void EsvApiInterface::saveText(string passage, bool cpyToClip){
	char bashOut[ESV_BUFFER_SIZE] = "";
	sprintf(bashOut, "echo \"$(curl %spassageQuery%s\\&passage=%s%s%s%s%s%s%s%s\\&output-format=plain-text)\" > %s.txt", url.c_str(), key.c_str(), passage.c_str(), passageRefs.c_str(), verseNums.c_str(), footnotes.c_str(), footnoteLinks.c_str(), headings.c_str(), subHeadings.c_str(), audioFormat.c_str(), passage.c_str());
	
	
	if(cpyToClip){
		copyText(passage);
	}
	
	system(bashOut);
}


void EsvApiInterface::openText(string passage, bool cpyToClip, bool save){
	saveText(passage, cpyToClip);
	char bashOut[ESV_BUFFER_SIZE] = "";
	
	if(save){
		sprintf(bashOut, "open %s.txt", passage.c_str());
	}
	else{
		sprintf(bashOut, "open %s.txt && sleep 1 && rm %s.txt", passage.c_str(), passage.c_str());
	}
	
	
	system(bashOut);
}

void EsvApiInterface::openRand(int ESV_RAND_TYPE, int ESV_RAND_OUTPUT, bool saving, long seed){
	char bashOut[ESV_BUFFER_SIZE];
	saveRand(ESV_RAND_TYPE, ESV_RAND_OUTPUT, seed);
	if(saving){
		if(ESV_RAND_TYPE == ESV_RAND_TYPE_RAND)
			sprintf(bashOut, "open randVerse.html");
		else if (ESV_RAND_TYPE == ESV_RAND_TYPE_DAILY)
			sprintf(bashOut, "open dailyVerse.html");
	}
	else{
		if(ESV_RAND_TYPE == ESV_RAND_TYPE_RAND)
			sprintf(bashOut, "open randVerse.html && sleep 1 && rm randVerse.html");
		else if (ESV_RAND_TYPE == ESV_RAND_TYPE_DAILY)
			sprintf(bashOut, "open dailyVerse.html && sleep 1 && rm dailyVerse.html");
	}
	
	system(bashOut);
}

void EsvApiInterface::saveRand(int ESV_RAND_TYPE, int ESV_RAND_OUTPUT, long seed){
	char bashOut[ESV_BUFFER_SIZE] = "";
	
	switch (ESV_RAND_TYPE) {
		case ESV_RAND_TYPE_DAILY:{
			if(includeCssInHtml){
				switch (cssType) {
					case ESV_CSS_OPTIONS_TYPE_DEFAULT:
					{
						sprintf(bashOut, "echo \"<LINK REL=StyleSheet HREF=\"http://static.esvmedia.org/legacy/css/text.css\" TYPE=\"text/css\" MEDIA=all>\" > dailyVerse.html && ");
					}
						break;
					case ESV_CSS_OPTIONS_TYPE_DARK:
					{
						if(redLetter){
							sprintf(bashOut, "echo \"<head><style>\" > dailyVerse.html && ");
							sprintf(bashOut, "%secho \"$(<%sdark_redLetter.css)\" >> dailyVerse.html && ", bashOut, directory.c_str());
							sprintf(bashOut, "%secho \"</style></head>\" >> dailyVerse.html && ", bashOut);
						}
						else{
							sprintf(bashOut, "echo \"<head><style>\" > dailyVerse.html && ");
							sprintf(bashOut, "%secho \"$(<%sdark.css)\" >> dailyVerse.html && ", bashOut, directory.c_str());
							sprintf(bashOut, "%secho \"</style></head>\" >> dailyVerse.html && ", bashOut);
						}
					}
						break;
					default:{sprintf(bashOut, "echo \"<LINK REL=StyleSheet HREF=\"http://static.esvmedia.org/legacy/css/text.css\" TYPE=\"text/css\" MEDIA=all>\" > dailyVerse.html && ");}break;}
			}
			
			if( ESV_RAND_OUTPUT == ESV_OUTPUT_TYPE_HTML )
				sprintf(bashOut, "%secho \"$(curl %sdailyVerse%s%s%s%s%s%s%s%s)\" >> dailyVerse.html", bashOut, url.c_str(), key.c_str(), passageRefs.c_str(), verseNums.c_str(), footnotes.c_str(), footnoteLinks.c_str(), headings.c_str(), subHeadings.c_str(), audioFormat.c_str());
			else if( ESV_RAND_OUTPUT == ESV_OUTPUT_TYPE_TEXT )
				sprintf(bashOut, "%secho \"$(curl %sdailyVerse%s%s%s%s%s%s%s%s\\&output-format=plain-text)\" > dailyVerse.txt && rm dailyVerse.html", bashOut, url.c_str(), key.c_str(), passageRefs.c_str(), verseNums.c_str(), footnotes.c_str(), footnoteLinks.c_str(), headings.c_str(), subHeadings.c_str(), audioFormat.c_str());
			else if( ESV_RAND_OUTPUT == ESV_OUTPUT_TYPE_MP3 )
				sprintf(bashOut, "%secho \"$(curl %sdailyVerse%s%s%s%s%s%s%s%s\\&output-format=mp3)\" > dailyVerse.mp3 && rm dailyVerse.html", bashOut, url.c_str(), key.c_str(), passageRefs.c_str(), verseNums.c_str(), footnotes.c_str(), footnoteLinks.c_str(), headings.c_str(), subHeadings.c_str(), audioFormat.c_str());
			else
				sprintf(bashOut, "%secho \"$(curl %sdailyVerse%s%s%s%s%s%s%s%s)\" >> dailyVerse.html", bashOut, url.c_str(), key.c_str(), passageRefs.c_str(), verseNums.c_str(), footnotes.c_str(), footnoteLinks.c_str(), headings.c_str(), subHeadings.c_str(), audioFormat.c_str());
			
			
		}
		break;
		case ESV_RAND_TYPE_RAND:{
			if(includeCssInHtml){
				switch (cssType) {
					case ESV_CSS_OPTIONS_TYPE_DEFAULT:
					{
						sprintf(bashOut, "echo \"<LINK REL=StyleSheet HREF=\"http://static.esvmedia.org/legacy/css/text.css\" TYPE=\"text/css\" MEDIA=all>\" > randVerse.html && ");
					}
						break;
					case ESV_CSS_OPTIONS_TYPE_DARK:
					{
						if(redLetter){
							sprintf(bashOut, "echo \"<head><style>\" > randVerse.html && ");
							sprintf(bashOut, "%secho \"$(<%sdark_redLetter.css)\" >> randVerse.html && ", bashOut, directory.c_str());
							sprintf(bashOut, "%secho \"</style></head>\" >> randVerse.html && ", bashOut);
						}
						else{
							sprintf(bashOut, "echo \"<head><style>\" > randVerse.html && ");
							sprintf(bashOut, "%secho \"$(<%sdark.css)\" >> randVerse.html && ", bashOut, directory.c_str());
							sprintf(bashOut, "%secho \"</style></head>\" >> randVerse.html && ", bashOut);
						}
					}
						break;
					default:{sprintf(bashOut, "echo \"<LINK REL=StyleSheet HREF=\"http://static.esvmedia.org/legacy/css/text.css\" TYPE=\"text/css\" MEDIA=all>\" > randVerse.html && ");}break;}
			}
			
			
			
			
			if( ESV_RAND_OUTPUT == ESV_OUTPUT_TYPE_HTML )
				sprintf(bashOut, "%secho \"$(curl %sverse%s\\&seed=%ld%s%s%s%s%s%s%s)\" >> randVerse.html", bashOut, url.c_str(), key.c_str(), seed, passageRefs.c_str(), verseNums.c_str(), footnotes.c_str(), footnoteLinks.c_str(), headings.c_str(), subHeadings.c_str(), audioFormat.c_str());
			else if( ESV_RAND_OUTPUT == ESV_OUTPUT_TYPE_TEXT )
				sprintf(bashOut, "%secho \"$(curl %sverse%s\\&seed=%ld%s%s%s%s%s%s%s\\&output-format=plain-text)\" > randVerse.txt && rm randVerse.html", bashOut, url.c_str(), key.c_str(), seed, passageRefs.c_str(), verseNums.c_str(), footnotes.c_str(), footnoteLinks.c_str(), headings.c_str(), subHeadings.c_str(), audioFormat.c_str());
			else if( ESV_RAND_OUTPUT == ESV_OUTPUT_TYPE_MP3 )
				sprintf(bashOut, "%secho \"$(curl %sverse%s\\&seed=%ld%s%s%s%s%s%s%s\\&output-format=mp3)\" > randVerse.mp3 && rm randVerse.html", bashOut, url.c_str(), key.c_str(), seed, passageRefs.c_str(), verseNums.c_str(), footnotes.c_str(), footnoteLinks.c_str(), headings.c_str(), subHeadings.c_str(), audioFormat.c_str());
			else
				sprintf(bashOut, "%secho \"$(curl %sverse%s\\&seed=%ld%s%s%s%s%s%s%s)\" >> randVerse.html", bashOut, url.c_str(), key.c_str(), seed, passageRefs.c_str(), verseNums.c_str(), footnotes.c_str(), footnoteLinks.c_str(), headings.c_str(), subHeadings.c_str(), audioFormat.c_str());
			
			
		}
		break;
			
		default:
			break;
	}
	
	
	system(bashOut);
	
}

string EsvApiInterface::getBookmark(string bookMarkName){
	string out = "not_found";
	
	char fileName[ESV_BUFFER_SIZE];
	sprintf(fileName, "%sbookmarks.dat", directory.c_str());
	ifstream inF(fileName);
	string line;
	if(inF.fail()){
		cout << "\n\nERROR EsvApiInterface::getBookmark(string): Can not find " << fileName << endl;
	}
	else{
		while( getline(inF, line) ){
			size_t idx = line.find_first_of(" ");
			
			if( bookMarkName.compare(line.substr(0,idx)) == 0 ){
				out = line.substr(idx+1);
			}
			
		}
	}
	
	inF.close();
	
	return out;
}

void EsvApiInterface::setBookmark(string bookMarkName, string passageQuery){
	char fileName[ESV_BUFFER_SIZE];
	sprintf(fileName, "%sbookmarks.dat", directory.c_str());
	ofstream outFile;
	outFile.open(fileName, ios::app);
	bool overwrite = false;
	if(outFile.is_open()){
		string possiblePQ = getBookmark(bookMarkName);
		if( possiblePQ.compare("not_found") == 0 ){
			outFile << bookMarkName << " " << passageQuery << endl;
		}
		else{
			cout << bookMarkName<< " is already a bookmark name for " << possiblePQ << ". Overwrite? (y/N): ";
			string usrIn;
			cin >> usrIn;
			if( usrIn.compare("y") == 0 ){
				overwrite = true;
			}
		}
	}
	else{
		cout << "ERROR: No file named " << fileName << endl;
	}
	outFile.close();
	
	if(overwrite){
		char tempFile[ESV_BUFFER_SIZE];
		sprintf(tempFile, "%stemp", directory.c_str());
		ofstream newBkmk;
		newBkmk.open(tempFile, ios::out);
		if(newBkmk.is_open()){
			ifstream inF(fileName);
			string line;
			if(inF.fail()){
				cout << "\n\nERROR EsvApiInterface::setBookmark(string, string): Can not find " << fileName << endl;
			}
			else{
				while( getline(inF, line) ){
					size_t idx = line.find_first_of(" ");
					
					if( bookMarkName.compare(line.substr(0,idx)) == 0 ){
						newBkmk << bookMarkName << " " << passageQuery << endl;
					}
					else{
						newBkmk << line << endl;
					}
					
				}
			}
			
			inF.close();
		}
		newBkmk.close();
		
		char bashOut[ESV_BUFFER_SIZE];
		sprintf(bashOut, "mv %stemp %sbookmarks.dat", directory.c_str(), directory.c_str());
		system(bashOut);
	}
}

void EsvApiInterface::retrieveBookmark(int ESV_BOOKMARK_OUTPUT, string bookMarkName, int open_save_both){
	
	string bkmk = getBookmark(bookMarkName);
	if( bkmk.compare("not_found") == 0 ){
		cout << "Can not find bookmark name" << bookMarkName << endl;
		return;
	}
	
	switch (ESV_BOOKMARK_OUTPUT) {
  case ESV_OUTPUT_TYPE_HTML:
		{
			if( open_save_both == 1 ){
				openPassage(bkmk, false);
			}
			else if( open_save_both == 2 ){
				savePassage(bkmk);
			}
			else if( open_save_both == 3 ){
				openPassage(bkmk, true);
			}
		}
			break;
  case ESV_OUTPUT_TYPE_TEXT:
		{
			if( open_save_both == 1 ){
				openText(bkmk, true, false);
			}
			else if( open_save_both == 2 ){
				saveText(bkmk, true);
			}
			else if( open_save_both == 3 ){
				openText(bkmk, true, true);
			}
		
		
		}
			break;
  case ESV_OUTPUT_TYPE_MP3:
		{
			if( open_save_both == 1 ){
				openMp3(bkmk, false);
			}
			else if( open_save_both == 2 ){
				saveMp3(bkmk);
			}
			else if( open_save_both == 3 ){
				openMp3(bkmk, true);
			}
		
		
		
		}
			break;
			
  default:
			break;
	}
	
}


void EsvApiInterface::printBookmarks(){
	cout << endl;
	
	char fileName[ESV_BUFFER_SIZE];
	sprintf(fileName, "%sbookmarks.dat", directory.c_str());
	ifstream inF1(fileName);
	string line;
	if(inF1.fail()){
		cout << "\n\nERROR EsvApiInterface::getBookmark(string): Can not find " << fileName << endl;
	}
	else{
		cout << " _________________________________________________________" << endl;
		cout << "|        Bookmark        |            Passage             |" << endl;
		cout << "|__________Name__________|_____________Query______________|" << endl;
		cout << "|                        |                                |" << endl;
		
		while( getline(inF1, line) ){
			size_t idx = line.find_first_of(" ");
			
			cout << "|";
			
			// center and print bookmark name
			if( idx < 24 ){
				for(size_t i=0; i<12-idx/2-idx%2; i++)
					cout << " ";
				
				cout << line.substr(0,idx);
				
				for(size_t i=0; i<12-idx/2 ; i++)
					cout << " ";
				
				cout << "|";
			}
			else{
				cout << line.substr(0,24) << "|";
			}
			
			// center and print passage
			size_t L = line.substr(idx+1).length();
			if( L < 32 ){
				for(size_t i=0; i<16-L/2-L%2; i++)
					cout << " ";
				
				cout << line.substr(idx+1);
				
				for(size_t i=0; i<16-L/2 ; i++)
					cout << " ";
				
				cout << "|" << endl;
			}
			else{
				cout << line.substr(idx+1,32) << "|" << endl;
			}
		}
	}
	inF1.close();
	cout << "|________________________|________________________________|" << endl;
	cout << endl;
	
}

void EsvApiInterface::setDefaultAction(int numArgs, int arg1or2, int ArgVar){
	
	if(numArgs == 0){
		if( arg1or2 == 1 )
			zeroArg1 = ArgVar;
		else if( arg1or2 == 2 )
			zeroArg2 = ArgVar;
		else if( arg1or2 == 3 )
			zeroArgFormat = ArgVar;
	}
	else if(numArgs == 1){
		if( arg1or2 == 1 )
			oneArg1 = ArgVar;
		else if( arg1or2 == 2 )
			oneArg2 = ArgVar;
		else if( arg1or2 == 3 )
			oneArgFormat = ArgVar;
	}
	
}

void EsvApiInterface::setDefaultBookmarkName(string newName){
	defaultBookmarkName = newName;
}

void EsvApiInterface::runDefaultAction(int numArgs, string firstArg){

	// No input arguments
	if( numArgs == 0 ){
		
		if( zeroArg1 == 1 ){						// Open and/or save the daily verse
			
			if( zeroArg2 == 1 )						// open only
				openRand(ESV_RAND_TYPE_DAILY, zeroArgFormat, false);
			else if( zeroArg2 == 2 )				// save only
				openRand(ESV_RAND_TYPE_DAILY, zeroArgFormat, false);
			else if( zeroArg2 == 3 )				// open and save
				openRand(ESV_RAND_TYPE_DAILY, zeroArgFormat, true);
		}
			
		else if( zeroArg1 == 2 ){					// Open a random verse
			openRand(ESV_RAND_TYPE_RAND, false, random());
		}
		
		else if( zeroArg1 == 3 ){					// Show bookmarks
			printBookmarks();
		}
		
		else if( zeroArg1 == 4 ){					// Open and/or save a specific bookmark
			retrieveBookmark(zeroArgFormat, defaultBookmarkName, zeroArg2);
//			if( zeroArgFormat == 1 )
//				retrieveBookmark(ESV_OUTPUT_TYPE_HTML, defaultBookmarkName, zeroArg2);
//			else if( zeroArgFormat == 2 )
//				retrieveBookmark(ESV_OUTPUT_TYPE_TEXT, defaultBookmarkName, zeroArg2);
//			else if( zeroArgFormat == 3 )
//				retrieveBookmark(ESV_OUTPUT_TYPE_MP3, defaultBookmarkName, zeroArg2);
			
		}
	}
	
	// One input argument
	else if( numArgs == 1 ){
		
		if( oneArg1 == 1 ){							// firstArg is passage query
			
			if( oneArg2 == 1 ){						// open only
				openPassage(firstArg, false);
			}
			else if( oneArg2 == 2 ){				// save only
				savePassage(firstArg);
			}
			else if( oneArg2 == 3){					// open and save
				openPassage(firstArg, true);
			}
		}
		else if( oneArg1 == 2 ){
			retrieveBookmark(oneArgFormat, firstArg, oneArg2);
		}
		else if( oneArg1 == 3 ){
			cout << endl << "Enter a bookmark name for " << firstArg << ": ";
			string uIn;
			cin >> uIn;
			setBookmark(uIn, firstArg);
		}
		
	}
}

void EsvApiInterface::printSettings(){
	
	cout << "passageRefs: " << passageRefs << endl;
	cout << "verseNums  : " << verseNums << endl;
	cout << "footnotes  : " << footnotes << endl;
	cout << "footntelnks: " << footnoteLinks << endl;
	cout << "headings   : " << headings << endl;
	cout << "subheadings: " << subHeadings << endl;
	cout << "CSS type   : " << cssType << endl;
}
