#include "mylist.h"

int count_s_nodes(struct s_node* head){
    if(head == NULL){
        my_str("ERROR: Head is NULL.");
        return -1;
    }

    int finNum = 0;
    struct s_node* currNode = malloc(sizeof(struct s_node));
    currNode = head;

    while(currNode != NULL){
        currNode = currNode->next;
        finNum++;
    }

    return finNum;
}
