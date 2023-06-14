#pragma once

#include "../setup/modules.h"

// Setup Pump Stepper
AccelStepper Pump(1, PO_PUMP_STP);

void InitStepperPump() {
  // Opsætning af Transportbånds Steppermotor
  Pump.setPinsInverted(false, false, true);  // Inverts the "direction" pin
  Pump.setMaxSpeed(PUMP_MAX_SPEED);          // Max. hastighed    (steps/sek.)
  Pump.setAcceleration(PUMP_ACC);            // Max. acceleration (steps/sek.^2)
  Height.setCurrentPosition(0);              // Set the start position to 0
  Pump.disableOutputs();                     // Stepper is OFF on startup
}

void HeatStepper_Pump() {
  Pump.enableOutputs();
}

uint8_t PumpGotoSampling(uint8_t process) {
  if (Pump.currentPosition() != PUMP_SAMPLING_END) {
    Pump.moveTo(PUMP_SAMPLING_END);
    Pump.run();
  } else {
    Pump.setCurrentPosition(0);
    return process + 1;
  }
}

uint8_t PumpGotoPurge(uint8_t process) {
  if (Pump.currentPosition() != PUMP_PURGE) {
    Pump.moveTo(PUMP_PURGE);
    Pump.run();
  } else {
    Pump.setCurrentPosition(0);
    process++;
  }
  return process;
}
