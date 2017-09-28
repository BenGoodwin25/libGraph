#include "graph.h"

//create a graph with the right number of nodes
void create_graph(Graph *self, size_t maxNodes){
  self->nbMaxNodes = maxNodes;
  self->adjList = malloc(maxNodes*sizeof(Neighbour));
}

//load a graph from a file
void load_graph(Graph *self, const char *graphFile){
  FILE* file = fopen(graphFile, "r");
  // TODO: READ FILE AND STORE IT in MEMORY
  fclose(file);
}

//add a node
void add_node(Graph *self, int nodeName){
  if(nodeName < self->nbMaxNodes){
    // TODO: Gestion erreur
    addNode(&self->adjList[nodeName], -1);
  } else {
    // TODO: Retour code erreur nom node pas dans liste (OOB)
  }
}

//add an edge
void add_edge(Graph *self, int fromName, int toName, int edgeName){
  // TODO: mieux gérer les erreures
  int error;
  if(self->isDirected){
    error  = addEdge(&self->adjList[fromName], toName, edgeName);
  } else {
    error = addEdge(&self->adjList[fromName], toName, edgeName);
    error = addEdge(&self->adjList[toName], fromName, edgeName);
  }
  printf("add_edge error statu : %d", error);
}

//Delete a node
void remove_node(Graph *self, Neighbour *selfNode){
  // TODO: Supprimer une node
}

//Delete an edge
void remove_edge(Graph *self, Neighbour *selfEdge){
  // TODO: Supprimer une edge
}

//Display a graph
void view_graph(Graph *self){
  // TODO: Dump graph into console
}

//Save the graph into a file
void save_graph(Graph *self, char *fileName){
  // TODO: Save the graph in a file
}

//Free graph and quit
void quit(Graph *self){
  // TODO: Destroy nodes and graph with free
}
