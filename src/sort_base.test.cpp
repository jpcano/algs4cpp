#include "sort_base.h"

#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>

TEST_CASE("sort_base.cpp test", "[sort_base.cpp]") {
  std::vector<int> a;

  a = {0};
  REQUIRE(SortBase<int>::isSorted(a) == true);

  a = {0, 1};
  REQUIRE(SortBase<int>::isSorted(a) == true);

  a = {0, 0};
  REQUIRE(SortBase<int>::isSorted(a) == true);

  a = {1, 0};
  REQUIRE(SortBase<int>::isSorted(a) == false);

  a = {0, 1, 0};
  REQUIRE(SortBase<int>::isSorted(a) == false);
}