#include <Servo.h>
char incomingByte;   // for incoming serial data
String stringIn;
String commandCache[20];
//======================================================
void setup() {
  Serial1.begin(115200);//與NodeMCU的通訊橋梁
  Serial.begin(115200);//與電腦的通訊橋梁(debug階段使用)
  Serial.println("Testing the connection with computer...");//debug用
  for (int i = 0; i < 20; i++) {
    commandCache[i] = "";//初始化指令陣列
  }
}
//======================================================
void loop() {
  communicateWithNodeMCU();//-----------與Wifi通訊區塊-----------
  debug();
}
//======================================================
/*接線說明(左側為NodeMCU,右側為Mega大陸版)
  G   ->  GND
  VIN ->  5V
  RX  ->  RX1
  TX  ->  TX1
*/
//======================================================
