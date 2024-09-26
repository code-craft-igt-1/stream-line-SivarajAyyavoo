#include "sender.h"
#include <random>
#include <iostream>

namespace sender {
    template<class T>
    T generateRandomNumber(T minNum, T maxNum) {
        std::random_device rd;
        std::mt19937 gen(rd());

        if constexpr (std::is_integral<T>::value) {
            std::uniform_int_distribution<T> dis(minNum, maxNum);
            return dis(gen);
        }
        else {
            std::uniform_real_distribution<T> dis(minNum, maxNum);
            return dis(gen);
        }
    }

    double generateTempInF() {
        return generateRandomNumber(MIN_TEMP_IN_F, MAX_TEMP_IN_F);
    }

    double generateSpo2() {
        return generateRandomNumber(MIN_SPO2, MAX_SPO2);
    }

    unsigned int generatePulseRate() {
        return generateRandomNumber(MIN_PULSERATE, MAX_PULSERATE);
    }

    std::vector<SensorData> generateSensorData(unsigned int numberOfSensorData) {
        std::vector<SensorData> dataFromSensor;
        for (int i = 0;i < numberOfSensorData;i++) {
            double temp = generateTempInF();
            unsigned int pulse = generatePulseRate();
            double spo2 = generateSpo2();

            dataFromSensor.emplace_back(temp, pulse, spo2);
        }
        return dataFromSensor;
    }

    void sendSensorDataToConsole(const std::vector<SensorData>& sensorDataList) {
        for (const auto& sensorData : sensorDataList) {
            std::cout << sensorData.temperatureInF << "," << sensorData.pulseRate << "," << sensorData.spo2 << std::endl;
        }
    }

    int main() {
        std::vector<SensorData> sensorDataList = generateSensorData(NO_OF_SENSORDATA);
        sendSensorDataToConsole(sensorDataList);

        return 0;
    }
}