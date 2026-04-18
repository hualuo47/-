#include<iostream>
#include<vector>
#include<climits>
using namespace std;
typedef long long ll;
ll cross(vector<int>& arr,int l,int m,int r){
    ll sum=1;
    ll leftmax=INT_MIN,leftmin=INT_MAX;
    for(int i=m;i>=l;i--){
        sum*=arr[i];
        leftmax=max(leftmax,sum);
        leftmin=min(leftmin,sum);
    }
    sum=1;
    ll rightmax=INT_MIN,rightmin=INT_MAX;
    for(int i=m+1;i<=r;i++){
        sum*=arr[i];
        rightmax=max(rightmax,sum);
        rightmin=min(rightmin,sum);
    }
    return max({leftmax*rightmax,rightmin*leftmin,leftmax*rightmin,leftmin*rightmax});
    
}
ll maxProduct(vector<int>& arr,int l,int r){
    if(l==r){
        return arr[l];
    }
    int m=l+(r-l)/2;
    ll leftRes=maxProduct(arr,l,m);
    ll rightRes=maxProduct(arr,m+1,r);
    ll crossRes=cross(arr,l,m,r);
    return max({leftRes,rightRes,crossRes});
}
 int maxProduct(vector<int>& nums) {
    if(nums.empty()) return 0;
     return (int)maxProduct(nums,0,nums.size()-1); 
    } 