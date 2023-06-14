#pragma once

#include "../modules/setup/modules.h"

// ------------------------------------------------------------ //
//                       Heating system                         //
// ------------------------------------------------------------ //

#define TSENSOR_PERIOD     1000
#define TARGET_TEMPERATURE 20.0  // °C
#define HYSTERESE          5.0   // °C

// ------------------------------------------------------------ //
//                          STEPPERS                            //
// ------------------------------------------------------------ //

// SAMPLEWHEEL STEPPER
#define WHEEL_MAX_SPEED    500
#define WHEEL_ACC          100

// PUMP STEPPER
#define PUMP_MAX_SPEED     300
#define PUMP_ACC           100
#define PUMP_SAMPLING_END  100   // How many steps to do make a sample
#define PUMP_PURGE         5000  // How many steps to do a full purge

// HEIGHT STEPPER
#define HEIGHT_MAX_SPEED   300
#define HEIGHT_ACC         100
#define HEIGHT_CLEARING    200  // How many steps to be clear of needles
