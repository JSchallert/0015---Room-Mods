void ledControl(String state){
  redLED(state);
  bluLED(state);
  grnLED(state);
  ylwLED(state);
}
  
void grnLED(String state){
  if (state[0] == '1'){
    analogWrite(GRNLED, 255);}
  else{
    analogWrite(GRNLED, 0);
  }}
void ylwLED(String state){
  if (state[1] == '1'){
    analogWrite(YLWLED, 255);}
  else{
    analogWrite(YLWLED, 0);
  }}
  
void redLED(String state){
  if (state[2] == '1'){
    analogWrite(REDLED, 255);}
  else{
    analogWrite(REDLED, 0);
  }}
  
void bluLED(String state){
  if (state[3] == '1'){
    analogWrite(BLULED, 255);}
  else{
    analogWrite(BLULED, 0);
  }}
