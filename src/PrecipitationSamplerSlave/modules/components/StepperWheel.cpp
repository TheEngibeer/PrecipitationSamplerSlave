#pragma once

#include "../setup/modules.h"

// Setup Wheel stepper
AccelStepper Wheel(1, PO_WHEEL_STP, 0);

void InitStepperWheel() {
  // Opsætning af Transportbånds Steppermotor
  Wheel.setPinsInverted(false, false, true); // Invertere signalet
  Wheel.setMaxSpeed(1000);                   // Max. hastighed    (steps/sek.)
  Wheel.setAcceleration(50);                 // Max. acceleration (steps/sek.^2)
}

void HeatStepper_Wheel() {
  Wheel.enableOutputs();
}
