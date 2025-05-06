cmake_minimum_required(VERSION 3.10)
project(algs4cpp VERSION 0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


### Tests

Include(FetchContent)
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.8.1
)
FetchContent_MakeAvailable(Catch2)
file(GLOB_RECURSE TEST_FILES
  "${PROJECT_SOURCE_DIR}/src/*.test.cpp"
)
add_executable(tests ${TEST_FILES})
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)

