#include <stdio.h>
#include <stdlib.h>

struct node {
   int data;
   struct node *next;
};

struct node *head = NULL;

void printList() {

   struct node *ptr = head;
   while(ptr != NULL) {
      printf("%d ", ptr->data);
      ptr = ptr->next;
   }
  
}

void insert_in_head(int num) {
//insert at the begining (make new head)
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data  = num;
    newNode->next = head;
    head = newNode;

}
 
 
void insert_node(struct node* prevNode, int num) { 
//insert after a specific node
    struct node* newNode =(struct node*) malloc(sizeof(struct node));
    newNode->data  = num;
    newNode->next = prevNode->next;  
    prevNode->next = newNode;

}


void delete_node(int value) {

   struct node* current = head;
   struct node* previous = NULL;
  
   if(head == NULL) {
      return;
   }

   while(current->data != value) {
 
      if(current->next == NULL) {
         return;
      } else {
         previous = current;
         current = current->next;
      }

   }

   if(current == head) {
      head = head->next;
   } else {
      previous->next = current->next;
   }    

}

int main()
{
    insert_in_head(5);
    insert_in_head(6);
    insert_in_head(12);
    insert_node( head, 8);
    insert_node( head->next, 36);
    delete_node(36);
    printList();
    return 0;
}