#include <gtest/gtest.h>
#include "./monitor.h"

TEST(Monitor, NotOkWhenAnyVitalIsOffRange) {
  ASSERT_FALSE(vitalsOk(99, 102, 70));
}

TEST(Monitor, OkWhenAllVitalsAreInRange) {
  ASSERT_TRUE(vitalsOk(98, 75, 95));
}

TEST(Monitor, TemperatureCritical) {
  ASSERT_FALSE(vitalsOk(103, 75, 95));
}

TEST(Monitor, PulseRateCritical) {
  ASSERT_FALSE(vitalsOk(98, 55, 95));
}

TEST(Monitor, Spo2Critical) {
  ASSERT_FALSE(vitalsOk(98, 75, 85));
}

TEST(Monitor, TemperatureOk) {
  ASSERT_TRUE(vitalsOk(98, 75, 95));
}

TEST(Monitor, pulseRateOk) {
  ASSERT_TRUE(vitalsOk(98, 75, 95));
}

TEST(Monitor, Spo2Ok) {
  ASSERT_TRUE(vitalsOk(98, 75, 95));
}
