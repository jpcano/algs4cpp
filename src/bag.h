#include <stdexcept>

template <typename T>
class Bag {
 public:
  Bag() : first(nullptr) {}
  ~Bag() {
    while (first != nullptr) {
      auto oldfirst = first;
      first = first->next;
      delete oldfirst;
    }
  }
  void add(T item) {
    auto oldfirst = first;
    first = new Node(item);
    first->item = item;
    first->next = oldfirst;
  }

 private:
  class Node {
   public:
    T item;
    Node* next;
    Node(T item) : item(item), next(nullptr) {}
  };
  Node* first;
};