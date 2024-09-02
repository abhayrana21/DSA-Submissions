#include <stdio.h>

struct node{
  int data;
  struct node *next;
};

struct node* insertatfirst(struct node *head,int data){
  struct node *ptr=(struct node *)malloc(sizeof(struct node));
  ptr->next = head;
  ptr->data=data;
  return ptr;
}

struct node* insertatindex(struct node *head,int data,int index){
  struct node *ptr=(struct node *)malloc(sizeof(struct node));
  struct node *p=head;
  int i=0;

  while(i!=index-1){
    p=p->next;
    i++;
  }
  ptr->data=data;
  ptr->next=p->next;
  p->next=ptr;
  return head;
}

void display(struct node *head){
  struct node *temp = head;
  while(temp != NULL){
    printf("%d ",temp->data);
    temp = temp->next;
  }
}

struct node* insertatend(struct node *head,int data){
  struct node* ptr=(struct node *)malloc(sizeof(struct node));
  ptr->data = data;

  struct node *p=head;

  while(p->next != NULL){
    p = p->next;
  }
  p->next = ptr;
  ptr->next = NULL;
  return head;
}

struct node* deletestart(struct node *head){
  struct node *ptr=head;
  head=head->next;
  free(ptr);
  return head;
}

struct node* deleteindex(struct node *head,int index){
  struct node *p=head;
  int i = 0;

  while(i!=index-1){
    p=p->next;
    i++;
  }
  struct node *q=p->next;
  p->next=q->next;
  free(q);
  return head;
}

struct node* deleteend(struct node *head){
  struct node *p=head;
  struct node *q=head->next;
  
  while(q->next != NULL){
    p=p->next;
    q=q->next;
  }
  p->next=NULL;
  free(q);
  return head;
}

struct node* deletebyvalue(struct node *head,int value){
  struct node *p=head;
  struct node *q=head->next;
  while(q->data != value && q->next != NULL){
    p=p->next;
    q=q->next;
  }
  if(q->data == value){
    p->next=q->next;
    free(q);
  }else{
    printf("Value not found\n");
  }
  return head;
}

int main(void) {
  struct node *head;
  struct node *second;
  struct node *third;

  head = (struct node*)malloc(sizeof(struct node));
  second = (struct node*)malloc(sizeof(struct node));
  third = (struct node*)malloc(sizeof(struct node));

  head->data = 1;
  head->next = second;

  second->data = 2;
  second->next = third;

  third->data = 3;
  third->next = NULL;
  head = insertatfirst(head, 11);
  head = insertatindex(head, 34, 1);
  head = insertatend(head, 5);
  head = deletestart(head);
  head = deleteindex(head, 2);
  head = deleteend(head);
  head = deletebyvalue(head, 3);
  display(head);

}
