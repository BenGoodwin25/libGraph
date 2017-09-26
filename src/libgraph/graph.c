#include "graph.h"

//create a graph with the right number of nodes
void create_graph(Graph *self, size_t maxNodes){
  self->nbMaxNodes = maxNodes;
  self->adjList = malloc(maxNodes*sizeof(Neighbour));
}

//load a graph from a file
void load_graph(Graph *self, FILE *datatext){

}

//add a node
void add_node(Graph *self, Node *selfNode){

}

//add an edge
void add_edge(Graph *self, Edge *selfEdge){

}

//Delete a node
void remove_node(Graph *self, Node *selfNode){

}

//Delete an edge
void remove_edge(Graph *self, Edge *selfEdge){

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
