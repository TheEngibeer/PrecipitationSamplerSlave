/*
MAKE SURE THE WHEEL IS TURNED TO "ZERO" POSITION BEFOR RUNNING THIS TEST!!!
*/

#include <AccelStepper.h>

#define PO_PUMP_STP       6     // Pump stepper-step signal
#define PUMP_MAX_SPEED    500   // Pump max speed (Steps/s)
#define PUMP_ACC          100   // Pump Acceleration (Steps/s^2)
#define PUMP_SAMPLING_END 200   // How many steps to o a sample
#define PUMP_PURGE        5000  // How many steps to do a fulle purge.

// Setup Pump stepper
AccelStepper Pump(1, PO_HEIGHT_STP, PO_HEIGHT_DIR);

// Related compoents
bool heightSwitch;
uint8_t process   = 0;    // Process handling
uint16_t moveDown = 200;  // Steps to move down

void setup() {
  // Opsætning af Transportbånds Steppermotor
  Pump.setPinsInverted(false, false, true);  // Inverts the "direction" pin
  Pump.setMaxSpeed(PUMP_MAX_SPEED);          // Max. hastighed    (steps/sek.)
  Pump.setAcceleration(PUMP_ACC);            // Max. acceleration (steps/sek.^2)
  Height.setCurrentPosition(0);              // Set the start position to 0
}

void loop() {
  switch (process) {
    case 0:  // Run pump for sampling
      process = PumpGotoSampling(process);

      break;
    case 1:  // Run pump for purge
      process = PumpGotoPurge(process);

      break;
    default:  // Set case to 0 if something is wrong
      process = 0;
      break;
  }
}

uint8_t PumpGotoSampling(uint8_t process) {
  if (Pump.currentPosition() != PUMP_SAMPLING_END) {
    Pump.moveTo(PUMP_SAMPLING_END);
    Pump.run();
  } else {
    Pump.setCurrentPosition(0);
    Serial.print("Sampling with: ");
    Serial.print(PUMP_PURGE);
    Serial.println(" Steps");
    process++;
  }
  return process;
}

uint8_t PumpGotoPurge(uint8_t process) {
  if (Pump.currentPosition() != PUMP_PURGE) {
    Pump.moveTo(PUMP_PURGE);
    Pump.run();
  } else {
    Pump.setCurrentPosition(0);
    Serial.print("Sampling with: ");
    Serial.print(PUMP_SAMPLING_END);
    Serial.println(" Steps");
    process++;
  }
  return process;
}