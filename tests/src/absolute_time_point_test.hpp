#include <boost/ut.hpp>
#include <pqrs/osx/chrono.hpp>
#include <sstream>

void run_absolute_time_point_test() {
  using namespace boost::ut;
  using namespace boost::ut::literals;

  "absolute_time_point"_test = [] {
    uint64_t u64 = 13835058055282163712ull; // 2^63 + 2^62
    pqrs::osx::chrono::absolute_time_point p(u64);
    expect(type_safe::get(p) == u64);

    std::stringstream stream;
    stream << p;
    expect(stream.str() == "13835058055282163712");

    expect(std::hash<pqrs::osx::chrono::absolute_time_point>{}(p) == std::hash<uint64_t>{}(u64));
  };
}
