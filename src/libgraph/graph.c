#include "graph.h"

//create a graph with the right number of nodes
// error 1 : unexpected allocation error
int create_graph(Graph *self, size_t maxNodes, bool isDirected){
  self->nbMaxNodes = maxNodes;
  self->isDirected = isDirected;
  self->adjList = malloc(maxNodes*sizeof(Neighbour*));
  if(self->adjList == NULL){
    return 1;
  }
  for(int i=0; i < maxNodes; i++){
    self->adjList[i] = NULL;
  }
  return 0;
}

//load a graph from a file
int load_graph(Graph *self, const char *graphFile){
  FILE* file = fopen(graphFile, "r");
  // TODO: READ FILE AND STORE IT in MEMORY
  fclose(file);
  return 0;
}

//add a node
// error 1 : node OOB
// error 2 : unexpected allocation error
int add_node(Graph *self, int nodeName){
  if(nodeName < self->nbMaxNodes){
    self->adjList[nodeName] = malloc(sizeof(Neighbour*));
    if(self->adjList[nodeName] == NULL){
      return 2;
    }
    self->adjList[nodeName]->neighbour = -1;
    self->adjList[nodeName]->edgeName = -1;
    self->adjList[nodeName]->weight = -1;
    self->adjList[nodeName]->nextNeighbour = NULL;
  } else {
    return 1;
  }
  return 0;
}

//add an edge
// error 8 : From node doesn't exists
// error 9 : To node doesn't exists
// error 10 : Edge already exists
int add_edge(Graph *self, int fromName, int toName, int edgeName, int Weight, bool isSymmetric){
  if(!is_node_exists(self, fromName)){
    return 8;
  }
  if(!is_node_exists(self, toName)){
    return 9;
  }
  if(is_edge_exists(self, edgeName)){
    return 10;
  }
  if(self->isDirected && !isSymmetric){
    return addEdge(self->adjList[fromName], toName, edgeName, Weight);
  } else {
    int error = addEdge(self->adjList[fromName], toName, edgeName, Weight);
    if(error != 0){
      return error;
    }
    return addEdge(self->adjList[toName], fromName, edgeName, Weight);
  }
  return 0;
}

bool is_node_oob(Graph *self, int nodeName){
  return self->nbMaxNodes < nodeName;
}

// Check if a node already exists
bool is_node_exists(Graph* self, int nodeName){
  return self->adjList[nodeName] != NULL;
}

// Check if an edge already exists
bool is_edge_exists(Graph* self, int edgeName){
  for(int i = 0; i < self->nbMaxNodes; i++){
    if(is_node_exists(self, i)){
      if(edgeExist(self->adjList[i], edgeName)){
        return true;
      }
    }
  }
  return false;
}

//Delete a node
// error 9 : Node is OOB
// error 10 : Node unknown
int remove_node(Graph *self, int nodeName){
  if(is_node_oob(self, nodeName)){
    return 9;
  }
  if(!is_node_exists(self, nodeName)){
    return 10;
  }
  // TODO: Supprimer une node
  // Supression des edge reliées à la node
  for(int i = 0; i < self->nbMaxNodes; i++){
    if(is_node_exists(self, i)){
      //search and delete node from endpoint
    }
  }
  // Supression de la node en elle même
  destroyList(self->adjList[nodeName]);
  self->adjList[nodeName] = NULL;
  return 0;
}

//Delete an edge
int remove_edge(Graph *self, int edgeName){
  // TODO: Supprimer une edge
  // Supprime l'edge
  for(int i = 0; i < self->nbMaxNodes; i++){
    deleteEdge(self->adjList[i], edgeName);
  }
  return 0;
}

//Display a graph
int view_graph(Graph *self){
  // TODO: Dump graph into console
  printf("# maximum number of node\n");
  printf("%zu\n", self->nbMaxNodes);
  printf("# directed\n");
  if(self->isDirected){
    printf("y\n");
  } else {
    printf("n\n");
  }
  printf("# node: neighbours\n");
  for(int i = 0; i < self->nbMaxNodes; i++){
    if(is_node_exists(self, i)){
      printf("%d: ", i+1);
      // call list dump
      printf("\n");
    }
  }

  return 0;
}

//Save the graph into a file
int save_graph(Graph *self, const char *graphFile){
  FILE* file = fopen(graphFile, "w");
  // BORDEL AVEC LE FICHIER
  fclose(file);

  return 0;
}

//Free graph and quit
int quit(Graph *self){
  //Save and free
  return 0;
}
