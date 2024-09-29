#include <cache.h>
#include <gtest/gtest.h>

TEST(CacheTest, LRUCacheTest) {
  LRUCache lru(2);
  lru.put(1, 1);
  lru.put(2, 2);
  GTEST_ASSERT_EQ(1, lru.get(1));
  lru.put(3, 3);
  GTEST_ASSERT_EQ(-1, lru.get(2));
  lru.put(4, 4);
  GTEST_ASSERT_EQ(-1, lru.get(1));
  GTEST_ASSERT_EQ(3, lru.get(3));
  GTEST_ASSERT_EQ(4, lru.get(4));
}

TEST(CacheTest, LFUCacheTest) {
  LRUCache lfu(2);
  lfu.put(1, 1);
  lfu.put(2, 2);
  GTEST_ASSERT_EQ(1, lfu.get(1));
  lfu.put(3, 3);
  GTEST_ASSERT_EQ(-1, lfu.get(2));
  GTEST_ASSERT_EQ(3, lfu.get(3));
  lfu.put(4, 4);
  GTEST_ASSERT_EQ(-1, lfu.get(1));
  GTEST_ASSERT_EQ(3, lfu.get(3));
  GTEST_ASSERT_EQ(4, lfu.get(4));
}