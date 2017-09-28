#include "graph.h"

//create a graph with the right number of nodes
int create_graph(Graph *self, size_t maxNodes){
  self->nbMaxNodes = maxNodes;
  self->adjList = malloc(maxNodes*sizeof(Neighbour));
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

int add_node(Graph *self, int nodeName){
  if(nodeName < self->nbMaxNodes){
    // TODO: Gestion erreur
    //addNode(&self->adjList[nodeName], -1, 0); TODO correct this addNode, dosn't exist anymore ...
  } else {
    // TODO: Retour code erreur nom node pas dans liste (OOB)
  }
  return 0;
}

//add an edge
int add_edge(Graph *self, int fromName, int toName, int edgeName, int Weight){
  // TODO: mieux gérer les erreures
  // TODO: Faire attention à savoir si l'edge existe déjà ou non
  int error;

  if(self->isDirected){
    error = addEdge(&self->adjList[fromName], toName, edgeName, Weight);
  } else {
    error = addEdge(&self->adjList[fromName], toName, edgeName, Weight);
    error = addEdge(&self->adjList[toName], fromName, edgeName, Weight);
  }
  return error;
}

// Check id an edge already exists
bool is_edge_exists(int edgeName){
  // TODO: implement function for checking existance of an edge
  return false;
}

//Delete a node
int remove_node(Graph *self, int nodeName){
  // TODO: Supprimer une node
  // Supression des edge reliées à la node
  // Supression de la node en elle même
  return 0;
}

//Delete an edge
int remove_edge(Graph *self, int edgeName){
  // TODO: Supprimer une edge
  // Supprime l'edge

  return 0;
}

//Display a graph
int view_graph(Graph *self){
  // TODO: Dump graph into console

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
