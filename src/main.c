#include "menu.h"

int main(int argc, char* argv[]) {
  int quit = 0;
  printHeader();
  while(quit == 0) {
    printMainMenu();
    quit = readUserInput();
  }
  return 0;
}
