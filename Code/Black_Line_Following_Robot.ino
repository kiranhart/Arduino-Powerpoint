/*
   Code by Kiran Hart
   https://www.GitHub.com/kiranhart/
*/

/*
  Define the pins of which the motors are connected to,
  we'll make them constants since don't want these to be
  changed anywhere else in the program but here.
*/
const int LM1 = 9; // Left Motor #1
const int LM2 = 10; // Left Motor #2
const int RM1 = 11; // Right Motor #1
const int RM2 = 12; // Right Motor #2

/*
  Create variables to store which digital pin the IR
  sensors are connected to. (Which digital pin "R"
  connects to from the QTI IR Sensor.
*/
int leftSensorPin = 2;
int rightSensorPin = 4;

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
   This method will be used to charge and discharge the capacitor on the IR sensor, doing
   this will allow us to read either a zero or one. If it reads zero that means that it's
   detecting a white surface, if it reads a one then that means it's detecting a black surface.
*/
int getIRSensorValue(int sensorPin) {
  //Charge the capacitor
  pinMode(sensorPin, OUTPUT);
  digitalWrite(sensorPin, HIGH);
  delay(1);
  //Discharge the capacitor
  pinMode(sensorPin, INPUT);
  digitalWrite(sensorPin, LOW);
  delay(1);
  return digitalRead(sensorPin);
}

/*
   This will be used to control the motors, each motor has two values, depending on the values
   either high or low (0 -255) the speed can be changed, same for the rotation direction.

   In Our case: 
   Left/Right Speed One > 0 && Left/Right Speed Two == 0 will move the motors in the correct direction
   If your's is moving backwards you can switch the two wire pins for each motor, for example, connect
   the wire that goes to pin 3 of the L293D to pin 6, and 6 to 3. Same for the other motor if needed.

   If you don't want to rewire setting the left/right speed two > 0 and left/right speed one == 0 may work.
   
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
    moveMotors(255, 0, 90, 0);
  } else if (getIRSensorValue(leftSensorPin) == 1 && getIRSensorValue(rightSensorPin) == 0) {
    /*If the left sensor is detecting a black surface / line slow down the left wheel so that 
    the right one will be moving faster allowing the robot to turn left.*/
    moveMotors(0, 0, 255, 0);
  } else if (getIRSensorValue(leftSensorPin) == 0 && getIRSensorValue(rightSensorPin) == 1) {
    /*If the right sensor is detecting a black surface / line slow down the right wheel so 
    the left one will be moving faster causing the robot to turn right*/
    moveMotors(255, 0, 0, 0);
  }
}
