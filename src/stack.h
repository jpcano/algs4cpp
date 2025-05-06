#include <memory>
#include <stdexcept>

template <typename T>
class Stack {
 public:
  Stack() : first(nullptr), N(0) {}

  bool isEmpty() { return N == 0; }
  int size() { return N; }
  void push(T value) {
    auto newNode = std::make_shared<Node>(value);
    newNode->next = first;
    first = newNode;
    N++;
  }
  T pop() {
    if (isEmpty()) {
      throw std::out_of_range("Stack is empty");
    }
    auto temp = first;
    T value = first->data;
    first = first->next;
    N--;
    return value;
  }

 private:
  class Node {
   public:
    T data;
    std::shared_ptr<Node> next;
    Node(T value) : data(value), next(nullptr) {}
  };
  std::shared_ptr<Node> first;
  int N;
};