#pragma once

#include "../setup/modules.h"

uint8_t taskComplete = 0;
uint8_t sampleNo     = 0;

void SamplingProcess() {
  switch (taskComplete) {
    case 0:  // Zeroing all steppers
      taskComplete = ZeroSteppers(taskComplete);
      break;
    case 1:
      // Har ikke kodet varmet endnu!
      taskComplete++;

      break;
    case 2:  // Sampling loop
      taskComplete = SampleCycle(taskComplete);

      break;
      // Go to sleep

    default:
      break;
  }
}