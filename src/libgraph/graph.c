#include "graph.h"

bool is_node_oob(Graph *self, int nodeName){
  return self->nbMaxNodes < nodeName;
}

void removeSubstring(char *s,const char *toremove)
{
  if(s != NULL){
    while( (s=strstr(s,toremove)) != NULL ) {
      memmove(s,s+strlen(toremove),1+strlen(s+strlen(toremove)));
    }
  }
}

//create a graph with the right number of nodes
// error 1 : unexpected allocation error
int create_graph(Graph *self, size_t maxNodes, bool isDirected){
  self->nbMaxNodes = maxNodes;
  self->isDirected = isDirected;
  self->adjList = malloc(maxNodes*sizeof(Neighbour*));
  if(self->adjList == NULL){
    LOG_ERROR("Unexpected allocation error while create the graph.\n");
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
    LOG_ERROR("Can't open file %s, file doesn't exists or can't be opened!\n", graphFile);
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
    if (fscanf(file, "%d:", &nodeName) == 1){
      // Create the node in our graph
      add_node(self, nodeName);
      // Get edges for that node
      fgets(buffer, BUFFER_SIZE, file);
      // Storing edges informations in memory to compute it later
      nodeName--;
      edges[nodeName] = (char*)malloc(strlen(buffer));
      memcpy(edges[nodeName], buffer, strlen(buffer));
      edges[nodeName][strlen(buffer)-1] = '\0';
    }
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
      // Scanning vars
      char separator[2] = ",";
      char *subString = strtok(edges[i], separator);
      while(subString != NULL){
        // read our edge description from our string
        if (sscanf(subString, " (%d/%d)", &neighbourName, &edgeName) == 2){
          // creating the edge from our edge values
          add_edge(self, i+1, neighbourName, edgeName, 0, false);
          // Delete the added edge if it's not directed or not symmetric
          if( !self->isDirected /* || edgeIsSymmetric */){
            char *edgeStr = malloc(sizeof(char)*255);
            sprintf(edgeStr, "(%d/%d)", i+1, edgeName);
            removeSubstring(edges[neighbourName-1], edgeStr);
          }
        }
        subString = strtok(NULL, separator);
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
// error 3 : error node name
int add_node(Graph *self, int nodeName){
  if(nodeName <= 0) {
    LOG_ERROR("Can't create a node named 0 or less\n");
    return 3;
  }
  nodeName--;
  if(!is_node_oob(self, nodeName)){
    self->adjList[nodeName] = malloc(sizeof(Neighbour*));
    if(self->adjList[nodeName] == NULL){
      LOG_ERROR("Unexpected allocation error while creating the node.\n");
      return 2;
    }
    self->adjList[nodeName]->neighbour = -1;
    self->adjList[nodeName]->edgeName = -1;
    self->adjList[nodeName]->weight = -1;
    self->adjList[nodeName]->nextNeighbour = NULL;

  } else {
    LOG_ERROR("The node is out of bound of the graph.\n");
    return 1;
  }
  return 0;
}

//add an edge
// error 8 : From node doesn't exists
// error 9 : To node doesn't exists
// error 10 : Edge already exists
int add_edge(Graph *self, int fromName, int toName, int edgeName, int Weight, bool isSymmetric){
  // Recompute to get the real names
  fromName--;
  toName--;
  if(is_node_oob(self, fromName)){
    LOG_ERROR("Startpoint node is out of bounds.\n");
    return 6;
  }
  if(is_node_oob(self, toName)){
    LOG_ERROR("Endpoint node is out of bounds.\n");
    return 7;
  }
  if(!is_node_exists(self, fromName)){
    LOG_ERROR("Startpoint node doesn't exists.\n");
    return 8;
  }
  if(!is_node_exists(self, toName)){
    LOG_ERROR("Endpoint node doesn't exists.\n");
    return 9;
  }
  if(is_edge_exists(self, edgeName)){
    LOG_WARN("Edge %d already exists in the graph.\n", edgeName);
    LOG_INFO("Edge wasn't created.\n");
    return 10;
  }
  if(self->isDirected && !isSymmetric){
    return addEdge(&self->adjList[fromName], toName, edgeName, Weight);
  } else {
    int error = addEdge(&self->adjList[fromName], toName, edgeName, Weight);
    if(error != 0){
      return error;
    }
    return addEdge(&self->adjList[toName], fromName, edgeName, Weight);
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
  nodeName--;
  if(is_node_oob(self, nodeName)){
    LOG_WARN("Node is out of bounds.\n");
    LOG_INFO("No nodes affected.\n");
    return 9;
  }
  if(!is_node_exists(self, nodeName)){
    LOG_WARN("Node doesn't exists.\n");
    LOG_INFO("No nodes affected.\n");
    return 10;
  }
  // Deleting edges linked to the node
  for(int i = 0; i < self->nbMaxNodes; i++){
    if(is_node_exists(self, i)){
      deleteEdgeFromNodeName(self->adjList[i], nodeName);
    }
  }
  // Deleting node
  destroyList(self->adjList[nodeName]);
  free(self->adjList[nodeName]);
  return 0;
}

//Delete an edge
int remove_edge(Graph *self, int edgeName){
  int error=0;
  for(int i = 0; i < self->nbMaxNodes; i++){
    if(is_node_exists(self, i)){
      error = deleteEdge(&self->adjList[i], edgeName);
      if (error != 0){
        LOG_INFO("node : %d, no edge %d found here\n",i+1,edgeName);
        //return error;
      }
    }
  }
  return error;
}

int output_graph_to_stream(Graph *self, FILE *stream){
  fputs("# maximum number of node\n", stream);
  fprintf(stream, "%zu\n", self->nbMaxNodes);
  fputs("# directed\n", stream);
  if(self->isDirected){
    fputs("y\n", stream);
  } else {
    fputs("n\n", stream);
  }
  fputs("# node: neighbours", stream);
  for(int i = 0; i < self->nbMaxNodes; i++){
    if(is_node_exists(self, i)){
      fputs("\n", stream);
      fprintf(stream, "%d: ", i+1);
      outputList(self->adjList[i], stream);
    }
  }
  fputs("\n",stream);
  return 0;
}

//Display a graph
int view_graph(Graph *self){
  if(self->nbMaxNodes <= 0){
    LOG_ERROR("Graph have to be initialized!\n");
    return 1;
  }
  return output_graph_to_stream(self, stdout);
}

//Save the graph into a file
int save_graph(Graph *self, const char *graphFile){
  FILE *file = fopen(graphFile, "w");
  if(!file){
    LOG_ERROR("Can't open or create the file %s.\n", graphFile);
    LOG_INFO("Graph wasn't saved");
    return 10;
  }
  int error = output_graph_to_stream(self, file);
  fclose(file);
  return error;
}

//Free graph and quit
int delete_graph(Graph *self){
  if(self != NULL && self->nbMaxNodes > 0){
    if(self->adjList != NULL){
      for (size_t i = 0; i < self->nbMaxNodes; i++){
        if(is_node_exists(self, i)){
          destroyList(self->adjList[i]);
          free(self->adjList[i]);
        }
      }
      free(self->adjList);
      self->isDirected = false;
      self->nbMaxNodes = 0;
    }
  }
  return 0;
}
