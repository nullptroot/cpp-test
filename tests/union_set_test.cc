#include <gtest/gtest.h>
#include <union_set.h>

TEST(UnionSetTest, UnionSetTest) {

  vector<int> father(10);
  init(father);
  join(father, 1, 8);
  join(father, 3, 8);
  join(father, 1, 7);
  join(father, 8, 5);
  join(father, 6, 2);
  join(father, 2, 9);
  GTEST_ASSERT_EQ(1, isSameSet(father, 8, 7));
  GTEST_ASSERT_EQ(0, isSameSet(father, 7, 2));
}
