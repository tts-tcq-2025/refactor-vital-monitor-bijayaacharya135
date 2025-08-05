#include "./monitor.h"

struct VitalRange {
    float value;
    float min;
    float max;
    VitalType type;
};

static bool isInRange(float value, float min, float max) {
    return value >= min && value <= max;
}

VitalType checkVitals(float temperature, float pulseRate, float spo2) {
    VitalRange vitals[] = {
        {temperature, 95.0f, 102.0f, TEMP_CRITICAL},
        {pulseRate,   60.0f, 100.0f, PULSE_CRITICAL},
        {spo2,        90.0f, 150.0f, SPO2_CRITICAL} // 150 is a practical upper bound for SpO2
    };
    for(const auto& vital : vitals) {
        if (!isInRange(vital.value, vital.min, vital.max)) {
            return vital.type;
        }
    }
    return VITALS_OK;
}

int vitalsOk(float temperature, float pulseRate, float spo2) {
    return checkVitals(temperature, pulseRate, spo2) == VITALS_OK ? 1 : 0;
}
