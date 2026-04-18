#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int cross(vector<int>& arr,int l,int m,int r){
    int leftmax=-1e18;
    int sum=0;
    for(int i=m;i>=l;i--){
        sum+=arr[i];
        leftmax=max(leftmax,sum);
    }
    sum=0;
    int rightmax=-1e18;
    for(int i=m+1;i<=r;i++){
        sum+=arr[i];
        rightmax=max(rightmax,sum);
    }
    return leftmax+rightmax;
}
int Maxsubarry(vector<int>& arr,int l,int r){
    if(l==r){
        return arr[l];
    }
    int m=(l+r)/2;
    int crossmax=cross(arr,l,m,r);
    int leftmax=Maxsubarry(arr,l,m);
    int rightmax=Maxsubarry(arr,m+1,r);
    int ans=max(leftmax,rightmax);
    return max(ans,crossmax);
}
int main(){
    vector<int> arr={5,4,-1,7,8};
    cout<<Maxsubarry(arr,0,arr.size()-1);
}