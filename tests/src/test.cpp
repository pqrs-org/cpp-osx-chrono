#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <pqrs/osx/chrono.hpp>

TEST_CASE("absolute_time_duration") {
  pqrs::osx::chrono::absolute_time_point t1(1000);
  pqrs::osx::chrono::absolute_time_point t2(2000);

  {
    auto d = t2 - t1;
    REQUIRE(d == pqrs::osx::chrono::absolute_time_duration(1000));
  }
  {
    auto d = t1 - t2;
    REQUIRE(d == pqrs::osx::chrono::absolute_time_duration(-1000));
  }
  {
    auto t = t1 + pqrs::osx::chrono::absolute_time_duration(100);
    REQUIRE(t == pqrs::osx::chrono::absolute_time_point(1100));
  }
  {
    auto t = t1 - pqrs::osx::chrono::absolute_time_duration(100);
    REQUIRE(t == pqrs::osx::chrono::absolute_time_point(900));
  }
  {
    auto t = t1;
    t += pqrs::osx::chrono::absolute_time_duration(100);
    REQUIRE(t == pqrs::osx::chrono::absolute_time_point(1100));
  }
  {
    auto t = t1;
    t -= pqrs::osx::chrono::absolute_time_duration(100);
    REQUIRE(t == pqrs::osx::chrono::absolute_time_point(900));
  }
}
