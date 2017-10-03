#include "menu.h"

#include <stdio.h>
#include <stdlib.h>

// main for the menu
/*
int main(int argc, char* argv[]) {
  Graph graph = {0};
  startMenu(&graph);
  return 0;
}
*/

// main for debugging live from libs

int main(int argc, char* argv[]) {
  Graph graph = {0};
  load_graph(&graph, "mon.graph");
  //quit(&graph);

  /*
  create_graph(&graph, 11, false);
  add_node(&graph, 3);
  add_node(&graph, 5);
  add_node(&graph, 7);
  add_edge(&graph, 3, 5, 1, 0, false);
  add_edge(&graph, 7, 3, 2, 0, false);
   */

  view_graph(&graph);
  //printf("#####\n");
  save_graph(&graph, "test.graf");
  //deleteEdgeFromNodeName(&graph, 6);
  view_graph(&graph);

  quit(&graph);
  return 0;
}

