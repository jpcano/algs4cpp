#include <stdexcept>

template <typename T>
class Queue {
 public:
  Queue() : first(nullptr), last(nullptr), N(0) {}
  ~Queue() {
    while (!isEmpty()) dequeue();
  }

  bool isEmpty() { return first == nullptr; }
  int size() { return N; }
  void enqueue(T item) {
    auto oldlast = last;
    last = new Node(item);
    last->item = item;
    last->next = nullptr;
    if (isEmpty())
      first = last;
    else
      oldlast->next = last;
    N++;
  }
  T dequeue() {
    if (isEmpty()) {
      throw std::out_of_range("Queue underflow");
    }
    auto oldfirst = first;
    T item = first->item;
    first = first->next;
    delete oldfirst;
    N--;
    if (isEmpty()) last = nullptr;
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
  Node* last;
  int N;
};