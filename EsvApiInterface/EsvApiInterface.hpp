//
//  EsvApiInterface.hpp
//  EsvApiInterface
//
//  Created by Justin Thompson on 7/19/17.
//  Copyright © 2017 Justin Thompson. All rights reserved.
//

#ifndef EsvApiInterface_hpp
#define EsvApiInterface_hpp

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

#define ESV_HTML_OPTIONS_PASSAGE_REFS	0
#define ESV_HTML_OPTIONS_VERSE_NUMS		1
#define ESV_HTML_OPTIONS_FOOTNOTES		2
#define ESV_HTML_OPTIONS_FOOTNOTE_LINKS	3
#define ESV_HTML_OPTIONS_HEADINGS		4
#define ESV_HTML_OPTIONS_SUBHEADINGS	5



class EsvApiInterface {
	
	// REST interface
	string url = "http://www.esvapi.org/v2/rest/";
	string key = "?key=IP";
//	string function = "passageQuery";				// passageQuery, query, verse
	
	
	// Options
	bool includeCssInHtml = true;
	
	// HTML output Options
	//				   add \ for bash formatting	   (1=true   0=false)
	string passageRefs = "\\&include-passage-references=1";
	string verseNums = "\\&include-verse-numbers=1";
	string footnotes = "\\&include-footnotes=1";
	string footnoteLinks = "\\&include-footnote-links=1";
	string headings = "\\&include-headings=1";
	string subHeadings = "\\&include-subheadings=1";
	
	// audio output 
	string audioFormat = "audio-format=mp3";
	
	
	
public:
	EsvApiInterface();
	
	void setKey(string newKey);
	void setHTMLOutputOptions(int ESV_HTML_OPTIONS_ENUM, bool value);
	
	
	
	// FUNCTION: passageQuery (with 3 output types)
	void openMp3(string passage);					// output type mp3
	void saveMp3(string passage);
	
	void openPassage(string passage);				// output type HTML
	void savePassage(string passage);
	
	void openText(string passage);					// output type plain text
	void saveText(string passage);
	
	
	void debug();
};



#endif /* EsvApiInterface_hpp */


