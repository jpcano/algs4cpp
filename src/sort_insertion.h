#include <vector>

#include "sort_base.h"

template <typename T>
class InsertionSort : public SortBase<T> {
 public:
  static void sort(std::vector<T>& a) {
    int N = a.size();
    for (int i = 0; i < N; i++)
      for (int j = i; j > 0 && SortBase<T>::less(a[j], a[j - 1]); j--)
        SortBase<T>::exch(a, j, j - 1);
  }
};