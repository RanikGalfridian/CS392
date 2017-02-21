#include "mylist.h"

void traverse_string(struct s_node* head){
    if(head == NULL){
        my_str("ERROR: Head is NULL!");
        return;
    }
 
    struct s_node* currNode = malloc(sizeof(struct s_node));
    currNode = head;
    char* currElem;

    while(currNode != NULL && currNode->elem != NULL){
        currElem = (char*)currNode->elem;
        currNode = currNode->next;
        my_str(currElem);
        my_str(", ");
    }
}
