#include <stdexcept>

template <typename T>
class Bag {
 private:
  class Node {
   public:
    T item;
    Node* next;
    Node(T item) : item(item), next(nullptr) {}
  };

  Node* first;

  class IteratorBag {
   public:
    using iterator_category = std::forward_iterator_tag;
    using difference_type = std::ptrdiff_t;
    using value_type = Node;
    using pointer = Node*;
    using reference = Node&;

    IteratorBag(Node* ptr) : m_ptr(ptr) {}

    T& operator*() const { return m_ptr->item; }
    pointer operator->() { return m_ptr; }
    IteratorBag& operator++() {
      m_ptr = m_ptr->next;
      return *this;
    }
    IteratorBag operator++(int) {
      IteratorBag tmp = *this;
      ++(*this);
      return tmp;
    }
    friend bool operator==(const IteratorBag& a, const IteratorBag& b) {
      return a.m_ptr == b.m_ptr;
    };
    friend bool operator!=(const IteratorBag& a, const IteratorBag& b) {
      return a.m_ptr != b.m_ptr;
    };

   private:
    Node* m_ptr;
  };

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

  IteratorBag begin() { return IteratorBag(first); }
  IteratorBag end() { return IteratorBag(nullptr); }
};