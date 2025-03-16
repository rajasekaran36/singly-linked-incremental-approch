#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
typedef struct node node;
int main(){
    node n1;
    n1.data = 10;
    n1.next = NULL;
    printf("%d",n1.data);

    node *n2; 
    n2 = (node*)malloc(sizeof(node));
    n2->data = 20;
    n2->next = NULL;
    printf("\n%d",n2->data);
    return 0;
}