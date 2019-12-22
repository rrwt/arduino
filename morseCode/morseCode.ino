#define dotDelay 200
#define dashDelay 600
#define ledPin 13

char* letters[] = {
  ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....",  // A - H
  "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.",  // I - P
  "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-",  // Q - X
  "-.--", "--.."
};

char* numbers[] = {
  ".---", "..---", "...--", "....-", ".....",
  "-....", "--...", "---..", "----.", "-----"
};


void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    char ch = Serial.read();

    if (ch >= 'a' && ch <= 'z') {
      flashSequence(letters[ch-'a']);
    } else if(ch >= 'A' && ch <= 'Z') {
      flashSequence(letters[ch-'A']);
    } else if(ch >= '0' && ch <= '9') {
      flashSequence(numbers[ch-'0']);
    } else {
      delay(dotDelay * 4);  // default case = space bar
    }
  }
}

void flashSequence(char *charSequence) {
  for (int i = 0; i < strlen(charSequence); i++) {
    flashChar(charSequence[i]);
  }
}

void flashChar(char c) {
  digitalWrite(ledPin, HIGH);

  if (c == '.') {
    delay(dotDelay);
  } else{
    delay(dashDelay);
  }

  digitalWrite(ledPin, LOW);
  delay(dotDelay);
}
