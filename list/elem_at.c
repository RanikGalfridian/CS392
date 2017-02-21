#include "mylist.h"

void* elem_at(struct s_node* head, int n){
    if(head == NULL){
        my_str("ERROR: Head is NULL!");
        return NULL;
    }
    if(n < 0) n = 0;

    int tempNum = 0;
    struct s_node* currNode = malloc(sizeof(struct s_node));
    void* myElem;

    currNode = head;

    while(currNode->next != NULL && tempNum != n){
        currNode = currNode->next;
        tempNum++;
    }

    myElem = currNode->elem;

    return myElem;
}
