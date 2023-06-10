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

/*
// Components
#include "../components/DS3231.cpp"
#include "../components/HCSR04.cpp"
#include "../components/Lid.cpp"
#include "../components/SD-Card.cpp"
#include "../components/SleepControl.cpp"
*/
