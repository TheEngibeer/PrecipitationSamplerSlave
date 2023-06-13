#pragma once

#include "../setup/modules.h"

// Setup Pump Stepper
AccelStepper Pump(1, PO_PUMP_STP);

void InitStepperPump() {
    // Opsætning af Transportbånds Steppermotor
    Pump.setPinsInverted(false, false, true); // Inverts the "direction" pin
    Pump.setMaxSpeed(300);                    // Max. hastighed    (steps/sek.)
    Pump.setAcceleration(100);                // Max. acceleration (steps/sek.^2)
    Height.setCurrentPosition(0);             // Set the start position to 0
    Pump.disableOutputs();                    // Stepper is OFF on startup
}

void HeatStepper_Pump() {
    Pump.enableOutputs();
}

void PumpGotoSampling(uint8_t process) {
    if (Pump.currentPosition() != 100) {
        Pump.moveTo(100);
        Pump.run();
    } else {
        Pump.setCurrentPosition(0);
        return process + 1;
    }
}

void PumpGotoPurge(int8_t process) {
    if (Pump.currentPosition() != 5000) {
        Pump.moveTo(5000);
        Pump.run();
    } else {
        Pump.setCurrentPosition(0);
        return process + 1;
    }
}
