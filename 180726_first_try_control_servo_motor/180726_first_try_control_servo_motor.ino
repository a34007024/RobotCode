//參考自:http://yehnan.blogspot.com/2013/09/arduinotower-pro-sg90.html
#include <Servo.h> 
Servo myservo;
int moverange = 100;//一步的旋轉範圍，數值越大轉越大
int movespeed = 300;//每走一步的延遲時間，數值越小轉越快
void setup() 
{ 
  myservo.attach(9, 500, 2400); //馬達控制接腳接在9號Pin腳
  // 修正脈衝寬度範圍為500us~2400us
  myservo.write(0);//一開始先移到0度
  delay(3000);
  myservo.write(180);//移到180度
  delay(3000);
  myservo.write(90); //置中90度
  delay(1000);
} 

void loop() 
{
  for(int i = 500; i <= 2400; i+=moverange){
    myservo.writeMicroseconds(i); // 直接以脈衝寬度控制
    delay(movespeed);
  }
  for(int i = 2400; i >= 500; i-=moverange){
    myservo.writeMicroseconds(i);
    delay(movespeed);
  }
}
