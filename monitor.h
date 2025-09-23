#pragma once
#include "vitals.h"

// Boundaries for each vital sign
extern const VitalBoundary tempBoundary;
extern const VitalBoundary pulseBoundary;
extern const VitalBoundary spo2Boundary;

// Declare supportedLanguages for global access
extern const std::vector<LanguageCode> supportedLanguages;

struct VitalsResult {
    VitalCondition temp;
    VitalCondition pulse;
    VitalCondition spo2;
};

// Pure function for evaluating all vitals
// Added: Accept unit for temperature
VitalsResult evaluateVitals(float temperature, TempUnit tempUnit, float pulse, float spo2);


