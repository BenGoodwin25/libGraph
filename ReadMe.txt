makefile :
This file is used to build libs and main program.

mon.graph :
test file for opening and saving graph.

src/main.c :
Source file contaning the main function. It starts the menu.

src/menu.c src/menu.h :
Source files containing all functions to interact with the menu and call further libgraph's functions.

src/libgraph/graph.c src/libgraph/graph.h :
Source files that contains graph's relative functions.

src/liblist/list.c src/liblist/list.h :
Source files that contains list's relative functions.

src/liblist/log.h :
Header file that contains small logs definitions.

Build and Run :
make && ./bin/menu
