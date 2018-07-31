#include <ESP8266WiFi.h>
#include <Servo.h>
const char* ssid = "Infas_因法師"; //your WiFi Name
const char* password = "infas.capacitor";  //Your Wifi Password
const int testLEDPin = 13;//D7 pin
int LEDstatus = LOW;
Servo Servo1;
Servo Servo2;
WiFiServer server(80);
WiFiClient client;
//=============================================================
void setup() {
  pinMode(testLEDPin,OUTPUT);
  digitalWrite(testLEDPin,LOW);
  Servo1.attach(2,500,2500);//pin2 = D4
  Servo2.attach(4,500,2500);//pin4 = D2
  Servo1.write(0);Servo2.write(0);delay(3000);
  Servo1.write(180);Servo2.write(180);delay(3000);
  Servo1.write(90);Servo2.write(90);
  Serial.begin(115200);
  delay(10); 
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid); 
  WiFi.begin(ssid, password);//嘗試連線到設定好的SSID
  while (WiFi.status() != WL_CONNECTED) {//如果還沒連線到
    delay(500);
    Serial.print(".");
  }
  //以下為成功連線後所執行的動作
  Serial.println("");
  Serial.println("WiFi connected"); 
  server.begin();//開啟伺服器
  Serial.println("Server started");
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());//顯示出這塊板子的IP位置
  Serial.println("/"); 
}
//===========================================================================
void loop() {
  while (WiFi.status() != WL_CONNECTED) {//如果沒連線到
    delay(100);
    Serial.print("Lost Connection! Trying to reconnect...");
  }
  //這邊以上非常重要!!!防止WIFI斷線，無法控制，而遙控車卻仍一直跑
  //Below is to Check if a client has connected
  client = server.available();
  if (!client) {
    return;//如果Client還未做出回應(接資料)，就在從頭跑一次LOOP
  }
  // Wait until the client sends some data
  Serial.println("new client");
  int receiveDataWaitTimes=0;//用來計算等待接收資料的次數
  while(!client.available()){
    delay(30);//如果Client還來不及做出回應(送資料)，等待他30毫秒
    receiveDataWaitTimes+=1;
    if(receiveDataWaitTimes>=10){
      receiveDataWaitTimes=0;
      break;//因為Client一直都沒做出回應，可能是斷線了，所以就不等了，跳出迴圈!
    }
  }
  // Read the first line of the request
  String request = client.readStringUntil('\r');//讀取Client的回應直到換行符號出現
  Serial.println(request);
  client.flush();//丟棄遺失的封包
  // Match the request
  if (request.indexOf("/LED=ON") != -1)  {
    digitalWrite(testLEDPin, HIGH);
    LEDstatus = HIGH;
  }
  if (request.indexOf("/LED=OFF") != -1)  {
    digitalWrite(testLEDPin, LOW);
    LEDstatus = LOW;
  }
  // Set testLEDPin according to the request
  //digitalWrite(testLEDPin, value);
  if(request.indexOf("/c") != -1)  {
    Servo1.write(90);
  }
  if(request.indexOf("/Servo1_angle0") != -1)  {
    Servo1.write(0);
  }
  if(request.indexOf("/Servo1_angle180") != -1)  {
    Servo1.write(180);
  }
  if(request.indexOf("/Servo2_angle90") != -1)  {
    Servo2.write(90);
  }
  if(request.indexOf("/Servo2_angle0") != -1)  {
    Servo2.write(0);
  }
  if(request.indexOf("/Servo2_angle180") != -1)  {
    Servo2.write(180);
  }
  sendHTML();
  Serial.println("Client disonnected");
  Serial.println("");
}
