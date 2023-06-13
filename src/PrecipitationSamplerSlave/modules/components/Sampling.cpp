#pragma once

#include "../setup/modules.h"

bool taskComplete = 0;

enum process {
  INIT_HEATING,
  HEAT_WAIT,
  SAMPLING,
  SLEEP
};

void SamplingProcess() {
}