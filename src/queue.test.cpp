#include "queue.h"

#include <stdexcept>
#include <string>

#include "doctest.h"

TEST_CASE("queue.cpp test") {
  Queue<std::string> queue;
  REQUIRE(queue.isEmpty() == true);
  REQUIRE(queue.size() == 0);

  queue.enqueue("Hello");
  REQUIRE(queue.isEmpty() == false);
  REQUIRE(queue.size() == 1);

  queue.enqueue("World");
  REQUIRE(queue.size() == 2);

  auto value = queue.dequeue();
  REQUIRE(value == "Hello");
  REQUIRE(queue.size() == 1);

  value = queue.dequeue();
  REQUIRE(value == "World");
  REQUIRE(queue.isEmpty() == true);
  REQUIRE(queue.size() == 0);

  REQUIRE_THROWS_AS(queue.dequeue(), std::out_of_range);
}
