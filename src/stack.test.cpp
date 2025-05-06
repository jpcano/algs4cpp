#include "stack.h"

#include <catch2/catch_test_macros.hpp>
#include <stdexcept>
#include <string>

TEST_CASE("stack.cpp test", "[stack.cpp]") {
  Stack<std::string> stack;
  REQUIRE(stack.isEmpty() == true);
  REQUIRE(stack.size() == 0);

  stack.push("Hello");
  REQUIRE(stack.isEmpty() == false);
  REQUIRE(stack.size() == 1);

  stack.push("World");
  REQUIRE(stack.size() == 2);

  auto value = stack.pop();
  REQUIRE(value == "World");
  REQUIRE(stack.size() == 1);

  value = stack.pop();
  REQUIRE(value == "Hello");
  REQUIRE(stack.isEmpty() == true);
  REQUIRE(stack.size() == 0);

  REQUIRE_THROWS_AS(stack.pop(), std::out_of_range);
}
