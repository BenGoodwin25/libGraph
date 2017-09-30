#include "graph.h"

// TODO: Log errors etc...

bool is_node_oob(Graph *self, int nodeName){
  return self->nbMaxNodes < nodeName;
}

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
#define BUFFER_SIZE 255
  // Graph related vars
  int nbMaxNodes = -1;
  bool isDirected = false;

  // File reading related
  char buffer[BUFFER_SIZE];
  char *edges[BUFFER_SIZE];
  char cIsDirected;
  FILE* file = fopen(graphFile, "r");
  if(!file){
    printf("[Error] Can't open file %s, file doesn't exists or can't be opened!\n", graphFile);
    return 1;
  }

  // Skip the first commented line
  fgets(buffer, BUFFER_SIZE, file);
  // Reading the maximum number of nodes for our graph
  fscanf(file, "%d", &nbMaxNodes);
  // go to the next line
  fgets(buffer, BUFFER_SIZE, file);

  // Skip the commented line
  fgets(buffer, BUFFER_SIZE, file);
  // Reading the directed parameter
  cIsDirected = fgetc(file);
  if(cIsDirected == 'y'){
    isDirected = true;
  } else {
    isDirected = false;
  }
  // We can now create our graph struct
  create_graph(self, nbMaxNodes, isDirected);
  // Go to next line
  fgets(buffer, BUFFER_SIZE, file);

  // Skip the commented line
  fgets(buffer, BUFFER_SIZE, file);
  // Reading graph nodes and edges
  while(!feof(file)){
    int nodeName;
    // Scan for the nodeName
    fscanf(file, "%d:", &nodeName);
    // Decrease nodeName to get the real name in memory
    nodeName--;
    // Create the node in our graph
    add_node(self, nodeName);
    // Get edges for that node
    fgets(buffer, BUFFER_SIZE, file);
    // Storing edges informations in memory to compute it later
    edges[nodeName] = (char*)malloc(strlen(buffer)+1);
    memcpy(edges[nodeName], buffer, strlen(buffer)+1);
    edges[nodeName][strlen(buffer)+1] = '\0';
  }
  // We have finish with our file so we can close it
  fclose(file);

  // Compute graph edges
  for(int i = 0; i < nbMaxNodes; i++) {
    // First, check if our current node is existing
    if(is_node_exists(self, i)){
      // edges vars
      int neighbourName;
      int edgeName;
      // scanning vars
      char *edge = edges[i];
      // Search for the first comma in edge list
      char *firstComma = strchr(edge, ',');
      // If there's a coma then we have multiple edges for this node
      while(firstComma != NULL){
        // looking for the size of string we have to allocate to get the edge description
        int size = strcspn(edge, ",");
        // create a temporary string to read the edge description
        char *edgeDescription = (char*)malloc(size);
        // copying the edge description in our temporary string
        strncpy(edgeDescription, edge, size);
        // read our edge description from our string
        sscanf(edgeDescription, " (%d/%d)", &neighbourName, &edgeName);
        // Now that we read the description into our vars we can free the edgeDescription
        free(edgeDescription);
        // creating the edge from our edge values
        add_edge(self, i, neighbourName-1, edgeName, 0, true);
        // then we can go to the next edge of the node (++firstComma to get the string after the first comma)
        edge = ++firstComma;
        // then searching for the next comma
        firstComma = strchr(edge, ',');
      }
      // if there is no more comma and we still have an edge description, compute it
      if(firstComma == NULL && strlen(edge) > 2){
        sscanf(edge, " (%d/%d)", &neighbourName, &edgeName);
        add_edge(self, i, neighbourName-1, edgeName, 0, true);
      }
      // We have finish to compute edges for this node, we free our temporary memory
      free(edges[i]);
    }
  }

  return 0;
}

//add a node
// error 1 : node OOB
// error 2 : unexpected allocation error
int add_node(Graph *self, int nodeName){
  if(!is_node_oob(self, nodeName)){
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
  // Supression des edge reliées à la node
  for(int i = 0; i < self->nbMaxNodes; i++){
    if(is_node_exists(self, i)){
      deleteEdgeFromNodeName(self->adjList[i], nodeName);
    }
  }
  // Supression de la node en elle même
  destroyList(self->adjList[nodeName]);
  free(self->adjList[nodeName]);
  return 0;
}

//Delete an edge
int remove_edge(Graph *self, int edgeName){
  for(int i = 0; i < self->nbMaxNodes; i++){
    if(is_node_exists(self, i)){
      int error = deleteEdge(self->adjList[i], edgeName);
      if (error != 0){
        return error;
      }
    }
  }
  return 0;
}

// TODO: gérer les erreurs?
int output_graph_to_stream(Graph *self, FILE *stream){
  fputs("# maximum number of node\n", stream);
  fprintf(stream, "%zu\n", self->nbMaxNodes);
  fputs("# directed\n", stream);
  if(self->isDirected){
    fputs("y\n", stream);
  } else {
    fputs("n\n", stream);
  }
  fputs("# node: neighbours\n", stream);
  for(int i = 0; i < self->nbMaxNodes; i++){
    if(is_node_exists(self, i)){
      fprintf(stream, "%d: ", i+1);
      outputList(self->adjList[i], stream);
      fputs("\n", stream);
    }
  }
  return 0;
}

//Display a graph
int view_graph(Graph *self){
  return output_graph_to_stream(self, stdout);
}

//Save the graph into a file
int save_graph(Graph *self, const char *graphFile){
  FILE *file = fopen(graphFile, "w");
  int error = output_graph_to_stream(self, file);
  fclose(file);
  return error;
}

//Free graph and quit
int quit(Graph *self){
  if(self != NULL){
    if(self->adjList != NULL){
      for (size_t i = 0; i < self->nbMaxNodes; i++){
        if(is_node_exists(self, i)){
          destroyList(self->adjList[i]);
          free(self->adjList[i]);
        }
      }
      free(self->adjList);
    }
  }
  return 0;
}
