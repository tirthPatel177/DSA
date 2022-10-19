// Question:
// Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

// Implement the LRUCache class:

// LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
// int get(int key) Return the value of the key if the key exists, otherwise return -1.
// void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
// The functions get and put must each run in O(1) average time complexity.

class LRUCache {
public:
    unordered_map<int, pair<list<int>::iterator, int>> ht;
    list<int> dll;
    int cap;
    LRUCache(int capacity) {
        cap=capacity;
    }
    
    void moveToFirst(int key){
        dll.erase(ht[key].first);
        dll.push_front(key);
        ht[key].first=dll.begin();
    }
    
    int get(int key) {
        if(ht.find(key)==ht.end()) return -1;
        
        moveToFirst(key);
        return ht[key].second;
    }
    
    void put(int key, int value) {
        if(ht.find(key)!=ht.end()){
            ht[key].second=value;
            moveToFirst(key);
        }
        else{
            dll.push_front(key);
            ht[key]={dll.begin(), value};
            cap--;
        }
        
        if(cap<0){
            ht.erase(dll.back());
            dll.pop_back();
            cap++;
        }
        
    }
};
