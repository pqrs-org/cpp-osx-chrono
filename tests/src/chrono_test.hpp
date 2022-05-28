#include <boost/ut.hpp>
#include <iostream>
#include <pqrs/osx/chrono.hpp>

void run_chrono_test(void) {
  using namespace boost::ut;
  using namespace boost::ut::literals;

  "make_absolute_time_duration"_test = [] {
    {
      std::chrono::nanoseconds ns(256 * 1000000);
      auto absolute_time_duration = pqrs::osx::chrono::make_absolute_time_duration(ns);
      expect(pqrs::osx::chrono::make_milliseconds(absolute_time_duration) == std::chrono::milliseconds(256));
    }

    {
      std::chrono::milliseconds ms(256 * 1000000);
      auto absolute_time_duration = pqrs::osx::chrono::make_absolute_time_duration(ms);
      expect(pqrs::osx::chrono::make_milliseconds(absolute_time_duration) == ms);
    }
  };

  "make_nanoseconds"_test = [] {
    {
      pqrs::osx::chrono::absolute_time_duration absolute_time_duration(256 * 1000000);
      auto ns = pqrs::osx::chrono::make_nanoseconds(absolute_time_duration);
      expect(std::abs(type_safe::get(pqrs::osx::chrono::make_absolute_time_duration(ns) - absolute_time_duration)) < 1000);
    }
  };

  "make_milliseconds"_test = [] {
    {
      pqrs::osx::chrono::absolute_time_duration absolute_time_duration(256 * 1000000);
      auto ms = pqrs::osx::chrono::make_milliseconds(absolute_time_duration);
      expect(std::abs(type_safe::get(pqrs::osx::chrono::make_absolute_time_duration(ms) - absolute_time_duration)) < 1000000);
    }
  };
}
