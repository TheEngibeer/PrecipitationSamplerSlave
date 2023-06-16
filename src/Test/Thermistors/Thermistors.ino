#define PA_TEMP_FUNNEL 14  // Temperature sensor for the funnel
#define PA_TEMP_PUMP   15  // Temperature sensor for the Pump

unsigned long lastMillis = 0;
unsigned long Interval   = 2;  // In seconds
int Funnel               = 0;  // Funnel reading
int Pump                 = 0;  // pump reading
int prevFunnel           = 0;
int prevPump             = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("Program Startet");
}

void loop() {
  if (millis() - lastMillis >= 2000) {
    lastMillis = millis();
    Funnel     = analogRead(PA_TEMP_FUNNEL);
    Pump       = analogRead(PA_TEMP_PUMP);
    Serial.print("Funnel:   ");
    Serial.println(Funnel);
  }
}