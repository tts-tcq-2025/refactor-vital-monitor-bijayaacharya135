#include <iostream>
#include "monitor.h"
#include "vitals.h"

void printVitalsResult(const VitalsResult& result) {
    std::cout << "Temperature: " << conditionToMessage(result.temp, tempBoundary) << std::endl;
    std::cout << "Pulse: " << conditionToMessage(result.pulse, pulseBoundary) << std::endl;
    std::cout << "SpO2: " << conditionToMessage(result.spo2, spo2Boundary) << std::endl;

    if (overallVitalsOk(result.temp, result.pulse, result.spo2))
        std::cout << "Vitals OK" << std::endl;
    else
        std::cout << "Vitals NOT OK" << std::endl;
}

int main() {
    float temperature = 95.0f, pulse = 60.0f, spo2 = 90.0f;
    VitalsResult result = evaluateVitals(temperature, pulse, spo2);
    printVitalsResult(result);
    return 0;
