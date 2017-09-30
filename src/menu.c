#include "menu.h"

void flushReadBuffer() {
  int c = 0;
  while ((c = getchar()) != '\n' && c != EOF) { }
}

void printHeader(){
  //---------MENU--------------//
  printf("##################################################################\n");
  printf("#                                                                #\n");
  printf("#                      graph-manager(%s)                      #\n",VERSION);
  printf("#                                                                #\n");
  printf("##################################################################\n");
}

void printMainMenu(){
  printf("#\n");
  printf("#  0 : Create Example Graph\n");
  printf("#  1 : Create Graph\n");
  printf("#  2 : Load Graph from file\n");
  printf("#  3 : Display Graph\n");
  printf("#  4 : Modify Graph\n");
  printf("#  5 : Save Graph to file\n");
  printf("#  6 : Delete Graph\n");
  printf("#  7 : Quit (and delete Graph)\n");
  printf("#\n");
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
  char inputString[3];
  int choice = -1;
  readUserInput(inputString, 3);
  if(sscanf(inputString, "%d", &choice) == 1){
    switch(choice){
      case 0:
        // Create an example graph
        break;
      case 1:
        // Ask user infos to create a graph
        readCreateGraph(graph);
        break;
      case 2:
        // Load a graph from file
        askFileLocation(graph);
        break;
      case 3:
        // Display the current graph
        view_graph(graph);
        break;
      case 4:
        // Menu for modifying a graph
        break;
      case 5:
        //Save current Graph to file
        break;
      case 6:
        // Deleting the graph
        break;
      case 7:
        // Quit the application
        quit(graph);
        return 1;
        break;
      default:
        fputs("# Please make a choice between 0 and 7\n", stdout);
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
      fprintf(stdout, "# Overflow, entry must be less than %d character long.\n", length-1);
      return 2;
    }
    return 0;
  } else {
    flushReadBuffer();
    return 1;
  }
}

void readCreateGraph(Graph *graph){
  // TODO
}

void askFileLocation(Graph *graph){
  char filePathInput[MAX_PATH_LENGTH];
  int error = -1;
  while(error != 0){
    fprintf(stdout, "# Which file should be loaded ?\n");
    error = readUserInput(filePathInput, MAX_PATH_LENGTH+1);
  }
  load_graph(graph, filePathInput);
  fprintf(stdout, "# Graph loaded\n");
}
