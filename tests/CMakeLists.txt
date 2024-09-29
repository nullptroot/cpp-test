find_package(GTest REQUIRED)

add_executable(binary_search_test binary_search_test.cc)
target_link_libraries(binary_search_test binary_search ${GTEST_BOTH_LIBRARIES})

add_test(
    NAME binary_search_test
    COMMAND binary_search_test
)

add_executable(cache_test cache_test.cc)
target_link_libraries(cache_test cache ${GTEST_BOTH_LIBRARIES})

add_test(
    NAME cache_test
    COMMAND cache_test
)

add_executable(bag_test bag_test.cc)
target_link_libraries(bag_test bag ${GTEST_BOTH_LIBRARIES})

add_test(
    NAME bag_test
    COMMAND bag_test
)

add_executable(kmp_test kmp_test.cc)
target_link_libraries(kmp_test kmp ${GTEST_BOTH_LIBRARIES})

add_test(
    NAME kmp_test
    COMMAND kmp_test
)

add_executable(single_stack_test single_stack_test.cc)
target_link_libraries(single_stack_test single_stack ${GTEST_BOTH_LIBRARIES})

add_test(
    NAME single_stack_test
    COMMAND single_stack_test
)

add_executable(union_set_test union_set_test.cc)
target_link_libraries(union_set_test union_set ${GTEST_BOTH_LIBRARIES})

add_test(
    NAME union_set_test
    COMMAND union_set_test
)

add_executable(sort_test sort_test.cc)
target_link_libraries(sort_test sort ${GTEST_BOTH_LIBRARIES})

add_test(
    NAME sort_test
    COMMAND sort_test
)

add_executable(prefix_tree_test prefix_tree_test.cc)
target_link_libraries(prefix_tree_test prefix_tree ${GTEST_BOTH_LIBRARIES})

add_test(
    NAME prefix_tree_test
    COMMAND prefix_tree_test
)

add_executable(tree_order_test tree_order_test.cc)
target_link_libraries(tree_order_test tree_order ${GTEST_BOTH_LIBRARIES})

add_test(
    NAME tree_order_test
    COMMAND tree_order_test
)