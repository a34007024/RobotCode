char incomingByte;   // for incoming serial data
String stringIn;
String commandCache[20];
void setup() {
  Serial1.begin(115200);//與NodeMCU的通訊橋梁
  Serial.begin(115200);//與電腦的通訊橋梁
  Serial.println("Testing the connection with computer...");
  for(int i = 0;i < 20;i++){
    commandCache[i] = "";//初始化指令陣列
  }
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
      stringIn = Serial1.readStringUntil('.');
    }
  }
  if(stringIn != ""){
    Serial.println("stringIn now is:"+stringIn);
    for(int i=0;i<20;i++){
      if(commandCache[i] == ""){//判斷哪一個指令快取陣列為空
        commandCache[i] = stringIn;//將新指令加到指令快取
        stringIn = "";//把新進來的指令清空
      }
    }
  }
}
