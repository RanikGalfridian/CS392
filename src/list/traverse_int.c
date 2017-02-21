#include "mylist.h"

void traverse_int(struct s_node* head){
    if(head == NULL){
        my_str("ERROR: Head is NULL!");
        return;
    }

    struct s_node* currNode = malloc(sizeof(struct s_node));
    currNode = head;
    int currElem;

    while(currNode != NULL && currNode->elem != NULL){
        currElem = *((int*)currNode->elem);
        currNode = currNode->next;
        my_int(currElem);
        my_str(", ");
    }
}
