#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
ll merge(vector<int>& arr,vector<int>& help,int l,int m,int r){
    ll ans=0;
    for(int i=l,j=m+1;i<=m;i++){
        while(j<=r&&arr[i]>2*arr[j]){
            j++;
        }
        ans=j-(m+1);
    }
    int a=l;
    int i=l;
    int b=m+1;
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
ll count(vector<int>& arr,vector<int>& help,int l,int r){
    if(l==r){
        return 0;
    }
    int m=(l+r)/2;
    return count(arr,help,l,m)+count(arr,help,m+1,r)+merge(arr,help,l,m,r);
}
ll ReservePairs(vector<int>& arr){
    if(arr.size()<=1){
        return 0;
    }
    vector<int> help(arr.size());
    return count(arr,help,0,arr.size()-1);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    while(cin>>n){
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        cout<<ReservePairs(arr)<<endl;
    }
    return 0;
}


