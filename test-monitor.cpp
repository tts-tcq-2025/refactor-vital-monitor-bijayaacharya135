#include <gtest/gtest.h>
#include "./monitor.h"

TEST(Monitor, AllVitalsNormal) {
    ASSERT_TRUE(vitalsOk(98.6, 72, 98));
}

TEST(Monitor, TemperatureLow) {
    ASSERT_FALSE(vitalsOk(94.9, 72, 98));
}

TEST(Monitor, TemperatureHigh) {
    ASSERT_FALSE(vitalsOk(102.1, 72, 98));
}

TEST(Monitor, PulseLow) {
    ASSERT_FALSE(vitalsOk(98.6, 59, 98));
}

TEST(Monitor, PulseHigh) {
    ASSERT_FALSE(vitalsOk(98.6, 101, 98));
}

TEST(Monitor, Spo2Low) {
    ASSERT_FALSE(vitalsOk(98.6, 72, 89));
}

TEST(Monitor, EdgeCases) {
    ASSERT_TRUE(vitalsOk(95.0, 60.0, 90.0));
    ASSERT_TRUE(vitalsOk(102.0, 100.0, 90.0));
}

TEST(Monitor, StatusEnum) {
    ASSERT_EQ(checkVitals(94.0, 70, 98), TEMP_CRITICAL);
    ASSERT_EQ(checkVitals(98.6, 101, 98), PULSE_CRITICAL);
    ASSERT_EQ(checkVitals(98.6, 70, 80), SPO2_CRITICAL);
    ASSERT_EQ(checkVitals(98.6, 70, 98), VITALS_OK);
}

