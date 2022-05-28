#include "absolute_time_duration_test.hpp"
#include "absolute_time_point_test.hpp"
#include "chrono_test.hpp"
#include "nlohmann_json_test.hpp"

int main(void) {
  run_absolute_time_duration_test();
  run_absolute_time_point_test();
  run_chrono_test();
  run_nlohmann_json_test();
  return 0;
}
