#include<Servo.h>
Servo robotComponents[17];
void setup(){
  for(int i=2;i<14;i++){
    robotComponents[i].attach(i,975,2150);
    robotComponents[i].write(90);
  }
  robotComponents[14].attach(44,975,2150);
  robotComponents[15].attach(45,975,2150);
  robotComponents[16].attach(46,975,2150);
  robotComponents[14].write(90);
  robotComponents[15].write(90);
  robotComponents[16].write(90);
  delay(2000);
  for(int i=2;i<14;i++){
    robotComponents[i].write(90);
  }
  for(int i=44;i<47;i++){
    robotComponents[i].write(90);
  }
}

void loop(){
  
}
