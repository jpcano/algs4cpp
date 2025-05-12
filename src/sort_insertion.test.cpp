#include "sort_insertion.h"

#include <catch2/catch_test_macros.hpp>

#include "sort_test_utils.h"

TEST_CASE("sort_insertion.cpp test", "[sort_insertion.cpp]") {
  sortIntTest<InsertionSort<int>>();
  sortCharTest<InsertionSort<char>>();
  sortRandomDoubleTest<InsertionSort<double>>();
}