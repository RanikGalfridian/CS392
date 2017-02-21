#include "mylist.h"

void* remove_node_at(struct s_node** head, int n){
    if(head == NULL || head[0] == NULL){
        my_str("There is nothing to remove (head is null)!");
        return NULL;
    }

    if(n < 0) n = 0;

    int tempNum = 0;
    struct s_node* currNode = malloc(sizeof(struct s_node));
    struct s_node* myNode = malloc(sizeof(struct s_node));
    void* myElem;


    currNode = head[0];


    while(currNode->next != NULL && tempNum != n){
        currNode = currNode->next;
        tempNum++;
    }

    if(n == 0) return remove_node(head);

    if(currNode->next == NULL)
        return remove_last(head);
    else{
        myElem = currNode->elem;

        myNode = currNode->prev;
        currNode->next->prev = myNode;
        myNode->next = currNode->next;

        currNode->prev = NULL;
        currNode->next = NULL;

        free(currNode);

        return myElem;
    }
}
