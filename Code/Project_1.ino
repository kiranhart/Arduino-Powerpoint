int ledPin = 1;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  digitalWrite(ledPin, HIGH);
  delay(1000); //wait one second
  digitalWrite(ledPin, LOW);
  delay(1000); //wait another second
}
