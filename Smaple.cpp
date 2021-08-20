#include<iostream>

using namespace std;

int main(){
    int n;
    
    cout<<"enter the number"<<endl;
    cin>>n;
    
    int arr[n]={};
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    
    
    int max=0,min=arr[0],key=45,sum=0;
    
    for(int i=0; i<n; i++){
        if(arr[i] > max ){
            max=arr[i];
        }
           
    }
    cout<<"max element is"<<max<<endl;
    
    for(int i=0;i<n;i++){
        if(arr[i] < min){
            min=arr[i];
        }
    }
    cout<<"min element is"<<min<<endl;
    
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            cout<< key <<" is found at index"<<i<<endl;
        }
    }
    
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    
    cout<<"sum is"<<sum<<endl;
    
    for(int i=1;i<n;i++){
        
    }
   

    
    return 0;
}
