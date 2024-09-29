#include <bag.h>
#include <gtest/gtest.h>

TEST(BagTest, BagTest) {

  vector<int> weight = {1, 3, 4};
  vector<int> value = {15, 20, 30};
  int bagWeight = 4;
  GTEST_ASSERT_EQ(35, bag1(weight, value, bagWeight));
  GTEST_ASSERT_EQ(35, bag2(weight, value, bagWeight));
  GTEST_ASSERT_EQ(35, bag3(weight, value, bagWeight));
}
