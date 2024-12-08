cmake_minimum_required(VERSION 3.29)
project(Jeux-de-la-vie)

include(FetchContent)
set(BUILD_SHARED_LIBS OFF)
FetchContent_Declare(
        SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.2
)
FetchContent_MakeAvailable(SFML)

FetchContent_Declare(
        GoogleTest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.15.2
)
FetchContent_MakeAvailable(GoogleTest)

set(CMAKE_CXX_STANDARD 20)

add_executable(Jeux-de-la-vie
        main.cpp
        Cell.cpp
        Cell.h
        Grid.h
        Grid.cpp
        Rules.cpp
        Rules.h
        File_manager.cpp
        File_manager.h
        Game.cpp
        Game.h
)

target_link_libraries(Jeux-de-la-vie sfml-graphics sfml-window sfml-system)

add_subdirectory(tests)