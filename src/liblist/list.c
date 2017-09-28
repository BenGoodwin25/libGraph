#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include "list.h"

Neighbour createList(){
  Neighbour self;
  self.nextNeighbour = NULL;
  return self;
}


bool edgeExist(Neighbour *self, int edgeName){
  Neighbour *tmp;
  tmp=self->nextNeighbour;
  while(tmp != NULL){
    if(tmp->edgeName == edgeName){
      return true;
    }
    tmp = tmp->nextNeighbour;
  }
  return false;
}

int addEdge(Neighbour* self, int neighbourTo, int edgeName, int Weight){
  if(edgeExist(self, edgeName)){
    printf("Edge already exist\n");
    return 1;
  }
  Neighbour *other = malloc(sizeof(Neighbour));
  if(other == NULL){
    printf("Error with memory allocation\n");
    return 1;
  }
  other->neighbour = neighbourTo;
  other->weight = Weight;
  other->edgeName = edgeName;
  other->nextNeighbour = self->nextNeighbour;
  self->nextNeighbour = other;
  return 0;
}

int deleteEdge(Neighbour* self, int edgeName){
  //TODO implement
  Neighbour *tmp;
  tmp=self->nextNeighbour;
  while(tmp->edgeName != edgeName && tmp->nextNeighbour != NULL ){
    tmp = tmp->nextNeighbour;
    if(tmp->edgeName == edgeName){
      //TODO remove edge
    }
  }
  return 0;
}

int delFirstEdge(Neighbour* self){
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
  printf("No edge to delete\n");
  return 1;
}

int destroyList(Neighbour *self){
  while(!isEmptyList(self)){
    delFirstEdge(self);
  }
  return 0;
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