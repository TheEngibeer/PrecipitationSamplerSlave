#pragma once

#include "../setup/modules.h"

void ZeroSteppers() {
  uint8_t ZeroProcess = 0;

  switch (ZeroProcess) {
  case 0:
    Height_Clearing();
    break;
  case 1:

    break;
  }

  /*
  1) Zero Wheel
      a) Go XXX steps down in height
      b) Keep running until ON/ON signal
      c) Set location to 0
  2) Zero height
      a) go up until ON signal
      b) Set location to 0.
  */
}