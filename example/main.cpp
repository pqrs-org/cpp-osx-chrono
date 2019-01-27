#include <iostream>
#include <pqrs/osx/chrono.hpp>
#include <thread>

int main(void) {
  auto absolute_time_point1 = pqrs::osx::chrono::mach_absolute_time_point();

  std::this_thread::sleep_for(std::chrono::milliseconds(100));

  auto absolute_time_point2 = pqrs::osx::chrono::mach_absolute_time_point();

  auto absolute_time_duration = absolute_time_point2 - absolute_time_point1;

  std::cout << "absolute_time_point1 "
            << absolute_time_point1
            << std::endl;
  std::cout << "absolute_time_duration "
            << absolute_time_duration
            << std::endl;
  std::cout << "absolute_time_duration (ns) "
            << pqrs::osx::chrono::make_nanoseconds(absolute_time_duration).count()
            << std::endl;
  std::cout << "absolute_time_duration (ms) "
            << pqrs::osx::chrono::make_milliseconds(absolute_time_duration).count()
            << std::endl;

  return 0;
}
