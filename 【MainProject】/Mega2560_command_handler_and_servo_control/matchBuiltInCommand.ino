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
}
