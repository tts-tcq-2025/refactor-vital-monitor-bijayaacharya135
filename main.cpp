#include <iostream>
#include "monitor.h"
#include "vitals.h"

// Use a global language code, can be changed at runtime
LanguageCode currentLang = "en"; // "de" for German, "fr" for French

void printVitalsResult(const VitalsResult& result) {
    std::cout << "Temperature: " << conditionToMessage(result.temp, tempBoundary, currentLang) << std::endl;
    std::cout << "Pulse: " << conditionToMessage(result.pulse, pulseBoundary, currentLang) << std::endl;
    std::cout << "SpO2: " << conditionToMessage(result.spo2, spo2Boundary, currentLang) << std::endl;

    // Print overall status in selected language
    if (overallVitalsOk(result.temp, result.pulse, result.spo2))
        std::cout << (currentLang == "en" ? "Vitals OK" :
                      currentLang == "de" ? "Vitalwerte OK" :
                      currentLang == "fr" ? "Valeurs vitales OK" : "Vitals OK") << std::endl;
    else
        std::cout << (currentLang == "en" ? "Vitals NOT OK" :
                      currentLang == "de" ? "Vitalwerte NICHT OK" :
                      currentLang == "fr" ? "Valeurs vitales PAS OK" : "Vitals NOT OK") << std::endl;
}

int main() {
    // Example: Switch to French
    // currentLang = "fr";

    float temperature = 95.0f, pulse = 60.0f, spo2 = 90.0f;
    VitalsResult result = evaluateVitals(temperature, pulse, spo2);
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
