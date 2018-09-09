char incomingByte;   // for incoming serial data
String stringIn;
void setup() {
  Serial1.begin(115200);//與NodeMCU的通訊橋梁
  Serial.begin(115200);//與電腦的通訊橋梁
  Serial.println("Testing the connection with computer...");
}
/*接線說明(左側為NodeMCU,右側為Mega)
G   ->  GND
VIN ->  5V
RX  ->  RX1
TX  ->  TX1
*/
void loop() {
  if(Serial1.available()){//如果Serial 1有送訊號出來
    incomingByte = Serial1.read();//讀取Serial 1接收到的資料
    if(incomingByte != "\r" && stringIn.length() < 15){
      stringIn += incomingByte;
    }
    else {
      stringIn = "";
    }
    //Serial.println("I have received some data from NodeNCU");
    Serial.print(incomingByte);// say what you got
    Serial.println("stringIn now is:"+stringIn);
  }
}

