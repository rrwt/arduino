#define inputPin 5


void setup() {
  pinMode(inputPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  int pinInput = digitalRead(inputPin);
  Serial.println(pinInput);
  delay(1000);
}
