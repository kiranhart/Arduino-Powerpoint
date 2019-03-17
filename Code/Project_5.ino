int temperaturePin = A0;
float temperature = 0;

void setup() {
  pinMode(temperaturePin, INPUT);
  Serial.begin(9600);
}

void loop() {
  temperature = analogRead(temperaturePin);
  //Convert to Celsius
  //Formula (fahrenheit - 32) * 5 / 9
  temperature = (temperature - 32) * 5 / 9;
  Serial.println(temperature);
}
