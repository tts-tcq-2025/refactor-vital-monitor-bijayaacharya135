#include "vitals.h"

VitalCondition mapToCondition(float value, const VitalBoundary& boundary) {
    if (value < boundary.boundaries[0]) return HYPO;
    if (value < boundary.boundaries[1]) return NEAR_HYPO;
    if (value <= boundary.boundaries[3]) return NORMAL;
    if (value <= boundary.boundaries[4]) return NEAR_HYPER;
    return HYPER;
}

const char* conditionToMessage(VitalCondition cond, const VitalBoundary& boundary) {
    return boundary.messages[cond];
}

bool isCritical(VitalCondition cond) {
    return cond == HYPO || cond == HYPER;
}

bool isWarning(VitalCondition cond) {
    return cond == NEAR_HYPO || cond == NEAR_HYPER;
}

bool overallVitalsOk(VitalCondition temp, VitalCondition pulse, VitalCondition spo2) {
    return !(isCritical(temp) || isCritical(pulse) || isCritical(spo2));
}
