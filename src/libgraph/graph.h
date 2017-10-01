#ifndef GRAPH_H
#define GRAPH_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include <list.h>
#include <log.h>

typedef struct _graph{
  bool isDirected;
  size_t nbMaxNodes;
  Neighbour **adjList;
} Graph;

//create a graph with the right number of nodes
int create_graph(Graph *self, size_t maxNodes, bool isDirected);

//load a graph from a file
int load_graph(Graph *self, const char *graphFile);

//add a node

int add_node(Graph *self, int nodeName);

//add an edge
int add_edge(Graph *self, int fromName, int toName, int edgeName, int Weight, bool isSymmetric);

// Check if a node already exists (true if exists)
bool is_node_exists(Graph* self, int nodeName);

// Check if an edge already exists (true if exists)
bool is_edge_exists(Graph* self, int edgeName);

//Delete a node
int remove_node(Graph *self, int nodeName);

//Delete an edge
int remove_edge(Graph *self, int edgeName);

//Display a graph
int view_graph(Graph *self);

//Save the graph into a file
int save_graph(Graph *self, const char *fileName);

//Free graph and quit
int delete_graph(Graph *self);

#endif
