#include <catch2/catch.hpp>
#include <iostream>
#include <pqrs/osx/chrono.hpp>

TEST_CASE("make_absolute_time_duration") {
  {
    std::chrono::nanoseconds ns(256 * 1000000);
    auto absolute_time_duration = pqrs::osx::chrono::make_absolute_time_duration(ns);
    REQUIRE(pqrs::osx::chrono::make_milliseconds(absolute_time_duration) == std::chrono::milliseconds(256));
  }

  {
    std::chrono::milliseconds ms(256 * 1000000);
    auto absolute_time_duration = pqrs::osx::chrono::make_absolute_time_duration(ms);
    REQUIRE(pqrs::osx::chrono::make_milliseconds(absolute_time_duration) == ms);
  }
}

TEST_CASE("make_nanoseconds") {
  {
    pqrs::osx::chrono::absolute_time_duration absolute_time_duration(256 * 1000000);
    auto ns = pqrs::osx::chrono::make_nanoseconds(absolute_time_duration);
    REQUIRE(std::abs(type_safe::get(pqrs::osx::chrono::make_absolute_time_duration(ns) - absolute_time_duration)) < 1000);
  }
}

TEST_CASE("make_milliseconds") {
  {
    pqrs::osx::chrono::absolute_time_duration absolute_time_duration(256 * 1000000);
    auto ms = pqrs::osx::chrono::make_milliseconds(absolute_time_duration);
    REQUIRE(std::abs(type_safe::get(pqrs::osx::chrono::make_absolute_time_duration(ms) - absolute_time_duration)) < 1000000);
  }
}
