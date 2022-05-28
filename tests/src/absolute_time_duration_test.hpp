#include <boost/ut.hpp>
#include <pqrs/osx/chrono.hpp>

void run_absolute_time_duration_test(void) {
  using namespace boost::ut;
  using namespace boost::ut::literals;

  "absolute_time_duration"_test = [] {
    {
      int64_t i64 = 6917529027641081856; // 2^62 + 2^61
      pqrs::osx::chrono::absolute_time_duration d(i64);
      expect(type_safe::get(d) == i64);
    }
    {
      int64_t i64 = -6917529027641081856; // -(2^62 + 2^61)
      pqrs::osx::chrono::absolute_time_duration d(i64);
      expect(type_safe::get(d) == i64);
    }

    {
      pqrs::osx::chrono::absolute_time_point p1(1000);
      pqrs::osx::chrono::absolute_time_point p2(2000);

      {
        auto d = p2 - p1;
        expect(d == pqrs::osx::chrono::absolute_time_duration(1000));
      }
      {
        auto d = p1 - p2;
        expect(d == pqrs::osx::chrono::absolute_time_duration(-1000));
      }
      {
        auto t = p1 + pqrs::osx::chrono::absolute_time_duration(100);
        expect(t == pqrs::osx::chrono::absolute_time_point(1100));
      }
      {
        auto t = p1 - pqrs::osx::chrono::absolute_time_duration(100);
        expect(t == pqrs::osx::chrono::absolute_time_point(900));
      }
      {
        auto t = p1;
        t += pqrs::osx::chrono::absolute_time_duration(100);
        expect(t == pqrs::osx::chrono::absolute_time_point(1100));
      }
      {
        auto t = p1;
        t -= pqrs::osx::chrono::absolute_time_duration(100);
        expect(t == pqrs::osx::chrono::absolute_time_point(900));
      }
    }
  };
}
