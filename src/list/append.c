#include "mylist.h"

void append(struct s_node* node, struct s_node** head){
    if(node == NULL || node->elem == NULL || head == NULL) return;
    

    struct s_node* currNode = malloc(sizeof(struct s_node));
    currNode = head[0];

    if(currNode == NULL){
        currNode->prev = NULL;
        head[0] = currNode;
        return;
    }

    while(currNode->next != NULL){
        currNode = currNode->next;
    }

    node->prev = currNode;
    currNode->next = node;
}
