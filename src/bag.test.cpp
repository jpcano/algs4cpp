#include "bag.h"

#include <string>
#include <vector>

#include "doctest.h"

TEST_CASE("bag.cpp test") {
  Bag<std::string> bag;
  std::vector<std::string> bag_content;

  bag.add("Hello");
  bag.add("World");
  for (auto item : bag) bag_content.push_back(item);

  std::vector<std::string> expected = {"World", "Hello"};
  REQUIRE(bag_content == expected);
}
