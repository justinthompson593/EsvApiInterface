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
//sprintf(scriptOut, "open http://www.esvapi.org/v2/rest/passageQuery?key=IP\\&passage=1cor3:16\\&output-format=mp3");
void EsvApiInterface::openMp3(string passage){
	char bashOut[512];
	sprintf(bashOut, "open %spassageQuery%s\\&passage=%s\\&output-format=mp3", url.c_str(), key.c_str(), passage.c_str());
	system(bashOut);
}

void EsvApiInterface::saveMp3(string passage){
	
}

void EsvApiInterface::openPassage(string passage){
	
}

void EsvApiInterface::savePassage(string passage){
	
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
