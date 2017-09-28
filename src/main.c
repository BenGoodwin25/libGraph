#include "menu.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
  //int quit = 0;
  Graph graph;
  create_graph(&graph, 11, false);
  add_node(&graph, 3);
  add_node(&graph, 5);
  add_edge(&graph, 3, 5, 1, 0, false);
  view_graph(&graph);
/*
  printHeader();
  while(quit == 0) {
    printMainMenu();
    quit = readUserInput();
  }
*/
  //printf("Press Any Key to Continue\n");
  //getchar();
  return 0;
}
