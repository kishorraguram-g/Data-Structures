#include<stdio.h>

int fact(int n)
{
    if (n<=1)
       return n;
    return n*(fact(n-1));
}

int ncr(int n, int r){
  int num,den;
  num=fact(n);
  den=fact(n-r)*fact(r);
  return num/den;
}

int NCR(int n,int r){
    if(n==r||r==0)
        return 1;
    return (NCR(n-1,r-1)+NCR(n-1,r)); 
}
int main(){
    printf("%d",NCR(5,3));
}