void communicateWithNodeMCU() {
  if (Serial1.available()) { //如果Serial 1(wifi板)有送訊號出來
    incomingByte = Serial1.read();//讀取Serial 1接收到的資料
    if (incomingByte == '$') {
      //use '' because the dataType of incomingByte is char
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
void printInputCommand() {
  for (int i = 0; i < 20; i++) {
    if (commandCache[i] != "") {
      Serial.println(commandCache[i]);
      //Serial.print(commandCache[i].length());//輸出字串長度
      //commandCache[i] = "";
    }
  }
}
