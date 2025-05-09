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

  std::vector<char> b = {'s', 'o', 'r', 't', 'e', 'x', 'a', 'm', 'p', 'l', 'e'};
  REQUIRE(SelectionSort<char>::isSorted(b) == false);
  SelectionSort<char>::sort(b);
  REQUIRE(SelectionSort<char>::isSorted(b) == true);
  std::vector<char> expected = {'a', 'e', 'e', 'l', 'm', 'o',
                                'p', 'r', 's', 't', 'x'};
  REQUIRE(b == expected);
}