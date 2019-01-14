void servoMove() { //依照儲存的馬達角度控制伺服馬達
  for (int i = 0; i < 15; i++) {
    servo[i].write(servoAngle[i]);
  }
}

void resetServos() {
  for (int i = 0; i < 15; i++) {
    servoAngle[i] = 90;
    if (i == 6)servoAngle[i] = 110;
    if (i == 7)servoAngle[i] = 0;
    if (i == 8)servoAngle[i] = 180;
    if (i == 10)servoAngle[i] = 100;
    if (i == 11)servoAngle[i] = 0;
    if (i == 12)servoAngle[i] = 180;
    //初始化所有馬達角度位置為復歸狀態
  }
  servoMove();
}

void standUp() {//站直
  for (int i = 0; i < 15; i++) {//更改馬達角度
    if (i == 0)  servoAngle[i] = 135  ;
    if (i == 1)  servoAngle[i] = 90   ;
    if (i == 2)  servoAngle[i] = 90   ;
    if (i == 3)  servoAngle[i] = 45   ;
    if (i == 4)  servoAngle[i] = 90   ;
    if (i == 5)  servoAngle[i] = 90   ;
    if (i == 6)  servoAngle[i] = 110  ;
    if (i == 7)  servoAngle[i] = 120  ;
    if (i == 8)  servoAngle[i] = 70   ;
    if (i == 9)  servoAngle[i] = 90   ;
    if (i == 10) servoAngle[i] = 100  ;
    if (i == 11) servoAngle[i] = 130  ;
    if (i == 12) servoAngle[i] = 40   ;
    if (i == 13) servoAngle[i] = 90   ;
    if (i == 14) servoAngle[i] = 90   ;
  }
  servoMove();
}

void communicateWithNodeMCU() {//-----------與Wifi通訊區塊-----------
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

void processCommand() { //將Wifi接受到的指令轉為可執行的數據
  String stringProcessCache;
  int servoNumCache = 0;   //暫存指令指定控制的馬達編號
  int servoAngleCache = 0; //暫存指令指定控制的馬達角度
  int commandNumCache = 0; //暫存指令要求執行的內建動作編號
  for (int i = 0; i < 15; i++) {
    /* Servo02_angle000這樣為一個符合規範的組合指令
       字串的長度為16
       而已訂好的指令都規定為(Mega板上已寫好的預設功能)
       command001、command002......字串長度為10
    */
    if (commandCache[i].length() == 16) { //組合指令
      stringProcessCache = commandCache[i];
      //字串是char array第一個字元為char[0]
      stringProcessCache.remove(0, 5); //從第0格開始，共去除5個字元
      stringProcessCache.remove(2, 9); //從第2格開始，共去除9個字元
      servoNumCache = stringProcessCache.toInt();
      Serial.println(servoNumCache);
      commandCache[i].remove(0, 13);
      servoAngleCache = commandCache[i].toInt();
      Serial.println(servoAngleCache);
      if (servoNumCache >= 0 && servoNumCache <= 14) { //組合指令簡易防呆
        if (servoAngleCache >= 0 && servoAngleCache <= 180) {
          servoAngle[servoNumCache] = servoAngleCache;//存放要求的角度，等待後面servoMove()執行
        }
      }
      commandCache[i] = "";//清空指令已表示完成
    }
    else if (commandCache[i].length() == 10) { //內建好的動作
      commandCache[i].remove(0, 7);
      commandNumCache = commandCache[i].toInt();

      matchBuiltInCommandRequest(commandNumCache);//呼叫內建動作指令

      commandCache[i] = "";//清空指令已表示完成
    }
    else commandCache[i] = "";
    //可能在傳輸中出錯而不符合規定的指令，直接丟棄
  }
}

void printInputCommand() {//輸出debug訊息用
  for (int i = 0; i < 20; i++) {
    if (commandCache[i] != "") {
      Serial.println(commandCache[i]);
      //Serial.print(commandCache[i].length());//輸出字串長度
      //commandCache[i] = "";
    }
  }
}

char comPortIncomingByte;//電腦通訊用
String comInputCache[20];
String comServoNum;
String comServoAngle;
int comNum = -1;
int comAngle = -1;
void sendControlCommandViaSerialPort() { //debug用,透過監控視窗發送控制指令
  //電腦用指令看起來像這樣 => s09a080<=結尾按Enter換行
  while (Serial.available()) { //一次吃完所有指令
    comPortIncomingByte = Serial.read();
    if (comPortIncomingByte == 's' || comPortIncomingByte == 'c') {
      for (int i = 0; i < 20; i++) {
        if (comInputCache[i] == "") { //判斷哪一個指令快取陣列為空
          comInputCache[i] = Serial.readStringUntil('.');//將新指令加到指令快取
          Serial.println(comInputCache[i]);
          break;//離開for迴圈繼續讀取COM送入的資料
        }
      }
    }
  }
  String stringProcessCache;
  int servoNumCache = 0;   //暫存指令指定控制的馬達編號
  int servoAngleCache = 0; //暫存指令指定控制的馬達角度
  int commandNumCache = 0; //暫存指令要求執行的內建動作編號
  for (int i = 0; i < 15; i++) {
    if (comInputCache[i].length() == 6) { //組合指令
      stringProcessCache = comInputCache[i];
      //字串是char array第一個字元為char[0]
      stringProcessCache.remove(2, 4); //從第2格開始，共去除4個字元
      servoNumCache = stringProcessCache.toInt();
      Serial.println(servoNumCache);
      comInputCache[i].remove(0, 3);
      servoAngleCache = comInputCache[i].toInt();
      Serial.println(servoAngleCache);
      if (servoNumCache >= 0 && servoNumCache <= 14) { //組合指令簡易防呆
        if (servoAngleCache >= 0 && servoAngleCache <= 180) {
          servoAngle[servoNumCache] = servoAngleCache;//存放要求的角度，等待後面servoMove()執行
        }
      }
    }
    else if (comInputCache[i].length() == 3) { //呼叫內建動作指令
      //Serial 呼叫內建動作指令範例:c101.為左側拳(直接打指令的編號，但要湊齊3位數如c001.、c002.)
      commandNumCache = comInputCache[i].toInt();

      matchBuiltInCommandRequest(commandNumCache);

    }
    comInputCache[i] = "";//清空指令已表示完成
  }
}
