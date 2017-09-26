#include <stdlib.h>
#include <stdbool.h>

#include "list.h"


List createList(){
  List self;
  self.first = NULL;
  return self;
}

int destroyList(List *self){
  while(!isEmptyList(self)){
    delFirstNode(self);
  }
  return 0;
}

int addNode(List* self, int data){
  List_node *other = malloc(sizeof(List_node));
  if(other == NULL){
    return 1;
  }
  other->data = data;
  other->next = self->first;
  self->first = other;
  return 0;
}

int deleteNode(List* self, int data){
  List_node* node;
  node = self->first;
  if(node->data == data){
    return delFirstNode(self);
  }
  else {
    while (node->next != NULL && node->next->data != data) {
      node = node->next;
    }
    if (node->next != NULL) {
      List *tmp = malloc(sizeof(List));
      tmp->first = node->next->next;
      free(node->next);
      node->next = NULL;
      node->next = tmp->first;
      tmp->first = NULL;
      free(tmp);
      return 0;
    }
    return 1;
  }
}

int delFirstNode(List* self){
  if(!isEmptyList(self)){
    List_node *tmp = malloc(sizeof(List_node));
    tmp->next = self->first->next;
    free(self->first);
    self->first=NULL;
    self->first = tmp->next;
    tmp->next = NULL;
    free(tmp);
    return 0;
  }
  return 1;
}

bool isEmptyList(const List* self){
  if(self->first == NULL){
    return true;
  } else {
    return false;
  }
}

size_t listSize(const List* self){
  if(isEmptyList(self)){
    return 0;
  } else {
    List visit;
    visit.first = self->first;
    size_t size = 1;
    while(visit.first->next != NULL){
      visit.first=visit.first->next;
      size+=1;
    }
    return size;
  }
}

List_node* searchNode(const List* self, int data){
  List_node *tmp;
  tmp=self->first;
  while(tmp->data != data && tmp->next != NULL ){
    tmp = tmp->next;
  }
  if(tmp->data == data){
    return tmp;
  }
  return NULL;
}
