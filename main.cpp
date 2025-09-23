#include <iostream>
#include "monitor.h"
#include "vitals.h"

// Use a global language code, can be changed at runtime
LanguageCode currentLang = "en"; // "de" for German, "fr" for French

std::string getOverallStatusMessage(bool ok, const LanguageCode& lang) {
    static const std::map<LanguageCode, std::array<std::string, 2>> messages = {
        {"en", {"Vitals OK", "Vitals NOT OK"}},
        {"de", {"Vitalwerte OK", "Vitalwerte NICHT OK"}},
        {"fr", {"Valeurs vitales OK", "Valeurs vitales PAS OK"}}
    };
    auto it = messages.find(lang);
    const auto& arr = (it != messages.end()) ? it->second : messages.at("en");
    return arr[ok ? 0 : 1];

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
