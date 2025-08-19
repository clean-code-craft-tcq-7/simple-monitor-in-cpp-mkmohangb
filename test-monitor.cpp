#include <gtest/gtest.h>
#include "./monitor.h"

class Monitor : public ::testing::Test {
protected:
  void SetUp() override {
    // Any setup code can go here if needed
    setDelayFunction([](int seconds) {});
  }
};

TEST_F(Monitor, AlertIfOutOfRange) {
  ASSERT_FALSE(alertIfNotOk(99, 102, 70, "Pulse Rate is out of range!"));
}

TEST_F(Monitor, NoAlertIfInRange) {
  ASSERT_TRUE(alertIfNotOk(98, 95, 98, "Normal Range"));
}

TEST_F(Monitor, NotOkWhenAnyVitalIsOffRange) {
  ASSERT_FALSE(vitalsOk(99, 102, 70));
}

TEST_F(Monitor, OkWhenAllVitalsAreInRange) {
  ASSERT_TRUE(vitalsOk(98, 75, 95));
}

TEST_F(Monitor, TemperatureCritical) {
  ASSERT_FALSE(vitalsOk(103, 75, 95));
}

TEST_F(Monitor, Spo2Critical) {
  ASSERT_FALSE(vitalsOk(98, 75, 85));
}

TEST_F(Monitor, pulseRateOk) {
  ASSERT_TRUE(vitalsOk(98, 75, 95));
}

TEST_F(Monitor, ReportIsNormal) {
  Report report = {98, 75, 95, 100}; // Assuming Report has these fields
  ASSERT_TRUE(report_is_normal(report));
}
