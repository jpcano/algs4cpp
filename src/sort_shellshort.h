#include <vector>

#include "sort_base.h"

template <typename T>
class Shellsort : public SortBase<T> {
 public:
  static void sort(std::vector<T>& a) {
    int N = a.size();
    int h = 1;
    while (h < N / 3) h = 3 * h + 1;
    while (h >= 1) {
      for (int i = h; i < N; i++) {
        for (int j = i; j >= h && SortBase<T>::less(a[j], a[j - h]); j -= h)
          SortBase<T>::exch(a, j, j - h);
      }
      h = h / 3;
    }
  }
};