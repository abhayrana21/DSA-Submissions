#include <stdio.h>
#include <stdlib.h>

struct queue{
int size;
int f;
int r;
int *arr;
};

int isEmpty(struct queue *q){
  return q->f == q->r;
}

int isFull(struct queue *q){
  return (q->r+1)%q->size == q->f;
}

void enqueue(struct queue *q, int val){
  if(isFull(q)){
    printf("Queue is full");
  }else{
    q->r = (q->r+1)%q->size;
    q->arr[q->r] = val;
  }
}

int dequeue(struct queue *q){
  int a = -1;
  if(isEmpty(q)){
    printf("Queue is empty");
  }else{
    q->f = (q->f+1)%q->size;
    a = q->arr[q->f];
  }
  return a;
}

void display(struct queue *q){
  for(int i=q->f+1;i<=q->r;i++){
    printf("%d ",q->arr[i]);
  }
}

void position(struct queue *q, int val){
  int i=q->f+1;
  while(i<=q->r){
    if (q->arr[i] == val){
      printf("\nThe position of %d is %d",val,i-1);
      break;
    }else{
      i++;
    }
  }
}

void main() {
  struct queue q;
  q.size = 10;
  q.f = q.r = 0;
  q.arr = (int *)malloc(q.size*sizeof(int));

  while(1){
    printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Position\n5.IsEmpty\n6.IsFull\n7.Exit\n");
    int choice;
    printf("Enter your choice: ");
    scanf("%d",&choice);
    switch(choice){
      case 1:
        printf("Enter the element to be enqueued: ");
        int val;
        scanf("%d",&val);
        enqueue(&q,val);
        break;  
      case 2:
        printf("The dequeued element is %d",dequeue(&q));
        break;
      case 3:
        display(&q);
        break;
      case 4:
        printf("Enter the element to be found: ");
        int val1;
        scanf("%d",&val1);
        position(&q,val1);
        break;
      case 5:
        if(isEmpty(&q)){
          printf("Queue is empty");
        }  else{
          printf("Queue is not empty");
        }
        break; 
      case 6:
        if(isFull(&q)){
          printf("Queue is full");
        }else{
          printf("Queue is not full");
        }
        break;
      case 7:
        break;
      default:
        printf("Invalid choice");
      break;
    }
  }
}
