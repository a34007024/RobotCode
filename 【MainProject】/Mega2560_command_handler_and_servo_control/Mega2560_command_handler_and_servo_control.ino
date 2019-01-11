#include <Servo.h>
char incomingByte;   // for incoming serial data
String stringIn;
String commandCache[20];
int servoAngle[15];//儲存每顆馬達的角度
Servo servo[15];

/*=======用來把伺服馬達指派成方便判別的變數(以下純粹當對照表格看)=========
* Servo LeftShoulderX   =	servo[0] ;      左肩膀X(側向伸展)	
* Servo LeftShoulderY	  =	servo[1] ;      左肩膀Y(前後伸展)	
* Servo LeftElbow		    =	servo[2] ;      左手肘				
* Servo RightShoulderX  =	servo[3] ;      右肩膀X(側向伸展)	
* Servo RightShoulderY  =	servo[4] ;      右肩膀Y(前後伸展)	
* Servo RightElbow	    =	servo[5] ;      右手軸				
* Servo LeftPelvisX	    =	servo[6] ;      左骨盆X(側向伸展)	
* Servo LeftThighY	    =	servo[7] ;      左大腿Y(前後伸展)	
* Servo LeftKnee		    =	servo[8] ;      左膝蓋				
* Servo LeftAnkle		    =	servo[9] ;      左腳踝				
* Servo RightPelvisX    =	servo[10] ;     右骨盆X(側向伸展)	
* Servo RightThighY	    =	servo[11] ;     右大腿Y(前後伸展)	
* Servo RightKnee		    =	servo[12] ;     右膝蓋				
* Servo RightAnkle	    =	servo[13] ;     右腳踝				
* Servo Waist			      =	servo[14] ;     腰部				
*/
//=======用來把伺服馬達指派成方便判別的變數(以上純粹當對照表格看)=========

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
  resetServos();
}
//======================================================
void loop() {
  communicateWithNodeMCU();//-----------與Wifi通訊區塊-----------
  printInputCommand();//輸出debug訊息用
  processCommand();//將指令轉為可執行的數據
  servoMove();//依照儲存的馬達角度控制伺服馬達
  sendControlCommandViaSerialPort();//debug用，透過監控視窗發送控制指令
}
//======================================================
/*接線說明(左側為NodeMCU,右側為Mega大陸版)
  G   ->  GND
  VIN ->  5V
  RX  ->  RX1
  TX  ->  TX1
  
  接線說明(左側為NodeMCU,右側為Mega義大利版)
  G   ->  GND
  VIN ->  5V
  RX  ->  TX1
  TX  ->  RX1
*/
