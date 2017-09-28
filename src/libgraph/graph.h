#ifndef GRAPH_H
#define GRAPH_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include "../liblist/list.h"

typedef struct _graph{
  bool isDirected;
  size_t nbMaxNodes;
  Neighbour *adjList;
} Graph;

//create a graph with the right number of nodes
int create_graph(Graph *self, size_t maxNodes);

//load a graph from a file
int load_graph(Graph *self, const char *graphFile);

//add a node
int add_node(Graph *self, int neighbour);

//add an edge
int add_edge(Graph *self, int fromName, int toName, int edgeName);

//Delete a node
int remove_node(Graph *self, Neighbour *selfNode);

//Delete an edge
int remove_edge(Graph *self, Neighbour *selfEdge);

//Display a graph
void view_graph(Graph *self);

//Save the graph into a file
int save_graph(Graph *self, const char *graphFile);

//Free graph and quit
int quit(Graph *self);

#endif
