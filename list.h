#ifndef LIST_H
#define LIST_H


struct list_node {
	size_t state; //name of the current elem
	struct list_node *next;
};

struct list {
	struct list_node *first;
};

//creation
void createList(struct list* self);

//destruction
void destroyList(struct list* self);

//ajout
bool addNode(struct list* self, size_t state);

//suppression après l'élément courant
void delNodeAfter(struct list_node* self);

//suppression du premier node
void delFirstNode(struct list* self);

//vide
bool isEmptyList(const struct list* self);

//taille
size_t listSize(const struct list* self);

//recherche
struct list_node* searchNode(const struct list* self, size_t state);

#endif
