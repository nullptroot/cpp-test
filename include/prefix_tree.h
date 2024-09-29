#include <iostream>
#include <memory>
#include <stack>
#include <string>
#include <vector>

using namespace std;

struct preTreeNode {
  int pass;
  int end;
  vector<preTreeNode*> next;
  preTreeNode() : pass(0), end(0), next(vector<preTreeNode*>(26, nullptr)) {};
};

class preTree  //空字符串没有考虑
{
 private:
  preTreeNode* root;

 public:
  preTree() : root(new preTreeNode) {}
  void deleteNode(preTreeNode* node);
  ~preTree() { deleteNode(root); }
  void insert(const string& word);
  int searchStringNums(const string& word) const;
  int searchPreStringNums(const string& word) const;
  void deleteString(const string& word);
};