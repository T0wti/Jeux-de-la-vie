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

set(CMAKE_CXX_STANDARD 20)

add_executable(Jeux-de-la-vie main.cpp
       Cell.cpp
        Cell.h
        Grid.h
        Grid.cpp
        Rules.cpp
        Rules.h
        Save.cpp
        Save.h
)

target_link_libraries(Jeux-de-la-vie sfml-graphics)
