#include <union_set.h>

void init(vector<int>& father) {
  for (int i = 0; i < father.size(); ++i) {
    father[i] = i;
  }
}
int find(vector<int>& father, int u) {
  return u == father[u] ? u : father[u] = find(father, father[u]);
}
void join(vector<int>& father, int u, int v) {
  u = find(father, u);
  v = find(father, v);
  if (u == v) {
    return;
  }
  father[v] = u;
}
bool isSameSet(vector<int>& father, int u, int v) {
  u = find(father, u);
  v = find(father, v);
  return u == v;
}