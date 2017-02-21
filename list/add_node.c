#include "mylist.h"

void add_node(struct s_node* node, struct s_node** head){
    if(node == NULL || node->elem == NULL || head == NULL) return;
    
    if(head[0] == NULL){
        head[0] = node;
        return;
    }

    node->next        = head[0];
    head[0]->prev     = node;
    //my_str("head[0]->prev reached");
    head[0]           = node;
}