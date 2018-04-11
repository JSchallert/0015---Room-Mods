//Main Controller
//Author: Jonathan Schallert
//Started 3/1/18
//Screen Control added 4/10/18

#include <Servo.h>
#include "LowPower.h"

//Inputs from Main Controller
#define GREEN  9
#define YELLOW 10
#define RED    11
#define BLUE   12
#define GRNOUT A5
#define YLWOUT A3
#define REDOUT A2
#define BLUOUT A0
int grn; int ylw;
int red; int blu;

//BassControl Variables
#define POTPIN A4
Servo bass;
int servoVal;

//ScreenControl Variables
#define DIR 2
#define STEP 3
#define POWER 4
bool deployed = false;
bool stepDirection = true;
bool stepping = false;
int totalSteps = 1000;
int brokenSteps = 0;
int constSpeed = 1;
int trigBufferMillis = 250;

void enableButtons() {
  pinMode(GREEN,  INPUT);
  pinMode(YELLOW, INPUT);
  pinMode(RED,    INPUT);
  pinMode(BLUE,   INPUT);}

void enableAnalogOuts(){
  pinMode(GRNOUT, OUTPUT);
  pinMode(YLWOUT, OUTPUT);
  pinMode(REDOUT, OUTPUT);
  pinMode(BLUOUT, OUTPUT);}

void enableScreenStepper(){
  pinMode(DIR,OUTPUT);
  pinMode(STEP,OUTPUT);
  pinMode(POWER,OUTPUT);
  //need the POWER out to control transistor, limit current
  //and limit overheating of stepper driver
  }

void setup() {
  Serial.begin(38400);
  //a bit arbitrary but it should be somewhat fast
  delay(5000);
  enableButtons();
  enableAnalogOuts();
  enableScreenStepper();
  digitalWrite(STEP,stepDirection); //starts the stepper with an initial direction
  bass.attach(2);  // attaches the servo on pin 2 to the servo object
}

void loop() {
  grn = digitalRead(GREEN);
  ylw = digitalRead(YELLOW);
  red = digitalRead(RED);
  blu = digitalRead(BLUE);
  String state = (String)grn + ylw + red + blu;
  ledControl(state);
  bassControl();
  screenControl(state);
}

