#include "vitals.h"

struct ConditionRange {
    float lower;
    float upper;
    VitalCondition condition;
};

VitalCondition mapToCondition(float value, const VitalBoundary& boundary) {
    float min = boundary.min;
    float max = boundary.max;
    float tol = boundary.tolerance;

    ConditionRange ranges[] = {
        { -INFINITY, min, CRITICAL_LOW },
        { min, min + tol, WARNING_LOW },
        { min + tol, max - tol, NORMAL },
        { max - tol, max, WARNING_HIGH },
        { max, INFINITY, CRITICAL_HIGH }
    };

    for (const auto& r : ranges) {
        if (value >= r.lower && value < r.upper) {
            return r.condition;
        }
    }
    return NORMAL;
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
