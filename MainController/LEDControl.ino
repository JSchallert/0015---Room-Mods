void ledControl(String state){
  redLED(state);
  bluLED(state);
  grnLED(state);
  ylwLED(state);
}
  
void grnLED(String state){
  if (state[0] == '1'){
    analogWrite(GRNOUT, 255);
  }else{
    analogWrite(GRNOUT, 0);
  }}
  
void ylwLED(String state){
  if (state[1] == '1'){
    analogWrite(YLWOUT, 255);
  }else{
    analogWrite(YLWOUT, 0);
  }}
  
void redLED(String state){
  if (state[2] == '1'){
    analogWrite(REDOUT, 255);
  }else{
    analogWrite(REDOUT, 0);
  }}
  
void bluLED(String state){
  if (state[3] == '1'){
    analogWrite(BLUOUT, 255);
  }else{
    analogWrite(BLUOUT, 0);
  }}
