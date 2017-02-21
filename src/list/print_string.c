#include "mylist.h"

void print_string(struct s_node* node){
    if(node == NULL){
        my_str("The node is NULL!");
        return;
    }

    char* elem = (char*)node->elem;

    my_str(elem);
}
