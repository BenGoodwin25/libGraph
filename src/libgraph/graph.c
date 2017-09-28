#include "graph.h"

//create a graph with the right number of nodes
int create_graph(Graph *self, size_t maxNodes){
  self->nbMaxNodes = maxNodes;
  self->adjList = malloc(maxNodes*sizeof(Neighbour));
}

//load a graph from a file
int load_graph(Graph *self, const char *graphFile){
  FILE* file = fopen(graphFile, "r");
  // BORDEL AVEC LE FICHIER
  fclose(file);
}

//add a node
int add_node(Graph *self, int neighbour){
  if(neighbour < self->nbMaxNodes){
    addNode(&self->adjList[neighbour], neighbour);
    // TODO: Créer un neighbour
  } else {
    // TODO: Retour code erreur
  }
}

//add an edge
int add_edge(Graph *self, int fromName, int toName, int edgeName){
  int error;

  if(self->isDirected){
    error = addEdge(&self->adjList[fromName], toName, edgeName);
  } else {
    error = addEdge(&self->adjList[fromName], toName, edgeName);
    error = addEdge(&self->adjList[toName], fromName, edgeName);
  }

  return error;
}

//Delete a node
int remove_node(Graph *self, Neighbour *selfNode){

}

//Delete an edge
int remove_edge(Graph *self, Neighbour *selfEdge){

}

//Display a graph
void view_graph(Graph *self){

}

//Save the graph into a file
int save_graph(Graph *self, const char *graphFile){
  FILE* file = fopen(graphFile, "w");
  // BORDEL AVEC LE FICHIER
  fclose(file);
}

//Free graph and quit
int quit(Graph *self){

  return 0;
}
