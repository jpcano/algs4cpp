#pragma once
#include <bits/stdc++.h>

#include <vector>

#include "doctest.h"

template <typename SortClass>
void sortRandomDoubleTest() {
  int N = 100;
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<> dis(0.0, 1.0);

  // Create a vector of N random doubles
  std::vector<double> a(N);
  for (int j = 0; j < N; j++) a[j] = dis(gen);
  // Copy the vector to b for the second sort
  std::vector<double> b = a;
  REQUIRE(a == b);
  // Sort b using the custom sort class
  SortClass::sort(b);
  REQUIRE(a != b);
  // Sort a vector using STL sort
  std::sort(a.begin(), a.end(), [](double a, double b) { return a < b; });
  REQUIRE(a == b);
}

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