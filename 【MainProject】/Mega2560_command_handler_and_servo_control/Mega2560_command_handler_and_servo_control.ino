#include <Servo.h>
char incomingByte;   // for incoming serial data
String stringIn;
String commandCache[20];
int servoAngle[15];//儲存每顆馬達的角度
Servo servo[15];
//======================================================
//=========用來把伺服馬達指派成方便判別的變數============
Servo LeftShoulderX   =	servo[0] ;
Servo LeftShoulderY	  =	servo[1] ;
Servo LeftElbow		    =	servo[2] ;
Servo RightShoulderX  =	servo[3] ;
Servo RightShoulderY  =	servo[4] ;
Servo RightElbow	      =	servo[5] ;
Servo LeftPelvisX	    =	servo[6] ;
Servo LeftThighY	      =	servo[7] ;
Servo LeftKnee		      =	servo[8] ;
Servo LeftAnkle		    =	servo[9] ;
Servo RightPelvisX	    =	servo[10] ;
Servo RightThighY	    =	servo[11] ;
Servo RightKnee		    =	servo[12] ;
Servo RightAnkle	      =	servo[13] ;
Servo Waist			      =	servo[14] ;
//=========用來把伺服馬達指派成方便判別的變數============
//======================================================
void setup() {
  Serial1.begin(115200);//與NodeMCU的通訊橋梁
  Serial.begin(115200);//與電腦的通訊橋梁(debug階段使用)
  Serial.println("Testing the connection with computer...");//debug用
  for (int i = 0; i < 20; i++) {
    commandCache[i] = "";//初始化指令陣列
  }
  for (int i = 0; i < 15; i++) {
    if (i == 0)servo[i].attach(44, 975, 2150);
    else if (i == 1)servo[i].attach(45, 975, 2150);
    else if (i == 2)servo[i].attach(46, 975, 2150);
    else servo[i].attach(i - 1, 975, 2150);
  }//伺服馬達Pin腳接線
  startUpResetServos();
}
//======================================================
void loop() {
  communicateWithNodeMCU();//-----------與Wifi通訊區塊-----------
  printInputCommand();//輸出debug訊息用
  processCommand();//將指令轉為可執行的數據
  servoMove();//依照儲存的馬達角度控制伺服馬達
  sendControlCommandViaSerialPort();{//debug用，透過監控視窗發送控制指令
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
