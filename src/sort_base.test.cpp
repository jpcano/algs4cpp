#include "sort_base.h"

#include <string>
#include <vector>

#include "doctest.h"

TEST_CASE("sort_base.cpp test") {
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