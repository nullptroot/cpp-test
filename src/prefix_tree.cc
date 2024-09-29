#include <prefix_tree.h>

void preTree::deleteNode(preTreeNode* node) {
  stack<preTreeNode*> help;
  for (auto i : node->next)
    if (i != nullptr)
      help.push(i);

  while (!help.empty()) {
    preTreeNode* temp = help.top();
    help.pop();
    for (auto i : temp->next)
      if (i != nullptr)
        help.push(i);
    delete temp;
  }
  node->next = vector<preTreeNode*>(26, nullptr);
  delete node;
}

void preTree::insert(const string& word) {
  if (word.empty())
    return;
  preTreeNode* temp = root;
  temp->pass++;
  for (auto c : word) {
    if (temp->next[c - 'a'] == nullptr)
      temp->next[c - 'a'] = new preTreeNode;
    temp = temp->next[c - 'a'];
    temp->pass++;
  }
  temp->end++;
}

int preTree::searchStringNums(const string& word) const {
  if (word.empty())
    return -1;
  preTreeNode* temp = root;
  for (auto c : word) {
    if (temp->next[c - 'a'] == nullptr)
      return -1;
    else
      temp = temp->next[c - 'a'];
  }
  return temp->end;
}

int preTree::searchPreStringNums(const string& word) const {
  if (word.empty())
    return -1;
  preTreeNode* temp = root;
  for (auto c : word) {
    if (temp->next[c - 'a'] == nullptr)
      return -1;
    else {
      temp = temp->next[c - 'a'];
    }
  }
  return temp->pass;
}

void preTree::deleteString(const string& word) {
  if (searchStringNums(word) == -1)
    return;
  preTreeNode* temp = root;
  preTreeNode* pre = nullptr;
  if (--temp->pass == 0) {
    deleteNode(temp);
    root->pass = 0;
  }
  for (auto c : word) {
    pre = temp;
    temp = temp->next[c - 'a'];
    if (--temp->pass == 0) {
      deleteNode(temp);
      pre->next[c - 'a'] = nullptr;
    }
  }
  temp->end--;
}