#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
typedef struct node node;
node *head, *current;
node* create_node(int data){
    node *new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}
void traverse(){
    current = head;
    while(current!=NULL){
        printf("%d->",current->data);
        current = current->next;
    }
    printf("NULL");
}
int main(){
    int i;
    node *n1,*n2,*n3,*n4;
    n1 = create_node(10);
    n2 = create_node(20);
    n3 = create_node(30);
    n4 = create_node(40);
    
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    head = n1;
    traverse();
    
    return 0;
}