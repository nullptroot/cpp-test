// binary_search.cc
#include <binary_search.h>
int binary(const vector<int>& val, int elem) {
  int L = 0;
  int R = val.size();
  while (L < R) {
    int mid = L + (R - L) / 2;
    if (val[mid] == elem) {
      return mid;
    } else if (val[mid] > elem) {
      R = mid;
    } else {
      L = mid + 1;
    }
  }
  return -1;
}

int binaryLeft(const vector<int>& val, int elem) {
  int L = 0;
  int R = val.size() - 1;
  while (L < R) {
    int mid = L + (R - L) / 2;
    if (val[mid] == elem) {
      R = mid;
    } else if (val[mid] > elem) {
      R = mid;
    } else if (val[mid] < elem) {
      L = mid + 1;
    }
  }
  return val[L] == elem ? L : -1;
}

int binaryRight(const vector<int>& val, int elem) {
  int L = 0;
  int R = val.size() - 1;
  while (L < R) {
    int mid = L + (R - L) / 2 + 1;
    if (val[mid] == elem) {
      L = mid;
    } else if (val[mid] > elem) {
      R = mid - 1;
    } else {
      L = mid;
    }
  }
  return val[R] == elem ? R : -1;
}
