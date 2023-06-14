/*
MAKE SURE THE WHEEL IS TURNED TO "ZERO" POSITION BEFOR RUNNING THIS TEST!!!
*/

#include <AccelStepper.h>

#define PO_HEIGHT_STP   5   // Height stepper-step signal
#define PO_HEIGHT_DIR   7   // Height stepper direction signal
#define PI_SWTCH_HEIGHT 12  // Height limmitswitch

// Setup Pump stepper
AccelStepper Height(1, PO_HEIGHT_STP, PO_HEIGHT_DIR);

// Related compoents
bool heightSwitch;
uint8_t process   = 0;    // Process handling
uint16_t moveDown = 200;  // Steps to move down

void setup() {
  // Opsætning af Transportbånds Steppermotor
  Height.setPinsInverted(false, false, true);  // Invertere signalet
  Height.setMaxSpeed(300);                     // Max. hastighed    (steps/sek.)
  Height.setAcceleration(100);                 // Max. acceleratio (steps/sek.^2)
}

void loop() {
  switch (process) {
    case 0:  // Move clear of the needles
      Height.moveTo(moveDown);

      if (Height.currentPosition() == moveDown) {
        Height.run();

      } else {
        Serial.println("Going to the TOP!");
        process++;
        delay(1500);
        break;
      }
      break;
    case 1:  // Move until at the top
      ReadHeightSwitch();

      if (PI_SWTCH_HEIGHT == LOW) {
        Height.setSpeed(-300);
        Height.runSpeed();
      } else {
        Height.setSpeed(300);
        Height.setCurrentPosition(0);
        process++;
        break;
      }
      break;
    case 2:  // Wait for 3 sek.
      delay(3000);
      Serial.print("Clearing needles. Moving ");
      Serial.print(moveDown);
      Serial.println(" steps down to stay clear");
      process = 0;
      break;

    default:  // Set case to 0 if something is wrong
      process = 0;
      break;
  }
}

void ReadHeightSwitch() {
  int val = analogRead(PI_SWTCH_HEIGHT);
  if (heightSwitch >= 512) {
    heightSwitch = HIGH;
  }
}