void communicateWithNodeMCU() {
  if (Serial1.available()) { //如果Serial 1(wifi板)有送訊號出來
    incomingByte = Serial1.read();//讀取Serial 1接收到的資料
    if (incomingByte == '$') {
      //use '' because the dataType of incomingByte is char
      //don't be foolish again xD! QwQ我好傻一開始竟然用""難怪沒反應
      //===========解析指令字串並分割============
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
void commandToServoInfo(){
  for(int i=0;i<20;i++){
    if(commandCache[i] != ""){
      //繼續編輯此處
      //把指令的馬達編號及角度解析並儲存到陣列裡
    }
  }
}
void servoMove(){
  for(int i=0;i<15;i++){
    /*Servo02_angle000這樣為一個符合規範的組合指令
     * 字串的長度為16
     * 而已訂好的指令都規定為(Mega板上已寫好的預設功能)
     * command001、command002......字串長度為10
     */
    if(commandCache[i].length() == 16){//組合指令
      
    }
    else if(commamdCache[i]){//內建好的動作
      
    }
    else commandCache[i] = "";
    //可能在傳輸中出錯而不符合規定的指令，直接丟棄
  }
}
void debug() {
  for (int i = 0; i < 20; i++) {
    if (commandCache[i] != "") {
      Serial.println(commandCache[i]);
      commandCache[i] = "";
      Serial.print(commandCache[i].length());//輸出字串長度
    }
  }
}
