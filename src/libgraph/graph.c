#include "graph.h"

//create a graph with the right number of nodes
int create_graph(Graph *self, size_t maxNodes, bool isDirected){
  self->nbMaxNodes = maxNodes;
  self->isDirected = isDirected;
  self->adjList = malloc(maxNodes*sizeof(Neighbour*));
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
int add_node(Graph *self, int nodeName){
  if(nodeName < self->nbMaxNodes){
    // TODO: Gestion erreur
    self->adjList[nodeName] = malloc(sizeof(Neighbour*));
    self->adjList[nodeName]->neighbour = -1;
    self->adjList[nodeName]->edgeName = -1;
    self->adjList[nodeName]->weight = -1;
    self->adjList[nodeName]->nextNeighbour = NULL;
  } else {
    // TODO: Retour code erreur nom node pas dans liste (OOB)
    printf("Node OOB\n");
  }
  return 0;
}

//add an edge
int add_edge(Graph *self, int fromName, int toName, int edgeName, int Weight){
  // TODO: mieux gérer les erreures
  // TODO: Faire attention à savoir si l'edge existe déjà ou non
  int error;

  if(self->isDirected){
    error = addEdge(self->adjList[fromName], toName, edgeName, Weight);
  } else {
    error = addEdge(self->adjList[fromName], toName, edgeName, Weight);
    error = addEdge(self->adjList[toName], fromName, edgeName, Weight);
  }
  return error;
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
