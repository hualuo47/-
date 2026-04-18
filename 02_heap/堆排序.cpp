#include<iostream>
#include<vector>
using namespace std;
void heapInsert(vector<int>& arr,int i){
    while(arr[i]>arr[(i-1)/2]){
        swap(arr[i],arr[(i-1)/2]);
        i=(i-1)/2;
    }
}
void heapify(vector<int>& arr,int i,int size){
    int l;
    l=(i*2)+1;
    while(l<size){
        int best=l+1<size&&arr[l+1]>arr[l]?l+1:l;
        best=arr[best]>arr[i]?best:i;
        if(best==i){
            break;
        }
        swap(arr[best],arr[i]);
        i=best;
        l=(i*2)+1;
    }
}
void heapsort(vector<int>& arr){
    if(arr.empty()) return ;
    int size=arr.size();
    for(int i=0;i<size;i++){
        heapInsert(arr,i);
    }
    while(size>1){
        swap(arr[0],arr[--size]);
        heapify(arr,0,size);
    }
}




