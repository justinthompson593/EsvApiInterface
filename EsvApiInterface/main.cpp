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
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include "EsvApiInterface.hpp"

using namespace std;

string esvDefaultPath = "/Users/justinthompson/Cpp/EsvApi/";

//#if defined(__APPLE__) && defined(__MACH__)
//char buff[32768];
//sprintf(buff, "echo \"%s\" | pbcopy", scripture.c_str());
//system(buff);
//#endif


EsvApiInterface ESVinterface(esvDefaultPath);

void processDefaultSettings(string line){
	
	if( strncmp(line.c_str(), "CS=", 3) == 0 ){
		string val = line.substr(3);
		ESVinterface.setCssType(stoi(val));
	}
	else if( strncmp(line.c_str(), "PR=", 3) == 0 ){
		string val = line.substr(3);
		ESVinterface.setHTMLOutputOptions(ESV_HTML_OPTIONS_PASSAGE_REFS, stoi(val));
	}
	else if( strncmp(line.c_str(), "VN=", 3) == 0 ){
		string val = line.substr(3);
		ESVinterface.setHTMLOutputOptions(ESV_HTML_OPTIONS_VERSE_NUMS, stoi(val));
	}
	else if( strncmp(line.c_str(), "FN=", 3) == 0 ){
		string val = line.substr(3);
		ESVinterface.setHTMLOutputOptions(ESV_HTML_OPTIONS_FOOTNOTES, stoi(val));
	}
	else if( strncmp(line.c_str(), "FL=", 3) == 0 ){
		string val = line.substr(3);
		ESVinterface.setHTMLOutputOptions(ESV_HTML_OPTIONS_FOOTNOTE_LINKS, stoi(val));
	}
	else if( strncmp(line.c_str(), "HD=", 3) == 0 ){
		string val = line.substr(3);
		ESVinterface.setHTMLOutputOptions(ESV_HTML_OPTIONS_HEADINGS, stoi(val));
	}
	else if( strncmp(line.c_str(), "SH=", 3) == 0 ){
		string val = line.substr(3);
		ESVinterface.setHTMLOutputOptions(ESV_HTML_OPTIONS_SUBHEADINGS, stoi(val));
	}
}

void initDefaults(){
	
	ofstream outFile;
	char fileName[2048];
	sprintf(fileName, "%sdefaults.dat", ESVinterface.getDirectory().c_str());
	outFile.open(fileName, ios::out);
	
	if(outFile.is_open()){
		cout << "Choose CSS type\n\n1: Default\n2: Dark\n\nEnter a number: ";
		string usrIn;
		cin >> usrIn;
		int in = stoi(usrIn);
		outFile << "CS=" << in << endl;
		
		cout << "Passage References (0=off / 1=on): ";
		cin >> usrIn;
		in = stoi(usrIn);
		outFile << "PR=" << in << endl;
		
		cout << "Verse Numbers      (0=off / 1=on): ";
		cin >> usrIn;
		in = stoi(usrIn);
		outFile << "VN=" << in << endl;
		
		cout << "Footnotes          (0=off / 1=on): ";
		cin >> usrIn;
		in = stoi(usrIn);
		outFile << "FN=" << in << endl;
		
		cout << "Footnote Links     (0=off / 1=on): ";
		cin >> usrIn;
		in = stoi(usrIn);
		outFile << "FL=" << in << endl;
		
		cout << "Headings           (0=off / 1=on): ";
		cin >> usrIn;
		in = stoi(usrIn);
		outFile << "HD=" << in << endl;
		
		cout << "Subheadings        (0=off / 1=on): ";
		cin >> usrIn;
		in = stoi(usrIn);
		outFile << "SH=" << in << endl;
		
		outFile.close();
	}
	else{
		// ?
	}
	
}

int main(int argc, const char * argv[]) {
	
	
	char fileName[2048];
	sprintf(fileName, "%sdefaults.dat", ESVinterface.getDirectory().c_str());
	ifstream ifs(fileName);
	string line;
	if(ifs.fail()){
		initDefaults();
	}
	else{
		while( getline(ifs, line) ){
			processDefaultSettings(line);
		}
	}
	
	
	
	cout << endl << "Settings: " << endl;
	ESVinterface.printSettings();
	
	
	
//	return 222;
	
	
	// Command Line Use

	int numFlags = 0;
	bool searching = false;
	string searchString;
	string searchScope = "";
	bool saving = false;
	bool psgQuery = true;
	bool txtOut = false;
	bool mp3Out = false;
	
	for(int i=1; i<argc; i++){
		
		// check for redefine defaults
		if( strncmp(argv[i], "-def", 7) == 0){
			initDefaults();
		}
		
		// check for search query
		if( (strncmp(argv[i], "-s", 2) == 0 && strncmp(argv[i], "-sub", 4) != 0) || strncmp(argv[i], "-search", 7) == 0){
			searching = true;
			i++;
			searchString = (string)argv[i];
			if( i+1 < argc ){
				cout << "adding " << argv[i+1] << " to search scope" << endl;
				i++;
				searchScope = (string)argv[i];
			}
		}
		// check to save html / mp3 / txt file
		if( strncmp(argv[i], "-S", 2) == 0 || strncmp(argv[i], "-Save", 5) == 0){
			saving = true;
		}
		
		// Formats
		if( strncmp(argv[i], "-txt", 4) == 0 ){
			txtOut = true;
		}
		if( strncmp(argv[i], "-mp3", 4) == 0 ){
			mp3Out = true;
		}
		if( strncmp(argv[i],   "-q", 2) == 0 ){
			psgQuery = false;
		}
		
		
		// check for flags to override default settings
		if( strncmp(argv[i], "-ref", 4) == 0){
			i++;
			numFlags++;
			ESVinterface.setHTMLOutputOptions(ESV_HTML_OPTIONS_PASSAGE_REFS, stoi(argv[i]));
		}
		if( strncmp(argv[i], "-hed", 4) == 0){
			i++;
			numFlags++;
			ESVinterface.setHTMLOutputOptions(ESV_HTML_OPTIONS_HEADINGS, stoi(argv[i]));
		}
		if( strncmp(argv[i], "-sub", 4) == 0){
			i++;
			numFlags++;
			ESVinterface.setHTMLOutputOptions(ESV_HTML_OPTIONS_SUBHEADINGS, stoi(argv[i]));
		}
		if( strncmp(argv[i], "-foot", 5) == 0){
			i++;
			numFlags++;
			ESVinterface.setHTMLOutputOptions(ESV_HTML_OPTIONS_FOOTNOTES, stoi(argv[i]));
		}
		if( strncmp(argv[i], "-flnk", 5) == 0){
			i++;
			numFlags++;
			ESVinterface.setHTMLOutputOptions(ESV_HTML_OPTIONS_FOOTNOTE_LINKS, stoi(argv[i]));
		}
		if( strncmp(argv[i], "-num", 4) == 0){
			i++;
			numFlags++;
			ESVinterface.setHTMLOutputOptions(ESV_HTML_OPTIONS_VERSE_NUMS, stoi(argv[i]));
		}
		
		
		
		
	}
	

	
	if(psgQuery){
		// assume 1st arg is a passage query
		string passage(argv[1]);
		ESVinterface.openPassage(passage, saving);
	}
	
	if(txtOut){
		string passage(argv[1]);
		ESVinterface.openText(passage, saving);
	}
	
	if(mp3Out){
		string passage(argv[1]);
		ESVinterface.openMp3(passage, saving);
	}
	
	if(searching){
		ESVinterface.search(searchString, searchScope, saving);
	}
	
	
	
//	int numArgs = argc - 2*numFlags - 1;
//	
//	
//	
//	if(numArgs == 1){
//		string passageInput(argv[1]);
//		ESVinterface.openPassage(passageInput);
//	}
	
	
	return 0;
}
