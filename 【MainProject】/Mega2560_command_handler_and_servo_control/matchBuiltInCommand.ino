void matchBuiltInCommandRequest(int processedCommandNumber) {//wifi與Serial port共用的內建動作指令
  switch (processedCommandNumber) {//經過字串處理的指令號碼
    case 1://向左移動

      break;
    case 2://向右移動

      break;
    case 3://向前移動

      break;
    case 4://向後移動

      break;
    case 101://左側拳
      for (int i = 0; i < 15; i++) {//更改馬達角度
        if (i == 0)  servoAngle[i] = 135  ;
        if (i == 1)  servoAngle[i] = 160  ;
        if (i == 2)  servoAngle[i] = 90 ;
        if (i == 3)  servoAngle[i] = 45 ;
        if (i == 4)  servoAngle[i] = 90 ;
        if (i == 5)  servoAngle[i] = 45 ;
        if (i == 6)  servoAngle[i] = 110  ;
        if (i == 7)  servoAngle[i] = 0  ;
        if (i == 8)  servoAngle[i] = 180  ;
        if (i == 9)  servoAngle[i] = 90 ;
        if (i == 10) servoAngle[i] = 100  ;
        if (i == 11) servoAngle[i] = 0  ;
        if (i == 12) servoAngle[i] = 180  ;
        if (i == 13) servoAngle[i] = 90 ;
        if (i == 14) servoAngle[i] = 90 ;
      }
      servoMove();
      delay(200);
      for (int i = 0; i < 15; i++) {//更改馬達角度
        if (i == 0)  servoAngle[i] = 0    ;
        if (i == 1)  servoAngle[i] = 160  ;
        if (i == 2)  servoAngle[i] = 15   ;
        if (i == 3)  servoAngle[i] = 45   ;
        if (i == 4)  servoAngle[i] = 90   ;
        if (i == 5)  servoAngle[i] = 45   ;
        if (i == 6)  servoAngle[i] = 110  ;
        if (i == 7)  servoAngle[i] = 0    ;
        if (i == 8)  servoAngle[i] = 180  ;
        if (i == 9)  servoAngle[i] = 90   ;
        if (i == 10) servoAngle[i] = 100  ;
        if (i == 11) servoAngle[i] = 0    ;
        if (i == 12) servoAngle[i] = 180  ;
        if (i == 13) servoAngle[i] = 90   ;
        if (i == 14) servoAngle[i] = 90   ;
      }
      servoMove();
      delay(200);
      for (int i = 0; i < 15; i++) {//更改馬達角度
        if (i == 0)  servoAngle[i] = 0    ;
        if (i == 1)  servoAngle[i] = 80   ;
        if (i == 2)  servoAngle[i] = 15   ;
        if (i == 3)  servoAngle[i] = 45   ;
        if (i == 4)  servoAngle[i] = 90   ;
        if (i == 5)  servoAngle[i] = 45   ;
        if (i == 6)  servoAngle[i] = 110  ;
        if (i == 7)  servoAngle[i] = 0    ;
        if (i == 8)  servoAngle[i] = 180  ;
        if (i == 9)  servoAngle[i] = 90   ;
        if (i == 10) servoAngle[i] = 100  ;
        if (i == 11) servoAngle[i] = 0    ;
        if (i == 12) servoAngle[i] = 180  ;
        if (i == 13) servoAngle[i] = 90   ;
        if (i == 14) servoAngle[i] = 90   ;
      }
      servoMove();
      delay(1000);
      resetServos();
      break;
    case 102://右側拳
      for (int i = 0; i < 15; i++) {//更改馬達角度
        if (i == 0)  servoAngle[i] = 135  ;
        if (i == 1)  servoAngle[i] = 90   ;
        if (i == 2)  servoAngle[i] = 90   ;
        if (i == 3)  servoAngle[i] = 45   ;
        if (i == 4)  servoAngle[i] = 25   ;
        if (i == 5)  servoAngle[i] = 80   ;
        if (i == 6)  servoAngle[i] = 110  ;
        if (i == 7)  servoAngle[i] = 0    ;
        if (i == 8)  servoAngle[i] = 180  ;
        if (i == 9)  servoAngle[i] = 90   ;
        if (i == 10) servoAngle[i] = 100  ;
        if (i == 11) servoAngle[i] = 0    ;
        if (i == 12) servoAngle[i] = 180  ;
        if (i == 13) servoAngle[i] = 90   ;
        if (i == 14) servoAngle[i] = 90   ;
      }
      servoMove();
      delay(200);
      for (int i = 0; i < 15; i++) {//更改馬達角度
        if (i == 0)  servoAngle[i] = 135  ;
        if (i == 1)  servoAngle[i] = 90   ;
        if (i == 2)  servoAngle[i] = 90   ;
        if (i == 3)  servoAngle[i] = 180  ;
        if (i == 4)  servoAngle[i] = 25   ;
        if (i == 5)  servoAngle[i] = 155  ;
        if (i == 6)  servoAngle[i] = 110  ;
        if (i == 7)  servoAngle[i] = 0    ;
        if (i == 8)  servoAngle[i] = 180  ;
        if (i == 9)  servoAngle[i] = 90   ;
        if (i == 10) servoAngle[i] = 100  ;
        if (i == 11) servoAngle[i] = 0    ;
        if (i == 12) servoAngle[i] = 180  ;
        if (i == 13) servoAngle[i] = 90   ;
        if (i == 14) servoAngle[i] = 90   ;
      }
      servoMove();
      delay(200);
      for (int i = 0; i < 15; i++) {//更改馬達角度
        if (i == 0)  servoAngle[i] = 135  ;
        if (i == 1)  servoAngle[i] = 90   ;
        if (i == 2)  servoAngle[i] = 90   ;
        if (i == 3)  servoAngle[i] = 180  ;
        if (i == 4)  servoAngle[i] = 105  ;
        if (i == 5)  servoAngle[i] = 155  ;
        if (i == 6)  servoAngle[i] = 110  ;
        if (i == 7)  servoAngle[i] = 0    ;
        if (i == 8)  servoAngle[i] = 180  ;
        if (i == 9)  servoAngle[i] = 90   ;
        if (i == 10) servoAngle[i] = 100  ;
        if (i == 11) servoAngle[i] = 0    ;
        if (i == 12) servoAngle[i] = 180  ;
        if (i == 13) servoAngle[i] = 90   ;
        if (i == 14) servoAngle[i] = 90   ;
      }
      servoMove();
      delay(1000);
      resetServos();
      break;
    case 201://左拳

      break;
    case 202://右拳

      break;
    case 301://左上勾拳
      for (int i = 0; i < 15; i++) {//更改馬達角度
        if (i == 0)  servoAngle[i] = 135 ;
        if (i == 1)  servoAngle[i] = 160 ;
        if (i == 2)  servoAngle[i] = 90 ;
        if (i == 3)  servoAngle[i] = 45 ;
        if (i == 4)  servoAngle[i] = 90 ;
        if (i == 5)  servoAngle[i] = 45 ;
        if (i == 6)  servoAngle[i] = 110 ;
        if (i == 7)  servoAngle[i] = 0 ;
        if (i == 8)  servoAngle[i] = 180 ;
        if (i == 9)  servoAngle[i] = 90 ;
        if (i == 10) servoAngle[i] = 100 ;
        if (i == 11) servoAngle[i] = 0 ;
        if (i == 12) servoAngle[i] = 180 ;
        if (i == 13) servoAngle[i] = 90 ;
        if (i == 14) servoAngle[i] = 90 ;
      }
      servoMove();
      delay(200);
      for (int i = 0; i < 15; i++) {//更改馬達角度
        if (i == 0)  servoAngle[i] = 0 ;
        if (i == 1)  servoAngle[i] = 140 ;
        if (i == 2)  servoAngle[i] = 140;
        if (i == 3)  servoAngle[i] = 45;
        if (i == 4)  servoAngle[i] = 90;
        if (i == 5)  servoAngle[i] = 45;
        if (i == 6)  servoAngle[i] = 110 ;
        if (i == 7)  servoAngle[i] = 0;
        if (i == 8)  servoAngle[i] = 180 ;
        if (i == 9)  servoAngle[i] = 90;
        if (i == 10) servoAngle[i] = 100 ;
        if (i == 11) servoAngle[i] = 0 ;
        if (i == 12) servoAngle[i] = 180 ;
        if (i == 13) servoAngle[i] = 90;
        if (i == 14) servoAngle[i] = 60;
      }
      servoMove();
      delay(1000);
      resetServos();
      break;
    case 302://右上勾拳
      for (int i = 0; i < 15; i++) {//更改馬達角度
        if (i == 0)  servoAngle[i] = 135 ;
        if (i == 1)  servoAngle[i] = 90 ;
        if (i == 2)  servoAngle[i] = 90 ;
        if (i == 3)  servoAngle[i] = 45 ;
        if (i == 4)  servoAngle[i] = 25 ;
        if (i == 5)  servoAngle[i] = 80 ;
        if (i == 6)  servoAngle[i] = 110 ;
        if (i == 7)  servoAngle[i] = 0 ;
        if (i == 8)  servoAngle[i] = 180 ;
        if (i == 9)  servoAngle[i] = 90 ;
        if (i == 10) servoAngle[i] = 100 ;
        if (i == 11) servoAngle[i] = 0 ;
        if (i == 12) servoAngle[i] = 180 ;
        if (i == 13) servoAngle[i] = 90 ;
        if (i == 14) servoAngle[i] = 90 ;
      }
      servoMove();
      delay(200);
      for (int i = 0; i < 15; i++) {//更改馬達角度
        if (i == 0)  servoAngle[i] = 135 ;
        if (i == 1)  servoAngle[i] = 90 ;
        if (i == 2)  servoAngle[i] = 90 ;
        if (i == 3)  servoAngle[i] = 180 ;
        if (i == 4)  servoAngle[i] = 25 ;
        if (i == 5)  servoAngle[i] = 80 ;
        if (i == 6)  servoAngle[i] = 110 ;
        if (i == 7)  servoAngle[i] = 0 ;
        if (i == 8)  servoAngle[i] = 180 ;
        if (i == 9)  servoAngle[i] = 90 ;
        if (i == 10) servoAngle[i] = 100 ;
        if (i == 11) servoAngle[i] = 0 ;
        if (i == 12) servoAngle[i] = 180 ;
        if (i == 13) servoAngle[i] = 90 ;
        if (i == 14) servoAngle[i] = 120 ;
      }
      servoMove();
      delay(1000);
      resetServos();
      break;
    case 311://左勾拳
      for (int i = 0; i < 15; i++) {//更改馬達角度
        if (i == 0)  servoAngle[i] = 75    ;
        if (i == 1)  servoAngle[i] = 35   ;
        if (i == 2)  servoAngle[i] = 90   ;
        if (i == 3)  servoAngle[i] = 45   ;
        if (i == 4)  servoAngle[i] = 90   ;
        if (i == 5)  servoAngle[i] = 45   ;
        if (i == 6)  servoAngle[i] = 110  ;
        if (i == 7)  servoAngle[i] = 0    ;
        if (i == 8)  servoAngle[i] = 180  ;
        if (i == 9)  servoAngle[i] = 90   ;
        if (i == 10) servoAngle[i] = 100  ;
        if (i == 11) servoAngle[i] = 0    ;
        if (i == 12) servoAngle[i] = 180  ;
        if (i == 13) servoAngle[i] = 90   ;
        if (i == 14) servoAngle[i] = 25   ;
      }
      servoMove();
      delay(1000);
      resetServos();
      break;
    case 312://右勾拳
      for (int i = 0; i < 15; i++) {//更改馬達角度
        if (i == 0)  servoAngle[i] = 135  ;
        if (i == 1)  servoAngle[i] = 90   ;
        if (i == 2)  servoAngle[i] = 110  ;
        if (i == 3)  servoAngle[i] = 105  ;
        if (i == 4)  servoAngle[i] = 140  ;
        if (i == 5)  servoAngle[i] = 90   ;
        if (i == 6)  servoAngle[i] = 110  ;
        if (i == 7)  servoAngle[i] = 0    ;
        if (i == 8)  servoAngle[i] = 180  ;
        if (i == 9)  servoAngle[i] = 90   ;
        if (i == 10) servoAngle[i] = 100  ;
        if (i == 11) servoAngle[i] = 0    ;
        if (i == 12) servoAngle[i] = 180  ;
        if (i == 13) servoAngle[i] = 90   ;
        if (i == 14) servoAngle[i] = 160  ;
      }
      servoMove();
      delay(1000);
      resetServos();
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
}
