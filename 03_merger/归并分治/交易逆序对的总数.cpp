#include<iostream>
#include<vector>
using namespace std;
int cross(vector<int>& arr,vector<int>& help,int l,int m,int r){
    int ans=0;
    for(int i=l,j=m+1,count=0;i<=m;i++){
        while(j<=r&&arr[i]>arr[j]){
            count++;
            j++;
        }
        ans+=count;
    }
    int a=l;
    int b=m+1;
    int i=l;
    while(a<=m&&b<=r){
        help[i++]=arr[a]<arr[b]?arr[a++]:arr[b++];
    }
    while(a<=m){
        help[i++]=arr[a++];
    }
    while(b<=r){
        help[i++]=arr[b++];
    }
    for(int i=l;i<=r;i++){
        arr[i]=help[i];
    }
    return ans;
}
int reversePairs(vector<int>& arr,vector<int>& help,int l,int r){
    if(l==r){
        return 0;
    }
    int m=(l+r)/2;
    int leftRes=reversePairs(arr,help,l,m);
    int rightRes=reversePairs(arr,help,m+1,r);
    int crossRes=cross(arr,help,l,m,r);
    return leftRes+rightRes+crossRes;
}
 int reversePairs(vector<int>& record) {
        if(record.size()<=1){
            return 0;
        }
        vector<int> help(record.size());
        return reversePairs(record,help,0,record.size()-1);
}
int main(){
    vector<int> arr={7,5,6,4};
    cout<<reversePairs(arr);
    return 0;
}
