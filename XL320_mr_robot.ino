

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
int servoFourID = 4;
int servoFiveID = 5;
int servoSixID = 6;
int servoSevenID = 7;
int servoEightID = 8;
int servoNineID = 9;

// Set the servo LEDs
int servoOneLED = 0;
int servoTwoLED = 0;
int servoThreeLED = 0;
int servoFourLED = 0;
int servoFiveLED = 0;
int servoSixLED = 0;
int servoSevenLED = 0;
int servoEightLED = 0;
int servoNineLED = 0;

// Zero starting positions
int servoOnePosition = 500;
int servoTwoPosition = 500;
int servoThreePosition = 450;
int servoFourPosition = 500;
int servoFivePosition = 500;
int servoSixPosition = 500;
int servoSevenPosition = 500;
int servoEightPosition = 500;
int servoNinePosition = 500;

int positionStore = 500;
int goingUp = true;

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
  // Use HalfDuplexSerial1 for a Leonardo, or HalfDuplexSerial for a Uno.
  HalfDuplexSerial1.begin(115200);
  HalfDuplexSerial1.setTimeout(delayBetweenSendReceive);

  // Initialise your robot
  robot.begin(HalfDuplexSerial1); // Hand in the serial object you're using
  
  // I like fast moving servos, so set the joint speed to max!
  for (int i = 1; i < 10; i++) {
    robot.setJointSpeed(i, 1023);
    robot.readPacket(buffer,256);
  }

  // Squat position
  servoOnePosition = 500;
  servoTwoPosition = 350;
  servoThreePosition = 550;
  servoFourPosition = 500;
  servoFivePosition = 350;
  servoSixPosition = 650;
  servoSevenPosition = 500;
  servoEightPosition = 350;
  servoNinePosition = 650;

}

void loop() {
  
  // ******* MOVING TWO JOINTS ON EACH LEG ******** //
//  int positionNow = positionStore;
//  if (goingUp && positionStore < 550) {
//    positionNow += 10;
//  } else {
//    goingUp = false;
//  }
//  if (!goingUp && positionStore > 450) {
//    positionNow -= 10;
//  } else {
//    goingUp = true;
//  }
//  positionStore = positionNow;
//  robot.moveJoint(2, positionStore);
//  robot.readPacket(buffer,256);
//  robot.moveJoint(3, positionStore);
//  robot.readPacket(buffer,256);
//  robot.moveJoint(5, positionStore);
//  robot.readPacket(buffer,256);
//  robot.moveJoint(6, positionStore);
//  robot.readPacket(buffer,256);
//  robot.moveJoint(8, positionStore);
//  robot.readPacket(buffer,256);
//  robot.moveJoint(9, positionStore);
//  robot.readPacket(buffer,256);
  // ******* END MOVING TWO JOINTS ON EACH LEG ******** //
  
  // ******* START SETTINGS ******* //
  // Squat positions
//  servoOnePosition = 500;
//  servoTwoPosition = 350;
//  servoThreePosition = 550;
//  servoFourPosition = 500;
//  servoFivePosition = 350;
//  servoSixPosition = 650;
//  servoSevenPosition = 500;
//  servoEightPosition = 350;
//  servoNinePosition = 650;
//  robot.moveJoint(1, servoOnePosition);
//  robot.readPacket(buffer,256);
//  robot.moveJoint(2, servoTwoPosition);
//  robot.readPacket(buffer,256);
//  robot.moveJoint(3, servoThreePosition);
//  robot.readPacket(buffer,256);
//  robot.moveJoint(4, servoFourPosition);
//  robot.readPacket(buffer,256);
//  robot.moveJoint(5, servoFivePosition);
//  robot.readPacket(buffer,256);
//  robot.moveJoint(6, servoSixPosition);
//  robot.readPacket(buffer,256);
//  robot.moveJoint(7, servoSevenPosition);
//  robot.readPacket(buffer,256);
//  robot.moveJoint(8, servoEightPosition);
//  robot.readPacket(buffer,256);
//  robot.moveJoint(9, servoNinePosition);
//  robot.readPacket(buffer,256);
  
  int servoOnePositionNow = servoOnePosition;
  int servoFourPositionNow = servoFourPosition;
  int servoSevenPositionNow = servoSevenPosition;
  
  if (goingUp && servoOnePosition < 600) {
    servoOnePositionNow += 10;
    servoFourPositionNow += 10;
    servoSevenPositionNow += 10;
  } else {
    goingUp = false;
  }
  
  if (!goingUp && servoOnePosition > 400) {
    servoOnePositionNow -= 10;
    servoFourPositionNow -= 10;
    servoSevenPositionNow -= 10;
  } else {
    goingUp = true;
  }
//
//  // Set LED to red when moving
//  if (abs(servoOnePosition - servoOnePositionNow) > 10) {
//    servoOneLED = movingColour;
//  }
//  if (abs(servoFourPosition - servoFourPositionNow) > 10) {
//    servoTwoLED = movingColour;
//  }
//  if (abs(servoSevenPosition - servoSevenPositionNow) > 10) {
//    servoThreeLED = movingColour;
//  }
//  
//  // Fade the laser intensity
//  analogWrite(laserPin, laserIntensity);
//  laserIntensity = (laserIntensity + 10) % 1024;
//
//  // Set servoPositions
  servoOnePosition = servoOnePositionNow;
  servoFourPosition = servoFourPositionNow;
  servoSevenPosition = servoSevenPositionNow;
  
  // Set LED Red
  for (int i = 1; i < 10; i++) {
    robot.LED(i, &rgb[random(1,7)] );
    robot.readPacket(buffer,256);
  }

  // Servo test..
  robot.moveJoint(servoOneID, servoOnePosition);
  robot.readPacket(buffer,256);
  robot.moveJoint(servoFourID, servoFourPosition);
  robot.readPacket(buffer,256);
  robot.moveJoint(servoSevenID, servoSevenPosition);
  robot.readPacket(buffer,256);

  // Random moving code.
//  for (int i = 1; i < 10; i++) {
//    robot.moveJoint(i, random(450, 550));
//    robot.readPacket(buffer,256);
//  }
  
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
