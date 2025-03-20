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
int search(int key){
    int index=-1;
    if(head==NULL){
        printf("The list is empty");
    }
    else{
        current = head;
        while(current->next!=NULL){
            index++;
            if(current->data==key){
                printf("\nElement %d found at %d",key,index);
                break;
            }
            current = current->next;
        }
    }
    return index;
}
int main(){
    int i;
    search(10);
    insert(10);
    insert(20);
    insert_at_head(30);
    traverse();
    search(10);
    search(30);
    search(20);
    return 0;
}