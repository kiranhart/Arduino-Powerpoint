int buttonPin = 1;
int buttonValue = 0;

void setup() {
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  buttonValue = digitalRead(buttonPin);
  Serial.println(buttonValue);
}
