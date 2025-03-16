#include<stdio.h>
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
    return 0;
}