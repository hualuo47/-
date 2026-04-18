#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> arr;
vector<int> help;
void merge(int l,int m,int r){
    int i=l;
    int a=l;
    int b=m+1;
    while(a<=m&&b<=r){
        help[i++]=arr[a]<=arr[b]?arr[a++]:arr[b++];
    }
    while(a<=m) {
        help[i++]=arr[a++];
    }
    while(b<=r){
        help[i++]=arr[b++];
    }
    for(int i=l;i<=r;i++){
        arr[i]=help[i];
    }
}
void Mergesort1(int l,int r){
    if(l==r){
        return;
    }
    int m=(l+r)/2;
    Mergesort(l,m);
    Mergesort(m+1,r);
    merge(l,m,r);
}
void Mergesort2(int l,int r){
    int n=arr.size();
    for(int step=1;step<n;step*=2){
        for(int l=0;l<n;l+=step*2){
            int m=l+step-1;
            if(m+1>=n){
                break;
            }
            int r=min(l+2*step-1,n-1);
            merge(l,m,r);
        }
    }
}
