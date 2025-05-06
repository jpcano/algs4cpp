#include "queue.h"

#include <catch2/catch_test_macros.hpp>
#include <stdexcept>
#include <string>

TEST_CASE("queue.cpp test", "[queue.cpp]") {
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
