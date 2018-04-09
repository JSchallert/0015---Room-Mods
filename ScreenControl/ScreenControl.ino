//Screen Control
//Author: Jonathan Schallert
//Date: 4/8/2018

#include "LowPower.h"
//testing github functionality
#define DIR 5
#define STEP 4

void setup() {
  Serial.begin(9600);
  pinMode(DIR,OUTPUT);
  pinMode(STEP,OUTPUT);
  digitalWrite(STEP,HIGH);
}

void reverse(){
  digitalWrite(DIR,HIGH);
  delay(200);
  //digitalWrite(DIR,LOW);
}

void stepperStep(){
  digitalWrite(STEP,LOW);
  delay(10);
  digitalWrite(STEP,HIGH);
  delay(10);
}


void loop() {
  stepperStep();
}
