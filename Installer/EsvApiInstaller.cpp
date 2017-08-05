#include <iostream>
#include <string.h>
#include <fstream>
/***********************************************************************
*
* EsvApiInstaller.cpp
*
*	USAGE: 	$ EsvApiInstaller [args]
*
*	DESCR: 	
*
*	OUTPUT:	
***********************************************************************/

using namespace std;



int main(int argc, char* argv[]){
	
	// Get files needed to build executable
	system("curl -o main.cpp https://raw.githubusercontent.com/justinthompson593/EsvApiInterface/master/EsvApiInterface/main.cpp");
	system("curl -o EsvApiInterface.cpp https://raw.githubusercontent.com/justinthompson593/EsvApiInterface/master/EsvApiInterface/EsvApiInterface.cpp");
	system("curl -o EsvApiInterface.hpp https://raw.githubusercontent.com/justinthompson593/EsvApiInterface/master/EsvApiInterface/EsvApiInterface.hpp");
	
	// Make new directory for settings & utility files
	system("mkdir EsvApi");
	
	// Get utility files
	system("curl -o EsvApi/dark.css https://raw.githubusercontent.com/justinthompson593/EsvApiInterface/master/EsvApiInterface/dark.css");
	system("curl -o EsvApi/dark_redLetter.css https://raw.githubusercontent.com/justinthompson593/EsvApiInterface/master/EsvApiInterface/dark_redLetter.css");
	
	
	// Add path to directory to top of main.cpp
	system("echo \"#define ESV_PATH \\\"$PWD/EsvApi/\\\"\" | cat - main.cpp > temp && mv temp main.cpp");
	
	// Build executable & clean up
	system("g++ main.cpp EsvApiInterface.cpp -o EsvApiInterface && rm -f main.cpp && rm -f EsvApiInterface.hpp && rm -f EsvApiInterface.cpp");
	
	// Initialize EsvApi & get user defaults
	system("./EsvApiInterface -init");
	
	// Move to EsvApi/
	system("mv EsvApiInterface EsvApi");
	
	// Add to path
	system("echo \"export PATH=\\\"$PWD/EsvApi:$PATH\\\"\" >> $HOME/.bash_profile");
	
	
	
	return 0;
}
