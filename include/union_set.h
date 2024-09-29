#include <iostream>
#include <string>
#include <vector>

using namespace std;

void init(vector<int>& father);
int find(vector<int>& father, int u);
void join(vector<int>& father, int u, int v);
bool isSameSet(vector<int>& father, int u, int v);