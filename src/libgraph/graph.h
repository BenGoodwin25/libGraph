#ifndef GRAPH_H
#define GRAPH_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include "../liblist/list.h"

typedef struct _graph{
  size_t maxNodes;
  struct list* adjencyList;
} Graph;

/*typedef enum _color{
  White,
  Grey,
  Black
} Color;*/

typedef struct _node{
    int data;
    //Color colorNode;
} Node;

typedef struct _edge{
  Node predecessor;
  Node successor;
//  struct weight;// Maybe for later
} Edge;

//create a graph with the right number of nodes
void create_graph(Graph *self, size_t maxNodes);

//load a graph from a file
void load_graph(Graph *self, FILE *datatext);

//add a node
void add_node(Graph *self, Node *selfNode);

//add an edge
void add_edge(Graph *self, Edge *selfEdge);

//Delete a node
void remove_node(Graph *self, Node *selfNode);

//Delete an edge
void remove_edge(Graph *self, Edge *selfEdge);

//Display a graph
void view_graph(Graph *self);

//Save the graph into a file
void save_graph(Graph *self, FILE *datatext);

//Free graph and quit
void quit(Graph *self);

#endif
