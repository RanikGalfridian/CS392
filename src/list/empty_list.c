#include "mylist.h"

void empty_list(struct s_node** head){
    int length = count_s_nodes(head[0]);
    for(int i = 0; i < length; i++){ remove_node(head);}
}
