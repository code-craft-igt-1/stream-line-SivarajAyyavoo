#ifndef SENDER_H
#define SENDER_H

#include <string>
#include <vector>

namespace sender {
    const unsigned int NO_OF_SENSORDATA = 10;

    const double MIN_TEMP_IN_F = 95.0;
    const double MAX_TEMP_IN_F = 110.0;

    const double MIN_SPO2 = 75.0;
    const double MAX_SPO2 = 100.0;

    const unsigned int MIN_PULSERATE = 0;
    const unsigned int MAX_PULSERATE = 200;

    struct SensorData {
        double temperatureInF;
        unsigned int pulseRate;
        double spo2;

        SensorData(double temp, unsigned int pulse, double oxygen)
            : temperatureInF(temp), pulseRate(pulse), spo2(oxygen) {}
    };

    double generateTempInF();
    unsigned int generatePulseRate();
    double generateSpo2();

    template<class T>
    T generateRandomNumber(T minNum, T maxNum);

    std::vector<SensorData> generateSensorData(unsigned int numberOfSensorData);

    void sendSensorDataToConsole(const std::vector<SensorData>& sensorData);
}  // namespace sender

#endif  // SENDER_H