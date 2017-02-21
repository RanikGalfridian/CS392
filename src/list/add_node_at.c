#include "mylist.h"

void add_node_at(struct s_node* node, struct s_node** head, int n){
    if(node == NULL || node->elem == NULL) return;
    if(n < 0) n = 0;

    int tempNum = 0;
    struct s_node* currNode = malloc(sizeof(struct s_node));
    currNode = head[0];

    while(tempNum != n && currNode->next != NULL){
        currNode = currNode->next;
        tempNum++;
    }

    if(currNode->next == NULL && tempNum == n){
        node->next = currNode;
        node->prev = currNode->prev;
        currNode->next = NULL;
        currNode->prev->next = node;
        currNode->prev = node;
    }else if(currNode->next == NULL){
        node->prev = currNode;
        node->next = NULL;
        currNode->next = node;
    }else{
        node->prev = currNode->prev;
        node->next = currNode;
        currNode->prev->next = node;
        currNode->prev = node;
    }
}
