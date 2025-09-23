#include "monitor.h"

// Define supported languages
const std::vector<LanguageCode> supportedLanguages = {"en", "de", "fr"};

// Messages for each vital and language
const VitalBoundary tempBoundary = {
    95.0f, 102.0f, 1.53f,
    {
        {"en", {
            {CRITICAL_LOW, "Hypothermia"},
            {WARNING_LOW, "Approaching hypothermia"},
            {NORMAL, "Normal"},
            {WARNING_HIGH, "Approaching hyperthermia"},
            {CRITICAL_HIGH, "Hyperthermia"}
        }},
        {"de", {
            {CRITICAL_LOW, "Unterkühlung"},
            {WARNING_LOW, "Annähernde Unterkühlung"},
            {NORMAL, "Normal"},
            {WARNING_HIGH, "Annähernde Hyperthermie"},
            {CRITICAL_HIGH, "Hyperthermie"}
        }},
        {"fr", {
            {CRITICAL_LOW, "Hypothermie"},
            {WARNING_LOW, "Approche hypothermie"},
            {NORMAL, "Normal"},
            {WARNING_HIGH, "Approche hyperthermie"},
            {CRITICAL_HIGH, "Hyperthermie"}
        }}
    }
};

const VitalBoundary pulseBoundary = {
    60.0f, 100.0f, 1.5f,
    {
        {"en", {
            {CRITICAL_LOW, "Bradycardia"},
            {WARNING_LOW, "Approaching bradycardia"},
            {NORMAL, "Normal"},
            {WARNING_HIGH, "Approaching tachycardia"},
            {CRITICAL_HIGH, "Tachycardia"}
        }},
        {"de", {
            {CRITICAL_LOW, "Bradykardie"},
            {WARNING_LOW, "Annähernde Bradykardie"},
            {NORMAL, "Normal"},
            {WARNING_HIGH, "Annähernde Tachykardie"},
            {CRITICAL_HIGH, "Tachykardie"}
        }},
        {"fr", {
            {CRITICAL_LOW, "Bradycardie"},
            {WARNING_LOW, "Approche bradycardie"},
            {NORMAL, "Normal"},
            {WARNING_HIGH, "Approche tachycardie"},
            {CRITICAL_HIGH, "Tachycardie"}
        }}
    }
};

const VitalBoundary spo2Boundary = {
    90.0f, 150.0f, 2.25f,
    {
        {"en", {
            {CRITICAL_LOW, "Hypoxemia"},
            {WARNING_LOW, "Approaching hypoxemia"},
            {NORMAL, "Normal"},
            {WARNING_HIGH, "Approaching hyperoxemia"},
            {CRITICAL_HIGH, "Hyperoxemia"}
        }},
        {"de", {
            {CRITICAL_LOW, "Hypoxämie"},
            {WARNING_LOW, "Annähernde Hypoxämie"},
            {NORMAL, "Normal"},
            {WARNING_HIGH, "Annähernde Hyperoxämie"},
            {CRITICAL_HIGH, "Hyperoxämie"}
        }},
        {"fr", {
            {CRITICAL_LOW, "Hypoxémie"},
            {WARNING_LOW, "Approche hypoxémie"},
            {NORMAL, "Normal"},
            {WARNING_HIGH, "Approche hyperoxémie"},
            {CRITICAL_HIGH, "Hyperoxémie"}
        }}
    }
};

// Added: Accept unit for temperature
VitalsResult evaluateVitals(float temperature, TempUnit tempUnit, float pulse, float spo2) {
    VitalsResult result;
    float tempF = toFahrenheit(temperature, tempUnit);
    result.temp = mapToCondition(tempF, tempBoundary);
    result.pulse = mapToCondition(pulse, pulseBoundary);
    result.spo2 = mapToCondition(spo2, spo2Boundary);
    return result;
}
