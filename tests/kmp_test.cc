#include <gtest/gtest.h>
#include <kmp.h>

TEST(KmpTest, KmpTest) {
  GTEST_ASSERT_EQ(0, strStr("sadbutsad", "sad"));
  GTEST_ASSERT_EQ(-1, strStr("leetcode", "leeto"));
}
