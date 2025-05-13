#include <catch2/catch_test_macros.hpp>

#include "sort_shellshort.h"
#include "sort_test_utils.h"

TEST_CASE("sort_shellsort.cpp test", "[sort_shellsort.cpp]") {
  sortIntTest<Shellsort<int>>();
  sortCharTest<Shellsort<char>>();
  sortRandomDoubleTest<Shellsort<double>>();
}