#include "graph.h"

//create a graph with the right number of nodes
void create_graph(Graph *self, size_t maxNodes){
  self->nbMaxNodes = maxNodes;
  self->adjList = malloc(maxNodes*sizeof(Neighbour));
}

//load a graph from a file
void load_graph(Graph *self, const char *graphFile){
  FILE* file = fopen(graphFile, "r");
  // BORDEL AVEC LE FICHIER
  fclose(file);
}

//add a node
void add_node(Graph *self, int neighbour){
  if(neighbour < self->nbMaxNodes){
    addNode(&self->adjList[neighbour], neighbour);
    // TODO: Créer un neighbour
  } else {
    // TODO: Retour code erreur
  }
}

//add an edge
void add_edge(Graph *self, int fromName, int toName, int edgeName){
  if(self->isDirected){
    // Support directed
  } else {
    // Support undirected
  }
}

//Delete a node
void remove_node(Graph *self, Neighbour *selfNode){

}

//Delete an edge
void remove_edge(Graph *self, Neighbour *selfEdge){

}

//Display a graph
void view_graph(Graph *self){

}

//Save the graph into a file
void save_graph(Graph *self, FILE *datatext){

}

//Free graph and quit
void quit(Graph *self){

}
