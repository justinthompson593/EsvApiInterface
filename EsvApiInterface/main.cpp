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

using namespace std;

string scripture = "";

//#if defined(__APPLE__) && defined(__MACH__)
//char buff[32768];
//sprintf(buff, "echo \"%s\" | pbcopy", scripture.c_str());
//system(buff);
//#endif

int main(int argc, const char * argv[]) {
	
	char scriptOut[32768];
	
	string httpAddress = "http://www.esvapi.org/v2/rest/";
	string book = "Gen";
	string chapter = "5";
	
	// just open it from online
	sprintf(scriptOut, "open %spassageQuery?key=IP\\&passage=%s+%s\\&include-headings=false", httpAddress.c_str(), book.c_str(), chapter.c_str());
	system(scriptOut);
	
	// curl it from online, save as .html, open it from here
	sprintf(scriptOut, "echo \"$(curl %spassageQuery?key=IP\\&passage=%s+%s)\" > scripture1.html && open scripture1.html", httpAddress.c_str(), book.c_str(), chapter.c_str());
	system(scriptOut);
	
	// OUTPUT FORMATS
	//
	// mp3
	sprintf(scriptOut, "open http://www.esvapi.org/v2/rest/passageQuery?key=IP\\&passage=1cor3:16\\&output-format=mp3");
	system(scriptOut);
	// plain-text			(Copied to Clipboard!)
	sprintf(scriptOut, "echo \"$(curl http://www.esvapi.org/v2/rest/passageQuery?key=IP\\&passage=1cor3\\&output-format=plain-text)\" | pbcopy");
	system(scriptOut);
	
	// trying stuff
	//	sprintf(scriptOut, "echo \"$(curl %spassageQuery?key=IP\\&passage=%s+%s\\&include-headings=false\\&output-format=crossway-xml-1.0)\" > scripture.html && open scripture.html", httpAddress.c_str(), book.c_str(), chapter.c_str());
	//	system(scriptOut);

	
	return 0;
}
