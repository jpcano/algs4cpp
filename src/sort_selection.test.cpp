#include "sort_selection.h"

#include <catch2/catch_test_macros.hpp>

#include "sort_test_utils.h"

TEST_CASE("sort_selection.cpp test", "[sort_selection.cpp]") {
  sortIntTest<SelectionSort<int>>();
  sortCharTest<SelectionSort<char>>();
}