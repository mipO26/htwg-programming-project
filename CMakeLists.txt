cmake_minimum_required(VERSION 3.16)

project(MyGame C)

set(CMAKE_C_STANDARD 11)
find_package(SDL2 REQUIRED)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    src/*.c
)

add_executable(MyGame ${SOURCES})

target_include_directories(MyGame PRIVATE
    src
)

target_link_libraries(MyGame PRIVATE SDL2::SDL2)