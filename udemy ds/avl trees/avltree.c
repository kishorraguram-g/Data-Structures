#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node *lchild;
    struct node *rchild;
    int data;
    int height;
}*root=NULL;
typedef struct node node;


int nodeheight(node *p){
    int hl,hr;
    hl=(p->lchild)?p->lchild->height:0;
    hr=(p->rchild)?p->rchild->height:0;
    return hl>hr?hl+1:hr+1;
}

int balancefactor(node *p){
    int hl,hr;
    hl=(p->lchild)?p->lchild->height:0;
    hr=(p->rchild)?p->rchild->height:0;
    return hl-hr;
}

node *LLrotation(node *p){
    node *pl=p->lchild;
    node *plr=pl->rchild;

    pl->rchild=p;
    p->lchild=plr;
    p->height=nodeheight(p);
    pl->height=nodeheight(pl);
    
    if(root==p)
      root =pl;
    return pl;
}   

node *RRrotation(node *p){
    return NULL;
}

node *LRrotation(node *p){
    return NULL;
}

node *RLrotation(node *p){
    return NULL;
}


node *rinsert(struct node *p,int key){
    struct node *t=NULL;
    if(p==NULL){
        t=(node *)malloc(sizeof(node));
        t->data=key;
        t->lchild=t->rchild=NULL;
        t->height=1;
        return t;
    }
    if(key<p->data){
        p->lchild=rinsert(p->lchild,key);
    }
    else if(key>p->data)
    {
        p->rchild=rinsert(p->rchild,key);
    }
    p->height=nodeheight(p);

    if(balancefactor(p)==2 && balancefactor(p->lchild)==1)
       return LLrotation(p);
    else  if(balancefactor(p)==2 && balancefactor(p->lchild)==-1)
       return LRrotation(p);
    else  if(balancefactor(p)==-2 && balancefactor(p->lchild)==1)
       return RRrotation(p);
    else  if(balancefactor(p)==-2 && balancefactor(p->lchild)==-1)
       return RRrotation(p);
    return p;

}

int main(){
    root=rinsert(root,10);
    rinsert(root,5);
    rinsert(root,2);
    printf("%d   %d   %d",root->data,root->lchild->data,root->rchild->data);
}