//Screen Control
//Author: Jonathan Schallert
//Date: 4/8/2018

#include "LowPower.h"
#define DIR 5
#define STEP 4
#define TRIGGER 6
int stepsPerRot = 200;
bool deployed = false;
bool stepDirection = true;
bool stepping = false;
int totalSteps = 1000;
int brokenSteps = 0;

void setup() {
  Serial.begin(38400);
  pinMode(DIR,OUTPUT);
  pinMode(STEP,OUTPUT);
  pinMode(TRIGGER,INPUT);
  digitalWrite(STEP,stepDirection);}

void reverse(){
  digitalWrite(DIR,!stepDirection);
  stepDirection = !stepDirection;}
  
void stepCustom(float timeDelay){
  stepping = true;
  digitalWrite(STEP,LOW);
  delay(timeDelay);
  digitalWrite(STEP,HIGH);
  delay(timeDelay);
  if(stepDirection){
    brokenSteps+=1;
  }else{
    brokenSteps-=1;}
}

void screenDeploy(bool stepdir){
  float timescale;
  for(int i=0,i<totalSteps,i++){
    timescale = sqrt(totalSteps);
    stepCustom(timescale);
    if(TRIGGER){
      Serial.println("Stopped!");
      break;}
  }
  stepping = false;
  Serial.println("Resetting...");
  Serial.println(brokenSteps);
  delay(250);
}

void zero(int steps){
  reverse();
  if(!stepDirection){
    for (int i = 0;i<steps;i++){
      stepCustom(4);}
  }else{
    for (int i = steps;i!=totalSteps;i++){
      stepCustom(4);}}
}

void loop() {
  if(TRIGGER){
    if(brokenSteps != 0){
      zero(brokenSteps);}
    else if(deployed){
      screenDeploy(deployed);}
    else{
      screenDeploy(deployed);}
  }
}
