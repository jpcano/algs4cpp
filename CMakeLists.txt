cmake_minimum_required(VERSION 3.10)
project(algs4cpp VERSION 0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

SET(CMAKE_CXX_FLAGS_DEBUG "-O0")
SET(CMAKE_C_FLAGS_DEBUG "-O0")

#### SortCompare CLI
add_executable(SortCompare "src/sort_compare.cpp")

#### Testing
file(GLOB_RECURSE TEST_FILES
  "${PROJECT_SOURCE_DIR}/src/*.test.cpp"
)
add_executable(DoctestTesting ${TEST_FILES})