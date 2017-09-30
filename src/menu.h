#ifndef MENU_H
#define MENU_H

#include <graph.h>

#define VERSION "0.0.1"

#define MAX_PATH_LENGTH 256

// Main menu
void printHeader();
void printMainMenu();
void startMenu(Graph *graph);
int readInputMainMenu(Graph *graph);

// common functions
int readUserInput(char *dest, int length);
void flushReadBuffer();

// read user inputs for creating a graph
void readCreateGraph(Graph *graph);
void askFileLocation(Graph *graph);

#endif
