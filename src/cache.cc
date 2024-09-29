#include <cache.h>

void LRUCache::adjustCache(int key, int value) {
  lists.erase(maps[key]);
  lists.push_front({key, value});
  maps[key] = lists.begin();
}
void LRUCache::addCache(int key, int value) {
  lists.push_front({key, value});
  maps[key] = lists.begin();
}
void LRUCache::outCache() {
  maps.erase(lists.back().first);
  lists.pop_back();
}
int LRUCache::get(int key) {
  if (maps.find(key) == maps.end()) {
    return -1;
  } else {
    int value = maps[key]->second;
    adjustCache(key, value);
    return value;
  }
}
void LRUCache::put(int key, int value) {
  if (maps.find(key) == maps.end()) {
    --_capacity;
    if (_capacity == 0) {
      outCache();
      ++_capacity;
    }
    addCache(key, value);
  } else {
    adjustCache(key, value);
  }
}

void LFUCache::adjustCache(int key, int value) {
  auto willAdjFreqIter = freqMaps[key];
  willAdjFreqIter->lists.erase(valueMaps[key]);
  auto maybeDelFreqIter = willAdjFreqIter;
  int freq = willAdjFreqIter->freq;
  willAdjFreqIter++;
  if (willAdjFreqIter != freqList.end() && willAdjFreqIter->freq == freq + 1) {
    willAdjFreqIter->lists.push_front({key, value});
    valueMaps[key] = willAdjFreqIter->lists.begin();
    freqMaps[key] = std::move(willAdjFreqIter);
  } else {
    freqNode newAddFreqNode;
    newAddFreqNode.freq = freq + 1;
    newAddFreqNode.lists.push_front({key, value});
    valueMaps[key] = newAddFreqNode.lists.begin();
    freqMaps[key] = freqList.insert(willAdjFreqIter, std::move(newAddFreqNode));
  }
  if (maybeDelFreqIter->lists.empty()) {
    freqList.erase(maybeDelFreqIter);
  }
}
void LFUCache::addCache(int key, int value) {
  auto maybeAddFreqIter = freqList.begin();
  if (maybeAddFreqIter != freqList.end() && maybeAddFreqIter->freq == 0) {
    maybeAddFreqIter->lists.push_front({key, value});
    valueMaps[key] = maybeAddFreqIter->lists.begin();
    freqMaps[key] = std::move(maybeAddFreqIter);
  } else {
    freqNode newAddFreqNode;
    newAddFreqNode.freq = 0;
    newAddFreqNode.lists.push_front({key, value});
    valueMaps[key] = newAddFreqNode.lists.begin();
    freqList.push_front(std::move(newAddFreqNode));
    freqMaps[key] = freqList.begin();
  }
}
void LFUCache::outCache() {
  auto maybeDelFreqIter = freqList.begin();
  int key = maybeDelFreqIter->lists.back().first;
  maybeDelFreqIter->lists.pop_back();
  freqMaps.erase(key);
  valueMaps.erase(key);
  if (maybeDelFreqIter->lists.empty()) {
    freqList.pop_front();
  }
}
int LFUCache::get(int key) {
  if (freqMaps.find(key) == freqMaps.end()) {
    return -1;
  } else {
    int value = valueMaps[key]->second;
    adjustCache(key, value);
    return value;
  }
}
void LFUCache::put(int key, int value) {
  if (freqMaps.find(key) == freqMaps.end()) {
    --_capacity;
    if (_capacity == 0) {
      ++_capacity;
      outCache();
    }
    addCache(key, value);
  } else {
    adjustCache(key, value);
  }
}