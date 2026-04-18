#include<iostream>
#include<vector>
#include<ctime>
#include<cstdlib>
#include<unordered_map>
using namespace std;
class RandomizedSet {
private:
vector<int> arr;
unordered_map<int,int> map;
public:
    RandomizedSet() {
        srand(time(nullptr));
        
    }
    bool insert(int val) {
        if(map.count(val)){
            return false;
        }
        map[val]=arr.size();
        arr.push_back(val);
        return true;
        
    }
    bool remove(int val) {
        if(!map.count(val)){
            return false;
        }
        int id=map[val];
        int EndValue=arr.back();
        arr[id]=EndValue;
        map[EndValue]=id;
        map.erase(val);
        arr.pop_back();
        return true;
    }
    
    int getRandom() {
        return arr[rand()%arr.size()];     
    }
};
