#include <gtest/gtest.h>
#include <single_stack.h>

TEST(KmpTest, KmpTest) {
  vector<int> height{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  vector<int> height1{2, 1, 5, 6, 2, 3};
  GTEST_ASSERT_EQ(6, trap(height));
  GTEST_ASSERT_EQ(10, largestRectangleArea(height1));
}
