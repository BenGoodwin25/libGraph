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
  load_graph(&graph, "../mon.graph");

  view_graph(&graph);
  printf("#####\n");
  //save_graph(&graph, "test.graf");
  //deleteEdgeFromNodeName(&graph, 6);
  //view_graph(&graph);

  delete_graph(&graph);
  return 0;
}

