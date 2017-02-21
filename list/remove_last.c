#include "mylist.h"

void* remove_last(struct s_node** node){
    if(node == NULL || node[0] == NULL){
        my_str("There is nothing to remove (node is null).");
        return NULL;
    }

    struct s_node* currNode = malloc(sizeof(struct s_node));
    struct s_node* myNode = malloc(sizeof(struct s_node));
    currNode = node[0];

    void* myElem;


    while(currNode->next != NULL){
        currNode = currNode->next;
    }

    myElem = currNode->elem;
    myNode = currNode->prev;

    currNode->prev = NULL;
    currNode->next = NULL;

    free(currNode);

    if(myNode != NULL)
        myNode->next = NULL;

    return myElem;
}
