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
#include <fstream>
#include <string>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

#define ESV_BUFFER_SIZE 4096

#define ESV_HTML_OPTIONS_PASSAGE_REFS		0
#define ESV_HTML_OPTIONS_VERSE_NUMS			1
#define ESV_HTML_OPTIONS_FOOTNOTES			2
#define ESV_HTML_OPTIONS_FOOTNOTE_LINKS		3
#define ESV_HTML_OPTIONS_HEADINGS			4
#define ESV_HTML_OPTIONS_SUBHEADINGS		5
#define ESV_HTML_OPTIONS_RED_LETTER			6

#define ESV_CSS_OPTIONS_TYPE_DEFAULT		1
#define ESV_CSS_OPTIONS_TYPE_DARK			2

#define ESV_RAND_TYPE_RAND					0
#define ESV_RAND_TYPE_DAILY					1

class EsvApiInterface {
	
	string directory = "";
	
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
	
	
	// Zero input arg default action
	int zeroArg1 = 0;
	int zeroArg2 = 0;
	int zeroArgFormat = 0;
	string defaultBookmarkName = "";
	
	// One input arg default action
	int oneArg1 = 0;
	int oneArg2 = 0;
	int oneArgFormat = 0;
	
	
public:
	EsvApiInterface();
	EsvApiInterface(string direc);
	
	void setDirectory(string direc);
	string getDirectory();
	
	void setKey(string newKey);
	void setHTMLOutputOptions(int ESV_HTML_OPTIONS_ENUM, bool value);
	void includeCss(bool True_False);
	void setCssType(int ESV_CSS_OPTIONS_ENUM);
	void setRedLetter(bool true_false);
	
	
	void setDefaultAction(int numArgs, int ArgVar1, int ArgVar2);
	void setDefaultBookmarkName(string newName);
	void runDefaultAction(int numArgs);
	
	// FUNCTION: passageQuery (with 3 output types)
	void openMp3(string passage, bool save=0);		// output type mp3
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
	
	// FUNCTION: verse  (using &seed= instead of &passage= for random or daily verse)
	void openRand(int ESV_RAND_TYPE, bool saving, long seed=0);
	void saveRand(int ESV_RAND_TYPE, long seed=0);
	
	
	string getCSS();
	
	// Bookmarks
	void printBookmarks();
	void setBookmark(string bookMarkName, string passageQuery);
	string getBookmark(string bookMarkName);
	
	
	void printSettings();
};



#endif /* EsvApiInterface_hpp */


