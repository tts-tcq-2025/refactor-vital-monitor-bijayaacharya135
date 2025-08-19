#include <gtest/gtest.h>
#include "monitor.h"
#include "vitals.h"

TEST(Vitals, TemperatureConditions) {
    EXPECT_EQ(mapToCondition(94.0f, tempBoundary), HYPO);
    EXPECT_EQ(mapToCondition(95.5f, tempBoundary), NEAR_HYPO);
    EXPECT_EQ(mapToCondition(98.0f, tempBoundary), NORMAL);
    EXPECT_EQ(mapToCondition(101.0f, tempBoundary), NEAR_HYPER);
    EXPECT_EQ(mapToCondition(103.0f, tempBoundary), HYPER);
}

TEST(Vitals, PulseConditions) {
    EXPECT_EQ(mapToCondition(59.0f, pulseBoundary), HYPO);
    EXPECT_EQ(mapToCondition(61.0f, pulseBoundary), NEAR_HYPO);
    EXPECT_EQ(mapToCondition(70.0f, pulseBoundary), NORMAL);
    EXPECT_EQ(mapToCondition(99.0f, pulseBoundary), NEAR_HYPER);
    EXPECT_EQ(mapToCondition(101.0f, pulseBoundary), HYPER);
}

TEST(Vitals, Spo2Conditions) {
    EXPECT_EQ(mapToCondition(89.0f, spo2Boundary), HYPO);
    EXPECT_EQ(mapToCondition(91.0f, spo2Boundary), NEAR_HYPO);
    EXPECT_EQ(mapToCondition(98.0f, spo2Boundary), NORMAL);
    EXPECT_EQ(mapToCondition(149.0f, spo2Boundary), NEAR_HYPER);
    EXPECT_EQ(mapToCondition(151.0f, spo2Boundary), HYPER);
}

TEST(Vitals, OverallStatus) {
    VitalsResult ok = evaluateVitals(98.0f, 70.0f, 98.0f);
    EXPECT_TRUE(overallVitalsOk(ok.temp, ok.pulse, ok.spo2));

    VitalsResult warning = evaluateVitals(95.5f, 70.0f, 98.0f);
    EXPECT_TRUE(overallVitalsOk(warning.temp, warning.pulse, warning.spo2));

    VitalsResult critical = evaluateVitals(94.0f, 70.0f, 98.0f);
    EXPECT_FALSE(overallVitalsOk(critical.temp, critical.pulse, critical.spo2));
}

