void sendHTML(){
  //以下對客戶端(Client，像是手機)丟HTML語法，
  // Return the response
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); //  do not forget this one
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
 
  client.print("Led is now: ");
 
  if(LEDstatus == HIGH) {
    client.print("On");
  } else {
    client.print("Off");
  }
  client.println("<br><br>");
  client.println("<a href=\"/LED=ON\"\"><button>On </button></a>");
  client.println("<a href=\"/LED=OFF\"\"><button>Off </button></a><br />");  
  client.println("<a href=\"/Servo1_angle0\"\"><button style=\"height:200px;width:200px\">1號馬達轉至0度</button></a><br /><br /><br />");  
  client.println("<a href=\"/Servo1_angle90\"\"><button style=\"height:200px;width:200px\">1號馬達轉至90度</button></a><br />");  
  client.println("<a href=\"/Servo1_angle180\"\"><button style=\"height:200px;width:200px\">1號馬達轉至180度</button></a><br />");  
  client.println("<a href=\"/Servo2_angle0\"\"><button style=\"height:200px;width:200px\">2號馬達轉至0度</button></a><br /><br /><br />");  
  client.println("<a href=\"/Servo2_angle90\"\"><button style=\"height:200px;width:200px\">2號馬達轉至90度</button></a><br />");  
  client.println("<a href=\"/Servo2_angle180\"\"><button style=\"height:200px;width:200px\">2號馬達轉至180度</button></a><br />");  
  //上面繫行看起來很怪，但是為了讓IDE把它當成純文字看，只好用一堆\" 這樣IDE才會將它視為"  
  client.println("</html>");
  delay(1);  
}

