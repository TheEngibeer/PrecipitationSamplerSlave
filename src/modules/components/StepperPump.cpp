#pragma once

#include "../setup/modules.h"

// Setup Pump Stepper
AccelStepper Pump(1, PO_PUMP_STP);

void InitStepperPump() {
  // Opsætning af Transportbånds Steppermotor
  Pump.setPinsInverted(false, false, true); // Invertere signalet
  Pump.setMaxSpeed(1000);                   // Max. hastighed    (steps/sek.)
  Pump.setAcceleration(50);                 // Max. acceleration (steps/sek.^2)
}