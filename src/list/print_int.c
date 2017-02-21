#include "mylist.h"

void print_int(struct s_node* node){
    if(node == NULL){
        my_str("The node is NULL!");
        return;
    }

    int elem = *((int*)node->elem);


    my_int(elem);
}
