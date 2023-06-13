#pragma once

// Internal Libraries
#include <Arduino.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>

// External Libraries
#include <Accelstepper.h>

// Config
#include "../../Config/constants.h"
#include "../../Config/pinout.h"

// Function prototypes
#include "./prototypes.h"

// System Control
#include "../system/control.cpp"
#include "../system/pinconfigs.cpp"

// Components
#include "../components/Sampling.cpp"
#include "../components/StepperHeight.cpp"
#include "../components/StepperPump.cpp"
#include "../components/StepperWheel.cpp"
