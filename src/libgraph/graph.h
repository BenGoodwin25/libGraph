#ifndef GRAPH_H
#define GRAPH_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include "list.h"

struct graph{
  size_t maxNodes;
  struct list* adjencyList;
};

enum Color{
  White,
  Grey,
  Black
};

struct node{
  enum Color colorNode;
};

struct edge{
  struct node predecessor;
  struct node successor;
//  struct weight;// Maybe for later
};

//create a graph with the right number of nodes
void create_graph(struct graph *self, size_t maxNodes);

//load a graph from a file
void load_graph(struct graph *self, FILE *datatext);

//add a node
void add_node(struct graph *self, struct node *selfNode);

//add an edge
void add_edge(struct graph *self, struct edge *selfEdge);

//Delete a node
void remove_node(struct graph *self, struct edge *selfNode);

//Delete an edge
void remove_edge(struct graph *self, struct edge *selfEdge);

//Display a graph
void view_graph(struct graph *self);

//Save the graph into a file
void save_graph(struct graph *self, FILE *datatext);

//Free graph and quit
void quit(struct graph *self);

#endif
