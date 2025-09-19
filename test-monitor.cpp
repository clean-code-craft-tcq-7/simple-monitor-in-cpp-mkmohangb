#include <gtest/gtest.h>
#include "./monitor.h"

// Test fixture
class Monitor : public ::testing::Test {
protected:
  void SetUp() override {
    // Code here will be called immediately after the constructor (right
    // before each test).
    setDelayFunction([](int seconds) {
      // No-op delay function for testing
    });
  }
};

TEST_F(Monitor, NotOkWhenTemperatureIsOutOfRange) {
  ASSERT_FALSE(vitalsOk(105, 102, 70));
}

TEST_F(Monitor, NotOkWhenPulseRateIsOutOfRange) {
  ASSERT_FALSE(vitalsOk(98, 120, 95));
}

TEST_F(Monitor, NotOkWhenSpo2IsOutOfRange) {
  ASSERT_FALSE(vitalsOk(98, 80, 80 ));
}

TEST_F(Monitor, OkWhenAllVitalsAreInRange) {
  ASSERT_TRUE(vitalsOk(98, 80, 95 ));
}

TEST_F(Monitor, OkWhenTemperatureIsInRange) {
  ASSERT_TRUE(vitalsOk(98, 80, 95 ));
}

TEST_F(Monitor, OkWhenPulseRateIsInRange) {
  ASSERT_TRUE(vitalsOk(98, 80, 95 ));
}

TEST_F(Monitor, OkWhenSpo2IsInRange) {
  ASSERT_TRUE(vitalsOk(98, 80, 95 ));
}
