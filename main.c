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
    printf("\n");
    current = head;
    while(current!=NULL){
        printf("%d->",current->data);
        current = current->next;
    }
    printf("NULL\n");
}
void insert(int data){
    node *new_node = create_node(data);
    if(head==NULL){
        head = new_node;
    }
    else{
        current = head;
        while(current->next!=NULL){
            printf("%d->",current->data);
            current = current->next;
        }
        current->next = new_node;
    }
}
void insert_at_head(int data){
    node *new_node = create_node(data);
    if(head==NULL){
        head = new_node;
    }
    else{
        new_node->next = head;
        head=new_node;
    }
}
void search(int data){
    printf("\nElement %d not found",data);
}
int main(){
    int i;
    search(10);
    //insert(10);
    //insert(20);
    //insert_at_head(30);
    //traverse();
    
    return 0;
}