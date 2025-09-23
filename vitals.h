#pragma once
#include <string>
#include <map>
#include <vector>

using LanguageCode = std::string;

enum VitalCondition {
    CRITICAL_LOW, WARNING_LOW, NORMAL, WARNING_HIGH, CRITICAL_HIGH
};

enum TempUnit {
    FAHRENHEIT,
    CELSIUS
};

struct VitalBoundary {
    float min;   // boundaries in Fahrenheit
    float max;
    float warningTolerance;
    std::map<LanguageCode, std::map<VitalCondition, std::string>> messages;
};

VitalCondition mapToCondition(float value, const VitalBoundary& boundary);
std::string conditionToMessage(VitalCondition cond, const VitalBoundary& boundary,
                              const LanguageCode& lang);
bool isCritical(VitalCondition cond);
bool overallVitalsOk(VitalCondition temp, VitalCondition pulse, VitalCondition spo2);

// Added: Convert temperature to Fahrenheit if needed
float toFahrenheit(float value, TempUnit unit);
