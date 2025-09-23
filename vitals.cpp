#include "vitals.h"
#include <cmath>

// Early warning logic using warningTolerance
VitalCondition mapToCondition(float value, const VitalBoundary& boundary) {
    float thresholds[4] = {
        boundary.min,
        boundary.min + boundary.warningTolerance,
        boundary.max - boundary.warningTolerance,
        boundary.max
    };
    VitalCondition conditions[5] = {
        CRITICAL_LOW, WARNING_LOW, NORMAL, WARNING_HIGH, CRITICAL_HIGH
    };
    for (int i = 0; i < 4; ++i) {
        if (value < thresholds[i])
            return conditions[i];
    }
    return conditions[4];
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
// Added: Convert Celsius to Fahrenheit if needed
float toFahrenheit(float value, TempUnit unit) {
    if (unit == CELSIUS)
        return value * 9.0f / 5.0f + 32.0f;
    return value;
}
