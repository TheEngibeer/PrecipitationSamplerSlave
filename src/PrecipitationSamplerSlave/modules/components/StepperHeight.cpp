#pragma once

#include "../setup/modules.h"

// Setup Pump stepper
AccelStepper Height(1, PO_HEIGHT_STP, PO_HEIGHT_DIR);

// Related compoents
bool heightSwitch;

void InitStepperHeight() {
  // Opsætning af Transportbånds Steppermotor
  Height.setPinsInverted(false, false, true); // Invertere signalet
  Height.setMaxSpeed(300);                    // Max. hastighed    (steps/sek.)
  Height.setAcceleration(100);                // Max. acceleratio (steps/sek.^2)
  Height.setCurrentPosition(0);
}

void HeatStepper_Height() {
  Height.enableOutputs();
}

void HeightGotoClearing(uint8_t process) {
  Height.moveTo(200);

  if (Height.currentPosition() == 200) {

    Height.run();
    return process;

  } else {

    return process + 1;
  }
}

void HeightGotoSampling(uint8_t process) {
  ReadHeightSwitch();

  if (PI_SWTCH_HEIGHT == LOW) {

    Height.runSpeed();
    return process;

  } else if (PI_SWTCH_HEIGHT == HIGH) {

    Height.setCurrentPosition(0);
    return process + 1;
  }
}

void ReadHeightSwitch() {

  int val = analogRead(PI_SWTCH_HEIGHT);
  if (heightSwitch >= 512) {
    heightSwitch = HIGH;
  }
}