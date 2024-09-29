#include <gtest/gtest.h>
#include <sort.h>

TEST(SortTest, SortTest) {

  vector<int> weight = {1, 3, 4};
  vector<int> value = {15, 20, 30};
  int bagWeight = 4;
  GTEST_ASSERT_EQ(1, compare(insert_sort, heap_sort, 10000));
  GTEST_ASSERT_EQ(1, compare(insert_sort, quick_sort, 10000));
  GTEST_ASSERT_EQ(1, compare(insert_sort, merge_sort, 10000));
}