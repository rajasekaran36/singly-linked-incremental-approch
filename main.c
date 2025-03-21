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
    else if(head->next==NULL){
        free(head);
        head = NULL;
        printf("Head Deleted");
    }
    else{
        node *previous = head;
        head = head->next;
        free(previous);
        printf("Head Deleted");
    }
}
void delete_tail(){
    int i;
    if(head==NULL){
        printf("\nList is empty can't perform delete");
    }
    else if(head->next==NULL){
        free(head);
        head = NULL;
        printf("\nTail Deleted");
    }
    else{
        current = head;
        while(current->next->next!=NULL){
            current = current->next;
        }
        node *last_node = current->next->next;
        current->next = NULL;
        free(last_node);
        printf("\nTail Deleted");
    }
}
void insert_at(int pos, int data){
    if(pos==0){
        insert_at_head(data);
    }
    else if(pos>=size()){
        insert(data);
    }
    else{
        int i;
        current = head;
        for(i=1;i<pos;i++){
            current = current->next;
        }
        node *new_node = create_node(data);
        node *previous = current;
        new_node->next = current->next;
        current->next = new_node;
    }
}
void delete_at(int pos){
    if(pos==0){
        delete_head();
    }
    else if(pos>=size()){
        delete_tail();
    }
    else{
        int i;
        current = head;
        for(i=1;i<pos-1;i++){
            current = current->next;
        }
        node *to_delete = current->next;
        current->next = to_delete->next;
        free(to_delete);
    }
}
int main(){
    puts("Singly Linked List");
    puts("-------------------");
    printf("\n1.Insert\n2.Delete\n3.Traversal\n4.Search\n5.Size");
    
    return 0;
}