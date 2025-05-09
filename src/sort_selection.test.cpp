#include "sort_selection.h"

#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>

TEST_CASE("sort_selection.cpp test", "[sort_selection.cpp]") {
  std::vector<int> a;

  a = {0};
  REQUIRE(SelectionSort<int>::isSorted(a) == true);
  SelectionSort<int>::sort(a);
  REQUIRE(SelectionSort<int>::isSorted(a) == true);

  a = {1, 0};
  REQUIRE(SelectionSort<int>::isSorted(a) == false);
  SelectionSort<int>::sort(a);
  REQUIRE(SelectionSort<int>::isSorted(a) == true);

  a = {1, 0, 0, 1};
  REQUIRE(SelectionSort<int>::isSorted(a) == false);
  SelectionSort<int>::sort(a);
  REQUIRE(SelectionSort<int>::isSorted(a) == true);
}