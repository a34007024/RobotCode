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

