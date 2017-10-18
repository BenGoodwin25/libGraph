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
  tmp=self;
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
int addEdge(Neighbour **self, int neighbourTo, int edgeName, int Weight){
  if(edgeExist(*self, edgeName)){
    printf("Edge already exist\n");
    return 1;
  }
  Neighbour *other = malloc(sizeof(Neighbour));
  if(other == NULL){
    printf("Error with memory allocation\n");
    return 2;
  }
  other->neighbour = neighbourTo;
  other->weight = Weight;
  other->edgeName = edgeName;
  other->nextNeighbour = *self;
  *self = other;
  return 0;
}

//
// Error $deleteEdge()$ : code of deleteEdge
int deleteEdgeFromNodeName(Neighbour** self, int nodeName){
  int error;
  Neighbour *tmp = *self;
  while(tmp != NULL){
    if(tmp->neighbour == nodeName){
      error=deleteEdge(self,tmp->edgeName);
    }
    tmp=tmp->nextNeighbour;
  }

  return error;
}

//
// error 1 : Edge doesn't exist
int deleteEdge(Neighbour** self, int edgeName){
  Neighbour *tmp=*self;
  if(tmp->edgeName == edgeName){
    return delFirstEdge(self);
  }
  bool error=true;
  while(tmp->nextNeighbour != NULL && tmp->nextNeighbour->edgeName != edgeName){
    tmp=tmp->nextNeighbour;
  }

  if(tmp->nextNeighbour != NULL && tmp->nextNeighbour->edgeName == edgeName){
    Neighbour *trash;
    trash=tmp->nextNeighbour->nextNeighbour;
    free(tmp->nextNeighbour);
    tmp->nextNeighbour=trash;
    //LOG_INFO("Edge deleted\n");
    error=false;
  }
  if(error){
    return 1;
  } else {
    return 0;
  }
}

//add a node
// error 1 : Edge doesn't exist
int delFirstEdge(Neighbour** self){
  Neighbour *tmp=*self;
  if(!isEmptyList(tmp)){
    *self = tmp->nextNeighbour;
    return 0;
  }
  printf("No edge to delete\n");
  return 1;
}

int destroyList(Neighbour *self){
  while(!isEmptyList(self)){
    delFirstEdge(&self);
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
