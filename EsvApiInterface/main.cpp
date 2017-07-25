//
//  main.cpp
//  EsvApiInterface
//
//  Created by Justin Thompson on 7/18/17.
//  Copyright © 2017 Justin Thompson. All rights reserved.
//
//  http://www.esvapi.org/api


#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "EsvApiInterface.hpp"

using namespace std;

string scripture = "";

//#if defined(__APPLE__) && defined(__MACH__)
//char buff[32768];
//sprintf(buff, "echo \"%s\" | pbcopy", scripture.c_str());
//system(buff);
//#endif


EsvApiInterface ESVinterface;



int main(int argc, const char * argv[]) {

	// Command Line Use

	int numFlags = 0;
	// check for flags
	for(int i=1; i<argc; i++){
		if( strncmp(argv[i], "-r", 2) == 0  ||  strncmp(argv[i], "-ref", 4) == 0){
			i++;
			numFlags++;
			ESVinterface.setHTMLOutputOptions(ESV_HTML_OPTIONS_PASSAGE_REFS, stoi(argv[i]));
		}
		if( strncmp(argv[i], "-h", 2) == 0  ||  strncmp(argv[i], "-hed", 4) == 0){
			i++;
			numFlags++;
			ESVinterface.setHTMLOutputOptions(ESV_HTML_OPTIONS_HEADINGS, stoi(argv[i]));
		}
		if( strncmp(argv[i], "-s", 2) == 0  ||  strncmp(argv[i], "-sh", 3) == 0  ||  strncmp(argv[i], "-sub", 4) == 0){
			i++;
			numFlags++;
			ESVinterface.setHTMLOutputOptions(ESV_HTML_OPTIONS_SUBHEADINGS, stoi(argv[i]));
		}
		if( strncmp(argv[i], "-f", 2) == 0  ||  strncmp(argv[i], "-fn", 3) == 0  ||  strncmp(argv[i], "-foot", 5) == 0){
			i++;
			numFlags++;
			ESVinterface.setHTMLOutputOptions(ESV_HTML_OPTIONS_FOOTNOTES, stoi(argv[i]));
		}
		if( strncmp(argv[i], "-fl", 3) == 0  ||  strncmp(argv[i], "-fnl", 4) == 0  ||  strncmp(argv[i], "-ftlnk", 6) == 0){
			i++;
			numFlags++;
			ESVinterface.setHTMLOutputOptions(ESV_HTML_OPTIONS_FOOTNOTE_LINKS, stoi(argv[i]));
		}
		if( strncmp(argv[i], "-n", 2) == 0  ||  strncmp(argv[i], "-vn", 3) == 0  ||  strncmp(argv[i], "-num", 4) == 0){
			i++;
			numFlags++;
			ESVinterface.setHTMLOutputOptions(ESV_HTML_OPTIONS_VERSE_NUMS, stoi(argv[i]));
		}
		
		
		
		
	}
	
	
	int numArgs = argc - 2*numFlags - 1;
	
	string passageInput(argv[1]);
	cout << "Your passage is " << passageInput << endl;
	cout << "Settings:" << endl;
	ESVinterface.printSettings();
	
	if(numArgs == 1){
		ESVinterface.openPassage(passageInput);
	}
	
	
	
//	cout << "Debugging EsvApiInterface" << endl;
////	ESVinterface.setHTMLOutputOptions(ESV_HTML_OPTIONS_HEADINGS, 0);
////	ESVinterface.setHTMLOutputOptions(ESV_HTML_OPTIONS_SUBHEADINGS, 0);
////	ESVinterface.debug();
////	
//////	ESVinterface.openMp3("John3:16");
//////	ESVinterface.saveMp3("Eph5:11");
////	
////	ESVinterface.openPassage("John2");
////	
////	ESVinterface.setHTMLOutputOptions(ESV_HTML_OPTIONS_HEADINGS, 1);
////	ESVinterface.setHTMLOutputOptions(ESV_HTML_OPTIONS_SUBHEADINGS, 1);
////	ESVinterface.debug();
////
////	ESVinterface.includeCss(0);
//	ESVinterface.setCssType(ESV_CSS_OPTIONS_TYPE_DARK);
////	ESVinterface.savePassage("Luke2");
//
////	ESVinterface.savePassage("Exo1");
////	ESVinterface.openPassage("Mat5");
//	
////	ESVinterface.saveText("Mat5");
//	ESVinterface.saveText("luke8:50-9:2",true);
//	ESVinterface.openText("luke8");
//	
	
	return 0;
}
