int buttonPin = 1;
int buttonValue = 0;
int ledPin = 2;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  buttonValue = digitalRead(buttonPin);
  Serial.println(buttonValue);

  //We can use if/else statements for this or we
  //can use a conditional operator, you decide.

  // Heres using an if / else statement
  if (buttonValue == 1) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

  //Here's using a conditional operator, you only need to use one, a 
  //I suggest using an if / else if you don't understand ? operators
  (buttonValue == 1) ? digitalWrite(ledPin, HIGH) : digitalWrite(ledPin, LOW);
}
