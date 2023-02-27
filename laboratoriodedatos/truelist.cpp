#include <stdlib.h>
#include <stdio.h>

struct Node{
  int data;
  Node* next;
};

Node* head;

void insert(int x){
  Node* temp = (Node*)malloc(sizeof(Node));
  temp->data = x;
  temp->next = head;
  head = temp; 
}
void print(){
  Node* temp = head;
  printf("lista: ");
  while(temp != NULL){
    printf(" %d", temp->data);
    temp= temp->next;
  }
  printf("\n");
}
int main(){
  head = NULL;
  printf("cuantos numeros?\n");
  int n,i,x;
  scanf("%d", &n);
  for(i=0;i<n;i++){
    printf("Entre el numero \n");
    scanf("%d", &x);
    insert(x);
    print();
  }
}
