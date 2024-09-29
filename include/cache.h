#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

class LRUCache {
 private:
  list<pair<int, int>> lists;
  unordered_map<int, list<pair<int, int>>::iterator> maps;
  int _capacity;
  void adjustCache(int key, int value);
  void addCache(int key, int value);
  void outCache();

 public:
  LRUCache(int capacity) : _capacity(capacity + 1) {};
  int get(int key);
  void put(int key, int value);
};
class LFUCache {
 private:
  struct freqNode {
    int freq = 0;
    list<pair<int, int>> lists;
  };
  list<freqNode> freqList;
  unordered_map<int, list<freqNode>::iterator> freqMaps;
  unordered_map<int, list<pair<int, int>>::iterator> valueMaps;
  int _capacity;
  void adjustCache(int key, int value);
  void addCache(int key, int value);
  void outCache();

 public:
  LFUCache(int capacity) : _capacity(capacity + 1) {};
  int get(int key);
  void put(int key, int value);
};
/*
1 -1 -1 3 4
1 -1 3 -1 3 4
*/
