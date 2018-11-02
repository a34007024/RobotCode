int servo = 13;
unsigned long currentTime,preTime;
void setup() {
  pinMode(servo, OUTPUT);
}
int start = 0;
void loop() {
  if(start == 0){
    preTime = currentTime = millis();
    start = 1;
  }
  currentTime = millis();
  if(currentTime - preTime >= 3000)preTime = currentTime;
  if(currentTime - preTime <= 1000)servopulse(servo,0);
  else if(currentTime - preTime <= 2000)servopulse(servo,90);
  else if(currentTime - preTime <= 3000)servopulse(servo,180);
}
void servopulse(int servoPin, int angle) { //定義一個脈衝函數
  int pulsewidth = (angle * 5) + 975;//將角度轉化為500-2480的脈寬值，每多轉1度，對應高電平多11us
  digitalWrite(servoPin, HIGH);//將舵機接口電平至高
  delayMicroseconds(pulsewidth);//延時脈寬值的微秒數
  digitalWrite(servoPin, LOW);//將舵機接口電平至低
  delayMicroseconds(20000 - pulsewidth);//20ms中的低態訊號持續時間
}
