#pragma once

int vitalsOk(float temperature, float pulseRate, float spo2);

int alertIfNotOk(int value, float min, float max, const char* message);

void setDelayFunction(void (*func)(int));

struct Report {
    float temperature;
    float pulseRate;
    float spo2;
    float bloodSugar;
};

int report_is_normal(Report report);