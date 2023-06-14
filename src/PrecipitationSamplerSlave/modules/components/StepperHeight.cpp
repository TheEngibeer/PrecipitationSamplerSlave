/*
    Real Time Clock handles timing using a Pmod RTCC (https://digilent.com/reference/pmod/pmodrtcc/start?redirect=1)

    Primary library: https://digilent.com/reference/_media/reference/pmod/pmodrtcc/rtcci2c.zip
    - Modified to latest Wire.h convention (Wire.receive() -> Wire.read() & Wire.send(xx) -> Wire.write(xx))
    Secondary library: https://github.com/PaulStoffregen/Time

    By
    Mads Rosenhoej Jeppesen - Aarhus 2021
    mrj@mpe.au.dk
*/

#pragma once

#include "../setup/modules.h"

// Setup Pump stepper
AccelStepper Height(1, PO_HEIGHT_STP, PO_HEIGHT_DIR);

// Related compoents
bool heightSwitch;

void InitStepperHeight() {
  // Opsætning af Transportbånds Steppermotor
  Height.setPinsInverted(false, false, true);  // Invertere signalet
  Height.setMaxSpeed(HEIGHT_MAX_SPEED);        // Max. hastighed    (steps/sek.)
  Height.setAcceleration(HEIGHT_ACC);          // Max. acceleratio (steps/sek.^2)
  Height.setCurrentPosition(0);
}

void HeatStepper_Height() {
  Height.enableOutputs();
}

uint8_t HeightGotoClearing(uint8_t process) {
  Height.moveTo(HEIGHT_CLEARING);

  if (Height.currentPosition() == HEIGHT_CLEARING) {
    Height.run();
    return process;

  } else {
    return process + 1;
  }
}

uint8_t HeightGotoSampling(uint8_t process) {
  ReadHeightSwitch();
  Height.setSpeed(-HEIGHT_MAX_SPEED);

  if (PI_SWTCH_HEIGHT == LOW) {
    Height.setSpeed(-HEIGHT_MAX_SPEED);
    Height.runSpeed();
  } else {
    Height.setSpeed(HEIGHT_MAX_SPEED);
    Height.setCurrentPosition(0);
    process++;
  }
  return process;
}

void ReadHeightSwitch() {
  int val = analogRead(PI_SWTCH_HEIGHT);
  if (heightSwitch >= 512) {
    heightSwitch = HIGH;
  }
}