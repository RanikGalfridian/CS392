#include "mylist.h"

struct s_node* new_node(void* elem, struct s_node* next, struct s_node* previous){
    struct s_node* myNode = malloc(sizeof(struct s_node));
    
    myNode->elem     = elem;
    myNode->next     = next;
    myNode->prev     = previous;

    return myNode;
}
