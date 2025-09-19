#pragma once

int vitalsOk(float temperature, float pulseRate, float spo2);

void setDelayFunction(void (*delayFunction)(int));
