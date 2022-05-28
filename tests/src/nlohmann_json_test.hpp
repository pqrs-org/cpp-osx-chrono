#include <boost/ut.hpp>
#include <iostream>
#include <pqrs/osx/chrono/extra/nlohmann_json.hpp>

void run_nlohmann_json_test(void) {
  using namespace boost::ut;
  using namespace boost::ut::literals;

  "absolute_time_point json"_test = [] {
    {
      uint64_t u64 = 13835058055282163712ull; // 2^63 + 2^62
      pqrs::osx::chrono::absolute_time_point p1(u64);
      nlohmann::json json = p1;
      auto p2 = json.get<pqrs::osx::chrono::absolute_time_point>();
      expect(p1 == p2);
      expect(json.dump() == "13835058055282163712");
    }

    {
      nlohmann::json json = 12.2;
      auto p = json.get<pqrs::osx::chrono::absolute_time_point>();
      expect(p == pqrs::osx::chrono::absolute_time_point(12));
    }

    try {
      nlohmann::json().get<pqrs::osx::chrono::absolute_time_point>();
      expect(false);
    } catch (pqrs::json::unmarshal_error& ex) {
      expect(std::string("json must be number, but is `null`") == ex.what());
    } catch (...) {
      expect(false);
    }

    try {
      nlohmann::json(true).get<pqrs::osx::chrono::absolute_time_point>();
      expect(false);
    } catch (pqrs::json::unmarshal_error& ex) {
      expect(std::string("json must be number, but is `true`") == ex.what());
    } catch (...) {
      expect(false);
    }

    try {
      nlohmann::json::object().get<pqrs::osx::chrono::absolute_time_point>();
      expect(false);
    } catch (pqrs::json::unmarshal_error& ex) {
      expect(std::string("json must be number, but is `{}`") == ex.what());
    } catch (...) {
      expect(false);
    }

    try {
      nlohmann::json::array().get<pqrs::osx::chrono::absolute_time_point>();
      expect(false);
    } catch (pqrs::json::unmarshal_error& ex) {
      expect(std::string("json must be number, but is `[]`") == ex.what());
    } catch (...) {
      expect(false);
    }

    try {
      nlohmann::json("1234").get<pqrs::osx::chrono::absolute_time_point>();
      expect(false);
    } catch (pqrs::json::unmarshal_error& ex) {
      expect(std::string("json must be number, but is `\"1234\"`") == ex.what());
    } catch (...) {
      expect(false);
    }
  };

  "absolute_time_duration json"_test = [] {
    {
      int64_t i64 = 6917529027641081856ll; // 2^62 + 2^61
      pqrs::osx::chrono::absolute_time_duration d1(i64);
      nlohmann::json json = d1;
      auto d2 = json.get<pqrs::osx::chrono::absolute_time_duration>();
      expect(d1 == d2);
      expect(json.dump() == "6917529027641081856");
    }

    {
      nlohmann::json json = 12.2;
      auto p = json.get<pqrs::osx::chrono::absolute_time_duration>();
      expect(p == pqrs::osx::chrono::absolute_time_duration(12));
    }

    {
      int64_t i64 = -6917529027641081856ll; // -(2^62 + 2^61)
      pqrs::osx::chrono::absolute_time_duration d1(i64);
      nlohmann::json json = d1;
      auto d2 = json.get<pqrs::osx::chrono::absolute_time_duration>();
      expect(d1 == d2);
      expect(json.dump() == "-6917529027641081856");
    }

    try {
      nlohmann::json().get<pqrs::osx::chrono::absolute_time_duration>();
      expect(false);
    } catch (pqrs::json::unmarshal_error& ex) {
      expect(std::string("json must be number, but is `null`") == ex.what());
    } catch (...) {
      expect(false);
    }

    try {
      nlohmann::json(true).get<pqrs::osx::chrono::absolute_time_duration>();
      expect(false);
    } catch (pqrs::json::unmarshal_error& ex) {
      expect(std::string("json must be number, but is `true`") == ex.what());
    } catch (...) {
      expect(false);
    }

    try {
      nlohmann::json::object().get<pqrs::osx::chrono::absolute_time_duration>();
      expect(false);
    } catch (pqrs::json::unmarshal_error& ex) {
      expect(std::string("json must be number, but is `{}`") == ex.what());
    } catch (...) {
      expect(false);
    }

    try {
      nlohmann::json::array().get<pqrs::osx::chrono::absolute_time_duration>();
      expect(false);
    } catch (pqrs::json::unmarshal_error& ex) {
      expect(std::string("json must be number, but is `[]`") == ex.what());
    } catch (...) {
      expect(false);
    }

    try {
      nlohmann::json("1234").get<pqrs::osx::chrono::absolute_time_duration>();
      expect(false);
    } catch (pqrs::json::unmarshal_error& ex) {
      expect(std::string("json must be number, but is `\"1234\"`") == ex.what());
    } catch (...) {
      expect(false);
    }
  };
}
