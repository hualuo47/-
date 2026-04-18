#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
ll crossGlobalInversion(vector<ll>& arr,vector<ll>& help,int l,int m,int r ){
        ll ans=0;
        for(ll i=l,j=m+1,count=0;i<=m;i++){
            while(j<=r&&arr[i]>arr[j]){
                count++;
                j++;
            }
            ans+=count;
        }
        int a=l,b=m+1,i=l;
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
ll LocalInversion(vector<ll>& arr,int l,int r){
    if(l==r){
        return 0;
    }
    ll ans=0;
    for(int i=0;i<r;i++){
        if(arr[i]>arr[i+1]){
            ans++;
        }
    }
    return ans;
}
ll GlobalInversion(vector<ll>& arr,vector<ll>& help,int l,int r){
    if(l==r){
        return 0;
    }
    int m=l+(r-l)/2;
    ll LeftRes=GlobalInversion(arr,help,l,m);
    ll RightRes=GlobalInversion(arr,help,m+1,r);
    ll CrossRes=crossGlobalInversion(arr,help,l,m,r);
    return LeftRes+RightRes+CrossRes;
}
bool isIdealPermutation(vector<int>& nums) {
        int n=nums.size();
        if(n<=1) return true;
        vector<int> arr1=nums;
        vector<int> arr2=nums;
        vector<int> help(n,0);
        ll LocalCount=LocalInversion(arr1,0,n-1);
        ll GlobalCount=GlobalInversion(arr2,help,0,n-1);
        return LocalCount==GlobalCount;
    }
