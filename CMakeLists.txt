cmake_minimum_required(VERSION 3.7)
project(poclmembench)

set (poclmembench_VERSION_MAJOR 0)
set (poclmembench_VERSION_MINOR 91)
 
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
include_directories("include")

SET(Boost_USE_STATIC_LIBS ON)
find_package(Boost REQUIRED COMPONENTS program_options)
include_directories( ${Boost_INCLUDE_DIRS} lib/embed-resource ${PROJECT_BINARY_DIR})

find_package(OpenCL REQUIRED)

configure_file (
  "${PROJECT_SOURCE_DIR}/include/Version.h.in"
  "${PROJECT_BINARY_DIR}/Version.h"
)

add_executable(poclmembench src/main.cpp src/OclEngine.cpp src/ProgramOptions.cpp)
target_link_libraries(poclmembench OpenCL::OpenCL Boost::program_options)
enable_testing()
add_subdirectory(test)
