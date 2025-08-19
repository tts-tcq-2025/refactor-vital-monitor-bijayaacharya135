#pragma once

enum VitalCondition {
    HYPO, NEAR_HYPO, NORMAL, NEAR_HYPER, HYPER
};

struct VitalBoundary {
    float boundaries[5]; // [lower, near_low, normal_low, normal_high, near_high]
    const char* messages[5];
};

VitalCondition mapToCondition(float value, const VitalBoundary& boundary);
const char* conditionToMessage(VitalCondition cond, const VitalBoundary& boundary);
bool isCritical(VitalCondition cond);
bool isWarning(VitalCondition cond);
bool overallVitalsOk(VitalCondition temp, VitalCondition pulse, VitalCondition spo2);
