int sensor = 4;

void setup() {
  Serial.begin(9600);
}

void loop() {
  //Charge the capacitor
  pinMode(sensor, OUTPUT);
  digitalWrite(sensor, HIGH);
  delay(1);

  //Discharge the capacitor
  pinMode(sensor, INPUT); 
  digitalWrite(sensor, LOW);
  delay(1);

  //Read the resulted value from the Infrared Sensor
  byte sensorValue = digitalRead(sensor);
  if (sensorValue == 0) { 
    Serial.println("Detecting White";
  } else {
    Serial.println("Detecting Black");
  }
}
