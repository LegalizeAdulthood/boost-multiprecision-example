include(GoogleTest)

find_package(GTest CONFIG REQUIRED)

add_executable(test-deep-zoom
    args_test.cpp)
target_link_libraries(test-deep-zoom PUBLIC deep-zoom GTest::gtest_main)
target_folder(test-deep-zoom "Tests")
gtest_discover_tests(test-deep-zoom)
