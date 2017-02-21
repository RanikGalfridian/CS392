#include "mylist.h"

void debug_int(struct s_node* head){
    if(head == NULL){
        my_str("There are no elements in head.");
        return;
    }

    struct s_node* currNode = malloc(sizeof(struct s_node));
    int elemNum;
    int nxtElemNum;
    int lstElemNum;
    currNode = head;

    while(currNode != NULL){
        elemNum = *((int*)(currNode->elem));
        
        if(currNode->next != NULL){
            nxtElemNum = *((int*)(currNode->next->elem));

            if(currNode->prev == NULL){
                my_str("(NULL <- ");
                my_int(elemNum);
                my_str(" -> ");
                my_int(nxtElemNum);
                my_str("), ");
            }else{
                lstElemNum = *((int*)(currNode->prev->elem));
                my_str("(");
                my_int(lstElemNum);
                my_str(" <- ");
                my_int(elemNum);
                my_str(" -> ");
                my_int(nxtElemNum);
                my_str("), ");
            }
        }else{
            if(currNode->prev == NULL){
                my_str("(NULL <- ");
                my_int(elemNum);
                my_str(" -> NULL), ");
            }else{
                lstElemNum = *((int*)(currNode->prev->elem));
                my_str("(");
                my_int(lstElemNum);
                my_str(" <- ");
                my_int(elemNum);
                my_str(" -> NULL), ");
            }
        }
        currNode = currNode->next;
    }
}
