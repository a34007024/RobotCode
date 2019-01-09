/*下一步從client class 與server class 著手
 以及從範例裡去找相關的傳輸資料的方法*/
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <ESP8266HTTPUpdateServer.h>

#ifndef STASSID
#define STASSID "RobotController-EZ"
#define STAPSK  "robot.wifiControl"
#endif

const char* host = "esp8266-webupdate";//更新網址的hostname
const char* ssid = STASSID; //your WiFi Name(要更改到上方更改)
const char* password = STAPSK;  //Your Wifi Password(要更改到上方更改)

WiFiServer server(80);
WiFiClient client;
ESP8266WebServer httpServer(88);
ESP8266HTTPUpdateServer httpUpdater;

String request;
const int ServosPowerRelayPin = D3;//D3
//===========================================
void setup() {
  pinMode(ServosPowerRelayPin,OUTPUT);
  digitalWrite(ServosPowerRelayPin,LOW);
  pinMode(A0,INPUT);
  delay(3000);
  digitalWrite(ServosPowerRelayPin,HIGH);//高態驅動Relay
  sendWifiInfoToSerial_and_OpenServer();
  //初始化Wifi連線功能、開啟序列埠通訊及網頁伺服器
}
//==========================================
void loop() {
  httpServer.handleClient();  //處理更新用的服務
  MDNS.update();            //處理更新用的服務
  while (WiFi.status() != WL_CONNECTED) {//如果斷線
    delay(100);
    Serial.println("Lost Connection! Trying to reconnect...");
    //若要在斷線時重置接腳的輸出狀態，要寫在這裡面
  }//這邊以上非常重要!!!防止WIFI斷線導致無法控制!
  
  //Below is to Check if a client has connected
  client = server.available();
  if (!client) {
    return;//如果Client還未做出回應(接資料)，就在從頭跑一次LOOP
  }
  // Wait until the client sends some data
  Serial.println("new client");
  while(!client.available()){
    delay(1);
    //這筆修改是根據:範例 -> ESP8266Wifi -> WifiWebServer
    //以及http://www.instructables.com/id/Getting-Started-With-ESP8266LiLon-NodeMCU-V3Flashi/
    //來進行修改的
  }
  request = client.readStringUntil('\r');// Read the request
  //讀取Client的回應直到換行符號出現
  Serial.println(request);
  client.flush();//丟棄遺失的封包
  //-------------------------------------------------------
  matchRequest();//根據Client執行請求
  sendHTML();
  Serial.println("Client disonnected");
  Serial.println("");
}
