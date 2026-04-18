#include<bits\stdc++.h>
using namespace std;
typedef long long ll;
int nthUglyNumber(int n) {
     priority_queue<ll,vector<ll>,greater<ll>> min_heap;
     int res=0;
     vector<int> factors={2,3,5};
     unordered_set<ll> num; 
     max_heap.push(1);
     num.insert(1);
     int cnt=0;
     for(int i=0;i<n;i++){
          res=(int)min_heap.top();
            min_heap.pop();
        for(auto& factor:factors){
            int next_val=res*factor;
            if(!num.count(next_val)){
                max_heap.push(next_val);
                num.insert(next_val);
            }
        }
     }  
     return res;
}