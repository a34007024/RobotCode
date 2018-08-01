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

void matchRequest(){
  if(request.indexOf("/Servo1_angle90") != -1)  {
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
  client.print("Led is now: This example does not have LED");
  client.println("<br><br>");
  client.println("<a href=\"/LED=ON\"\"><button>On </button></a>");
  client.println("<a href=\"/LED=OFF\"\"><button>Off </button></a><br />");  
  client.println("<a href=\"/Servo1_angle0\"\"><button style=\"height:200px;width:200px\">1號馬達轉至0度</button></a><br /><br /><br />");  
  client.println("<a href=\"/Servo1_angle90\"\"><button style=\"height:200px;width:200px\">1號馬達轉至90度</button></a><br />");  
  client.println("<a href=\"/Servo1_angle180\"\"><button style=\"height:200px;width:200px\">1號馬達轉至180度</button></a><br />");  
  client.println("<a href=\"/Servo2_angle0\"\"><button style=\"height:200px;width:200px\">2號馬達轉至0度</button></a><br /><br /><br />");  
  client.println("<a href=\"/Servo2_angle90\"\"><button style=\"height:200px;width:200px\">2號馬達轉至90度</button></a><br />");  
  client.println("<a href=\"/Servo2_angle180\"\"><button style=\"height:200px;width:200px\">2號馬達轉至180度</button></a><br />");  
  //上面幾行看起來很怪，但是為了讓IDE把它當成純文字看，只好用一堆\" 這樣IDE才會將它視為"  
  client.println("</html>");
  delay(1);
}


