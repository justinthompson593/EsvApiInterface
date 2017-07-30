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

#define ESV_HTML_OPTIONS_PASSAGE_REFS		0
#define ESV_HTML_OPTIONS_VERSE_NUMS			1
#define ESV_HTML_OPTIONS_FOOTNOTES			2
#define ESV_HTML_OPTIONS_FOOTNOTE_LINKS		3
#define ESV_HTML_OPTIONS_HEADINGS			4
#define ESV_HTML_OPTIONS_SUBHEADINGS		5

#define ESV_CSS_OPTIONS_TYPE_DEFAULT		1
#define ESV_CSS_OPTIONS_TYPE_DARK			2

class EsvApiInterface {
	
	// REST interface
	string url = "http://www.esvapi.org/v2/rest/";
	string key = "?key=IP";
//	string function = "passageQuery";				// passageQuery, query, verse
	
	
	// Options
	bool redLetter = true;
	
	
	// HTML output Options
	bool includeCssInHtml = true;
	int cssType = ESV_CSS_OPTIONS_TYPE_DEFAULT;
	//				   add \ for bash formatting	   (1=true   0=false)
	string passageRefs = "\\&include-passage-references=1";
	string verseNums = "\\&include-verse-numbers=1";
	string footnotes = "\\&include-footnotes=1";
	string footnoteLinks = "\\&include-footnote-links=1";
	string headings = "\\&include-headings=1";
	string subHeadings = "\\&include-subheadings=1";
	
	// Audio output Options 
	string audioFormat = "\\&audio-format=mp3";
	
	
	
public:
	EsvApiInterface();
	
	void setKey(string newKey);
	void setHTMLOutputOptions(int ESV_HTML_OPTIONS_ENUM, bool value);
	void includeCss(bool True_False);
	void setCssType(int ESV_CSS_OPTIONS_ENUM);
	void setRedLetter(bool true_false);
	
	
	// FUNCTION: passageQuery (with 3 output types)
	void openMp3(string passage);					// output type mp3
	void saveMp3(string passage);
	
	void openPassage(string passage, bool save=0);	// output type HTML
	void savePassage(string passage);
	
	void copyText(string passage);					// output type plain text
	void openText(string passage, bool copyToClipboard=0, bool save=0);
	void saveText(string passage, bool copyToClipboard=0);
	
	// FUNCTION: query
	string processScope(string userInputBookToSearch);
	string processSearchName(string searchStr);
	void search(string stringToFind, string bookToSearch="", bool save=0);
	void saveSearch(string stringToFind, string bookToSearch="");
	
	
	void printSettings();
};



#endif /* EsvApiInterface_hpp */


