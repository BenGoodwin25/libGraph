#include "menu.h"

int main(int argc, char* argv[]) {
  //int quit = 0;
  Graph graph;
  create_graph(&graph, 10, false);
  add_node(&graph, 3);
  add_node(&graph, 5);
  add_edge(&graph, 3, 5, 1, 0);
  if(is_edge_exists(&graph, 1)){
    printf("Edge 1 exists\n");
  } else {
    printf("Edge 1 doesn't exists\n");
  }
/*
  printHeader();
  while(quit == 0) {
    printMainMenu();
    quit = readUserInput();
  }
*/
  return 0;
}
