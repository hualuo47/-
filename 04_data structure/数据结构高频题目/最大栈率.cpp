#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class FreqStack {
private:
 int topTimes;
 unordered_map<int,vector<int>> cntTimes;
 unordered_map<int,int> valueTimes;
public:
    FreqStack() {
     topTimes=0;   
    }
    
    void push(int val) {
     valueTimes[val]++;
     int curTimes=valueTimes[val];
     if(!cntTimes.count(curTimes)){
        cntTimes[curTimes]=vector<int>();
     }
     cntTimes[curTimes].push_back(val);
     topTimes=max(topTimes,curTimes);
    }
    
    int pop() {
        vector<int>& curtopNum=cntTimes[topTimes];
        int ans=curtopNum.back();
        curtopNum.pop_back();
        if(curtopNum.empty()){
            cntTimes.erase(topTimes);
            topTimes--;
        }
        int val=ans;
        if(valueTimes[val]==1){
            valueTimes.erase(val);
        }
        else{
            valueTimes[val]--;
        }
        return ans;
    }
};