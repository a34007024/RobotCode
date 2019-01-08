void sendWifiInfoToSerial(){
  Serial.begin(115200);
  delay(10); 
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid); 
  WiFi.begin(ssid, password);//嘗試連線到設定好的SSID
  while (WiFi.status() != WL_CONNECTED) {
    //判斷是否成功連線
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
int BatteryVoltage = 0;
void matchRequest(){
  if(request.indexOf("/$command999.") != -1)  {
    BatteryVoltage = analogRead(A0);
  }
}

void sendHTML(){
  //以下對客戶端(Client，像是手機)丟HTML語法，
  // Return the response
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); //  do not forget this one
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  //-------------以上為HTML Header----------------
  client.println(BatteryVoltage);
  client.print("Led is now: This example does not have LED");
  client.println("<br><br>");
  client.println("<input type=\"submit\" value=\"submit\" />");
  client.println("<a href=\"/$Servo02_angle180.$Servo03_angle150.$Servo05_angle080.$Servo06_angle020.$Servo07_angle180.$Servo08_angle180.$Servo09_angle180.$Servo10_angle180.$Servo11_angle180.$Servo12_angle180.$Servo13_angle180.\"\"><button style=\"height:200px;width:200px\">complex command test</button></a><br />");  
  client.println("<a href=\"/$Servo01_angle000.\"\"><button style=\"height:200px;width:200px\">Servo1 set to 0°</button></a><br /><br /><br />");  
  client.println("<a href=\"/$Servo01_angle180.\"\"><button style=\"height:200px;width:200px\">Servo1 set to 180°</button></a><br />");  
  client.println("<a href=\"/$Servo02_angle000.\"\"><button style=\"height:200px;width:200px\">Servo2 set to 0°</button></a><br /><br /><br />");   
  client.println("<a href=\"/$Servo02_angle180.\"\"><button style=\"height:200px;width:200px\">Servo2 set to 180°</button></a><br />");  
  //上面幾行看起來很怪，但是為了讓IDE把它當成純文字看，只好用一堆\" 這樣IDE才會將它視為" 
  //請求的路徑規定為 $表示開始 .表示結尾且每筆請求的長度都要一樣
  //這樣在ArduinoMega上的字串處理會比較方便
  client.println("</html>");
  delay(1);
}
