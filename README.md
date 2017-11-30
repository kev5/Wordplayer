# Wordplayer
C++ &amp; Python programs to find words from huge text files and match with the valid words formed by random letters given as input.

Some random letters will be given as input in the command line. The text file to be used will be entered as an argument during the execution of the programs.

For example-
```
% python wordplayer.py words100k.txt
helloworld 6
holder
hollow
rolled
wooled
.
ndarmo 5
adorn
roman
.
omrandn 6
random
rodman
.
exit 0
%
```
```helloworld 6``` signifies that the user wants all possible 6 letter combinations from the word 'helloworld', that are present in the text file he entered.

After printing all possible words that the program can find in the text file, it prints a '```.```' and prompts the user to enter any other words he'd like to search the text file for.

The program exits after the user enters '```exit 0```'.

Note that all the words in the text files are in lower case.


