cmake_minimum_required(VERSION 3.16)
project(pluto LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_PREFIX_PATH /usr/local)

add_executable(pluto
    main.cpp
    world.cpp
)

find_package(SFML 3 REQUIRED COMPONENTS Graphics Window System)

target_link_libraries(pluto PRIVATE SFML::Graphics SFML::Window SFML::System)

target_include_directories(pluto PRIVATE .)
