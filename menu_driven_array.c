#include<stdio.h>
#include<stdlib.h>
struct array{
    int *a;
    int size;
    int length;
};
void display(struct array arr){
    printf("\nthe elements are\n");
    for(int i=0;i<arr.length;i++){
        printf("%d ",arr.a[i]);
    }
}
void append(struct array *arr, int x){
    if(arr->length<arr->size){
        arr->a[arr->length++]=x;
    }
    
}
void insert(struct array *arr, int index, int x){
    if(index>=0 && index<=arr->length){
        for(int i=arr->length;i>index;i--){
            arr->a[i]=arr->a[i-1];
        }
        arr->a[index]=x;
        arr->length++;
    }
}
void delete(struct array *arr, int index){
    if(index>=0 && index<=arr->length){
        int x=arr->a[index];
        for(int i=index;i<arr->length-1;i++){
            arr->a[i]=arr->a[i+1];
        }
        arr->length--;
        printf("the deleted element is %d",x);
    }
}
void swap(int *a, int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
int LineraSearch(struct array *arr, int key){
    int i;
    for(i=0;i<arr->length;i++){
        if(key==arr->a[i]){
            swap(&arr->a[i],&arr->a[i-1]);
            return i;
        }
    }
    return -1;
}
int BinarySearch(struct array arr,int key){
    int l,h,mid;
    l=0;
    h=arr.length-1;
    while(l<=h){
        mid=(l+h)/2;
        if(key==arr.a[mid]){
            return mid;
           
        }
        else if(key<arr.a[mid]){
            h=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return -1;

}
void get(struct array arr,int index){
    if(index<arr.length){
        int x=arr.a[index];
        printf("the element u requested is %d",x);
    }

}
int set(struct array *arr,int index, int x){
    if(index>=0 && index<arr->length)
    return arr->a[index]=x;
    
}
void max(struct array arr){
   int maxx=arr.a[0];
    for(int i=1;i<arr.length;i++){
            if(arr.a[i]>maxx){
            maxx=arr.a[i];
        }
    }
    printf("the maximum element is %d",maxx);
}
void min(struct array arr){
    int minn=arr.a[0];
    for(int i=0;i<arr.length;i++){
        if(arr.a[i]<minn){
            minn=arr.a[i];
        }
    }
    printf("the minimum element is %d",minn);
}
void sum(struct array arr){
    int total=0;
    for(int i=0;i<arr.length;i++){
        total=total+arr.a[i];
    }
    printf("the sum of this array is %d",total);
}
void reverse(struct array *arr){
    int i,j;
    for(i=0,j=arr->length-1;i<j;i++,j--){
        int temp;

        temp=arr->a[i];
        arr->a[i]=arr->a[j];
        arr->a[j]=temp;
    }
}
void left_shift(struct array *arr){
    for(int i=0;i<arr->length;i++){
        arr->a[i]=arr->a[i+1];
    }
}
void right_shift(struct array *arr){
    for(int j=arr->length;j>=0;j--){
        arr->a[j]=arr->a[j-1];
    }
}

void insert_in_sortedarray(struct array *arr, int k){
    int i,x;
    i=arr->length-1;
    while(arr->a[i]>k){
        arr->a[i+1]=arr->a[i];
        i--;

    }
    arr->a[i+1]=k;
    arr->length++;
}
int check_if_sort(struct array *arr){
    for(int i=0;i<arr->length-1;i++){
        if(arr->a[i]>arr->a[i+1]){
            return 0;
        }
        return 1;

    }
}
int main(){
    struct array arr;
    int ch;
    int index,x,key;
    printf("enter the size of array");
    scanf("%d",&arr.size);

    arr.a=(int *)malloc(arr.size*sizeof(int));
    arr.length=0;


    while(1){
        printf("\n");
        printf("\nMenu\n");
        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.Linsearch\n");
        printf("4.Binsearch\n");
        printf("5.Append\n");
        printf("6.Get Element\n");
        printf("7.Reverse The Array\n");
        printf("8.Sum of The Array\n");
        printf("9.check array\n");
        printf("10.Display The Array\n");


        printf("enter your choice\n");
        scanf("%d",&ch);

        switch(ch){
            case 1: printf("enter the value \n");
                scanf("%d",&x);
                printf("enter the index\n");
                scanf("%d",&index);
                insert(&arr,index,x);
                display(arr);
                break;
                    
                

            case 2: printf("enter index\n");
                scanf("%d",&index);
                delete(&arr,index);
                break;
                    
                    
            case 3: printf("enter the element to search\n");
                scanf("%d",&key);
                index=LineraSearch(&arr,key);
                printf("element index %d",index);
                break;
            
             case 4: printf("enter the element to search\n");
                scanf("%d",&key);
                index=BinarySearch(arr,key);
                printf("element index %d",index);
                break;

            case 5: printf("enter the element \n");
                scanf("%d",&x);
                append(&arr,x);
                break;

            case 6: printf("enter the index \n");
                scanf("%d",&index);
                get(arr,index);
                
                break;

            case 7: printf("array reversed \n");
               reverse(&arr);
                break;

            case 8: printf("\n");
               sum(arr);
                break;

            case 9: printf("\n");
               printf("value returned is %d ",check_if_sort(&arr));
                break;
                    
            case 10: display(arr);
                
        }
    }
    return 0;
}