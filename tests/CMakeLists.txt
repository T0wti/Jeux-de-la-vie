include_directories(${CMAKE_SOURCE_DIR})
# Add here all the files needed
add_executable(tests )

# Link Google Test and the main code
target_link_libraries(tests gtest gtest_main)

# Enable the tests
include(GoogleTest)
gtest_discover_tests(tests)
