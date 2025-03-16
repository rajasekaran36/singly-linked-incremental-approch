#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
typedef struct node node;
node* create_node(int data){
    node *new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}
int main(){
    node *n1,*n2;
    n1 = create_node(10);
    n2 = create_node(20);

    printf("%d",n1->data);
    printf("\n%d",n2->data);
    return 0;
}