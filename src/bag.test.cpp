#include "bag.h"

#include <catch2/catch_test_macros.hpp>
#include <stdexcept>
#include <string>

TEST_CASE("bag.cpp test", "[bag.cpp]") {
  Bag<std::string> bag;
  bag.add("Hello");
}
