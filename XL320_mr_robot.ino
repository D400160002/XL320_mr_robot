
// ======================================
// Dynamixel XL-320 three servo robot arm
// ======================================

#include "XL320.h"

// Half Duplex Hardware Serial to read data back from the servos
#include <HalfDuplexHardwareSerial.h>

// Name your robot!
XL320 robot;

// Set some variables for incrementing position & LED colour
char rgb[] = "rgbypcwo";

// Set the colours you want for moving or staying still
int movingColour = 0;
int stillColour = 1;

// Set laser intensity
int laserIntensity = 0;
int laserPin = 3;

// Delay between sending & receiving data
int delayBetweenSendReceive = 10;

// Set the default servoID to talk to
int servoOneID = 1;
int servoTwoID = 2;
int servoThreeID = 3;

// Set the servo LEDs
int servoOneLED = 0;
int servoTwoLED = 0;
int servoThreeLED = 0;

// Remember the last servo position to change the LED colour when moving
int servoOnePosition = 0;
int servoTwoPosition = 0;
int servoThreePosition = 0;

byte buffer[256];

void setup() {
  
  // Setup half duplex
  pinMode(0, INPUT_PULLUP);
  pinMode(1, INPUT_PULLUP);
  
  // Set the input pot pins
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  
  // LED to show packet errors (goes out for errors)
  pinMode(13, OUTPUT);
  
  // Setup the laser
  pinMode(laserPin, OUTPUT);
  
  // Talk serial with your servo by connecting the servo input data line to Digital TX 1
  HalfDuplexSerial.begin(115200);
  HalfDuplexSerial.setTimeout(delayBetweenSendReceive);

  // Initialise your robot
  robot.begin(HalfDuplexSerial); // Hand in the serial object you're using
  
  // I like fast moving servos, so set the joint speed to max!
  robot.setJointSpeed(servoOneID, 1023);
  robot.readPacket(buffer,256); // After each command to be ready for next command
  robot.setJointSpeed(servoTwoID, 1023);
  robot.readPacket(buffer,256);
  robot.setJointSpeed(servoThreeID, 1023);
  robot.readPacket(buffer,256);

}

void loop() {
  
  servoOneLED = servoTwoLED = servoThreeLED = stillColour;

  int servoOnePositionNow = 1024 - analogRead(A0);
  int servoTwoPositionNow = analogRead(A1);
  int servoThreePositionNow = analogRead(A2);

  // Set LED to red when moving
  if (abs(servoOnePosition - servoOnePositionNow) > 10) {
    servoOneLED = movingColour;
  }
  if (abs(servoTwoPosition - servoTwoPositionNow) > 10) {
    servoTwoLED = movingColour;
  }
  if (abs(servoThreePosition - servoThreePositionNow) > 10) {
    servoThreeLED = movingColour;
  }
  
  // Fade the laser intensity
  analogWrite(laserPin, laserIntensity);
  laserIntensity = (laserIntensity + 1) % 10;

  // Set servoPositions
  servoOnePosition = servoOnePositionNow;
  servoTwoPosition = servoTwoPositionNow;
  servoThreePosition = servoThreePositionNow;
  
  // Set LED Red
  robot.LED(servoOneID, &rgb[servoOneLED] );
  robot.readPacket(buffer,256);
  robot.LED(servoTwoID, &rgb[servoTwoLED] );
  robot.readPacket(buffer,256);
  robot.LED(servoThreeID, &rgb[servoThreeLED] );
  robot.readPacket(buffer,256);

  // Servo test.. select a random servoID and colour
  robot.moveJoint(servoOneID, servoOnePosition);
  robot.readPacket(buffer,256);
  robot.moveJoint(servoTwoID, servoTwoPosition);
  robot.readPacket(buffer,256);
  robot.moveJoint(servoThreeID, servoThreePosition);
  robot.readPacket(buffer,256);
  
  // To read back from the servo
//  XL320::Packet pp = XL320::Packet(buffer, robot.readPacket(buffer,256));
//  if (pp.isValid()) {
//    // Set pin 13 HIGH so we know!
//    digitalWrite(13, HIGH);
//  } else {
//    digitalWrite(13, LOW);
//  }
//  delay(delayBetweenSendReceive);
}
