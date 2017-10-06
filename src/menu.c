#include "menu.h"

void flushReadBuffer() {
  int c = 0;
  while ((c = getchar()) != '\n' && c != EOF) { }
}

void printHeader(){
  printf("##################################################################\n");
  printf("#                                                                #\n");
  printf("#                      graph-manager(%s)                      #\n",VERSION);
  printf("#                                                                #\n");
  printf("##################################################################\n");
}

void printMainMenu(){
  printf("\n");
  printf("#  %d : Create Example Graph\n", CREATE_EXAMPLE_GRAPH);
  printf("#  %d : Create Graph\n", CREATE_GRAPH);
  printf("#  %d : Load Graph from file\n", LOAD_FROM_FILE);
  printf("#  %d : Display Graph\n", DISPLAY_GRAPH);
  printf("#  %d : Add Node\n", ADD_NODE);
  printf("#  %d : Add Edge\n", ADD_EDGE);
  printf("#  %d : Delete Node\n", DELETE_NODE);
  printf("#  %d : Delete Edge\n", DELETE_EDGE);
  printf("#  %d : Save Graph to file\n", SAVE_GRAPH);
  printf("#  %d : Delete Graph\n", DELETE_GRAPH);
  printf("#  %d : Quit (and delete Graph)\n", QUIT);
  printf("\n");
}

void startMenu(Graph *graph){
  int quit = 0;
  printHeader();
  while(quit == 0){
    printMainMenu();
    quit = readInputMainMenu(graph);
  }
}

int readInputMainMenu(Graph *graph){
  char inputString[4];
  int choice = -1;
  printf("Choice : ");
  readUserInput(inputString, 4);
  printf("\n");
  if(sscanf(inputString, "%d", &choice) == 1){
    switch(choice){
      case CREATE_EXAMPLE_GRAPH:
        createExampleGraph(graph);
        break;
      case CREATE_GRAPH:
        readCreateGraph(graph);
        break;
      case LOAD_FROM_FILE:
        askFileLocation(graph);
        break;
      case DISPLAY_GRAPH:
        printf("# Graph :\n");
        view_graph(graph);
        printf("\n");
        break;
      case ADD_NODE:
        break;
      case ADD_EDGE:
        break;
      case DELETE_NODE:
        break;
      case DELETE_EDGE:
        break;
      case SAVE_GRAPH:
        askSaveLocation(graph);
        break;
      case DELETE_GRAPH:
        delete_graph(graph);
        printf("# Graph deleted!\n");
        break;
      case QUIT:
        delete_graph(graph);
        return 1;
        break;
      default:
        fputs("# Please make a choice between 0 and 10\n", stdout);
        break;
    }
  } else {
    fputs("# Please, enter a valide number\n", stdout);
  }
  return 0;
}

int readUserInput(char *dest, int length){
  char *backspacePos = NULL;

  if(fgets(dest, length, stdin) != NULL){
    backspacePos = strchr(dest, '\n');
    if(backspacePos != NULL){
      *backspacePos = '\0';
    } else {
      flushReadBuffer();
      dest[0] = '\0';
      LOG_WARN("Overflow, entry must be less than %d character long.\n", length-1);
      return 2;
    }
    return 0;
  } else {
    flushReadBuffer();
    return 1;
  }
}

void readCreateGraph(Graph *graph){
  int maxNodes;
  char maxNodeInput[11];
  char directedInput[2];
  bool isDirected;

  if(graph->nbMaxNodes > 0){
    delete_graph(graph);
  }

  printf("# Enter the maximum number of nodes :\n");
  readUserInput(maxNodeInput, 12);
  if(sscanf(maxNodeInput, "%d", &maxNodes) == 1){
    printf("# Is the graph symmetric ? (y/n)\n");
    readUserInput(directedInput, 3);
    if(directedInput[0] == 'y'){
      isDirected = true;
    } else if(directedInput[0] == 'n') {
      isDirected = false;
    } else {
        LOG_ERROR("Can't determine by your entry if it's directed or not.\n");
    }
    create_graph(graph, maxNodes, isDirected);
  } else {
    LOG_ERROR("Can't convert your entry to a valid number\n");
  }
}

void askFileLocation(Graph *graph){
  char filePathInput[MAX_PATH_LENGTH];
  int error = -1;
  while(error != 0){
    fprintf(stdout, "# Which file should be loaded ?\n");
    error = readUserInput(filePathInput, MAX_PATH_LENGTH+1);
  }
  if(load_graph(graph, filePathInput) == 0){
    fprintf(stdout, "# Graph successfully loaded\n");
  }
}

void askSaveLocation(Graph *graph){
  char filePathInput[MAX_PATH_LENGTH];
  int error = -1;
  while(error != 0){
    fprintf(stdout, "# Where graph should be saved ?\n");
    error = readUserInput(filePathInput, MAX_PATH_LENGTH+1);
  }
  if(save_graph(graph, filePathInput) == 0){
    fprintf(stdout, "# Graph successfully saved\n");
  }
}

void createExampleGraph(Graph *graph){
  create_graph(graph, 11, false);
  add_node(graph, 0);
  add_node(graph, 1);
  add_node(graph, 2);
  add_node(graph, 3);
  add_node(graph, 4);
  add_node(graph, 5);
  add_node(graph, 6);
  add_node(graph, 7);
  add_edge(graph, 0, 6, 1, 0, true);
  add_edge(graph, 0, 2, 2, 0, true);
  add_edge(graph, 0, 3, 5, 0, true);
  add_edge(graph, 1, 4, 4, 0, true);
  add_edge(graph, 1, 6, 8, 0, true);
  add_edge(graph, 3, 6, 3, 0, true);
  printf("# Example graph created!\n");
}
