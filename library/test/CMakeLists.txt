# test

add_executable(test_mine
    test_basic.cpp
)
target_link_libraries(test_mine mine::mine GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(test_mine)
