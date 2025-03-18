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
void insert(int data){
    node *new_node = create_node(data);
    if(head==NULL){
        head = new_node;
    }
    else{
        head->next = new_node;
    }
}
int main(){
    int i;
    insert(10);
    insert(20);
    traverse();
    
    return 0;
}