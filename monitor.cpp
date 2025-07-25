#include "./monitor.h"
#include <assert.h>
#include <thread>
#include <chrono>
#include <iostream>
#include <string>
using std::cout, std::flush, std::this_thread::sleep_for, std::chrono::seconds;

void displayVitalAlert(const std::string& message) {
  cout << message;
  for (int i = 0; i < 6; i++) {
    cout << "\r* " << flush;
    sleep_for(seconds(1));
    cout << "\r *" << flush;
    sleep_for(seconds(1));
  }
}

int isTemperatureOk(float temperature) {
  if (temperature > 102 || temperature < 95) {
    displayVitalAlert("Temperature is critical!");
    return 0;
  }
  return 1;
}

int isPulseRateOk(float pulseRate) {
  if (pulseRate < 60 || pulseRate > 100) {
    displayVitalAlert("Pulse Rate is critical!");
    return 0;
  }
  return 1;
}

int isSpo2Ok(float spo2) {
  if (spo2 < 90) {
    displayVitalAlert("Oxygen Saturation is critical!");
    return 0;
  }
  return 1;
}

int vitalsOk(float temperature, float pulseRate, float spo2) {
  return isTemperatureOk(temperature) &&  isPulseRateOk(pulseRate) && isSpo2Ok(spo2);
}
