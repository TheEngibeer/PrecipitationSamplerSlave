/*
Duty cycle is between 0 - 255
0% = 0
25% = 64
50% = 127
75% = 191
100% = 255

*/

#define PO_HEAT_FUNNEL 9   // Output signal to turn on funnel heating
#define PO_HEAT_PUMP   10  // Output signal to turn on pump heating

uint8_t percent          = 99;
uint8_t process          = 0;
int dutyCycle            = round((percent / 100) * 255);
unsigned long lastMillis = 0;
uint32_t HeatTime        = 30;  // In seconds

void setup() {
  Serial.begin(9600);

  pinMode(PO_HEAT_FUNNEL, OUTPUT);
  pinMode(PO_HEAT_PUMP, OUTPUT);

  Serial.print("Heating both at ");
  Serial.print(percent);
  Serial.println("%");
}

void loop() {
  switch (process) {
    case 0:
      Serial.print("Heating Funnel at ");
      Serial.print(percent);
      Serial.print("%, for ");
      Serial.print(HeatTime);
      Serial.println(" seconds");
      process++;
      delay(2000);
      break;
    case 1:
      if (millis() - lastMillis <= 3000) {
        analogWrite(PO_HEAT_FUNNEL, 0);
      } else {
        lastMillis = millis();
        process++;
      }

      break;

    case 2:
      Serial.print("Heating Pump at ");
      Serial.print(percent);
      Serial.print("%, for ");
      Serial.print(HeatTime);
      Serial.println(" seconds");
      process++;
      delay(2000);

      break;

    case 3:
      if (millis() - lastMillis <= HeatTime * 1000) {
        analogWrite(PO_HEAT_PUMP, dutyCycle);
      } else {
        lastMillis = millis();
        process    = 0;
      }
      break;

    default:
      break;
  }
}