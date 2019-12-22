#define ledPin LED_BUILTIN
int delayPeriod = 50;
int delayIncrement = 25;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  for(int i = 0; i < 100; i++){
    digitalWrite(ledPin, HIGH);
    delay(delayPeriod + i * delayIncrement);

    digitalWrite(ledPin, LOW);
    delay(delayPeriod + i * delayIncrement); 
  }
}
