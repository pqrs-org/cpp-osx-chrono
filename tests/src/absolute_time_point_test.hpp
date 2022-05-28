#include <boost/ut.hpp>
#include <pqrs/osx/chrono.hpp>

void run_absolute_time_point_test(void) {
  using namespace boost::ut;
  using namespace boost::ut::literals;

  "absolute_time_point"_test = [] {
    uint64_t u64 = 13835058055282163712ull; // 2^63 + 2^62
    pqrs::osx::chrono::absolute_time_point p(u64);
    expect(type_safe::get(p) == u64);
  };
}
