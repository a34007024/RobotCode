//https://www.arduino.cc/en/Reference/ServoAttached
#include <Servo.h>
Servo testServo;
void setup() {
  testServo.attach(9,975,2150);
  //指定為Pin9,脈波寬度範圍為975us~2150us
  //伺服馬達文件寫(0.5ms~2.5ms = 500us~2500us)
  //但是我們測出來的脈波範圍為975us~2150us
  while(testServo.attached()==false){
    delay(500);//等待馬達連接
  }
  testServo.write(0);delay(3000);
  testServo.write(180);delay(3000);
  testServo.write(90);delay(1000);
}
int pos = 90;//馬達起始位置
void loop() {
  for (pos = 0; pos <= 180; pos += 10) // 從 0 度旋轉到 180 度，每次 1 度 
  {// 正轉 180度
    testServo.write(pos);               // 告訴 servo 走到 'pos' 的位置
    delay(30);                        // 等待 15ms 讓 servo 走到指定位置
  }
  for (pos = 180; pos >= 0; pos -= 10) // 從 180 度旋轉到 0 度，每次 1 度 
  {// 反轉 180度 
    testServo.write(pos);               // 告訴 servo 走到 'pos' 的位置
    delay(30);                        // 等待 15ms 讓 servo 走到指定位置
  }
}
