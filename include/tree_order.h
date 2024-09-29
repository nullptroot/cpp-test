#include <iostream>
#include <ostream>
#include <stack>
#include <vector>

using namespace std;

class Node {
 public:
  Node* left;
  Node* right;
  int val;
  Node() : left(nullptr), right(nullptr), val(0) {};
  Node(int val) : left(nullptr), right(nullptr), val(val) {};
};
// Node *traveral(vector<int> &inorder,int inorderBegin,int inorderEnd,vector<int> &postorder,int postorderBegin,int postorderEnd);
void pre_order(Node* node, vector<int>& arr);
vector<int> pre_order_stack(Node* node);
void mid_order(Node* node, vector<int>& arr);
vector<int> mid_order_stack(Node* node);
void las_order(Node* node, vector<int>& arr);
vector<int> las_order_stack(Node* node);
Node* traveral(vector<int>& inorder, int inorderBegin, int inorderEnd,
               vector<int>& postorder, int postorderBegin, int postorderEnd);
