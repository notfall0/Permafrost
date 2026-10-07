cmake_minimum_required(VERSION 3.20)
project(Permafrost VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS NO)

set(VENDOR_DIR ${CMAKE_CURRENT_SOURCE_DIR}/vendor)

include(dependencies.cmake)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(permafrost)
