#pragma once

#include "../setup/modules.h"

// Setup Wheel stepper
AccelStepper Wheel(1, PO_WHEEL_STP, 0);

// Related components
bool wheelSwitches[2];  // wheelswitch[1] = Upper (Sample) , wheelswitch[2] = Lower (Purge)

void InitStepperWheel() {
  // Opsætning af Transportbånds Steppermotor
  Wheel.setPinsInverted(false, false, true);  // Invertere signalet
  Wheel.setMaxSpeed(WHEEL_MAX_SPEED);         // Max. hastighed    (steps/sek.)
  Wheel.setAcceleration(WHEEL_ACC);           // Max. acceleration (steps/sek.^2)
  Wheel.setCurrentPosition(0);
  Wheel.disableOutputs();
}

void HeatStepper_Wheel() {
  Wheel.enableOutputs();
}

uint8_t WheelGotoHome(uint8_t process) {
  ReadWheelSwitches();

  // Set zeroing
  if ((wheelSwitches[1] = HIGH) && (wheelSwitches[2] = HIGH)) {
    Wheel.setCurrentPosition(0);
    process++;
  } else {
    Wheel.runSpeed();
  }
  return process;
}

uint8_t WheelGotoSampling(uint8_t process) {
  ReadWheelSwitches();

  // Go to a Sampling hole
  if ((wheelSwitches[1] = HIGH) && (wheelSwitches[2] = LOW)) {
    process++;
  } else {
    Wheel.runSpeed();
  }
  return process;
}

uint8_t WheelGotoPurge(uint8_t process) {
  ReadWheelSwitches();

  // Go to a Sampling hole
  if ((wheelSwitches[1] = LOW) && (wheelSwitches[2] = HIGH)) {
    process++;
  } else {
    Wheel.runSpeed();
  }
  return process;
}

void ReadWheelSwitches() {
  // Reading and converting upper switch
  int valUpper = analogRead(PI_SWTCH_UPPER);
  if (valUpper >= 512) {
    wheelSwitches[1] = HIGH;
  } else {
    wheelSwitches[1] = LOW;
  }

  // Reading and converting lower switch
  int valLower = analogRead(PI_SWTCH_LOWER);
  if (valLower >= 512) {
    wheelSwitches[2] = HIGH;
  } else {
    wheelSwitches[2] = LOW;
  }
}
