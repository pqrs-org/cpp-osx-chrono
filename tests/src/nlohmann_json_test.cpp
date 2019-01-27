#include <catch2/catch.hpp>

#include <iostream>
#include <pqrs/osx/chrono/extra/nlohmann_json.hpp>

TEST_CASE("absolute_time_point json") {
  {
    uint64_t u64 = 13835058055282163712ull; // 2^63 + 2^62
    pqrs::osx::chrono::absolute_time_point p1(u64);
    nlohmann::json json = p1;
    pqrs::osx::chrono::absolute_time_point p2 = json;
    REQUIRE(p1 == p2);
    REQUIRE(json.dump() == "13835058055282163712");
  }
}

TEST_CASE("absolute_time_duration json") {
  {
    int64_t i64 = 6917529027641081856ll; // 2^62 + 2^61
    pqrs::osx::chrono::absolute_time_duration d1(i64);
    nlohmann::json json = d1;
    pqrs::osx::chrono::absolute_time_duration d2 = json;
    REQUIRE(d1 == d2);
    REQUIRE(json.dump() == "6917529027641081856");
  }

  {
    int64_t i64 = -6917529027641081856ll; // -(2^62 + 2^61)
    pqrs::osx::chrono::absolute_time_duration d1(i64);
    nlohmann::json json = d1;
    pqrs::osx::chrono::absolute_time_duration d2 = json;
    REQUIRE(d1 == d2);
    REQUIRE(json.dump() == "-6917529027641081856");
  }
}
