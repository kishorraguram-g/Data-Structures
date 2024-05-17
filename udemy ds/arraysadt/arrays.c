#include<stdio.h>
#include<stdlib.h>

struct  Array{
    int A[10];
    int size;
    int length;
};

void display(struct Array arr){
    int i;
    printf("The elements are\n");
    for(i=0;i<arr.length;i++)
        printf("%d ",arr.A[i]);
}

void append(struct Array *arr,int x){
    if(arr->length<arr->size)
       arr->A[arr->length++]=x;
}

void insert(struct Array *arr,int index,int x){
  int i;
  if(arr->length>=index&&index>=0){
    for(int i=arr->length;i>=index;i--){
        arr->A[i]=arr->A[i-1];
    }
    arr->A[index]=x;
    arr->length++;
  }
}

int delete(struct Array *arr,int index){
    int x=0;
    int i;
    if(index>=0&& index<arr->length){
        x=arr->A[index];
        for(i=index;i<arr->length-1;i++){
            arr->A[i]=arr->A[i+1];
        }
        arr->length--;
        return x;
    }
    return 0;
}
void swap(int *x,int* y){
    int temp=*x;
    *x=*y;
    *y=temp;
}
int linearsearch(struct Array *arr,int key){
    int i;
    for(i=0;i<arr->length;i++){
        if(key==arr->A[i])
        {
          swap(&arr->A[i],&arr->A[0]);
          return i;
        }
    }
    return -1;
}


int binarysearch(struct Array arr,int key){
    int l,h,mid;
    l=0;
    h=arr.length-1;
    while(l<=h){
        mid=(l+h)/2;
        if(key==arr.A[mid])
         return mid;
        else if(key>mid)
          l=mid+1;
        else 
        h=mid-1;
    }
    return -1;
}

int RBinsearch(int a[],int l,int h,int key)
{
    if(l<=h){
    int mid=(l+h)/2;
    if(key==a[mid])
      return mid;
    else if(key>mid)
    {
      l=mid+1;
      return RBinsearch(a,l,h,key);
    }
    else 
      h=mid-1;
      return RBinsearch(a,l,h,key);
    }
    return -1;
}

int get(struct Array arr,int x){
   int i;
   for(i=0;i<arr.length;i++){
    if(arr.A[i]==x)
      return i;
   }
   return -1;
}


void set(struct  Array *arr,int x,int index){
  if(index>=0&&index<arr->length)
    arr->A[index]=x;
}

int max(struct Array arr){
  int max=arr.A[0];
  for(int i=0;i<arr.length;i++){
    if(max<arr.A[i])
      max=arr.A[i];
  }
  return max;
}

int min(struct Array arr){
  int min=arr.A[0];
  for(int i=0;i<arr.length;i++){
    if(min>arr.A[i])
      min=arr.A[i];
  }
  return min;
}

int Sum(struct Array arr){
  int sum=0;
  for(int i=0;i<arr.length;i++){
    sum+=arr.A[i];
  }
  return sum;
}

float avg(struct Array arr){
  int sum=Sum(arr);
  return (float)sum/arr.length;
}


void reverseES(struct Array *arr){
  int ar[arr->length];
  int i,j;
  for(i=arr->length-1,j=0;i>=0;i--,j++){
    ar[j]=arr->A[i];
  }
  for(int i=0;i<arr->length;i++){
    arr->A[i]=ar[i];
  }
}

void reverseNs(struct Array *arr){
  int i,j;
  for(i=0,j=arr->length-1;i<j;i++,j--){
          int temp=arr->A[i];
          arr->A[i]=arr->A[j];
          arr->A[j]=temp;
  }
}

void leftrotate(struct Array *arr){
   int temp=arr->A[0];
   int i;
   for(i=0;i<arr->length-1;i++){
    arr->A[i]=arr->A[i+1];
   }
   arr->A[i]=temp;
}

void rightrotate(struct Array *arr){
  int temp=arr->A[arr->length-1];
  int i;
  for(i=arr->length-1;i>0;i--){
    arr->A[i]=arr->A[i-1];
  }
  arr->A[i]=temp;
}

void insertatsorted(struct Array *arr,int x){
   int i=arr->length-1;
   if(arr->length<arr->size){
    while(i>=0 &&arr->A[i]>x){
        arr->A[i+1]=arr->A[i];
        i--;
    }
    arr->A[i+1]=x;
    arr->length++;
   }
}

int issortedarr(struct Array arr){
    for(int i=0;i<arr.length-1;i++){
      if(arr.A[i]>arr.A[i+1])
         return 0;
    }
    return 1;
}

void Rearrange(struct Array *arr){
   int i,j;
   i=0;
   j=arr->length-1;
   while(i<j){
      while(arr->A[i]<0) i++;
      while(arr->A[j]>=0) j--;
      if(i<j)
        {
          swap(&arr->A[i],&arr->A[j]);
        }
   }
}

struct Array * merge(struct Array *arr1, struct Array *arr2){
    int i, j, k;
    i = j = k = 0;
    struct Array *arr3 = (struct Array*) malloc(sizeof(struct Array));

    while(i < arr1->length && j < arr2->length){
        if(arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else
            arr3->A[k++] = arr2->A[j++];
    }

    for(; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];
    for(; j < arr2->length; j++)
        arr3->A[k++] = arr2->A[j];

    arr3->length = k;
    arr3->size = 11;

    return arr3;
}


struct Array * Union(struct Array *arr1, struct Array *arr2){
    int i = 0, j = 0, k = 0;
    struct Array *arr3 = (struct Array*) malloc(sizeof(struct Array));

    while(i < arr1->length && j < arr2->length){
        if(arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else if(arr1->A[i] > arr2->A[j])
            arr3->A[k++] = arr2->A[j++];
        else { 
            arr3->A[k++] = arr1->A[i++];
            j++; 
        }
    }
    for(; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];
    for(; j < arr2->length; j++)
        arr3->A[k++] = arr2->A[j];
    arr3->length = k;
    arr3->size = 11;  
    return arr3;
}

struct Array * Intersection(struct Array *arr1, struct Array *arr2){
    int i = 0, j = 0, k = 0;
    struct Array *arr3 = (struct Array*) malloc(sizeof(struct Array));

    while(i < arr1->length && j < arr2->length){
        if(arr1->A[i] < arr2->A[j])
                i++;            
        else if(arr1->A[i] > arr2->A[j])
            j++;
        else { 
            arr3->A[k++] = arr1->A[i++];
            j++; 
        }
    }
    arr3->length = k;
    arr3->size = 11;  
    return arr3;
}

struct Array * Difference(struct Array *arr1, struct Array *arr2){
    int i = 0, j = 0, k = 0;
    struct Array *arr3 = (struct Array*) malloc(sizeof(struct Array));

    while(i < arr1->length && j < arr2->length){
        if(arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else if(arr1->A[i] > arr2->A[j])
            j++;
        else { 
            i++;
            j++; 
        }
    }
    for(; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];
    arr3->length = k;
    arr3->size = 11;  
    return arr3;
}


int main(){
    struct Array arr1={{1,2,3,6,7},10,   5};
    struct Array arr2={{2,6,8,10,11},10,5};
    struct Array *arr3 = Union(&arr1, &arr2);
    display(*arr3); 
    arr3=merge(&arr1,&arr2);
    printf("\n");
    display(*arr3);
    printf("\n");
    arr3=Intersection(&arr1,&arr2);
    display(*arr3);
    printf("\n");
    arr3=Difference(&arr1,&arr2);
    display(*arr3);
}

