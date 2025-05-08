#include "bag.h"

#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>

TEST_CASE("bag.cpp test", "[bag.cpp]") {
  Bag<std::string> bag;
  std::vector<std::string> bag_content;

  bag.add("Hello");
  bag.add("World");
  for (auto item : bag) bag_content.push_back(item);

  std::vector<std::string> expected = {"World", "Hello"};
  REQUIRE(bag_content == expected);
}
