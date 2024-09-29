#include <sort.h>

void swap(vector<int>& val, int i, int j) {
  int temp = val[i];
  val[i] = val[j];
  val[j] = temp;
}
void insert_sort(vector<int>& val) {
  for (int i = 1; i < val.size(); i++) {
    for (int j = i; j > 0 && val[j] < val[j - 1]; j--)
      swap(val, j, j - 1);
  }
}

ostream& operator<<(ostream& os, const vector<int>& val) {
  for (auto i : val)
    cout << i << " ";
  cout << endl;
  return os;
}
vector<int> fill_with_rand() {
  vector<int> temp(rand() % 100 + 5);
  for (int i = 0; i < (int)temp.size(); i++) {
    temp[i] = rand() % 100;
  }
  return temp;
}
bool operator!=(const vector<int>& val1, const vector<int>& val2) {
  for (int i = 0; i < val1.size(); i++) {
    if (val1[i] != val2[i])
      return 1;
  }
  return 0;
}
bool compare(void (*sort1)(vector<int>&), void (*sort2)(vector<int>&),
             int times) {
  while (times-- > 0) {

    vector<int> temp1 = fill_with_rand();
    vector<int> temp2 = temp1;
    vector<int> temp3 = temp1;
    sort1(temp1);
    sort2(temp2);

    if (temp1 != temp2) {
      return 0;
    }
  }
  return 1;
}

void quick_sort(vector<int>& val) {
  process_quick(val, 0, val.size() - 1);
}
vector<int> partision(vector<int>& val, int L, int R) {
  int less = L - 1;
  int more = R;
  while (L < more) {
    if (val[L] < val[R])
      swap(val, L++, ++less);
    else if (val[L] > val[R])
      swap(val, L, --more);
    else
      L++;
  }
  swap(val, more, R);
  int a[2] = {less + 1, more};
  return vector<int>(a, a + 2);
}
void process_quick(vector<int>& val, int L, int R) {
  if (L < R) {
    vector<int> temp = partision(val, L, R);

    process_quick(val, L, temp[0] - 1);
    process_quick(val, temp[0] + 1, R);
  }
}
void merge_sort(vector<int>& val) {
  process_merge(val, 0, val.size() - 1);
}
void process_merge(vector<int>& val, int L, int R) {
  if (L < R) {
    int mid = (L + R) / 2;
    process_merge(val, L, mid);
    process_merge(val, mid + 1, R);
    merge(val, L, mid, R);
  }
}
void merge(vector<int>& val, int L, int mid, int R) {
  vector<int> help(R - L + 1);
  int i = 0;
  int p1 = L;
  int p2 = mid + 1;
  while (p1 <= mid && p2 <= R) {
    help[i++] = val[p1] <= val[p2] ? val[p1++] : val[p2++];
  }
  while (p1 <= mid)
    help[i++] = val[p1++];
  while (p2 <= R)
    help[i++] = val[p2++];
  for (i = 0; i < help.size(); i++)
    val[L + i] = help[i];
}
void heap_sort(vector<int>& val) {
  for (int i = 0; i < val.size(); i++)
    heap_insert(val, i);
  int heapsize = val.size();
  swap(val, 0, --heapsize);
  while (heapsize > 0) {
    heapify(val, 0, heapsize);
    swap(val, 0, --heapsize);
  }
}
void heap_insert(vector<int>& val, int index) {
  while (val[index] > val[(index - 1) / 2]) {
    swap(val, index, (index - 1) / 2);
    index = (index - 1) / 2;
  }
}
void heapify(vector<int>& val, int index, int heapsize) {
  int left = index * 2 + 1;
  while (left < heapsize) {
    int largest =
        left + 1 < heapsize && val[left + 1] > val[left] ? left + 1 : left;
    largest = val[index] > val[largest] ? index : largest;
    if (index == largest)
      break;
    else {
      swap(val, index, largest);
      index = largest;
      left = index * 2 + 1;
    }
  }
}
