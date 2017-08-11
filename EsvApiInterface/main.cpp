
// If there is nothing above this line, then something went wrong on the install.
// It should look like the like below, but without the "//" at the begining.

#define ESV_PATH "/Users/justinthompson/Cpp/EsvApi/"

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
#include <random>
#include "EsvApiInterface.hpp"

using namespace std;


EsvApiInterface ESVinterface(ESV_PATH);

bool is_number(const std::string& s){
	std::string::const_iterator it = s.begin();
	while (it != s.end() && std::isdigit(*it)) ++it;

	return !s.empty() && it == s.end();
	
	// From https://stackoverflow.com/questions/4654636/how-to-determine-if-a-string-is-a-number-with-c
}




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
	else if( strncmp(line.c_str(), "RL=", 3) == 0 ){
		string val = line.substr(3);
		ESVinterface.setHTMLOutputOptions(ESV_HTML_OPTIONS_RED_LETTER, stoi(val));
	}
}

void initDefaults(string exeName){
	
	cout << "______________Esv Api Interface______________" << endl << endl;
	
	ofstream outFile;
	char fileName[2048];
	sprintf(fileName, "%sdefaults.dat", ESVinterface.getDirectory().c_str());
	outFile.open(fileName, ios::out);
	
	if(outFile.is_open()){
		cout << "Choose CSS type\n" << endl;
		cout << "1: Default" << endl;
		cout << "2: Dark" << endl;
		cout << "3: Custom" << endl;
		cout << endl << endl << "Enter a number: ";
		string usrIn;
		cin >> usrIn;
//		int in = stoi(usrIn);
		outFile << "CS=" << usrIn << endl;
		
		cout << "Verse Numbers      (0=off / 1=on): ";
		cin >> usrIn;
//		in = stoi(usrIn);
		outFile << "VN=" << usrIn << endl;
		
		cout << "Headings           (0=off / 1=on): ";
		cin >> usrIn;
//		in = stoi(usrIn);
		outFile << "HD=" << usrIn << endl;
		
		cout << "Subheadings        (0=off / 1=on): ";
		cin >> usrIn;
//		in = stoi(usrIn);
		outFile << "SH=" << usrIn << endl;
		
		cout << "Footnotes          (0=off / 1=on): ";
		cin >> usrIn;
//		in = stoi(usrIn);
		outFile << "FN=" << usrIn << endl;
		
		cout << "Footnote Links     (0=off / 1=on): ";
		cin >> usrIn;
//		in = stoi(usrIn);
		outFile << "FL=" << usrIn << endl;
		
		cout << "Passage References (0=off / 1=on): ";
		cin >> usrIn;
//		in = stoi(usrIn);
		outFile << "PR=" << usrIn << endl;
		
		cout << "Words of Christ in red  ( 0 / 1 ): ";
		cin >> usrIn;
//		in = stoi(usrIn);
		outFile << "RL=" << usrIn << endl;
		
		cout << endl << "What should happen when you run EsvApiInterface with no input arguments? i.e.\n\t$ ";
		cout << exeName << endl << endl;
		cout << "1: Open and/or save the daily verse" << endl;
		cout << "2: Open and/or save a random verse" << endl;
		
		
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
		initDefaults(argv[0]);
	}
	else{
		while( getline(ifs, line) ){
			processDefaultSettings(line);
		}
		ifs.close();
	}
	
	// Check first argument
	if( strncmp(argv[1], "-init", 5) == 0 ){				// -init flag used in installer
		return 1;
	}
	
	// Command Line Use

//	int numFlags = 0;
	bool searching = false;
	string searchString;
	string searchScope = "";
	bool saving = false;
//	bool psgQuery = true;
//	bool txtOut = false;
//	bool mp3Out = false;
	bool cpyToClip = false;
	
	bool randomIn = false;
	int randType = 0;
	long seedIn = 0;
	
//	bool quietAll = false;
//	bool quietPassage = false;
//	bool quietText = false;
//	bool quietMp3 = false;
	
	// New idea
	bool savePassage = false;
	bool openPassage = true;
	
	bool saveText = false;
	bool openText = false;
	
	bool saveMp3 = false;
	bool openMp3 = false;
	
	
	// Process input flags
	for(int i=1; i<argc; i++){
		
//		// Quiet outputs
//		if( strncmp(argv[i], "-Q", 2) == 0 ){
//			quietAll = true;
//		}
//		if( strncmp(argv[i], "-qp", 3) == 0 ){
//			quietPassage = true;
//		}
//		if( strncmp(argv[i], "-qt", 3) == 0 ){
//			quietPassage = true;
//		}
		
		// Check for opening
		if( strncmp(argv[i], "-op", 3) == 0 || strncmp(argv[i], "--open-passage", 14) == 0 ){
			openPassage = true;
		}
		if( strncmp(argv[i], "-ot", 3) == 0 || strncmp(argv[i], "--open-text", 11) == 0 ){
			openText = true;
		}
		if( strncmp(argv[i], "-o3", 3) == 0 || strncmp(argv[i], "--open-mp3", 10) == 0){
			openMp3 = true;
		}
		
		// Check for saving
		if( strncmp(argv[i], "-sp", 3) == 0 || strncmp(argv[i], "--save-passage", 14) == 0){
			savePassage = true;
		}
		if( strncmp(argv[i], "-st", 3) == 0 || strncmp(argv[i], "--save-text", 11) == 0){
			saveText = true;
		}
		if( strncmp(argv[i], "-s3", 3) == 0 || strncmp(argv[i], "--save-mp3", 10) == 0){
			saveMp3 = true;
		}
		
		// Copy text to clipboard
		if( strncmp(argv[i], "-c", 2) == 0 ){
			cpyToClip = true;
		}
		
		// check for redefine defaults
		if( strncmp(argv[i], "-def", 4) == 0){
			initDefaults(argv[0]);
			ifstream ifs2(fileName);
			if(ifs2.fail()){
				// ¿initDefaults must have failed?
			}
			else{
				while( getline(ifs2, line) ){
					processDefaultSettings(line);
				}
				ifs2.close();
			}
			
		}
		
		// check for search query
		if( strncmp(argv[i], "-sr", 3) == 0 || strncmp(argv[i], "-search", 7) == 0){
			searching = true;
			i++;
			searchString = (string)argv[i];
			if( i+1 < argc ){
				i++;
				searchScope = (string)argv[i];
			}
		}

		
		//	Check for randVerse or whatever else save flag: -S
		if( strncmp(argv[i], "-S", 2) == 0 || strncmp(argv[i], "-Save", 5) == 0){
			saving = true;
		}
//
//		// Output Formats
//		if( strncmp(argv[i], "-txt", 4) == 0 ){
//			txtOut = true;
//		}
//		if( strncmp(argv[i], "-mp3", 4) == 0 ){
//			mp3Out = true;
//		}
//		if( strncmp(argv[i],   "-q", 2) == 0 ){		// quiet default openPassage
//			psgQuery = false;
//		}
		
		
		// check for flags to override default settings
		if( strncmp(argv[i], "-ref", 4) == 0){
			i++;
			ESVinterface.setHTMLOutputOptions(ESV_HTML_OPTIONS_PASSAGE_REFS, stoi(argv[i]));
		}
		if( strncmp(argv[i], "-hed", 4) == 0){
			i++;
			ESVinterface.setHTMLOutputOptions(ESV_HTML_OPTIONS_HEADINGS, stoi(argv[i]));
		}
		if( strncmp(argv[i], "-sub", 4) == 0){
			i++;
			ESVinterface.setHTMLOutputOptions(ESV_HTML_OPTIONS_SUBHEADINGS, stoi(argv[i]));
		}
		if( strncmp(argv[i], "-foot", 5) == 0){
			i++;
			ESVinterface.setHTMLOutputOptions(ESV_HTML_OPTIONS_FOOTNOTES, stoi(argv[i]));
		}
		if( strncmp(argv[i], "-flnk", 5) == 0){
			i++;
			ESVinterface.setHTMLOutputOptions(ESV_HTML_OPTIONS_FOOTNOTE_LINKS, stoi(argv[i]));
		}
		if( strncmp(argv[i], "-num", 4) == 0){
			i++;
			ESVinterface.setHTMLOutputOptions(ESV_HTML_OPTIONS_VERSE_NUMS, stoi(argv[i]));
		}
		if( strncmp(argv[i], "-rl", 3) == 0){
			i++;
			ESVinterface.setHTMLOutputOptions(ESV_HTML_OPTIONS_RED_LETTER, stoi(argv[i]));
		}
		
		
		
		// randomVerse / dailyVerse
		if( strncmp(argv[i], "-rnd", 4) == 0 || strncmp(argv[i], "-rand", 5) == 0 ){
			randomIn = true;
			
			if( i+1 < argc ){						// check next arg
				string nextArg(argv[i+1]);
				if(is_number(nextArg)){				// then next arg is a random seed
					randType = ESV_RAND_TYPE_RAND;
					seedIn = stol(argv[i+1]);
				}
				else{
					randType = ESV_RAND_TYPE_DAILY;
				}
				
			}
			else{
				randType = ESV_RAND_TYPE_DAILY;
			}
		}
		
		
	} // for(  argv[i] , i++  )END INPUT PROCESSING
	
	
	
	// Check if there's only 1 arg. If so, use user's default settings TODO
	if( argc == 1 ){
		
		return 2;
	}

	if(searching)
		ESVinterface.search(searchString, searchScope, saving);
	
	if(randomIn){
		if(randType == ESV_RAND_TYPE_RAND)
			ESVinterface.openRand(ESV_RAND_TYPE_RAND, saving, seedIn);
		else
			ESVinterface.openRand(ESV_RAND_TYPE_DAILY, saving);
			
	}
	
	if( strncmp(argv[1], "-", 1) != 0 ){// if the first arg is NOT a flag,
		// then argv[1] is the passage query (in format [Num]BookChp:Vrs i.e. 1cor2:3-5)
		
		// HTML output
		if( openPassage && savePassage )
			ESVinterface.openPassage(argv[1], true);
		else if( openPassage && !savePassage )
			ESVinterface.openPassage(argv[1], false);
		else if( !openPassage && savePassage )
			ESVinterface.savePassage(argv[1]);
	
		// Text output
		if( openText && saveText )
			ESVinterface.openText(argv[1], true);
		else if( openText && !saveText )
			ESVinterface.openText(argv[1], false);
		else if( !openText && saveText )
			ESVinterface.saveText(argv[1]);
		
		// Mp3 output
		if( openMp3 && saveMp3 )
			ESVinterface.openMp3(argv[1], true);
		else if( openMp3 && !saveMp3 )
			ESVinterface.openMp3(argv[1], false);
		else if( !openMp3 && saveMp3 )
			ESVinterface.saveMp3(argv[1]);
		
	}
	
	
	
	
	
	// Open media
	//	if( strncmp(argv[1], "-", 1) != 0 ){
	//		if(psgQuery)
	//			ESVinterface.openPassage(argv[1], saving);
	//
	//		if(txtOut)
	//			ESVinterface.openText(argv[1], cpyToClip, saving);
	//
	//		if(mp3Out)
	//			ESVinterface.openMp3(argv[1], saving);
	//
	//		if(cpyToClip && !txtOut)
	//			ESVinterface.copyText(argv[1]);
	//	}

	
//	if( strncmp(argv[1], "-", 1) != 0 ){
//
//		if(psgQuery && (quietAll || quietPassage) && saving)
//			ESVinterface.savePassage(argv[1]);
//		else if(psgQuery && !quietAll && !quietPassage)
//			ESVinterface.openPassage(argv[1], saving);
//		
//		if(txtOut && (quietAll || quietText) && saving)
//			ESVinterface.saveText(argv[1]);
//		else if(txtOut && !quietAll && !quietText)
//			ESVinterface.openText(argv[1], cpyToClip, saving);
//		
//		if(mp3Out && (quietAll || quietMp3) && saving)
//			ESVinterface.saveMp3(argv[1]);
//		else if(txtOut && !quietAll && !quietMp3)
//			ESVinterface.openMp3(argv[1], saving);
//
//	}
//	
//	
//	if(cpyToClip && !txtOut)
//		ESVinterface.copyText(argv[1]);
//	
	
	
	return 0;
}
