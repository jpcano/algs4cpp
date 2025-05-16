#include "sort_insertion.h"

#include "doctest.h"
#include "sort_test_utils.h"

TEST_CASE("sort_insertion.cpp test") {
  sortIntTest<InsertionSort<int>>();
  sortCharTest<InsertionSort<char>>();
  sortRandomDoubleTest<InsertionSort<double>>();
}