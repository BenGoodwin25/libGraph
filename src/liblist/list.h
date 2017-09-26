#ifndef LIST_H
#define LIST_H


typedef struct _list_node {
	int data;
	struct _list_node *next;
	struct _list_node *previous;
} List_node;

typedef struct _list {
	List_node *first;
} List;


//creation
List createList();

//destruction
int destroyList(List* self);

//ajout
int addNode(List* self, int data);

//suppression du node ayant la donnée data
int deleteNode(List* self, int data);

//suppression du premier node
int delFirstNode(List* self);

//vide
bool isEmptyList(const List* self);

//taille
size_t listSize(const List* self);

//Recherche
List_node* searchNode(const List* self, int data);

#endif
