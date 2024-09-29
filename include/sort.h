#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

void insert_sort(vector<int>& val);

void swap(vector<int>& val, int i, int j);

ostream& operator<<(ostream& os, const vector<int>& val);
vector<int> fill_with_rand();
bool operator!=(const vector<int>& val1, const vector<int>& val2);
bool compare(void (*sort1)(vector<int>&), void (*sort2)(vector<int>&),
             int times);

void quick_sort(vector<int>& val);
vector<int> partision(vector<int>& val, int L, int R);
void process_quick(vector<int>& val, int L, int R);

void merge_sort(vector<int>& val);
void process_merge(vector<int>& val, int L, int R);
void merge(vector<int>& val, int L, int mid, int R);

void heap_sort(vector<int>& val);
void heap_insert(vector<int>& val, int index);
void heapify(vector<int>& val, int index, int heapsize);