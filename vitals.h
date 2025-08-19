#pragma once

enum VitalCondition {
    CRITICAL_LOW, WARNING_LOW, NORMAL, WARNING_HIGH, CRITICAL_HIGH
};

struct VitalBoundary {
    float min;
    float max;
    float tolerance;
    const char* messages[5];
};

VitalCondition mapToCondition(float value, const VitalBoundary& boundary);
const char* conditionToMessage(VitalCondition cond, const VitalBoundary& boundary);
bool isCritical(VitalCondition cond);
bool overallVitalsOk(VitalCondition temp, VitalCondition pulse, VitalCondition spo2);
