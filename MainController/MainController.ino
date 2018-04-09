//Main Controller or something
//Author: Jonathan Schallert
//Started 3/1/18
#include <Servo.h>
//Inputs
#define GREEN  9
#define YELLOW 10
#define RED    11
#define BLUE   12
#define GRNLED A5
#define YLWLED A3
#define REDLED A2
#define BLULED A0
#define POTPIN A4
int grn; int ylw;
int red; int blu;
Servo bass;
int servoVal;

void enableButtons() {
  pinMode(GREEN,  INPUT);
  pinMode(YELLOW, INPUT);
  pinMode(RED,    INPUT);
  pinMode(BLUE,   INPUT);}

void enableAnalogOuts(){
  pinMode(GRNLED, OUTPUT);
  pinMode(YLWLED, OUTPUT);
  pinMode(REDLED, OUTPUT);
  pinMode(BLULED, OUTPUT);
}

void setup() {
  Serial.begin(9600);
  delay(5000);
  enableButtons();
  enableAnalogOuts();
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
}

