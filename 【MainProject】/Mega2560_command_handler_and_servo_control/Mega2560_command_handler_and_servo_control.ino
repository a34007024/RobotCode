char incomingByte;   // for incoming serial data
String stringIn;
bool commandInStatus = false;
void setup() {
  Serial1.begin(115200);//與NodeMCU的通訊橋梁
  Serial.begin(115200);//與電腦的通訊橋梁
  Serial.println("Testing the connection with computer...");
}
/*接線說明(左側為NodeMCU,右側為Mega大陸版)
G   ->  GND
VIN ->  5V
RX  ->  RX1
TX  ->  TX1
*/
void loop() {
  if(Serial1.available()){//如果Serial 1有送訊號出來
    incomingByte = Serial1.read();//讀取Serial 1接收到的資料
    if(incomingByte == '$'){
      //use '' because the dataType of incomingByte is char
      //don't be foolish again xD! QwQ我好傻一開始竟然用""難怪沒反應
      commandInStatus = true;
      stringIn = Serial1.readStringUntil('.');
    }
  }
  //if(commandInStatus == true) stringIn += incomingByte;
  if(stringIn != "")
    Serial.println("stringIn now is:"+stringIn);
}
