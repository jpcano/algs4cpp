#include <stdexcept>

template <typename T>
class Stack {
 public:
  Stack() : first(nullptr), N(0) {}
  ~Stack() {
    while (!isEmpty()) pop();
  }

  bool isEmpty() { return first == nullptr; }
  int size() { return N; }
  void push(T item) {
    auto oldfirst = first;
    first = new Node(item);
    first->item = item;
    first->next = oldfirst;
    N++;
  }
  T pop() {
    if (isEmpty()) {
      throw std::out_of_range("Stack underflow");
    }
    auto oldfirst = first;
    T item = first->item;
    first = first->next;
    delete oldfirst;
    N--;
    return item;
  }

 private:
  class Node {
   public:
    T item;
    Node* next;
    Node(T item) : item(item), next(nullptr) {}
  };
  Node* first;
  int N;
};