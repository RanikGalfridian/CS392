#include "mylist.h"

void* remove_node(struct s_node** node){
    if(node == NULL || node[0] == NULL){
        my_str("ERROR: Node is NULL!");
        return NULL;
    }

    struct s_node* myNode = malloc(sizeof(struct s_node));
    void* myElem = node[0]->elem;

    /*if(node[0]->next == NULL)
        return remove_last(node);
    else{
        myElem = node[0]->elem;

        myNode = node[0]->prev;
        node[0]->next->prev = myNode;
        myNode->next = node[0]->next;

        node[0]->prev = NULL;
        node[0]->next = NULL;

        free(node[0]);

        return myElem;
    }*/

    myElem = node[0]->elem;
    myNode = node[0]->next;

    if(node[0]->prev != NULL)
        node[0]->prev->next = node[0]->next;
    if(node[0]->next != NULL)
        node[0]->next->prev = node[0]->prev;

    node[0]->next = NULL;
    node[0]->prev = NULL;
    free(node[0]);
    node[0] = myNode;

    return myElem;
}
