#include "./sender.h"

#include "gtest/gtest.h"

namespace sender {
namespace test {
    TEST(SensorDataGenerationTest, TemperatureRange) {
        for (int i = 0;i < 10;i++) {
            double temp = generateTempInF();
            EXPECT_GE(temp, MIN_TEMP_IN_F);
            EXPECT_LE(temp, MAX_TEMP_IN_F);
        }
    }

    TEST(SensorDataGenerationTest, Spo2Range) {
        for (int i = 0; i < 10; ++i) {
            double spo2 = generateSpo2();
            EXPECT_GE(spo2, MIN_SPO2);
            EXPECT_LE(spo2, MAX_SPO2);
        }
    }

    TEST(SensorDataGenerationTest, PulseRateRange) {
        for (int i = 0; i < 10; ++i) {
            unsigned int pulse = generatePulseRate();
            EXPECT_GE(pulse, MIN_PULSERATE);
            EXPECT_LE(pulse, MAX_PULSERATE);
        }
    }

    TEST(SensorDataGenerationTest, SensorDataGeneration) {
        std::vector<SensorData> sensorDataList = generateSensorData(10);
        for (const auto& sensorData : sensorDataList) {
            EXPECT_GE(sensorData.temperatureInF, MIN_TEMP_IN_F);
            EXPECT_LE(sensorData.temperatureInF, MAX_TEMP_IN_F);
            EXPECT_GE(sensorData.pulseRate, MIN_PULSERATE);
            EXPECT_LE(sensorData.pulseRate, MAX_PULSERATE);
            EXPECT_GE(sensorData.spo2, MIN_SPO2);
            EXPECT_LE(sensorData.spo2, MAX_SPO2);
        }
    }
}
}