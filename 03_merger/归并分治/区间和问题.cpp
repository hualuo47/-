#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
ll cross(vector<ll>& pre,vector<ll>& help,int l,int m,int r,int lower,int upper){
    int left=l,right=l;
    int ans=0;
    for(int j=m+1;j<=r;j++){
        ll low=pre[j]-upper;
        ll high=pre[j]-lower;
        while(left<=m&&pre[left]<low){
            left++;
        }
        while(right<=m&&pre[right]<=high){
            right++;
        }
        ans+=(right-left);
    }
    int a=l,b=m+1,i=l;
    while(a<=m&&b<=r){
        help[i++]=pre[a]<pre[b]?pre[a++]:pre[b++];
    }
    while(a<=m){
        help[i++]=pre[a++];
    }
    while(b<=r){
        help[i++]=pre[b++];
    }
    for(int i=l;i<=r;i++){
        pre[i]=help[i];
    }
    return ans;

}
ll countRangeSum(vector<ll>& pre,vector<ll>& help,int l,int r,int lower,int upper){
    if(l==r){
        return 0;
    }
    int m=l+(r-l)/2;
    ll leftRes=countRangeSum(pre,help,l,m,lower,upper);
    ll rightRes=countRangeSum(pre,help,m+1,r,lower,upper);
    ll crossRes=cross(pre,help,l,m,r,lower,upper);
    return leftRes+rightRes+crossRes;
}
int countRangeSum(vector<int>& nums,int lower,int upper){
   int n=nums.size();
   vector<ll> pre(n+1,0);
   for(int i=0;i<n;i++){
    pre[i+1]=pre[i]+nums[i];
   }
   vector<ll> help(n+1);
   return countRangeSum(pre,help,0,pre.size()-1,lower,upper);
}