#pragma once
#include <iostream>
#include <vector>

template <typename T>
class SortBase {
 protected:
  static bool less(T v, T w) { return v < w; }
  static void exch(std::vector<T>& a, int i, int j) {
    T t = a[i];
    a[i] = a[j];
    a[j] = t;
  }

 public:
  static void show(const std::vector<T>& a) {
    for (int i = 0; i < a.size(); i++) std::cout << a[i] << " ";
    std::cout << std::endl;
  }
  static bool isSorted(const std::vector<T>& a) {
    for (int i = 1; i < a.size(); i++)
      if (less(a[i], a[i - 1])) return false;
    return true;
  }
};