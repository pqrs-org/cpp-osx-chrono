#include <catch2/catch.hpp>

#include <iostream>
#include <pqrs/osx/chrono/extra/nlohmann_json.hpp>

TEST_CASE("absolute_time_point json") {
  {
    uint64_t u64 = 13835058055282163712ull; // 2^63 + 2^62
    pqrs::osx::chrono::absolute_time_point p1(u64);
    nlohmann::json json = p1;
    auto p2 = json.get<pqrs::osx::chrono::absolute_time_point>();
    REQUIRE(p1 == p2);
    REQUIRE(json.dump() == "13835058055282163712");
  }

  {
    nlohmann::json json = 12.2;
    auto p = json.get<pqrs::osx::chrono::absolute_time_point>();
    REQUIRE(p == pqrs::osx::chrono::absolute_time_point(12));
  }

  REQUIRE_THROWS_AS(
      nlohmann::json().get<pqrs::osx::chrono::absolute_time_point>(),
      pqrs::json::unmarshal_error);
  REQUIRE_THROWS_WITH(
      nlohmann::json().get<pqrs::osx::chrono::absolute_time_point>(),
      "json must be number, but is `null`");
  REQUIRE_THROWS_WITH(
      nlohmann::json(true).get<pqrs::osx::chrono::absolute_time_point>(),
      "json must be number, but is `true`");
  REQUIRE_THROWS_WITH(
      nlohmann::json::object().get<pqrs::osx::chrono::absolute_time_point>(),
      "json must be number, but is `{}`");
  REQUIRE_THROWS_WITH(
      nlohmann::json::array().get<pqrs::osx::chrono::absolute_time_point>(),
      "json must be number, but is `[]`");
  REQUIRE_THROWS_WITH(
      nlohmann::json("1234").get<pqrs::osx::chrono::absolute_time_point>(),
      "json must be number, but is `\"1234\"`");
}

TEST_CASE("absolute_time_duration json") {
  {
    int64_t i64 = 6917529027641081856ll; // 2^62 + 2^61
    pqrs::osx::chrono::absolute_time_duration d1(i64);
    nlohmann::json json = d1;
    auto d2 = json.get<pqrs::osx::chrono::absolute_time_duration>();
    REQUIRE(d1 == d2);
    REQUIRE(json.dump() == "6917529027641081856");
  }

  {
    nlohmann::json json = 12.2;
    auto p = json.get<pqrs::osx::chrono::absolute_time_duration>();
    REQUIRE(p == pqrs::osx::chrono::absolute_time_duration(12));
  }

  {
    int64_t i64 = -6917529027641081856ll; // -(2^62 + 2^61)
    pqrs::osx::chrono::absolute_time_duration d1(i64);
    nlohmann::json json = d1;
    auto d2 = json.get<pqrs::osx::chrono::absolute_time_duration>();
    REQUIRE(d1 == d2);
    REQUIRE(json.dump() == "-6917529027641081856");
  }

  REQUIRE_THROWS_AS(
      nlohmann::json().get<pqrs::osx::chrono::absolute_time_duration>(),
      pqrs::json::unmarshal_error);
  REQUIRE_THROWS_WITH(
      nlohmann::json().get<pqrs::osx::chrono::absolute_time_duration>(),
      "json must be number, but is `null`");
  REQUIRE_THROWS_WITH(
      nlohmann::json(true).get<pqrs::osx::chrono::absolute_time_duration>(),
      "json must be number, but is `true`");
  REQUIRE_THROWS_WITH(
      nlohmann::json::object().get<pqrs::osx::chrono::absolute_time_duration>(),
      "json must be number, but is `{}`");
  REQUIRE_THROWS_WITH(
      nlohmann::json::array().get<pqrs::osx::chrono::absolute_time_duration>(),
      "json must be number, but is `[]`");
  REQUIRE_THROWS_WITH(
      nlohmann::json("1234").get<pqrs::osx::chrono::absolute_time_duration>(),
      "json must be number, but is `\"1234\"`");
}
