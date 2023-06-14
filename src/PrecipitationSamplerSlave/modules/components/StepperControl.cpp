#pragma once

#include "../setup/modules.h"

uint8_t zeroProcess    = 0;
uint8_t stepperProcess = 0;

uint8_t ZeroSteppers(uint8_t zeroStatus) {
  if (zeroProcess < 2) {
    switch (zeroProcess) {
      case 0:
        zeroProcess = HeightGotoClearing(zeroProcess);
        break;
      case 1:
        zeroProcess = WheelGotoHome(zeroProcess);
        break;
      case 2:
        break;
    }
  } else {
    zeroStatus++;
  }
  return zeroStatus;
}

uint8_t SampleCycle(uint8_t sampleCount) {
  switch (stepperProcess) {
    case 0:
      stepperProcess = HeightGotoClearing(stepperProcess);
      break;
    case 1:
      stepperProcess = WheelGotoSampling(stepperProcess);
      break;
    case 2:
      stepperProcess = HeightGotoSampling(stepperProcess);
      break;
    case 3:
      stepperProcess = PumpGotoSampling(stepperProcess);
      break;
    case 4:
      stepperProcess = HeightGotoClearing(stepperProcess);
      break;
    case 5:
      stepperProcess = WheelGotoPurge(stepperProcess);
      break;
    case 6:
      stepperProcess = PumpGotoPurge(stepperProcess);
      break;
    case 7:
      stepperProcess = 0;
      sampleCount++;
      break;

    default:
      stepperProcess = 0;
      break;
  }
  return sampleCount;
}