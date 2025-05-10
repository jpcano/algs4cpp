#include <catch2/catch_test_macros.hpp>
#include <vector>

template <typename SortClass>
void sortIntTest() {
  std::vector<int> a;

  a = {0};
  REQUIRE(SortClass::isSorted(a) == true);
  SortClass::sort(a);
  REQUIRE(SortClass::isSorted(a) == true);

  a = {1, 0};
  REQUIRE(SortClass::isSorted(a) == false);
  SortClass::sort(a);
  REQUIRE(SortClass::isSorted(a) == true);

  a = {1, 0, 0, 1};
  REQUIRE(SortClass::isSorted(a) == false);
  SortClass::sort(a);
  REQUIRE(SortClass::isSorted(a) == true);
}

template <typename SortClass>
void sortCharTest() {
  std::vector<char> b = {'s', 'o', 'r', 't', 'e', 'x', 'a', 'm', 'p', 'l', 'e'};
  REQUIRE(SortClass::isSorted(b) == false);
  SortClass::sort(b);
  REQUIRE(SortClass::isSorted(b) == true);
  std::vector<char> expected = {'a', 'e', 'e', 'l', 'm', 'o',
                                'p', 'r', 's', 't', 'x'};
  REQUIRE(b == expected);
}