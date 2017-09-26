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
void create_graph(Graph *self, size_t maxNodes);

//load a graph from a file
void load_graph(Graph *self, FILE *datatext);

//add a node
void add_node(Graph *self, Neighbour *selfNode);

//add an edge
void add_edge(Graph *self, Neighbour *selfEdge);

//Delete a node
void remove_node(Graph *self, Neighbour *selfNode);

//Delete an edge
void remove_edge(Graph *self, Neighbour *selfEdge);

//Display a graph
void view_graph(Graph *self);

//Save the graph into a file
void save_graph(Graph *self, FILE *datatext);

//Free graph and quit
void quit(Graph *self);

#endif
