PROJECT(camera_basler)
cmake_minimum_required(VERSION 2.6)

find_package(Rock)
if (ROCK_USE_CXX11)
    rock_activate_cxx11()
endif()

include_directories($ENV{PYLON_ROOT}/include)
link_directories($ENV{PYLON_ROOT}/lib64)

SET (CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/.orogen/config")
INCLUDE(camera_baslerBase)

