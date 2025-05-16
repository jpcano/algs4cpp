#include "sort_selection.h"

#include "doctest.h"
#include "sort_test_utils.h"

TEST_CASE("sort_selection.cpp test") {
  sortIntTest<SelectionSort<int>>();
  sortCharTest<SelectionSort<char>>();
  sortRandomDoubleTest<SelectionSort<double>>();
}