#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
struct info{
    int maxSub;
    int minSub;
    int sumSub;
};
pair<int,int> cross(vector<int>& arr,int l,int m,int r){
    int sum=0;
    int leftmax=INT_MIN,leftmin=INT_MAX;
    for(int i=m;i>=l;i--){
        sum+=arr[i];
        leftmax=max(leftmax,sum);
        leftmin=min(leftmin,sum);
    }
    sum=0;
    int rightmax=INT_MIN,rightmin=INT_MAX;
    for(int i=m+1;i<=r;i++){
        sum+=arr[i];
        rightmax=max(rightmax,sum);
        rightmin=min(rightmin,sum);
    }
    return {leftmax+rightmax,leftmin+rightmin};
}
info CirclemaxSub(vector<int>& arr,int l,int r){
    if(l==r){
        return {arr[l],arr[l],arr[l]};
    }
    int m=l+(r-l)/2;
    info res;
    info leftRes=CirclemaxSub(arr,l,m);
    info rightRes=CirclemaxSub(arr,m+1,r);
    pair<int,int> crossRes=cross(arr,l,m,r);
    res.sumSub=leftRes.sumSub+rightRes.sumSub;
    res.maxSub=max(leftRes.maxSub,rightRes.maxSub,crossRes.first);
    res.minSub=min(leftRes.minSub,rightRes.minSub,crossRes.second);
    return res;
}
int maxSubarraySumCircular(vector<int>& nums) {
       int n=nums.size();
       info res=CirclemaxSub(nums,0,n-1);
       if(res.maxSub<0){
        return res.maxSub;
       } 
       return max(res.maxSub,res.sumSub-res.minSub);
}