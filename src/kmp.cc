#include <kmp.h>

void getNext(vector<int>& next, const string& needle) {
  int j = 0;
  next[0] = 0;
  for (int i = 1; i < needle.size(); ++i) {
    while (j > 0 && needle[i] != needle[j]) {
      j = next[j - 1];
    }
    if (needle[i] == needle[j]) {
      ++j;
    }
    next[i] = j;
  }
}
int strStr(string haystack, string needle) {
  if (needle.size() == 0) {
    return 0;
  }
  vector<int> next(needle.size());
  getNext(next, needle);
  int j = 0;
  for (int i = 0; i < haystack.size(); ++i) {
    while (j > 0 && haystack[i] != needle[j]) {
      j = next[j - 1];
    }
    if (haystack[i] == needle[j]) {
      j++;
    }
    if (j == needle.size()) {
      return i - j + 1;
    }
  }
  return -1;
}