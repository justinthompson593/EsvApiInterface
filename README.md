# EsvApiInterface

## Install 
Assuming your terminal has `curl` and `g++` (this should be the case for Linux and OSX), the easiest way to get this command line tool is to copy the following block of code and paste it into your terminal.
```
curl -o installer.cpp https://raw.githubusercontent.com/justinthompson593/EsvApiInterface/master/Installer/EsvApiInstaller.cpp && g++ installer.cpp -o installer && ./installer && rm -f installer.cpp && rm -f installer
```

## Command Line Use

### Flags

Flag | Function
---- | --------
-q | Quiets default openPassage 
-S | Saves all selected output formats
-txt | Output text file
-mp3 | Output mp3 file

### Passage Query

If your first argument is not a flag, then it is assumed to be a passage query. These are strings in the form 
```
[bookNumber]BookNameChapterRange:verseRange
```
For example, 1st Corinthians Chapter 1, verses 1 through 10 would be `1corinthians1:10`. Book abbreviations are also acceptable, so `1cor1:10` will work too. 
