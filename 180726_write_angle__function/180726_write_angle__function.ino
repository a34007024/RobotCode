//arduino官網:https://www.arduino.cc/en/Tutorial/Sweep
//中文網站參考:http://atceiling.blogspot.com/2017/03/arduino.html
#include <Servo.h>
Servo myservo;  // 建立一個 servo 物件，最多可建立 12個 servo
int pos = 0;    // 設定 Servo 位置的變數

void setup() {
  myservo.attach(9);  // 將 servo 物件連接到 pin 9
  myservo.write(180);
  delay(3000);
  myservo.write(0);//伺服馬達位置復歸
  delay(3000);
}

void loop() {
  for (pos = 0; pos <= 180; pos += 1) // 從 0 度旋轉到 180 度，每次 1 度 
  {// 正轉 180度
    myservo.write(pos);               // 告訴 servo 走到 'pos' 的位置
    delay(15);                        // 等待 15ms 讓 servo 走到指定位置
  }
  for (pos = 180; pos >= 0; pos -= 1) // 從 180 度旋轉到 0 度，每次 1 度 
  {// 反轉 180度 
    myservo.write(pos);               // 告訴 servo 走到 'pos' 的位置
    delay(15);                        // 等待 15ms 讓 servo 走到指定位置
  }
}
