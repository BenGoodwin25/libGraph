#include "menu.h"

int main(int argc, char* argv[]) {
  int quit = 0;
  Graph graph;
  create_graph(&graph, 10);
  if(is_node_exists(&graph, 5)){
    printf("Node 5 exists\n");
  } else {
    printf("Node 5 doesn't exists\n");
  }
  add_node(&graph, 3);
  if(is_node_exists(&graph, 3)){
    printf("Node 3 exists\n");
  } else {
    printf("Node 3 doesn't exists\n");
  }
  add_node(&graph, 4);
  /*
  printHeader();
  while(quit == 0) {
    printMainMenu();
    quit = readUserInput();
  }
  */
  return 0;
}
