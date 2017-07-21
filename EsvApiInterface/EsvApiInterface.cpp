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
			
  default:
			break;
	}
}

void EsvApiInterface::openMp3(string passage){
	char bashOut[2048];
	sprintf(bashOut, "open %spassageQuery%s\\&passage=%s\\&output-format=mp3", url.c_str(), key.c_str(), passage.c_str());
	system(bashOut);
}

void EsvApiInterface::saveMp3(string passage){
	char bashOut[2048];
	sprintf(bashOut, "echo \"$(curl %spassageQuery%s\\&passage=%s\\&output-format=mp3)\" > %s.mp3", url.c_str(), key.c_str(), passage.c_str(), passage.c_str());
	system(bashOut);
}
//sprintf(scriptOut, "open %spassageQuery?key=IP\\&passage=%s+%s\\&include-headings=false", httpAddress.c_str(), book.c_str(), chapter.c_str());
void EsvApiInterface::openPassage(string passage){
	char bashOut[2048];
	if(includeCssInHtml){
		savePassage(passage);
		sprintf(bashOut, "open %s.html && sleep 1 && rm %s.html", passage.c_str(), passage.c_str());
	}
	else{
		sprintf(bashOut, "open %spassageQuery%s\\&passage=%s%s%s%s%s%s%s", url.c_str(), key.c_str(), passage.c_str(), passageRefs.c_str(), verseNums.c_str(), footnotes.c_str(), footnoteLinks.c_str(), headings.c_str(), subHeadings.c_str());
	}
	
	system(bashOut);
}

void EsvApiInterface::savePassage(string passage){
	char bashOut[2048] = "";
	if(includeCssInHtml)
		sprintf(bashOut, "echo \"<LINK REL=StyleSheet HREF=\"http://static.esvmedia.org/legacy/css/text.css\" TYPE=\"text/css\" MEDIA=all>\" > %s.html && ", passage.c_str());
	
	sprintf(bashOut, "%secho \"$(curl %spassageQuery%s\\&passage=%s%s%s%s%s%s%s)\" >> %s.html", bashOut, url.c_str(), key.c_str(), passage.c_str(), passageRefs.c_str(), verseNums.c_str(), footnotes.c_str(), footnoteLinks.c_str(), headings.c_str(), subHeadings.c_str(), passage.c_str());
	
	system(bashOut);
}

void EsvApiInterface::openText(string passage){
	
}

void EsvApiInterface::saveText(string passage){
	
}


void EsvApiInterface::debug(){
	
	cout << "passageRefs: " << passageRefs << endl;
	cout << "verseNums  : " << verseNums << endl;
	cout << "footnotes  : " << footnotes << endl;
	cout << "footntelnks: " << footnoteLinks << endl;
	cout << "headings   : " << headings << endl;
	cout << "subheadings: " << subHeadings << endl;
}
