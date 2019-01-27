#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <pqrs/osx/chrono.hpp>

TEST_CASE("absolute_time_point") {
  uint64_t u64 = 13835058055282163712ull; // 2^63 + 2^62
  pqrs::osx::chrono::absolute_time_point p(u64);
  REQUIRE(type_safe::get(p) == u64);
}

TEST_CASE("absolute_time_duration") {
  {
    int64_t i64 = 6917529027641081856; // 2^62 + 2^61
    pqrs::osx::chrono::absolute_time_duration d(i64);
    REQUIRE(type_safe::get(d) == i64);
  }
  {
    int64_t i64 = -6917529027641081856; // -(2^62 + 2^61)
    pqrs::osx::chrono::absolute_time_duration d(i64);
    REQUIRE(type_safe::get(d) == i64);
  }

  {
    pqrs::osx::chrono::absolute_time_point p1(1000);
    pqrs::osx::chrono::absolute_time_point p2(2000);

    {
      auto d = p2 - p1;
      REQUIRE(d == pqrs::osx::chrono::absolute_time_duration(1000));
    }
    {
      auto d = p1 - p2;
      REQUIRE(d == pqrs::osx::chrono::absolute_time_duration(-1000));
    }
    {
      auto t = p1 + pqrs::osx::chrono::absolute_time_duration(100);
      REQUIRE(t == pqrs::osx::chrono::absolute_time_point(1100));
    }
    {
      auto t = p1 - pqrs::osx::chrono::absolute_time_duration(100);
      REQUIRE(t == pqrs::osx::chrono::absolute_time_point(900));
    }
    {
      auto t = p1;
      t += pqrs::osx::chrono::absolute_time_duration(100);
      REQUIRE(t == pqrs::osx::chrono::absolute_time_point(1100));
    }
    {
      auto t = p1;
      t -= pqrs::osx::chrono::absolute_time_duration(100);
      REQUIRE(t == pqrs::osx::chrono::absolute_time_point(900));
    }
  }
}
