#include<stdio.h>
#include<stdlib.h>

struct node {
    struct node *lchild;
    int data;
    struct node *rchild;

};
typedef struct node node;

struct Queue{
    int size;
    int front;
    int rear;
    node **Q; 
};

void create(struct Queue *q,int size){
    q->size=size;
    q->front=q->rear=-1;
    q->Q=(node **)malloc(q->size*sizeof(node *));
}
void enqueue(struct Queue *q,node *x){
    if(q->rear==q->size-1){
        printf("Queue is full\n");
        return;
    }
    q->rear++;
    q->Q[q->rear]=x;
}

node * dequeue(struct Queue *q){
  node *x=NULL;
  if(q->front==q->rear){
    printf("Queue is empty\n");
    return x;
  }
  q->front++;
  x=q->Q[q->front];
  return x;
}

int isEmpty(struct Queue q){
    return q.front==q.rear;
}




//TREE FUNCTIONS                        **************


struct node *root=NULL;
void createT(){
    struct node *p,*t;
    int x;
    struct Queue q;
    create(&q,100);

    printf("Enter the root value: ");
    scanf("%d",&x);
    root=(struct node *)malloc(sizeof(node));
    root->data=x;
    root->lchild=root->rchild=NULL;    

    enqueue(&q,root);
    while(!isEmpty(q)){
        p=dequeue(&q);
        printf("Enter the left child of %d (-1 if none): ", p->data);
        scanf("%d",&x);
        if(x!=-1){
            t=(node *)malloc(sizeof(node));
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            enqueue(&q,t);
        }
        printf("Enter the right child of %d (-1 if none): ", p->data);
        scanf("%d",&x);
        if(x!=-1){
            t=(node *)malloc(sizeof(node));
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->rchild=t;
            enqueue(&q,t);
        }
    }
}


void preorder(node *x){
    if(x){
        printf("%d",x->data);
        preorder(x->lchild);
        preorder(x->rchild);
    }
}
void levelorder(node *p){
    struct Queue q;
    enqueue(&q,p);
    while(!isEmpty(q)){
        node *current = dequeue(&q);
        printf("%d ", current->data); // Print the data with a space
        if(current->lchild){
            enqueue(&q,current->lchild);
        }
        if(current->rchild){
            enqueue(&q,current->rchild);
        }
    }
}

int main(){
    createT();
    levelorder(root);
}