#include "./monitor.h"
#include <assert.h>
#include <thread>
#include <chrono>
#include <iostream>
using std::cout, std::flush, std::this_thread::sleep_for, std::chrono::seconds;

void displayAlert(const std::string& message) {
  cout << message << "\n";
  for (int i = 0; i < 6; i++) {
    cout << "\r* " << flush;
    sleep_for(seconds(1));
    cout << "\r *" << flush;
    sleep_for(seconds(1));
  }
}

int isInRange(float value, float min, float max) {
  return value > min && value < max;
}

int isTemperatureOk(float temperature) {
  if (!isInRange(temperature, 95, 102)) {
    displayAlert("Temperature is critical!");
    return 0;
  }
  return 1;
}

int isPulseRateOk(float pulseRate) {
  if (!isInRange(pulseRate, 60, 100)) {
    displayAlert("Pulse Rate is out of range!");
    return 0;
  }
  return 1;
}

int isSpo2Ok(float spo2) {
  if (!isInRange(spo2, 90, 100)) {
    displayAlert("Oxygen Saturation out of range!");
    return 0;
  }
  return 1;
}

int vitalsOk(float temperature, float pulseRate, float spo2) {
  return isTemperatureOk(temperature) &&
         isPulseRateOk(pulseRate) &&
         isSpo2Ok(spo2);
}
