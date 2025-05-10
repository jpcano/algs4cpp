#include "sort_insertion.h"

#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>

TEST_CASE("sort_insertion.cpp test", "[sort_insertion.cpp]") {
  std::vector<int> a;

  a = {0};
  REQUIRE(InsertionSort<int>::isSorted(a) == true);
  InsertionSort<int>::sort(a);
  REQUIRE(InsertionSort<int>::isSorted(a) == true);

  a = {1, 0};
  REQUIRE(InsertionSort<int>::isSorted(a) == false);
  InsertionSort<int>::sort(a);
  REQUIRE(InsertionSort<int>::isSorted(a) == true);

  a = {1, 0, 0, 1};
  REQUIRE(InsertionSort<int>::isSorted(a) == false);
  InsertionSort<int>::sort(a);
  REQUIRE(InsertionSort<int>::isSorted(a) == true);

  std::vector<char> b = {'s', 'o', 'r', 't', 'e', 'x', 'a', 'm', 'p', 'l', 'e'};
  REQUIRE(InsertionSort<char>::isSorted(b) == false);
  InsertionSort<char>::sort(b);
  REQUIRE(InsertionSort<char>::isSorted(b) == true);
  std::vector<char> expected = {'a', 'e', 'e', 'l', 'm', 'o',
                                'p', 'r', 's', 't', 'x'};
  REQUIRE(b == expected);
}