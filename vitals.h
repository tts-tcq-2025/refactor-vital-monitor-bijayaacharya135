#pragma once
#include <string>
#include <map>
#include <vector>

// Language codes are now strings for flexibility
using LanguageCode = std::string;

// VitalCondition remains as before
enum VitalCondition {
    CRITICAL_LOW, WARNING_LOW, NORMAL, WARNING_HIGH, CRITICAL_HIGH
};

// VitalBoundary now uses a map for messages per language
struct VitalBoundary {
    float min;
    float max;
    float warningTolerance;
    std::map<LanguageCode, std::map<VitalCondition, std::string>> messages;
};

// Pure functions for mapping and messaging
VitalCondition mapToCondition(float value, const VitalBoundary& boundary);
std::string conditionToMessage(VitalCondition cond, const VitalBoundary& boundary, const LanguageCode& lang);
bool isCritical(VitalCondition cond);
bool overallVitalsOk(VitalCondition temp, VitalCondition pulse, VitalCondition spo2);
