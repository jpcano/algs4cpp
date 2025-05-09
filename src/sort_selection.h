#include <vector>

#include "sort_base.h"

template <typename T>
class SelectionSort : public SortBase<T> {
 public:
  static void sort(std::vector<T>& a) {
    int N = a.size();
    for (int i = 0; i < N; i++) {
      int min = i;
      for (int j = i + 1; j < N; j++)
        if (SortBase<T>::less(a[j], a[min])) min = j;
      SortBase<T>::exch(a, i, min);
    }
  }
};