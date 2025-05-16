#include "sort_shellshort.h"
#include "sort_test_utils.h"

TEST_CASE("sort_shellsort.cpp test") {
  sortIntTest<Shellsort<int>>();
  sortCharTest<Shellsort<char>>();
  sortRandomDoubleTest<Shellsort<double>>();
}