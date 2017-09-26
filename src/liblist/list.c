#include <stdlib.h>
#include <stdbool.h>

#include "list.h"


void createList(struct list* self){
  self = malloc(sizeof(struct list));
  self->first=NULL;
}

void destroyList(struct list* self){
  while(!isEmptyList(self)){
    delFirstNode(self);
  }
}

bool addNode(struct list* self, size_t state){
  struct list_node *other = malloc(sizeof(struct list_node));
  if(other == NULL){
    return false;
  } else {
    other->node = state;
    other->next = self->first;
    self->first = other;
    return true;
  }
}

void delFirstNode(struct list* self){
  if(!isEmptyList(self)){
    struct list_node *tmp = malloc(sizeof(struct list_node));
    tmp->next = self->first->next;
    free(self->first);
    self->first=NULL;
    self->first = tmp->next;
    tmp->next = NULL;
    free(tmp);
  }
}

bool isEmptyList(const struct list* self){
  if(self->first == NULL){
    return true;
  } else {
    return false;
  }
}

size_t listSize(const struct list* self){
  if(isEmptyList(self)){
    return 0;
  } else {
    struct list visit;
    visit.first = self->first;
    size_t size = 1;
    while(visit.first->next != NULL){
      visit.first=visit.first->next;
      size+=1;
    }
    return size;
  }
}

void delNodeAfter(struct list_node* self){

}

/*struct list_node* searchNode(const struct list*  self, size_t state){

}*/
