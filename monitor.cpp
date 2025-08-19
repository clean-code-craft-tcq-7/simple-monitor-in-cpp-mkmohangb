#include "./monitor.h"
#include <assert.h>
#include <thread>
#include <chrono>
#include <iostream>
using std::cout, std::flush, std::this_thread::sleep_for, std::chrono::seconds;


void delay(int seconds) {
  sleep_for(std::chrono::seconds(seconds));
}

void (*delayPtr)(int) = delay;

void setDelayFunction(void (*func)(int)) {
  delayPtr = func;
}

void displayAlert(const char* message) {
  cout << message << "\n";
  for (int i = 0; i < 6; i++) {
    cout << "\r* " << flush;
    delayPtr(1);
    cout << "\r *" << flush;
    delayPtr(1);
  }
}

int alertIfNotOk(int value, float min, float max, const char* message) {
  if (value < min || value > max) {
    displayAlert(message);
    return 0;
  }
  return 1;
}

int isInRange(float value, float min, float max) {
  return value > min && value < max;
}

int isTemperatureOk(float temperature) {
  return alertIfNotOk(temperature, 95, 102, "Temperature is out of range!");
}

int isPulseRateOk(float pulseRate) {
  return alertIfNotOk(pulseRate, 60, 100, "Pulse Rate is out of range!");
}

int isSpo2Ok(float spo2) {
  return alertIfNotOk(spo2, 90, 100, "SpO2 is out of range!");
}

int isBloodSugarOk(float bloodSugar) {
  return alertIfNotOk(bloodSugar, 70, 110, "Blood Sugar is out of range!");
}

int vitalsOk(float temperature, float pulseRate, float spo2) {
  return isTemperatureOk(temperature) &&
         isPulseRateOk(pulseRate) &&
         isSpo2Ok(spo2);
}

int report_is_normal(Report report) {
}
