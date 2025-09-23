#include <iostream>
#include "monitor.h"
#include "vitals.h"

// Use a global language code, can be changed at runtime
LanguageCode currentLang = "en"; // "de" for German, "fr" for French

std::string getOverallStatusMessage(bool ok, const LanguageCode& lang) {
    if (ok) {
        if (lang == "en") return "Vitals OK";
        if (lang == "de") return "Vitalwerte OK";
        if (lang == "fr") return "Valeurs vitales OK";
    } else {
        if (lang == "en") return "Vitals NOT OK";
        if (lang == "de") return "Vitalwerte NICHT OK";
        if (lang == "fr") return "Valeurs vitales PAS OK";
    }
    return ok ? "Vitals OK" : "Vitals NOT OK";
}

void printVitalsResult(const VitalsResult& result) {
    std::cout << "Temperature: " << conditionToMessage(result.temp, tempBoundary, currentLang) << std::endl;
    std::cout << "Pulse: " << conditionToMessage(result.pulse, pulseBoundary, currentLang) << std::endl;
    std::cout << "SpO2: " << conditionToMessage(result.spo2, spo2Boundary, currentLang) << std::endl;
    std::cout << getOverallStatusMessage(overallVitalsOk(result.temp, result.pulse, result.spo2), currentLang) << std::endl;
}

int main() {
    // Example: Switch to French
    // currentLang = "fr";

   // Example: Input in Celsius
    float temperatureC = 36.0f; // Celsius
    float pulse = 60.0f;
    float spo2 = 90.0f;
    VitalsResult result = evaluateVitals(temperatureC, CELSIUS, pulse, spo2);
    printVitalsResult(result);

    // Example: Input in Fahrenheit
    float temperatureF = 95.0f; // Fahrenheit
    result = evaluateVitals(temperatureF, FAHRENHEIT, pulse, spo2);
    printVitalsResult(result);

    // Example: Print all messages for all languages
    for (const auto& lang : supportedLanguages) {
        std::cout << "\nLanguage: " << lang << std::endl;
        std::cout << "Temperature: " << conditionToMessage(result.temp, tempBoundary, lang) << std::endl;
        std::cout << "Pulse: " << conditionToMessage(result.pulse, pulseBoundary, lang) << std::endl;
        std::cout << "SpO2: " << conditionToMessage(result.spo2, spo2Boundary, lang) << std::endl;
    }
    return 0;
}
