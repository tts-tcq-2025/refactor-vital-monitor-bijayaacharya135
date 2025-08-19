#include "vitals.h"

VitalCondition mapToCondition(float value, const VitalBoundary& boundary) {
    if (value < boundary.min) return CRITICAL_LOW;
    if (value < boundary.min + boundary.tolerance) return WARNING_LOW;
    if (value <= boundary.max - boundary.tolerance) return NORMAL;
    if (value <= boundary.max) return WARNING_HIGH;
    return CRITICAL_HIGH;
}

const char* conditionToMessage(VitalCondition cond, const VitalBoundary& boundary) {
    return boundary.messages[cond];
}

bool isCritical(VitalCondition cond) {
    return cond == CRITICAL_LOW || cond == CRITICAL_HIGH;
}

bool overallVitalsOk(VitalCondition temp, VitalCondition pulse, VitalCondition spo2) {
    return !(isCritical(temp) || isCritical(pulse) || isCritical(spo2));
}
