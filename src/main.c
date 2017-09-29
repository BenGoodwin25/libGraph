#include "menu.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
  //int quit = 0;
  Graph graph = {0};
  load_graph(&graph, "mon.graph");
  /*
  create_graph(&graph, 11, false);
  add_node(&graph, 3);
  add_node(&graph, 5);
  add_node(&graph, 7);
  add_edge(&graph, 3, 5, 1, 0, false);
  add_edge(&graph, 7, 3, 2, 0, false);
  */
  view_graph(&graph);
  //save_graph(&graph, "test.graf");
/*
  printHeader();
  while(quit == 0) {
    printMainMenu();
    quit = readUserInput();
  }
*/
  //printf("Press Any Key to Continue\n");
  //getchar();
  quit(&graph);
  return 0;
}
