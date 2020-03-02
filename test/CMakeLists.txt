project(Queue-CPP-2020_test)

add_executable(Queue-CPP-2020_test testMain.cpp queueTest.cpp)
target_link_libraries(Queue-CPP-2020_test gtest gtest_main pthread)
