/*
 * Code by Kiran Hart
 * https://www.GitHub.com/kiranhart/
 */


/*
Define the pins of which the motors are connected to,
we'll make them constants since don't want these to be
changed anywhere else in the program but here.
 */
private const int LM1 = 2; // Left Motor #1
private const int LM2 = 3; // Left Motor #2
private const int RM1 = 4; // Right Motor #1
private const int RM2 = 5; // Right Motor #2

/*
Create variables to store which digital pin the IR
sensors are connected to. (Which digital pin "R" 
connects to from the QTI IR Sensor.
 */
private int leftSensorPin = 6;
private int rightSensorPin = 7;

void setup() {
  //Start the serial monitor so we can print
  //any important data to be viewed by the user.
  Serial.begin(9600);
  
  //Setup the pinModes for the motors
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT); 
}

/*
 * This method will be used to charge and discharge the capacitor on the IR sensor, doing
 * this will allow us to read either a zero or one. If it reads zero that means that it's 
 * detecting a white surface, if it reads a one then that means it's detecting a black surface.
 */
int getIRSensorValue(int sensorPin) {
  //Charge the capacitor 
  pinMode(sensorPin, OUTPUT);
  digitalWrite(sensorPin, HIGH);
  delay(1);
  //Discharge the capacitor
  pinMode(2, INPUT);
  digitalWrite(sensorPin, LOW);
  delay(1);
  return digitalRead(sensorPin);
}

/*
 * This will be used to control the motors, each motor has two values, depending on the values
 * either high or low (0 -255) the speed can be changed, same for the rotation direction.
 */
void moveMotors(int leftSpeedOne, int leftSpeedTwo, int rightSpeedOne, int rightSpeedTwo) {
  analogWrite(LM1, leftSpeedOne);
  analogWrite(LM2, leftSpeedTwo);
  analogWrite(RM1, rightSpeedOne);
  analogWrite(RM2, rightSpeedOne);
}

void loop() {
  //Both of the sensors are detecting a white surface.
  if (getIRSensorValue(leftSensorPin) == 0 && getIRSensorValue(rightSensorPin) == 0) {
    //Move the motors forward, at a constant speed 
    moveMotors(HIGH, LOW, HIGH, LOW);
  } 

  //Left sensor is detecting a black surface, Right sensor is detecting a white surface
  if (getIRSensorValue(leftSensorPin) == 1 && getIRSensorValue(rightSensorPin) == 0) {
    
  }

  //Left sensor is detecting a white surface, Right sensor is detecting a black surface
  if (getIRSensorValue(leftSensorPin) == 0 && getIRSensorValue(rightSensorPin) == 1) {
    
  }

  //Both of the sensors are detecting a black surface, stop the robot.
  if (getIRSensorValue(leftSensorPin) == 1 && getIRSensorValue(rightSensorPin) == 1) {
    moveMotors(LOW, LOW, LOW, LOW);
  }
}
