cmake_minimum_required(VERSION 3.16)
project(Jukebox)

set(CMAKE_CXX_STANDARD 20)

find_package(raylib REQUIRED)

add_executable(Jukebox
    src/main.cpp
    src/AssetManager.cpp
)

file(COPY ${CMAKE_SOURCE_DIR}/assets DESTINATION ${CMAKE_BINARY_DIR})
target_include_directories(Jukebox PRIVATE ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(Jukebox raylib)