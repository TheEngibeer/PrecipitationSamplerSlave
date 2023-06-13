/*
  Ice Nucleation Controller (Field Version) system pinout
  Naming pattern (all uppercase):
  P   + <I:input, T: interrupt input, A:analog input, O:output, P:pwm output>_
    + <general part name>_
    + <purpose>_
    + <where applicable: left, right, top, bottom, position etc...>
  Mads Rosenhøj Jeppesen
  Aarhus University
  2023
*/

#pragma once

#include "../modules/setup/modules.h"

// ------------------------------------------------------------ //
//                 Arduino/Arduino communication                //
// ------------------------------------------------------------ //

#define PO_ARDUINO_COM 3 // Communication from Slave to master

// ------------------------------------------------------------ //
//                     Stepper Controllers                      //
// ------------------------------------------------------------ //

#define PO_WHEEL_STP 4  // Sample Wheel stepper-step signal
#define PO_STEPPER_EN 5 // Stepper enable signal to all steppers
#define PO_HEIGHT_STP 6 // Height stepper-step signal
#define PO_PUMP_STP 7   // Pump stepper-step signal
#define PO_HEIGHT_DIR 8 // Height stepper direction signal

// ------------------------------------------------------------ //
//                        Heat Elements                         //
// ------------------------------------------------------------ //

#define PO_HEAT_FUNNEL 9 // Output signal to turn on funnel heating
#define PO_HEAT_PUMP 10  // Output signal to turn on pump heating

// ------------------------------------------------------------ //
//                     Mechanical switches                      //
// ------------------------------------------------------------ //

#define PI_SWTCH_UPPER 11  // Sample wheel encoding switch (Sample hole)
#define PI_SWTCH_LOWER 12  // Sample wheel encoding switch (Flush hole)
#define PI_SWTCH_HEIGHT 13 // Height limit switch

// ------------------------------------------------------------ //
//                      Temp. sensors                           //
// ------------------------------------------------------------ //

#define PA_TEMP_FUNNEL 15 // Limitswitch for "Lid Closed"
#define PA_TEMP_PUMP 16

// ------------------------------------------------------------ //
//                         Load cells                           //
// ------------------------------------------------------------ //

#define PI_LOADCELL_DT 17
#define PI_LOADCELL_SCK 18
