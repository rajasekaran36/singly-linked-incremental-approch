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
    int found=0;
    if(head==NULL){
        printf("The list is empty");
        return -1;
    }
    else{
        current = head;
        while(current!=NULL){
            index++;
            if(current->data==key){
                printf("\nElement %d found at %d",key,index);
                found=1;
                break;
            }
            current = current->next;
        }
    }
    if(found==0){
        printf("\nElement %d is not found",key);
    }
    return index;
}
int size(){
    int count = 0;
    if(head==NULL){
        printf("\nList is empty");
    }
    else{
        current = head;
        while(current!=NULL){
            count++;
            current = current->next;
        }
    }
    printf("\nThe size of list is %d",count);
    return count;
}
void delete_head(){
    if(head==NULL){
        printf("\nList is empty can't perform delete");
    }
    else{
        head = NULL;
        printf("Head Deleted");
    }
}
int main(){
    int i;
    insert(10);
    insert(20);
    traverse();
    delete_head();
    traverse();
    return 0;
}