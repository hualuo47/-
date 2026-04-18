#include<iostream>
#include<vector>
#include<ctime>
#include<unordered_map>
#include<unordered_set>
#include<cstdlib>
using namespace std;
class RandomizedCollection {
private:
unordered_map<int,unordered_set<int>> map;
vector<int> arr;
public:
    RandomizedCollection() {
        srand(time(nullptr));
    }
    
    bool insert(int val) {
        arr.push_back(val);
        map[val].insert(arr.size()-1);
        return map[val].size()==1;
    }
    bool remove(int val) {
     if(!map.count(val)){
        return false;
     }
     int id=*map[val].begin();
     int EndValue=arr.back();
     if(val==EndValue){
        map[val].erase(arr.size()-1);
     }
     else{
        arr[id]=EndValue;
        map[val].erase(id);
        map[EndValue].erase(arr.size()-1);
        map[EndValue].insert(id);
     }
     if(map[val].empty()){
        map.erase(val);
     }
     arr.pop_back();
     return true;
    }

    
    int getRandom() {
        return arr[rand()%arr.size()];
    }
};
