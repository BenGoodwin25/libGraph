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

//add a node
// error 1 : Edge already exist
// error 2 : unexpected allocation error
int addEdge(Neighbour* self, int neighbourTo, int edgeName, int Weight){
  if(edgeExist(self, edgeName)){
    printf("Edge already exist\n");
    return 1;
  }
  Neighbour *other = malloc(sizeof(Neighbour));
  if(other == NULL){
    printf("Error with memory allocation\n");
    return 2;
  }
  //TODO go to the end
  other->neighbour = neighbourTo;
  other->weight = Weight;
  other->edgeName = edgeName;
  other->nextNeighbour = self->nextNeighbour;
  self->nextNeighbour = other;
  return 0;
}

//
// Error $deleteEdge()$ : code of deleteEdge
int deleteEdgeFromNodeName(Neighbour* self, int nodeName){
  Neighbour *tmp;
  tmp=self->nextNeighbour;
  int error;
  while(tmp->neighbour != nodeName && tmp->nextNeighbour != NULL ){
    error=deleteEdge(self,tmp->edgeName);
  }
  return error;
}

//
// error 1 : Edge doesn't exist
int deleteEdge(Neighbour* self, int edgeName){
  if(self != NULL) {
    Neighbour *tmp = malloc(sizeof(Neighbour));
    while (self->nextNeighbour != NULL) {
      if (self->nextNeighbour->edgeName == edgeName) {
        tmp->nextNeighbour = self->nextNeighbour->nextNeighbour;
        free(self->nextNeighbour);
        self->nextNeighbour = NULL;
        self->nextNeighbour = tmp->nextNeighbour;
        tmp->nextNeighbour = NULL;
        free(tmp);
        return 0;
      }
      tmp = tmp->nextNeighbour;
    }
    free(tmp);
  }
  return 1;
}

//add a node
// error 1 : Edge doesn't exist
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

int outputList(Neighbour *self, FILE *stream){
  if(self != NULL) {
    Neighbour *tmp=self;
    while(tmp != NULL){
      if(tmp->neighbour != -1){
        fprintf(stream,"(%d/%d)", tmp->neighbour+1, tmp->edgeName);
        //Yes all that for a ", " ...
        if(tmp->nextNeighbour != NULL && tmp->nextNeighbour->neighbour != -1){
          fprintf(stream,", ");
        }
      }
      tmp=tmp->nextNeighbour;

    }
  }
  return 0;
}
