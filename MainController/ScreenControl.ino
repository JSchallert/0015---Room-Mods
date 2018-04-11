void screenControl(String state){
  //GYRB
  if (state[3] == '1'){
    digitalWrite(POWER,HIGH);
    delay(trigBufferMillis);
    if(brokenSteps!=0 && !stepping){
      zero(brokenSteps);
    }else{
      screenDeploy();}
    digitalWrite(POWER,LOW);}}

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
  Serial.println(brokenSteps);}

void screenDeploy(){
  float timescale;
  for(int i=0;i<totalSteps;i++){
    timescale = constSpeed;
    //rewrite to be some function of the step number
    stepCustom(timescale);
    if(digitalRead(BLUE)){
      Serial.println("Stopped!");
      break;}}
  stepping = false;
  Serial.println("Resetting...");
  Serial.print("Loop broke at:");
  Serial.println(brokenSteps);
  delay(trigBufferMillis);}

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
    reverse();}}

    
