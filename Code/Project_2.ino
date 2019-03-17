int pin = 3;
int brightness = 0;
int increment = 5;

void setup() {
  pinMode(pin, OUTPUT);
}

void loop() {
  analogWrite(pin, brightness);
  brightness += increment;

  if (brightness == 0 || brightness == 255) {
    increment = -increment;
  }

  delay(30);
}
