/*下一步從client class 與server class 著手
 以及從範例裡去找相關的傳輸資料的方法*/
#include <ESP8266WiFi.h>
const char* ssid = "Infas_因法師"; //your WiFi Name
const char* password = "infas.capacitor";  //Your Wifi Password
WiFiServer server(80);
WiFiClient client;
int servo1Angle = 30;
String request;
//===========================================
void setup() {
  Serial.begin(115200);
  sendWifiInfoToSerial();
  //初始化Wifi連線功能及開啟序列埠通訊
}
//==========================================
void loop() {
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
  int receiveDataWaitTimes=0;//用來計算等待接收資料的次數
  while(!client.available()){
    delay(30);//如果Client還來不及做出回應(送資料)，等待他30毫秒
    receiveDataWaitTimes+=1;
    if(receiveDataWaitTimes>=10){
      receiveDataWaitTimes=0;
      break;//因為Client一直都沒做出回應，可能是斷線了，所以就不等了，跳出迴圈!
    }
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
