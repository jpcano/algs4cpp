#include <memory>
#include <stdexcept>

template <typename T>
class Stack {
 public:
  Stack() : first(nullptr), N(0) {}

  bool isEmpty() { return first == nullptr; }
  int size() { return N; }
  void push(T item) {
    auto oldfirst = first;
    first = std::make_shared<Node>(item);
    first->item = item;
    first->next = oldfirst;
    N++;
  }
  T pop() {
    if (isEmpty()) {
      throw std::out_of_range("Stack underflow");
    }
    T item = first->item;
    first = first->next;
    N--;
    return item;
  }

 private:
  class Node {
   public:
    T item;
    std::shared_ptr<Node> next;
    Node(T item) : item(item), next(nullptr) {}
  };
  std::shared_ptr<Node> first;
  int N;
};