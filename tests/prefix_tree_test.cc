#include <gtest/gtest.h>
#include <prefix_tree.h>

TEST(KmpTest, KmpTest) {
  vector<string> temp(4);
  temp[0] = "abc";
  temp[1] = "abce";
  temp[2] = "abc";
  temp[3] = "ab";
  preTree pretree;
  for (auto i : temp) {
    pretree.insert(i);
  }
  GTEST_ASSERT_EQ(3, pretree.searchPreStringNums(string("abc")));
  pretree.deleteString("abc");
  GTEST_ASSERT_EQ(2, pretree.searchPreStringNums(string("abc")));
}
