# EsvApiInterface

## Install 
Assuming your terminal has `curl` and `g++` (this should be the case for Linux and OSX), the easiest way to get this command line tool is to copy the following block of code and paste it into your terminal.
```
curl -o installer.cpp https://raw.githubusercontent.com/justinthompson593/EsvApiInterface/master/Installer/EsvApiInstaller.cpp && g++ installer.cpp -o installer && ./installer && rm -f installer.cpp && rm -f installer
```

## Command Line Use

### Flags

* Saving and Output Options

Flag | Function | Notes
---- | -------- | -----
-q | Quiets default openPassage as HTML | Unnecessary to use if 1st arg is a flag
-c | Copies passage to clipboard | Currently only available for OSX
-S | Saves all selected output formats |  
-txt | Selects text  output | 
-mp3 | Selects mp3  output|

* Overriding Default Settings

Flag | Setting | Notes
---- | -------- | -----
-num | Verse Numbers | 0 = off / 1 = on
-hed | Headers | 0 = off / 1 = on
-sub | Subheaders | 0 = off / 1 = on
-foot | Footnotes | 0 = off / 1 = on  
-flnk | Footnote Links | 0 = off / 1 = on
-ref | Passage References | 0 = off / 1 = on


### Passage Query

If your first argument is not a flag, then it is assumed to be a passage query. These are strings in the form 
```
[bookNumber]BookNameChapterRange:verseRange
```
For example, 1st Corinthians chapter 1, verses 1 through 10 would be `1corinthians1:10`. Book abbreviations are also acceptable, so `1cor1:10` will work too. An acceptable passage query for Genesis chapters 1 through 3 is `Gen1-3`.  
