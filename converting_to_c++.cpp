#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

class array{
    private:
    int *a;
    int size;
    int length;
    void swap(int *a, int *b);

    public:
    array(){
        size=10;
        length=0;
        a=new int[size];
    }
    array(int sz){
        size=sz;
        length=0;
        a=new int[size];
    }
    ~array(){
        delete []a;
    }
void display();
void append( int x);
void insert( int index, int x);
void deletee( int index);
int LineraSearch(int key);
int BinarySearch(int key);
void get(int index);
int set(int index, int x);
void max();
void min();
void sum();
void reverse();
void left_shift();
void right_shift();
void insert_in_sortedarray( int k);
int check_if_sort();
void single_missing_element();
void multiple_missing_element();
};

void array::display(){
    cout<<endl<<"the elements are"<<endl;
    for(int i=0;i<length;i++){
        cout<<a[i]<<" ";
    }
}
void array::append( int x){
    if(length<size){
        a[length++]=x;
    }
    
}
void array::insert( int index, int x){
    if(index>=0 && index<=length){
        for(int i=length;i>index;i--){
            a[i]=a[i-1];
        }
        a[index]=x;
        length++;
    }
}
void array::deletee( int index){
    if(index>=0 && index<=length){
        int x=a[index];
        for(int i=index;i<length-1;i++){
            a[i]=a[i+1];
        }
        length--;
        cout<<"the deleted element is "<<x;
    }
}
void array::swap(int *a, int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
int array::LineraSearch( int key){
    int i;
    for(i=0;i<length;i++){
        if(key==a[i]){
            swap(&a[i],&a[i-1]);
            return i;
        }
    }
    return 0;
}
int array::BinarySearch(int key){
    int l,h,mid;
    l=0;
    h=length-1;
    while(l<=h){
        mid=(l+h)/2;
        if(key==a[mid]){
            return mid;
           
        }
        else if(key<a[mid]){
            h=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return -1;

}
void array::get(int index){
    if(index<length){
        int x=a[index];
        cout<<"the element u requested is "<<x;
    }

}
int array::set(int index, int x){
    if(index>=0 && index<length){
        return a[index]=x;

    }
    return 0;
    
    
}
void array::max(){
   int maxx=a[0];
    for(int i=1;i<length;i++){
            if(a[i]>maxx){
            maxx=a[i];
        }
    }
    cout<<"the maximum element is "<<maxx;
}
void array::min(){
    int minn=a[0];
    for(int i=0;i<length;i++){
        if(a[i]<minn){
            minn=a[i];
        }
    }
    cout<<"the minimum element is "<<minn;
}
void array::sum(){
    int total=0;
    for(int i=0;i<length;i++){
        total=total+a[i];
    }
    cout<<"the sum of this array is"<<total;
}
void array::reverse(){
    int i,j;
    for(i=0,j=length-1;i<j;i++,j--){
        int temp;

        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
    }
}
void array::left_shift(){
    for(int i=0;i<length;i++){
        a[i]=a[i+1];
    }
}
void array::right_shift(){
    for(int j=length;j>=0;j--){
        a[j]=a[j-1];
    }
}

void array::insert_in_sortedarray( int k){
    int i,x;
    i=length-1;
    while(a[i]>k){
        a[i+1]=a[i];
        i--;

    }
    a[i+1]=k;
    length++;
}
int array::check_if_sort(){
    for(int i=0;i<length-1;i++){
        if(a[i]>a[i+1]){
            return 0;
        }
        return 1;

    }
    return 0;
}
void array::single_missing_element(){
    int l,h,n,i;
    int diff=0;
    h=a[length-1];
    l=a[0];


    diff=l-0;
    for(int i=0;i<length;i++){
        if(a[i]-i!=diff){
            cout<<"missing element is"<<i+diff<<endl;
            break;   
        }
    }
}
void array::multiple_missing_element(){
    int diff,i,n,l,h;
    l=a[0];
    h=a[length-1];
    n=length;
    diff=l-0;
    for(i=0;i<n;i++){
        if(a[i]-i!=diff){
            while(diff<a[i]-i){
                cout<<"missing elements are"<<i+diff<<endl;
                diff++;
            }
        }
    }

}
int main(){
    array *arr;
    int ch,sz;
    int x, index,key;
    cout<<"enter the size of array"<<endl;
    cin>>sz;
    arr=new array(sz);

    while(1){
        cout<<endl;
        cout<<endl<<"Menu"<<endl;
        cout<<endl<<"1.Insert"<<endl;
        cout<<endl<<"2.delete"<<endl;
        cout<<endl<<"3.linsearch"<<endl;
        cout<<endl<<"4.binarysearch"<<endl;
        cout<<endl<<"5.append"<<endl;
        cout<<endl<<"6.get"<<endl;
        cout<<endl<<"7.reverse"<<endl;
        cout<<endl<<"8.sum"<<endl;
        cout<<endl<<"9.check"<<endl;
        cout<<endl<<"10.missing element"<<endl;
        cout<<endl<<"11.multiple missing element"<<endl;
        cout<<endl<<"12.display"<<endl;
        cout<<endl;
        


        cout<<"enter your choice"<<endl;
        cin>>ch;

        switch(ch){
            case 1: cout<<"enter the value"<<endl;
                cin>>x;
                cout<<"enter the index"<<endl;
                cin>>index;
                arr->insert(index,x);
                arr->display();
                break;
                    
                

            case 2: cout<<"enter index"<<endl;
                cin>>index;
                arr->deletee(index);
                break;
                    
                    
            case 3: cout<<"enter the element to search"<<endl;
                cin>>key;
                index=arr->LineraSearch(key);
                cout<<"element found at index"<<" "<<index;
                break;
            
             case 4: cout<<"enter the element to search"<<endl;
                cin>>key;
                index=arr->BinarySearch(key);
                cout<<"element index"<<" "<<index;
                break;

            case 5: cout<<"enter the element "<<endl;
                cin>>x;
                arr->append(x);
                break;

            case 6: cout<<"enter the index "<<endl;
                cin>>index;
                arr->get(index);
                
                break;

            case 7: cout<<"array reversed "<<endl;
               arr->reverse();
                break;

            case 8: cout<<endl;
               arr->sum();
                break;

            case 9: cout<<endl;
               cout<<"value returned is"<<" "<<arr->check_if_sort()<<endl;
                break;

            case 10: cout<<endl;
               arr->single_missing_element();
                break;

            case 11:cout<<endl;
                arr->multiple_missing_element();
                break;
                    
            case 12: arr->display();
                
        }
    }
    return 0;

    
}
