#include "mylist.h"

int main(){
    int a   = 1;
    int d   = 2;
    int e   = 3;
    int f   = 4;
    int g   = 5;

    char char1  = 'a';
    char char2  = 'b';
    char char3  = 'c';
    char char4  = 'd';
    char char5  = 'e';

    char* str1  = "str";
    char* str2  = "str2";
    char* str3  = "str3";
    char* str4  = "str4";
    char* str5  = "str5";

    struct s_node** head = (struct s_node**)malloc(sizeof(struct s_node*));
    struct s_node** head2 = (struct s_node**)malloc(sizeof(struct s_node*));
    struct s_node** head3 = (struct s_node**)malloc(sizeof(struct s_node*));
    struct s_node** test = (struct s_node**)malloc(sizeof(struct s_node*));

    void* num    = (void*)&a;
    void* num2   = (void*)&d;
    void* num3   = (void*)&e;
    void* num4   = (void*)&f;
    void* num5   = (void*)&g;
    void* let1   = (void*)&char1;
    void* let2   = (void*)&char2;
    void* let3   = (void*)&char3;
    void* let4   = (void*)&char4;
    void* let5   = (void*)&char5;

    my_str("+------- new_node -------+\n");
    struct s_node* intNode    = new_node(num, NULL, NULL);
    struct s_node* intNode2   = new_node(num2, NULL, NULL);
    struct s_node* intNode3   = new_node(num3, NULL, intNode2);

    struct s_node* charNode   = new_node(let1, NULL, NULL);
    struct s_node* charNode2  = new_node(let2, NULL, NULL);
    struct s_node* charNode3  = new_node(let3, NULL, charNode2);
    
    struct s_node* strNode    = new_node(str1, NULL, NULL);
    struct s_node* strNode2   = new_node(str2, NULL, NULL);
    struct s_node* strNode3   = new_node(str3, NULL, NULL);

    head[0]  = intNode;
    head2[0] = charNode;
    head3[0] = strNode;

    print_int(intNode);
    my_str("\n");
    print_char(charNode);
    my_str("\n");
    print_string(strNode);

    my_str("\n");
    debug_int(intNode);
    my_str("\n");
    debug_int(intNode2);
    my_str("\n");
    debug_int(intNode3);
    my_str("\n");
    debug_char(charNode);
    my_str("\n");
    debug_string(strNode);
    my_str("\n\n");

    my_str("+------- add_node(s) -------+\n");
    add_node(intNode2, head);
    add_elem(intNode3->elem, head);
    add_node_at(new_node(num4, NULL, NULL), head, 2); /* (NULL <- 4 -> NULL) into (3 -> 4 <- NULL) */
    append(new_node(num5, NULL, NULL), head);
    debug_int(head[0]);

    my_str("\n\n **CHARS**\n");
    add_node(charNode2, head2);
    add_elem(charNode3->elem, head2);
    add_node_at(new_node(let4, NULL, NULL), head2, 2);
    append(new_node(let5, NULL, NULL), head2);
    debug_char(head2[0]);

    my_str("\n\n **STRINGS**\n");
    add_node(strNode2, head3);
    add_elem(strNode3->elem, head3);
    add_node_at(new_node(str4, NULL, NULL), head3, 2);
    append(new_node(str5, NULL, NULL), head3);
    debug_string(head3[0]);
    my_str("\n\n");

    my_str("+------- count_s_nodes -------+\n");
    my_int(count_s_nodes(head[0]));
    my_int(count_s_nodes(head2[0]));
    my_int(count_s_nodes(head3[0]));
    my_str("\n\n");

    my_str("+------- elem_at -------+\n");
    my_int(*(int*)elem_at(head[0], 3));
    my_str("\n\n");

    my_str("+------- traverse_node(s) -------+\n");
    traverse_int(head[0]);
    my_str("\n\n");

    my_str("+------- remove_node(s) -------+\n");
    test[0] = node_at(head[0], 2);
    remove_node(test);
    debug_int(head[0]);
    my_str("\n");
    remove_last(head);
    debug_int(head[0]);
    my_str("\n");
    remove_node_at(head, 1);
    debug_int(head[0]);
    my_str("\n\n");


    return 0;
}
