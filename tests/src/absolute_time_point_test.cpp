#include <catch2/catch.hpp>

#include <pqrs/osx/chrono.hpp>

TEST_CASE("absolute_time_point") {
  uint64_t u64 = 13835058055282163712ull; // 2^63 + 2^62
  pqrs::osx::chrono::absolute_time_point p(u64);
  REQUIRE(type_safe::get(p) == u64);
}
