#pragma once

#include "../setup/modules.h"

// Setup Pump stepper
AccelStepper Height(1, PO_HEIGHT_STP, PO_HEIGHT_DIR);

void InitStepperHeight() {
  // Opsætning af Transportbånds Steppermotor
  Height.setPinsInverted(false, false, true); // Invertere signalet
  Height.setMaxSpeed(1000);                   // Max. hastighed    (steps/sek.)
  Height.setAcceleration(50);                 // Max. acceleration (steps/sek.^2)
}