#include<iostream>
#include<vector>
using namespace std;
void cross(vector<pair<int,int>>& arr,vector<pair<int,int>>& help,vector<int>& counts,int l,int m,int r){
    for(int i=l,j=m+1,count=0;i<=m;i++){
        while(j<=r&&arr[i].first>arr[j].first){
            count++;
            j++;
        }
        counts[arr[i].second]+=count;
    }
    int i=l,a=l,b=m+1;
    while(a<=m&&b<=r){
        help[i++]=arr[a].first<arr[b].first?arr[a++]:arr[b++];
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
}
void countSmall(vector<pair<int,int>>& arr,vector<pair<int,int>>& help,vector<int>& counts,int l,int r){
    if(l==r){
        return 0;
    }
    int m=(l+r)/2;
    countSmall(arr,help,counts,l,m);
    countSmall(arr,help,counts,m+1,r);
    cross(arr,help,counts,l,m,r);
}
vector<int> countSmall(vector<int>& nums){
    int n=nums.size();
    vector<int> counts(n,0); 
    if(n<=1){
        return counts ;
    }
    vector<pair<int,int>> arr(n);
    for(int i=0;i<n;i++){
        arr[i]={nums[i],i};
    }
    vector<pair<int,int>> help(n);
    countSmall(arr,help,counts,0,n-1);
    return counts;
}
int main(){
    vector<int> arr={5,2,6,1};
    cout<<countSmall(arr);
    return 0;
}