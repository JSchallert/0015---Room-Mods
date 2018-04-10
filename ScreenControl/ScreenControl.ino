//Screen Control
//Author: Jonathan Schallert
//Date: 4/8/2018

#define DIR 2
#define STEP 3
#define TRIGGER 4
int stepsPerRot = 200;
bool deployed = false;
bool stepDirection = true;
bool stepping = false;
int totalSteps = 1000;
int brokenSteps = 0;
int constSpeed = 1;

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
  Serial.println(brokenSteps);
}

void screenDeploy(){
  float timescale;
  for(int i=0;i<totalSteps;i++){
    timescale = constSpeed;
    stepCustom(timescale);
    if(digitalRead(TRIGGER)){
      Serial.println("Stopped!");
      break;}
  }
  stepping = false;
  Serial.println("Resetting...");
  Serial.print("Loop broke at:");
  Serial.println(brokenSteps);
  delay(250);
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
  bool x = digitalRead(TRIGGER);
  Serial.print("TRIGGER: ");
  Serial.print(x);
  Serial.print("  STEPS: ");
  Serial.println(brokenSteps);
  return x;
}

void loop() {
  bool trig = trigger();
  if(trig){
    delay(200);
    if(brokenSteps!=0 && !stepping){
      zero(brokenSteps);
    }else{
      screenDeploy();}
  }
}
