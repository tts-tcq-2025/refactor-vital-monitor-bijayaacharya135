#include "vitals.h"
#include <cmath>

// Early warning logic using warningTolerance
VitalCondition mapToCondition(float value, const VitalBoundary& boundary) {
    float min = boundary.min;
    float max = boundary.max;
    float tol = boundary.warningTolerance;

    if (value < min) return CRITICAL_LOW;
    if (value < min + tol) return WARNING_LOW;
    if (value < max - tol) return NORMAL;
    if (value < max) return WARNING_HIGH;
    return CRITICAL_HIGH;
}

// Language support: fetch message from map using language code
std::string conditionToMessage(VitalCondition cond, const VitalBoundary& boundary, const LanguageCode& lang) {
    auto langIt = boundary.messages.find(lang);
    if (langIt != boundary.messages.end()) {
        auto condIt = langIt->second.find(cond);
        if (condIt != langIt->second.end()) {
            return condIt->second;
        }
    }
    // Fallback to English if not found
    return boundary.messages.at("en").at(cond);
}

bool isCritical(VitalCondition cond) {
    return cond == CRITICAL_LOW || cond == CRITICAL_HIGH;
}

bool overallVitalsOk(VitalCondition temp, VitalCondition pulse, VitalCondition spo2) {
    return !(isCritical(temp) || isCritical(pulse) || isCritical(spo2));
}
