#include<Servo.h>
const int led = 50,ledGND = 51;
int servoAngle[15];
Servo servo[15];
//======================================================
//=========用來把伺服馬達指派成方便判別的變數============
Servo LeftShoulderX   =  servo[0] ;
Servo LeftShoulderY   = servo[1] ;
Servo LeftElbow       = servo[2] ;
Servo RightShoulderX  = servo[3] ;
Servo RightShoulderY  = servo[4] ;
Servo RightElbow        = servo[5] ;
Servo LeftPelvisX     = servo[6] ;
Servo LeftThighY        = servo[7] ;
Servo LeftKnee          = servo[8] ;
Servo LeftAnkle       = servo[9] ;
Servo RightPelvisX      = servo[10] ;
Servo RightThighY     = servo[11] ;
Servo RightKnee       = servo[12] ;
Servo RightAnkle        = servo[13] ;
Servo Waist           = servo[14] ;
//=========用來把伺服馬達指派成方便判別的變數============
unsigned long ms,prems;
void setup(){
  for (int i = 0; i < 15; i++) {
    if (i == 0)servo[i].attach(44, 975, 2150);
    else if (i == 1)servo[i].attach(45, 975, 2150);
    else if (i == 2)servo[i].attach(46, 975, 2150);
    else servo[i].attach(i-1, 975, 2150);
  }//伺服馬達Pin腳接線
  for (int i = 0; i < 15; i++) {//初始蹲下
    servo[i].write(10);
  }
  ms = millis();
  prems = ms;
  while(prems - ms < 2000){//delay 2000ms
    ms = millis();
  }
}

void loop(){
  ms = millis();
  if(ms-prems<3000){
    for(int angle=10;angle<=90;angle++){//起立
      LeftThighY.write(angle);
      LeftKnee.write(angle);
      RightThighY.write(angle);
      RightKnee.write(angle);
    }
    while(ms-prems<3000){
      ms = millis();//等待到3秒過後
    }
  }
  else if(ms-prems>3000){
    for(int angle=90;angle>10;angle--){//蹲下
      LeftThighY.write(angle);
      LeftKnee.write(angle);
      RightThighY.write(angle);
      RightKnee.write(angle);
    }
    while(ms-prems<6000){
      ms = millis();//再等待到3秒過後
    }
    ms = millis();
    prems = millis();//完成循環，歸零prems
  }
}
