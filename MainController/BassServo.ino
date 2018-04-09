void bassControl(){
  servoVal = analogRead(POTPIN);            // reads the value of the potentiometer (value between 0 and 1023)
  servoVal = map(servoVal, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  bass.write(servoVal);                  // sets the servo position according to the scaled value
  delay(15);
}

