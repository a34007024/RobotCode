void communicateWithNodeMCU() {
  if (Serial1.available()) { //如果Serial 1(wifi板)有送訊號出來
    incomingByte = Serial1.read();//讀取Serial 1接收到的資料
    if (incomingByte == '$') {
      //use '' because the dataType of incomingByte is char <= 是字元!
      //don't be foolish again xD! QwQ我好傻一開始竟然用""難怪沒反應
      //===========解析指令字串並分割============
      //指令範例: $Servo02_angle000. 從$開始.結束
      for (int i = 0; i < 20; i++) {
        if (commandCache[i] == "") { //判斷哪一個指令快取陣列為空
          commandCache[i] = Serial1.readStringUntil('.');//將新指令加到指令快取
          break;//離開for迴圈繼續讀取Wifi送入的資料
        }
      }
      //===========解析指令字串並分割============
    }
  }
}

void servoMove(){
  String stringProcessCache;
  int servoNum = 0;
  int servoAngle = 0;
  int commandNum = 0;
  for(int i=0;i<15;i++){
    /* Servo02_angle000這樣為一個符合規範的組合指令
     * 字串的長度為16
     * 而已訂好的指令都規定為(Mega板上已寫好的預設功能)
     * command001、command002......字串長度為10
     */
    if(commandCache[i].length() == 16){//組合指令
      stringProcessCache = commandCache[i];
      //字串是char array第一個字元為char[0]
      stringProcessCache.remove(0,5);//從第0格開始，共去除5個字元
      stringProcessCache.remove(2,9);//從第2格開始，共去除9個字元
      servoNum = stringProcessCache.toInt();
      Serial.println(servoNum);
      commandCache[i].remove(0,13);
      servoAngle = commandCache[i].toInt();
      Serial.println(servoAngle);
      servo[servoNum].write(servoAngle);
      commandCache[i] = "";//清空指令已表示完成
    }
    else if(commandCache[i].length() == 10){//內建好的動作
      commandCache[i].remove(0,7);
      commandNum = commandCache[i].toInt();
      switch(commandNum){
        case 1://向左移動
          
          break;
        case 2://向右移動
          
          break;
        case 3://向前移動
          
          break;
        case 4://向後移動
          
          break;
        case 101://左側拳
          
          break;
        case 102://右側拳
          
          break;
        case 201://左拳
          
          break;
        case 202://右拳
          
          break;
        case 301://左上勾拳
          
          break;
        case 302://右上勾拳
          
          break;
        case 401://往前倒下爬起
          
          break;
        case 402://往後倒下爬起
          
          break;
        case 501://面向左邊(移動角度大)

          break;
        case 502://面向左邊(移動角度小)

          break;
        case 511://面向右邊(移動角度大)

          break;
        case 512://面向右邊(移動角度小)
          
          break;
        case 600://蹲下

          break;
        case 999://電量顯示
          //do nothing
          //交給NodeMCU處理
          break;
        default:
          //do nothing
          break;
      }
      commandCache[i] = "";//清空指令已表示完成
    }
    else commandCache[i] = "";
    //可能在傳輸中出錯而不符合規定的指令，直接丟棄
  }
}

void startUpResetServos(){
  Waist.write(90);
  delay(1000);
  LeftShoulderX.write(90);
  LeftShoulderY.write(90);
  LeftElbow.write(90);
  delay(2000);
  RightShoulderX.write(90);
  RightShoulderY.write(90);
  RightElbow.write(90);
  delay(2000);
  LeftPelvisX.write(90);
  LeftThighY.write(90);
  LeftKnee.write(90);
  LeftAnkle.write(90);
  delay(2000);
  RightPelvisX.write(90);
  RightThighY.write(90);
  RightKnee.write(90);
  RightAnkle.write(90);
  delay(2000);
}

void printInputCommand() {
  for (int i = 0; i < 20; i++) {
    if (commandCache[i] != "") {
      Serial.println(commandCache[i]);
      //Serial.print(commandCache[i].length());//輸出字串長度
      //commandCache[i] = "";
    }
  }
}
