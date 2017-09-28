#ifndef LIST_H
#define LIST_H


typedef struct _neighbour {
  int neighbour;
  int edgeName;
	int weight;
	struct _neighbour *nextNeighbour;
} Neighbour;

//creation
Neighbour createList();

//destruction
int destroyList(Neighbour* self);

bool nodeExist(Neighbour *self, int neighbour);

bool edgeExist(Neighbour *self, int edgeName);

//ajout
int addNode(Neighbour* self, int neighbour, int Weight);

//créé une 'edge'
int addEdge(Neighbour* self, int neighbourTo, int edgeName);

//suppression du node ayant la donnée neighbour
int deleteNode(Neighbour* self, int neighbour);

int deleteEdge(Neighbour* self, int edgeName);

//suppression du premier node
int delFirstNode(Neighbour* self);

//vide
bool isEmptyList(const Neighbour* self);

//taille
size_t listSize(const Neighbour* self);

//Recherche
Neighbour* searchNode(const Neighbour* self, int neighbour);


#endif
