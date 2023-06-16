// Quickstop.pde
// -*- mode: C++ -*-
//
// Check stop handling.
// Calls stop() while the stepper is travelling at full speed, causing
// the stepper to stop as quickly as possible, within the constraints of the
// current acceleration.
//
// Copyright (C) 2012 Mike McCauley
// $Id:  $

#define PO_PUMP_STP 6  // Pump stepper-step signal

#include <AccelStepper.h>

// Define a stepper and the pins it will use
AccelStepper stepper(AccelStepper::FULL4WIRE, PO_PUMP_STP, -1, -1, -1, false);

void setup() {
  Serial.begin(9600);
  stepper.setMaxSpeed(2000);
  stepper.setAcceleration(5000);
}

void loop() {
  stepper.moveTo(500);
  while (stepper.currentPosition() != 300)  // Full speed up to 300
    stepper.run();
  stepper.stop();  // Stop as fast as possible: sets new target
  stepper.runToPosition();
  // Now stopped after quickstop

  // Now go backwards
  stepper.moveTo(-500);
  while (stepper.currentPosition() != 0)  // Full speed basck to 0
    stepper.run();
  stepper.stop();  // Stop as fast as possible: sets new target
  stepper.runToPosition();
  // Now stopped after quickstop
}
