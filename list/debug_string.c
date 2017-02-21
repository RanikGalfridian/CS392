#include "mylist.h"

void debug_string(struct s_node* head){
    if(head == NULL){
        my_str("There are no elements in head.");
        return;
    }

    struct s_node* currNode = malloc(sizeof(struct s_node));
    char* elemNum;
    char* nxtElemNum;
    char* lstElemNum;
    currNode = head;

    while(currNode != NULL){
        elemNum = (char*)(currNode->elem);
        
        if(currNode->next != NULL){
            nxtElemNum = (char*)(currNode->next->elem);

            if(currNode->prev == NULL){
                my_str("(NULL <- ");
                my_str(elemNum);
                my_str(" -> ");
                my_str(nxtElemNum);
                my_str("), ");
            }else{
                lstElemNum = (char*)(currNode->prev->elem);
                my_str("(");
                my_str(lstElemNum);
                my_str(" <- ");
                my_str(elemNum);
                my_str(" -> ");
                my_str(nxtElemNum);
                my_str("), ");
            }
        }else{
            if(currNode->prev == NULL){
                my_str("(NULL <- ");
                my_str(elemNum);
                my_str(" -> NULL), ");
            }else{
                lstElemNum = (char*)(currNode->prev->elem);
                my_str("(");
                my_str(lstElemNum);
                my_str(" <- ");
                my_str(elemNum);
                my_str(" -> NULL), ");
            }
        }
        currNode = currNode->next;
    }
}
