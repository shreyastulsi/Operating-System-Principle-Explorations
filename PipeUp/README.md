## UID: 706157430

## Pipe Up
This program intends to simulate the UNIX piplein system where you can input a sequence of commands and the output for one command acts as the the input to the next command
## Building

Explain briefly how to build your program
To build the program, simply use the make command.

## Running

Show an example run of your program, using at least two additional arguments, and what to expect
./pipe ls wc
Output will mirror the command ls|wc, displays the number of lines, words, characters in the current directory


My specific output:
7 7 63

## Cleaning up
To clean up ,
simply run:
rm pipe
rm *.o
