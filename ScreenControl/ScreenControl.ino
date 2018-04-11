//Screen Control
//Author: Jonathan Schallert
//Date: 4/8/2018
//Uses some button to take user input to a stepper
//controlling its state between two positions
#define DIR 2
#define STEP 3
#define POWER 5
#define TRIGGER 4
bool deployed = false;
bool stepDirection = true;
bool stepping = false;
int totalSteps = 1000;
int brokenSteps = 0;
int constSpeed = 1;
int trigBufferMillis = 250;

void setup() {
  Serial.begin(38400);
  pinMode(DIR,OUTPUT);
  pinMode(STEP,OUTPUT);
  pinMode(POWER,OUTPUT);
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
  Serial.println(brokenSteps);
}

void screenDeploy(){
  float timescale;
  for(int i=0;i<totalSteps;i++){
    timescale = constSpeed;
    //rewrite to be some function of the step number
    stepCustom(timescale);
    if(digitalRead(TRIGGER)){
      Serial.println("Stopped!");
      break;}
  }
  stepping = false;
  Serial.println("Resetting...");
  Serial.print("Loop broke at:");
  Serial.println(brokenSteps);
  delay(trigBufferMillis);
}

void zero(int steps){
  reverse();
  if(!stepDirection){
    Serial.println("Retracting");
    for (int i = 0;i<steps;i++){
      stepCustom(constSpeed);}
    reverse();
  }else{
    Serial.println("Redeploying...");
    for (int i = steps;i!=totalSteps;i++){
      stepCustom(constSpeed);}
    reverse();}
}

bool trigger(){
  bool trigread = digitalRead(TRIGGER);
  Serial.print("TRIGGER: ");
  Serial.print(trigread);
  Serial.print("  STEPS: ");
  Serial.println(brokenSteps);
  return trigread;
}

void loop() {
  bool trig = trigger();
  if(trig){
    digitalWrite(POWER,HIGH);
    delay(trigBufferMillis);
    if(brokenSteps!=0 && !stepping){
      zero(brokenSteps);
    }else{
      screenDeploy();}
    digitalWrite(POWER,LOW);
  }
}
