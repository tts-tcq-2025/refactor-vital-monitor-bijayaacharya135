#pragma once

enum VitalType {
    VITALS_OK,
    TEMP_CRITICAL,
    PULSE_CRITICAL,
    SPO2_CRITICAL
};

VitalType checkVitals(float temperature, float pulseRate, float spo2);
int vitalsOk(float temperature, float pulseRate, float spo2);
