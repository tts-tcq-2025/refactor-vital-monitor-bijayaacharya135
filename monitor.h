#pragma once
#include "vitals.h"

extern const VitalBoundary tempBoundary;
extern const VitalBoundary pulseBoundary;
extern const VitalBoundary spo2Boundary;

struct VitalsResult {
    VitalCondition temp;
    VitalCondition pulse;
    VitalCondition spo2;
};

VitalsResult evaluateVitals(float temperature, float pulse, float spo2);

