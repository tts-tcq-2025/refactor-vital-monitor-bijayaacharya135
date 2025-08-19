#include <gtest/gtest.h>
#include "monitor.h"
#include "vitals.h"

TEST(Vitals, TemperatureConditions) {
    EXPECT_EQ(mapToCondition(94.0f, tempBoundary), CRITICAL_LOW);
    EXPECT_EQ(mapToCondition(95.5f, tempBoundary), WARNING_LOW);
    EXPECT_EQ(mapToCondition(98.0f, tempBoundary), NORMAL);
    EXPECT_EQ(mapToCondition(101.0f, tempBoundary), WARNING_HIGH);
    EXPECT_EQ(mapToCondition(103.0f, tempBoundary), CRITICAL_HIGH);
}

TEST(Vitals, PulseConditions) {
    EXPECT_EQ(mapToCondition(59.0f, pulseBoundary), CRITICAL_LOW);
    EXPECT_EQ(mapToCondition(61.0f, pulseBoundary), WARNING_LOW);
    EXPECT_EQ(mapToCondition(70.0f, pulseBoundary), NORMAL);
    EXPECT_EQ(mapToCondition(99.5f, pulseBoundary), WARNING_HIGH);
    EXPECT_EQ(mapToCondition(101.0f, pulseBoundary), CRITICAL_HIGH);
}

TEST(Vitals, Spo2Conditions) {
    EXPECT_EQ(mapToCondition(89.0f, spo2Boundary), CRITICAL_LOW);
    EXPECT_EQ(mapToCondition(91.0f, spo2Boundary), WARNING_LOW);
    EXPECT_EQ(mapToCondition(98.0f, spo2Boundary), NORMAL);
    EXPECT_EQ(mapToCondition(149.0f, spo2Boundary), WARNING_HIGH);
    EXPECT_EQ(mapToCondition(151.0f, spo2Boundary), CRITICAL_HIGH);
}

TEST(Vitals, OverallStatus) {
    VitalsResult ok = evaluateVitals(98.0f, 70.0f, 98.0f);
    EXPECT_TRUE(overallVitalsOk(ok.temp, ok.pulse, ok.spo2));

    VitalsResult warning = evaluateVitals(95.5f, 70.0f, 98.0f);
    EXPECT_TRUE(overallVitalsOk(warning.temp, warning.pulse, warning.spo2));

    VitalsResult critical = evaluateVitals(94.0f, 70.0f, 98.0f);
    EXPECT_FALSE(overallVitalsOk(critical.temp, critical.pulse, critical.spo2));
}
