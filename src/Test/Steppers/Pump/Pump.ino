/*
MAKE SURE THE WHEEL IS TURNED TO "ZERO" POSITION BEFOR RUNNING THIS TEST!!!
*/

#include <AccelStepper.h>

#define PO_STEPPER_EN     4                   // Stepper enable signal to all steppers
#define PO_PUMP_STP       6                   // Pump stepper-step signal
#define PUMP_MAX_SPEED    2000                // Pump max speed (Steps/s)
#define PUMP_ACC          200                 // Pump Acceleration (Steps/s^2)
#define PUMP_SAMPLING_END 200                 // How many steps to o a sample
uint32_t PUMP_PURGE = PUMP_SAMPLING_END * 7;  // How many steps to do a fulle purge.

// Setup Pump stepper
AccelStepper Pump(PO_STEPPER_EN, PO_PUMP_STP, 0);

// Related compoents
uint8_t process = 0;  // Process handling

void setup() {
  Serial.begin(9600);
  pinMode(PO_PUMP_STP, OUTPUT);

  // Opsætning af Steppermotor
  Pump.setPinsInverted(false, false, true);  // Inverts the "direction" pin
  Pump.setMaxSpeed(PUMP_MAX_SPEED);          // Max. hastighed    (steps/sek.)
  Pump.setAcceleration(PUMP_ACC);            // Max. acceleration (steps/sek.^2)
  Pump.setCurrentPosition(0);                // Set the start position to 0
  Pump.setSpeed(1000);
  Serial.println("Signal Opened");
}

void loop() {
  switch (process) {
    case 0:  // Run pump for sampling
      Serial.print("Sampling with: ");
      Serial.print(PUMP_SAMPLING_END);
      Serial.println(" Steps");
      process++;
      break;
    case 1:
      process = PumpGotoSampling(process);
      break;
    case 2:
      Serial.print("PURGING with: ");
      Serial.print(PUMP_PURGE);
      Serial.println(" Steps");
      process++;
      break;

    case 3:  // Run pump for purge
      process = PumpGotoPurge(process);

      break;

    default:  // Set case to 0 if something is wrong
      process = 0;
      break;
  }
}

uint8_t PumpGotoSampling(uint8_t process) {
  Pump.moveTo(PUMP_SAMPLING_END);
  while (Pump.currentPosition() != PUMP_SAMPLING_END - 100)
    Pump.run();
  Pump.stop();  // Stop as fast as possible: sets new target
  Pump.runToPosition();
  // Now stopped after quickstop
  process++;
}

uint8_t PumpGotoPurge(uint8_t process) {
  Pump.moveTo(PUMP_PURGE);
  while (Pump.currentPosition() != PUMP_PURGE - 100)  // Full speed up to 300
    Pump.run();
  Pump.stop();  // Stop as fast as possible: sets new target
  Pump.runToPosition();
  // Now stopped after quickstop
  process++;
}