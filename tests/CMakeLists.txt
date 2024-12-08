# Ajouter les sources de test
add_executable(tests test_Cell.cpp)

# Lier Google Test et ton projet principal
target_link_libraries(tests gtest gtest_main)

# Activer les tests
include(GoogleTest)
gtest_discover_tests(tests)
