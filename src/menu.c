#include "menu.h"

void printHeader(){
  //---------MENU--------------//
  printf("##################################################################\n");
  printf("#                                                                #\n");
  printf("#                      graph-manager(%s)                         #\n",VERSION);
  printf("#                                                                #\n");
  printf("##################################################################\n");
}

void printMainMenu(){
  printf("#\n");
  printf("#  0 : Create Example Graph\n");
  printf("#  1 : Create Graph\n");
  printf("#  2 : Display Graph\n");
  printf("#  3 : Modify Graph\n");
  printf("#  4 : Delete Graph\n");
  printf("#  5 : Quit (and delete Graph)\n");
  printf("#\n");
}

int readUserInput(){
  int choice;
  printf("Your Choice :");
  scanf("%d", &choice);
  switch(choice){
    case 5:
      return 1;
    default:
      break;
  }
}

/*
int main(){
  
  /*
  while(loop == 1){
    
    switch(choice){
      case 1:
        if(fa_created1==true){
          printf("Automate already created, destroy it before creating a other one\n");
        } else {
          printf("Do you want a example automate (from the TP subject) ?(1/0)");
          scanf("%d", &example);
          if (example==1) {
            fa_create(&tomate,2,5);

            fa_set_state_initial(&tomate, 0);
            fa_set_state_initial(&tomate, 1);
            fa_set_state_final(&tomate, 4);

            fa_add_transition(&tomate, 0, 'a', 1);
            fa_add_transition(&tomate, 0, 'a', 2);
            fa_add_transition(&tomate, 0, 'a', 3);
            fa_add_transition(&tomate, 1, 'b', 3);
            fa_add_transition(&tomate, 2, 'a', 3);
            fa_add_transition(&tomate, 2, 'b', 4);
            fa_add_transition(&tomate, 3, 'a', 3);
            fa_add_transition(&tomate, 3, 'b', 4);
            fa_add_transition(&tomate, 4, 'a', 4);
          } else {
            printf("How many states do you want ?");
            scanf("%zu", &states);
            printf("How many alpha's do you want ?");
            scanf("%zu", &alphas);
            fa_create(&tomate, alphas, states);
          }
          fa_created1 = true;
        }
        break;
      case 2:  //TODO Modify the menu to be able to use it with the new graphLib
  

        if(fa_created2==true){
          printf("Automate already created, destroy it before creating a other one\n");
        } else {
          printf("Do you want a example automate (from the TP subject) ?(1/0)");
          scanf("%d", &example);
          if (example==1) {
            fa_create(&tomate2,2,5);

            fa_set_state_initial(&tomate2, 0);
            fa_set_state_initial(&tomate2, 1);
            fa_set_state_final(&tomate2, 4);

            fa_add_transition(&tomate2, 0, 'a', 1);
            fa_add_transition(&tomate2, 0, 'a', 2);
            fa_add_transition(&tomate2, 0, 'a', 3);
            fa_add_transition(&tomate2, 1, 'b', 3);
            fa_add_transition(&tomate2, 2, 'a', 3);
            fa_add_transition(&tomate2, 2, 'b', 4);
            fa_add_transition(&tomate2, 3, 'a', 3);
            fa_add_transition(&tomate2, 3, 'b', 4);
            fa_add_transition(&tomate2, 4, 'a', 4);
          } else {
            printf("How many states do you want ?");
            scanf("%zu", &states);
            printf("How many alpha's do you want ?");
            scanf("%zu", &alphas);
            fa_create(&tomate2, alphas, states);
          }
          fa_created2 = true;
        }
        break;
      case 3:
        if(fa_created1==false){
          printf("No Production has been done, do one before displaying it\n");
        } else {
          printf("The Automate has %zu transition(s)\n",fa_count_transitions(&tomate));
          if(fa_is_deterministic(&tomate)) {
            printf("The Automate is deterministic\n");
          }else{
            printf("The Automate isn't deterministic\n");
          }
          if(fa_is_complete(&tomate)) {
            printf("The Automate is complete\n");
          }else{
            printf("The Automate isn't complete\n");
          }
          if(fa_is_language_empty(&tomate)) {
            printf("The Automate has an empty language\n");
          }else{
            printf("The Automate doesn't have an empty language\n");
          }
          fa_pretty_print(&tomate,stdout);

        }
        break;
      case 4:
        if(fa_createdprod==false){
          printf("No Automate has been created, create it before displaying it\n");
        } else {
          printf("The Automate has %zu transition(s)\n",fa_count_transitions(&tomateprod));
          if(fa_is_deterministic(&tomateprod)) {
            printf("The Automate is deterministic\n");
          }else{
            printf("The Automate isn't deterministic\n");
          }
          if(fa_is_complete(&tomateprod)) {
            printf("The Automate is complete\n");
          }else{
            printf("The Automate isn't complete\n");
          }
          if(fa_is_language_empty(&tomateprod)) {
            printf("The Automate has an empty language\n");
          }else{
            printf("The Automate doesn't have an empty language\n");
          }
          if(fa_has_empty_intersection(&tomate,&tomate2)) {
            printf("The Automates have an empty intersection\n");
          }else{
            printf("The Automates doesn't have an empty intersection\n");
          }
          fa_pretty_print(&tomateprod,stdout);

        }
        break;
      case 5:
        loop2=1;
        int choice2;
        size_t s1,s2;
        char alpha;
        if(fa_created1==false){
          printf("No Automate has been created, create it before modifying it\n");
        } else {
          while(loop2==1) {
            printf("#################################################################\n");
            printf("#                                                               #\n");
            printf("#             0 : Add Transition                                #\n");
            printf("#             1 : Remove Transition                             #\n");
            printf("#             2 : Add Initial State                             #\n");
            printf("#             3 : Add Final State                               #\n");
            printf("#             4 : Make Complete                                 #\n");
            printf("#             5 : Merge States                                  #\n");
            printf("#             6 : Remove State                                  #\n");
            printf("#             7 : Remove non accessible states                  #\n");
            printf("#             8 : Remove non co-accessible states(not working)  #\n");
            printf("#             9 : Product of two automates                      #\n");
            printf("#             10 : Go Back                                      #\n");
            printf("#                                                               #\n");
            printf("#################################################################\n");
            choice2 = 0;
            printf("Your Choice :");
            scanf("%d", &choice2);
            switch (choice2) {
              case 0:
                printf("State from ?(0,1,...)");
                scanf("%zu", &s1);
                printf("With which letter ?(a,b,...)");
                scanf("%s", &alpha);
                printf("State to ?(0,1,...)");
                scanf("%zu", &s2);
                fa_add_transition(&tomate,s1,alpha,s2);
                break;
              case 1:
                printf("State from ?(0,1,...)");
                scanf("%zu", &s1);
                printf("With which letter ?(a,b,...)");
                scanf("%s", &alpha);
                printf("State to ?(0,1,...)");
                scanf("%zu", &s2);
                fa_remove_transition(&tomate,s1,alpha,s2);
                break;
              case 2:
                printf("Initial state ?(0,1,...)");
                scanf("%zu", &s1);
                fa_set_state_initial(&tomate,s1);
                break;
              case 3:
                printf("Final state ?(0,1,...)");
                scanf("%zu", &s1);
                fa_set_state_final(&tomate,s1);
                break;
              case 4:
                printf("Completing ...\n");
                fa_make_complete(&tomate);
                break;
              case 5:
                printf("First State to merge ?(0,1,...)");
                scanf("%zu", &s1);
                printf("Second State to merge ?(0,1,...)");
                scanf("%zu", &s2);
                fa_merge_states(&tomate,s1,s2);
                break;
              case 6:
                printf("State to remove ?(0,1,...)");
                scanf("%zu", &s1);
                fa_remove_state(&tomate,s1);
                break;
              case 7:
                fa_remove_non_accessible_states(&tomate);
                break;
              case 8:
                fa_remove_non_co_accessible_states(&tomate);
                loop2 = 0;
                break;
              case 9:
                fa_create_product(&tomateprod,&tomate,&tomate2);
                fa_createdprod=true;
                loop2 = 0;
                break;
              case 10:
                loop2 = 0;
                break;
              default:
                printf("Restart menu and choose a number between 1 and 8\n");
                loop2=0;
                break;
            }
          }
        }
        break;
      case 6:
        if(fa_created1==false){
          printf("No Automate has been created, create it before deleting it\n");
        } else {
          printf("Deleting ...\n");
          fa_created1 = false;
          fa_destroy(&tomate);
        }
        break;
      case 7:
        if(fa_created1==true && fa_created2==true) {
          if (fa_is_included(&fa_created1, &fa_created2)) {
            printf("Automate number 1 could be included in automate number 2.\n");
          } else {
            printf("Automate number 1 can not be included in automate number 2.\n");
          }
        } else {
          printf("Make sure to have created two automate.\n");
        }
        break;
      case 8:
        printf("Exiting ...\n");
        if(fa_created1==true){
          fa_destroy(&tomate);
        }
        loop=0;
        break;
      default:
        printf("Restart menu and choose a number between 1 and 5\n");
        loop=0;
        break;
    }
    return 0;
  }
}*/

