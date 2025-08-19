#include "monitor.h"

const VitalBoundary tempBoundary = {
    {95.0f, 96.53f, 96.54f, 100.47f, 102.0f},
    {"Hypothermia", "Near Hypothermia", "Normal", "Near Hyperthermia", "Hyperthermia"}
};
const VitalBoundary pulseBoundary = {
    {60.0f, 61.5f, 61.6f, 98.5f, 100.0f},
    {"Bradycardia", "Near Bradycardia", "Normal", "Near Tachycardia", "Tachycardia"}
};
const VitalBoundary spo2Boundary = {
    {90.0f, 91.35f, 91.36f, 148.65f, 150.0f},
    {"Hypoxemia", "Near Hypoxemia", "Normal", "Near Hyperoxemia", "Hyperoxemia"}
};

VitalsResult evaluateVitals(float temperature, float pulse, float spo2) {
    VitalsResult result;
    result.temp = mapToCondition(temperature, tempBoundary);
    result.pulse = mapToCondition(pulse, pulseBoundary);
    result.spo2 = mapToCondition(spo2, spo2Boundary);
    return result;
}
