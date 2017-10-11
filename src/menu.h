#ifndef MENU_H
#define MENU_H

#include <graph.h>

#define VERSION "0.0.1"

#define MAX_PATH_LENGTH 256
#define MAX_DIGIT_LENGTH 10

#define LOG_ERROR_INT_CONVERT() LOG_ERROR("Can't convert your entry to a valid number\n")

#define CREATE_EXAMPLE_GRAPH 0
#define CREATE_GRAPH 1
#define LOAD_FROM_FILE 2
#define DISPLAY_GRAPH 3
#define ADD_NODE 4
#define ADD_EDGE 5
#define DELETE_NODE 6
#define DELETE_EDGE 7
#define SAVE_GRAPH 8
#define DELETE_GRAPH 9
#define QUIT 10

// Main menu
void printMainMenu();
void startMenu(Graph *graph);
int readInputMainMenu(Graph *graph);

// common functions
int readUserInput(char *dest, int length);
void flushReadBuffer();

// read user inputs for action on graph
void readCreateGraph(Graph *graph);
void askFileLocation(Graph *graph);
void askSaveLocation(Graph *graph);
void readNewNode(Graph *graph);
void readNewEdge(Graph *graph);
void readDeleteNode(Graph *graph);
void readDeleteEdge(Graph *graph);
void createExampleGraph(Graph *graph);

#endif
