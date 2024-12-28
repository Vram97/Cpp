class RandomizedSet {
public:
    RandomizedSet() {
        it=s.begin();
    }
    
    bool insert(int val) {
        // if(s.contains(val)){
        //     return false;
        // }
        // else{
        //     s.insert(val);
        //     return true;
        // }
        return s.insert(val).second;
    }
    
    bool remove(int val) {
        // if(s.contains(val)){
        //     s.erase(val);
        //     return true;
        // }
        // else{
        //     return false;
        // }
        return s.erase(val);
    }
    
    int getRandom() {
        it=s.begin();
        std::advance(it,(std::rand()%s.size()));
        return *it;
    }
private:
    unordered_set<int> s;
    unordered_set<int>::iterator it;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
