// binary_search_test.cc
#include <binary_search.h>
#include <gtest/gtest.h>

TEST(BianrySearchTest, binary_search) {
  vector<int> temp{2, 5, 8, 12, 12, 12, 12, 56, 59, 63, 85};
  GTEST_ASSERT_EQ(1, binary(temp, 5));
  GTEST_ASSERT_EQ(5, binary(temp, 12));
  GTEST_ASSERT_EQ(7, binary(temp, 56));
  GTEST_ASSERT_EQ(8, binary(temp, 59));
  GTEST_ASSERT_EQ(9, binary(temp, 63));
  GTEST_ASSERT_EQ(10, binary(temp, 85));
  GTEST_ASSERT_EQ(-1, binary(temp, 0));
  GTEST_ASSERT_EQ(3, binaryLeft(temp, 12));
  GTEST_ASSERT_EQ(6, binaryRight(temp, 12));
}
