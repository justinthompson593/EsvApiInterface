# EsvApiInterface

## TODO

- [ ] check links to mp3 verses
- [ ] add bookmarks
- [ ] custom css option
- [ ] make user defined default outputs for:
	- [ ] no args
	- [ ] one arg (passageQuery)
- [ ] link to examples
- [x] get main running


## Install 

### System Requirements

You'll need a terminal which runs bash and has `g++`, and `curl`. If you're on OSX, then the terminal will already have these and `pbcopy`, which is used to copy scripture to your clipboard. If you're using Linux or are in a Unix bash environment, you will need `xsel` to make use of this feature. Without it, you'll have access to all the other features, but you'll get errors if you try to use the `-c` flag (see Flags below for details). If your system is lacking any of these 3 tools, you can use your package manager to download them directly from the command line. If you're running Ubuntu, for instance, you could run `$ sudo apt-get install xsel` to get the missing software (and similarly with `g++` and `curl`, but I know those are native to Ubuntu). Note that you don't need to type in the `$` sign; that's just in there to look like it does on the terminal.

### Command Line Install

First open a terminal and `cd` to the directory where you want to install the executable `EsvApiInterface` and the supporting .css files (both will show up in a new directory named EsvApi in your chosen install directory).  Assuming you have `curl` and `g++` (this should be the case for Linux and OSX), the easiest way to get this command line tool is to copy the following code and paste it into your terminal. 

`
curl -o installer.cpp https://raw.githubusercontent.com/justinthompson593/EsvApiInterface/master/Installer/EsvApiInstaller.cpp && g++ installer.cpp -o installer && ./installer && rm -f installer.cpp && rm -f installer
`

A quick rundown of the code above: we download [EsvApiInstaller.cpp](https://github.com/justinthompson593/EsvApiInterface/blob/master/Installer/EsvApiInstaller.cpp) file as installer.cpp. If you like, you can follow the link to see that this code downloads [these](https://github.com/justinthompson593/EsvApiInterface/blob/master/EsvApiInterface/main.cpp) [three](https://github.com/justinthompson593/EsvApiInterface/blob/master/EsvApiInterface/EsvApiInterface.cpp) [files](https://github.com/justinthompson593/EsvApiInterface/blob/master/EsvApiInterface/EsvApiInterface.hpp) to your computer, and then uses `g++` to turn them into the executable `EsvApiInterface`. It will run the executable and ask you to define your [defaults](). Afterwards, it will remove the downloaded .cpp and .hpp files, leaving all .css files and the executable in the new EsvApi directory. Finally, the installer will add the path to the executable to your `PATH` variable in your bash startup file. 

### Build On Your Own

On [this](https://github.com/justinthompson593/EsvApiInterface) page there is a green button...TODO Finish this. 

## Command Line Use

### Passage Query

If your first argument is not a flag, then it is assumed to be a passage query. These are strings in the form

`
[bookNumber]BookNameChapterRange:verseRange
`

For example, 1st Corinthians chapter 1, verses 1 through 10 would be `1corinthians1:1-10`. Book abbreviations are also acceptable, so `1cor1:10` will work too. An acceptable passage query for Genesis chapters 1 through 3 is `Gen1-3`.  

Most calls to `EsvApiInterface` involve a passage query or some reference to one. 


### Flags

#### Open and Save: _How to access scripture_

These can be used in any order. But because the `-s` flag can be followed by 1 or 2 arguments, it's best to put your searches at the end of your command.  

Short Flag | Long Flag | Example Use | Result 
---------- | --------- | ----------- | ------
-op | --open-passage | `$ EsvApiInterface 1john1 -op` | Opens first John chapter </br>1 as an html file in your </br>default web browser
-sp | --save-passage | `$ EsvApiInterface 1john1 -sp` | Saves first John chapter </br>1 as 1john1.html in your </br>current directory
-ot | --open-text | `$ EsvApiInterface Gen3 -ot` | Opens Genesis chapter </br>3 as a temporary file in </br>your default text editor
-st | --save-text | `$ EsvApiInterface Gen3 -st` | Saves Genesis chapter 3 </br>as Gen3.txt in your </br>current directory
-o3 | --open-mp3 | `$ EsvApiInterface Mat5:3-11 -o3` | Opens this [link](https://audio.esv.org/hw/40005003-40005011.mp3) to Matthew </br>chapter 5 verses 3 through </br>11  in your web browser
-s3 | --save-mp3 | `$ EsvApiInterface Mat5:3-11 -s3` | Saves this [link](https://audio.esv.org/hw/40005003-40005011.mp3) in a file named </br>Mat5:3-11.mp3 in your </br>current directory
 


<!--Flag | Function | Notes-->
<!------ | -------- | ------->
<!---q | Quiets default openPassage as html | Unnecessary to use if 1st arg is a flag-->
<!---c | Copies passage as text to clipboard | Available for OSX, Unix, and Linux-->
<!---rand | Opens random verse as html | Returns the daily verse if not followed by a number. Otherwise, the following number is used as a random generator seed. -rnd works too.-->
<!---s | Searches for string | Must be followed by a search query in quotes. If followed by a Book Name, the search scope will be limited to that book.-->
<!---S | Saves all selected output formats |  -->
<!---txt | Selects text  output | Does not work with -rand-->
<!---mp3 | Selects mp3  output| Does not work with -rand-->

A note about `-s`: Running `$ EsvApiInterface -s "brought the king"` will open an html file with search results from the entire bible. `$ EsvApiInterface -s "brought the king" 1Kings` will limit the search results to 1st Kings. See the function processScope in [this file](https://github.com/justinthompson593/EsvApiInterface/blob/master/EsvApiInterface/EsvApiInterface.cpp) around line 150. The `bookName` variables show all the acceptable abbreviations. You can also go [here](https://www.esv.org/search/?q=advanced), select the Book dropdown and enter any of the book names (in quotes if more than 1 word like "Song of Solomon" or "2 Samuel"). Note that the formatting for the optional search input is different than for a passage query, which is far more forgiving. The full name of the book will always work. 

#### Overriding Default Settings 

The flag must be followed by a 0 or a 1. Running `$ EsvApiInterface 1Cor1-2 -sub 0 -foot 0 ` would open 1st Corinthians chapters 1 and 2 as an html file, and the formatting would not have subheadings or footnotes.

Flag | Setting | Next Value
---- | -------- | -----
-num | Verse Numbers | 0 = off / 1 = on
-hed | Headings | 0 = off / 1 = on
-sub | Subheadings | 0 = off / 1 = on
-foot | Footnotes | 0 = off / 1 = on  
-flnk | Footnote Links | 0 = off / 1 = on
-ref | Passage References | 0 = off / 1 = on
-red | Red Letter | 0 = off / 1 = on

#### Bookmarks

We also have bookmarks. In the columns below, we'll assume the Results are what you'd get if you had run each previous Example Use, and in each previous row before. If you'd like to open and save in a given format, text for instance, then put a `-S` flag before the `-bot` (i.e. `$ EsvApiInterface -S -bot myBookmarkName` will open yourBookmarkPassageQuery.txt in your default text editor and save it to your current directory). 

Short Flag | Long Flag | Example Use | Result 
---------- | --------- | ----------- | ------
-B | --add-bookmark | `$ EsvApiInterface -B eph5 1` | Saves passage `eph5` with</br>bookmark name `1` in</br>EsvApi/bookmarks.dat
-B | --add-bookmark | `$ EsvApiInterface -B John1:1-5` | Prompts you for the</br>bookmark name,say `2`,</br>and saves both in </br>bookmarks.dat
-bm | --bookmarks | `$ EsvApiInterface -bm` | Prints<sup>[\[1\]](https://github.com/justinthompson593/EsvApiInterface/#1-actual-stdout-printing-differs-from-what-is-shown-in-the-table-the-_s-are-there-to-easily-keep-spaces-in-markdown)</sup> your bookmarks </br>in columns to stdout </br>`\|_Bookmark_\|__Passage__\|`</br>`\|___Name___\|___Query___\|`</br>`\|____1_____\|___eph5____\|`</br>`\|____2_____\|_John1:1-5_\|`
-bmc | --bkmk-copy | `$ EsvApiInterface -bmc 2` | Copies the formatted text</br>of John chapter 1 verses</br>1 through 
-bop | --bkmk-open-psg | `$ EsvApiInterface -bop 1` | Opens Ephesians 5 as a</br>temporary html file in</br>your default browser
-bsp | --bkmk-save-psg | `$ EsvApiInterface -sop 1` | Saves Ephesians 5 as </br>eph5.html in your current</br>directory without opening
-bot | --bkmk-open-txt | `$ EsvApiInterface -bot 2` | Opens John chapter 1</br>verses 1 through 5 as a</br>temporary html file in</br>your default text editor
-bst | --bkmk-save-txt | `$ EsvApiInterface -bst 1` | Saves Ephesians 5 as</br>eph5.txt in your current</br>directory without opening
-bo3 | --bkmk-open-mp3 | `$ EsvApiInterface -bot 2` | Opens this [link](https://audio.esv.org/hw/43001001-43001005.mp3) to</br>John chapter 1 verses</br>1 through 5 in your</br>default browser
-bs3 | --bkmk-save-mp3 | `$ EsvApiInterface -bst 1` | Saves this [link](https://audio.esv.org/hw/49005001-49005033.mp3) in a</br>file named eph5.mp3 in</br>your current directory</br>without opening	









## Examples 


## Notes
###### \[1\] Actual stdout printing differs from what is shown in the table. The "_"'s are there to easily keep spaces in markdown. 



<!--In the following table, we'll use `$ passageQuery flags` as a shorthand for `$ EsvApiInterface passageQuery flags`. So `$ john3 -q -mp3` in the table is short-hand for the `$ EsvApiInterface john3 -q -mp3` you'd have in the command line.-->
<!---->
<!--Command | Result-->
<!--------- | -------->
<!--`$ john3:16 -c` | Opens John chapter 3 verse 16 in html and copies the formatted text to the clipboard-->
<!--`$ john3 -q -mp3` | Opens audio link to John chapter 3 without opening the html page-->
<!--`$ john3 -S -mp3` | Saves and opens both john3.html and john3.mp3-->


 
