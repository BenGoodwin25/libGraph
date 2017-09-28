#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include "list.h"

Neighbour createList(){
  Neighbour self;
  self.nextNeighbour = NULL;
  return self;
}

int destroyList(Neighbour *self){
  while(!isEmptyList(self)){
    delFirstNode(self);
  }
  return 0;
}

bool nodeExist(Neighbour *self, int neighbour){
  if(searchNode(self,neighbour)!=NULL) {
    return true;
  } else {
    return false;
  }
}

bool edgeExist(Neighbour *self, int edgeName){
  Neighbour *tmp;
  tmp=self->nextNeighbour;
  while(tmp->edgeName != edgeName && tmp->nextNeighbour != NULL ){
    tmp = tmp->nextNeighbour;
    if(tmp->edgeName == edgeName){
      return true;
    }
  }
  return false;
}

int addNode(Neighbour* self, int neighbour, int Weight){
  if(nodeExist(self,neighbour)){
    printf("Node already exist");
    return 2;
  }
  Neighbour *other = malloc(sizeof(Neighbour));
  if(other == NULL){
    return 1;
  }
  other->neighbour = neighbour;
  other->weight=Weight;
  other->nextNeighbour = self->nextNeighbour;
  self->nextNeighbour = other;
  return 0;
}

int addEdge(Neighbour* self, int neighbourTo, int edgeName){
  // TODO: Implement function
  if(edgeExist(self,edgeName)){
    printf("Edge already exist");
    return 2;
  }
  return 0;
}

int deleteNode(Neighbour* self, int neighbour){
  Neighbour* node;
  node = self->nextNeighbour;
  if(node->neighbour == neighbour){
    return delFirstNode(self);

  }
  else {
    while (node->nextNeighbour != NULL && node->nextNeighbour->neighbour != neighbour) {
      node = node->nextNeighbour;
    }
    if (node->nextNeighbour != NULL) {
      //TODO Remove edge ??
      Neighbour *tmp = malloc(sizeof(Neighbour));
      tmp->nextNeighbour = node->nextNeighbour->nextNeighbour;
      free(node->nextNeighbour);
      node->nextNeighbour = NULL;
      node->nextNeighbour = tmp->nextNeighbour;
      tmp->nextNeighbour = NULL;
      free(tmp);
      return 0;
    }
    return 1;
  }
}

int deleteEdge(Neighbour* self, int edgeName){
  //TODO
  return 0;
}

int delFirstNode(Neighbour* self){
  if(!isEmptyList(self)){
    Neighbour *tmp = malloc(sizeof(Neighbour));
    tmp->nextNeighbour = self->nextNeighbour->nextNeighbour;
    free(self->nextNeighbour);
    self->nextNeighbour=NULL;
    self->nextNeighbour = tmp->nextNeighbour;
    tmp->nextNeighbour = NULL;
    free(tmp);
    return 0;
  }
  return 1;
}

bool isEmptyList(const Neighbour* self){
  if(self->nextNeighbour == NULL){
    return true;
  } else {
    return false;
  }
}

size_t listSize(const Neighbour* self){
  if(isEmptyList(self)){
    return 0;
  } else {
    Neighbour visit;
    visit.nextNeighbour = self->nextNeighbour;
    size_t size = 1;
    while(visit.nextNeighbour->nextNeighbour != NULL){
      visit.nextNeighbour=visit.nextNeighbour->nextNeighbour;
      size+=1;
    }
    return size;
  }
}

Neighbour* searchNode(const Neighbour* self, int neighbour){
  Neighbour *tmp;
  tmp=self->nextNeighbour;
  while(tmp->neighbour != neighbour && tmp->nextNeighbour != NULL ){
    tmp = tmp->nextNeighbour;
  }
  if(tmp->neighbour == neighbour){
    return tmp;
  }
  return NULL;
}