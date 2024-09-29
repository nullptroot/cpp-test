#include <gtest/gtest.h>
#include <tree_order.h>

bool isEquals(const vector<int>& arr1, const vector<int>& arr2) {
  if (arr1.size() != arr2.size()) {
    return false;
  }
  for (int i = 0; i < arr1.size(); ++i) {
    if (arr1[i] != arr2[i]) {
      return false;
    }
  }
  return true;
}

TEST(TreeOrderTest, TreeOrderTest) {
  Node* root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->right->right = new Node(6);
  vector<int> arr, res;
  pre_order(root, arr);
  res = pre_order_stack(root);
  GTEST_EXPECT_TRUE(isEquals(arr, res));
  arr = vector<int>();
  mid_order(root, arr);
  res = mid_order_stack(root);
  GTEST_EXPECT_TRUE(isEquals(arr, res));
  arr = vector<int>();
  las_order(root, arr);
  res = las_order_stack(root);
  GTEST_EXPECT_TRUE(isEquals(arr, res));
}

TEST(MakeTreeTest, MakeTreeTest) {
  vector<int> inorder{9, 3, 15, 20, 7};
  vector<int> postorder{9, 15, 7, 20, 3};
  Node* node = traveral(inorder, 0, 5, postorder, 0, 5);
  vector<int> res;
  res = mid_order_stack(node);
  GTEST_EXPECT_TRUE(isEquals(inorder, res));
  res = las_order_stack(node);
  GTEST_EXPECT_TRUE(isEquals(postorder, res));
}