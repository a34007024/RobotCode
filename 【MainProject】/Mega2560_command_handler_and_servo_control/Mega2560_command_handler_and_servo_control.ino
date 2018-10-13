#include <Servo.h>
char incomingByte;   // for incoming serial data
String stringIn;
String commandCache[20];
int servoAngle[15];
Servo servo[15];
//======================================================
//=========用來把伺服馬達指派成方便判別的變數============
Servo LeftHand = servo[0];

//=========用來把伺服馬達指派成方便判別的變數============
//======================================================
void setup() {
  Serial1.begin(115200);//與NodeMCU的通訊橋梁
  Serial.begin(115200);//與電腦的通訊橋梁(debug階段使用)
  Serial.println("Testing the connection with computer...");//debug用
  for (int i = 0; i < 20; i++) {
    commandCache[i] = "";//初始化指令陣列
  }
  for(int i=0;i<15;i++){
    if(i==0)servo[i].attach(44,1000,2150);
    else if(i==1)servo[i].attach(45,1000,2150);
    else if(i==14)servo[i].attach(46,1000,2150);
    else servo[i].attach(i,1000,2150);
  }//伺服馬達Pin腳接線
}
//======================================================
void loop() {
  communicateWithNodeMCU();//-----------與Wifi通訊區塊-----------
  printInputCommand();
  servoMove();//同時也把指令解析功能包含進去了!
}
//======================================================
/*接線說明(左側為NodeMCU,右側為Mega大陸版)
  G   ->  GND
  VIN ->  5V
  RX  ->  RX1
  TX  ->  TX1
*/
/*接線說明(左側為NodeMCU,右側為Mega義大利版)
  G   ->  GND
  VIN ->  5V
  RX  ->  TX1
  TX  ->  RX1
*/
//======================================================
