#include <tree_order.h>

void pre_order(Node* node, vector<int>& arr) {
  if (node != nullptr) {
    arr.push_back(node->val);
    pre_order(node->left, arr);
    pre_order(node->right, arr);
  }
}
void mid_order(Node* node, vector<int>& arr) {

  if (node != nullptr) {
    mid_order(node->left, arr);
    arr.push_back(node->val);
    mid_order(node->right, arr);
  }
}
void las_order(Node* node, vector<int>& arr) {

  if (node != nullptr) {
    las_order(node->left, arr);
    las_order(node->right, arr);
    arr.push_back(node->val);
  }
}

vector<int> pre_order_stack(Node* node) {
  vector<int> res;
  stack<Node*> help;
  help.push(node);
  while (!help.empty()) {
    Node* curNode = help.top();
    help.pop();
    res.push_back(curNode->val);
    if (curNode->right != nullptr) {
      help.push(curNode->right);
    }
    if (curNode->left != nullptr) {
      help.push(curNode->left);
    }
  }
  return res;
}
vector<int> mid_order_stack(Node* node) {
  vector<int> res;
  stack<Node*> help;
  Node* curNode = node;
  while (!help.empty() || curNode != nullptr) {
    if (curNode != nullptr) {
      help.push(curNode);
      curNode = curNode->left;
    } else {
      curNode = help.top();
      help.pop();
      res.push_back(curNode->val);
      curNode = curNode->right;
    }
  }
  return res;
}
vector<int> las_order_stack(Node* node) {
  vector<int> res;
  stack<Node*> help;
  Node* curNode = node;
  Node* pre = nullptr;
  while (!help.empty() || curNode != nullptr) {
    if (curNode != nullptr) {
      help.push(curNode);
      curNode = curNode->left;
    } else {
      curNode = help.top();
      if (curNode->right != nullptr && curNode->right != pre) {
        curNode = curNode->right;
      } else {
        help.pop();
        pre = curNode;
        res.push_back(curNode->val);
        curNode = nullptr;
      }
    }
  }
  return res;
}

//左闭右开

Node* traveral(vector<int>& inorder, int inorderBegin, int inorderEnd,
               vector<int>& postorder, int postorderBegin, int postorderEnd) {
  if (postorderEnd == postorderBegin)
    return nullptr;
  int rootVal = postorder[postorderEnd - 1];
  Node* root = new Node(rootVal);
  if (postorderEnd - 1 == postorderBegin)
    return root;
  int index;
  for (index = inorderBegin; index < inorderEnd; ++index) {
    if (inorder[index] == rootVal)
      break;
  }

  int leftInorderBegin = inorderBegin;
  int leftInorderEnd = index;
  int rightInorderBegin = index + 1;
  int rightInorderEnd = inorderEnd;

  int leftPostorderBegin = postorderBegin;
  int leftPostorderEnd = postorderBegin + index - inorderBegin;
  int rightPostorderBegin = leftPostorderEnd;
  int rightPostorderEnd = postorderEnd - 1;
  root->left = traveral(inorder, leftInorderBegin, leftInorderEnd, postorder,
                        leftPostorderBegin, leftPostorderEnd);
  root->right = traveral(inorder, rightInorderBegin, rightInorderEnd, postorder,
                         rightPostorderBegin, rightPostorderEnd);
  return root;
}