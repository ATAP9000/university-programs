#include <iostream>

using namespace std;
// A linked list node  
class Node  
{  
    public: 
    int data;  
    Node *next;  
};  
// This code is contributed by rathbhupendra 
void insertAfter(struct Node* prev_node, int new_data) 
{ 
    /*1. check if the given prev_node is NULL */ 
    if (prev_node == NULL)  
    {  
       printf("the given previous node cannot be NULL");        
       return;   
    }
    else if(prev
           
    /* 2. allocate new node */
    struct Node* new_node =(struct Node*) malloc(sizeof(struct Node)); 
   
    /* 3. put in the data  */
    new_node->data  = new_data; 
   
    /* 4. Make next of new node as next of prev_node */
    new_node->next = prev_node->next;  
   
    /* 5. move the next of prev_node as new_node */
    prev_node->next = new_node; 
} 

void printList(Node *node)  
{  
    while (node != NULL)  
    {  
        cout<<" "<<node->data;  
        node = node->next;  
    }  
}

int main()  
{
  int n;
    /* Start with the empty list */
    Node* head = NULL;  
    do{
      cout<<"programa de lista: \n";
      cin>>n;
      // Insert 6. So linked list becomes 6->NULL  
      append(&head, n);  
    }while(n!=999);

    printList(head);
}
