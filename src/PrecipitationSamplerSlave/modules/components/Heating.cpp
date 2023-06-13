#pragma once

#include "../setup/modules.h"

// Timers
unsigned long lastMillisFunnel = 0;
unsigned long lastMillisPump = 0;

void InitHeating(bool taskComplete) {
    HeaterFunnel();
    HeaterPump();
}

void HeaterFunnel() {
    if (millis() - lastMillisFunnel < TSENSOR_PERIOD) {
        lastMillisFunnel = millis();

        float tempFunnel = readTemperature(PA_TEMP_FUNNEL);
        ONOFFRegulation(tempFunnel, PA_TEMP_FUNNEL);
    }
}

void HeaterPump() {

    if (millis() - lastMillisPump < TSENSOR_PERIOD) {
        lastMillisPump = millis();

        float tempPump = readTemperature(PA_TEMP_PUMP);
        ONOFFRegulation(tempPump, PA_TEMP_PUMP);
    }
}

void HeaterSteppers() {
}

float readTemperature(int temperaturePin) {
    // Read sensor
    int TSensor = analogRead(temperaturePin);
    // Convert to Degrees
    float temperature = Analog2Celcius(TSensor);

    return temperature;
}

void ONOFFRegulation(float temperature, int TempSensorPin) {
    //  ON/OFF regulation with hysterese
    if (temperature <= (targetTemperature - hysterese)) {
        digitalWrite(TempSensorPin, HIGH);
    } else if (temperature <= (targetTemperature + hysterese)) {
        digitalWrite(TempSensorPin, LOW);
    }
}

float Analog2Celcius(int Reading) {
    // Convert sensor value to Degrees Celcius
    float tempCelcius = (Reading / 1024.0) * 5.0; // Assuming a 5V reference voltage
    tempCelcius = (tempCelcius - 0.5) * 100.0;    // Assuming a 10mV/°C temperature sensor

    return tempCelcius;
}