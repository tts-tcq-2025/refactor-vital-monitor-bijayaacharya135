#pragma once
#include "vitals.h"

// Boundaries for each vital sign
extern const VitalBoundary tempBoundary;
extern const VitalBoundary pulseBoundary;
extern const VitalBoundary spo2Boundary;

struct VitalsResult {
    VitalCondition temp;
    VitalCondition pulse;
    VitalCondition spo2;
};

// Pure function for evaluating all vitals
VitalsResult evaluateVitals(float temperature, float pulse, float spo2);
