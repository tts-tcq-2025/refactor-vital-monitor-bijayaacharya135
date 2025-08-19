#include "monitor.h"
#include <iostream>
#include <thread>
#include <chrono>

using std::cout, std::flush, std::this_thread::sleep_for, std::chrono::seconds;

void showAlert(VitalType status) {
    const char* message = nullptr;
    switch(status) {
        case TEMP_CRITICAL:
            message = "Temperature is critical!";
            break;
        case PULSE_CRITICAL:
            message = "Pulse Rate is out of range!";
            break;
        case SPO2_CRITICAL:
            message = "Oxygen Saturation out of range!";
            break;
        case VITALS_OK:
            message = "All vitals are normal.";
            break;
    }
    cout << message << "\n";
    if(status != VITALS_OK) {
        for (int i = 0; i < 6; i++) {
            cout << "\r* " << flush;
            sleep_for(seconds(1));
            cout << "\r *" << flush;
            sleep_for(seconds(1));
        }
        cout << "\n";
    }
}
