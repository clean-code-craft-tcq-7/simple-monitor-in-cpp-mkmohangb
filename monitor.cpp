#include "./monitor.h"
#include <assert.h>
#include <thread>
#include <chrono>
#include <iostream>
using std::cout, std::flush, std::this_thread::sleep_for, std::chrono::seconds;

void displayVitalAlert(const char* message) {
  cout << message;
  for (int i = 0; i < 6; i++) {
    cout << "\r* " << flush;
    sleep_for(seconds(1));
    cout << "\r *" << flush;
    sleep_for(seconds(1));
  }
}

int isInRange(float value, float lowerLimit, float upperLimit) {
  return (value >= lowerLimit && value <= upperLimit);
}

int isTemperatureOk(float temperature) {
  if (!isInRange(temperature, 95, 102)) {
    displayVitalAlert("Temperature is critical!\n");
    return 0;
  }
  return 1;
}

int isPulseRateOk(float pulseRate) {
  if (!isInRange(pulseRate, 60, 100)) {
    displayVitalAlert("Pulse Rate is out of range!\n");
    return 0;
  }
  return 1;
}

int isSpo2Ok(float spo2) {
  if (!isInRange(spo2, 90, 100)) {
    displayVitalAlert("Oxygen Saturation out of range!\n");
    return 0;
  }
  return 1;
}

int vitalsOk(float temperature, float pulseRate, float spo2) {
  return isTemperatureOk(temperature) && isPulseRateOk(pulseRate) && isSpo2Ok(spo2);
}
