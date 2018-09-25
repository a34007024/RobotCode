# 使用Mega內建的通訊port
因為SoftwareSerial的傳輸 baud rate不夠
導致容易傳輸錯誤

# 網路上說藍芽與ESP8266模組與板子的RX TX 要交錯接
RX -> TX    TX -> RX
但經過測試後發現，NodeMCU的通訊腳似乎是相反的
只有RX -> RX  TX -> TX 才可正常通訊

# 接線說明(左側為NodeMCU,右側為Mega)
G   ->  GND
VIN ->  5V
RX  ->  RX1
TX  ->  TX1

# NodeMCU只用來進行指令的收發
指令可以以一套動作來編寫
如action1是左鉤拳action2是右鉤拳forward是往前走
backward是往後退等
也可以由使用者自訂動作指令
APP會自動產生符合規範的指令傳給NodeMCU
如Servo1_90.Servo2_45.Servo8_66--
或是Servo1_60.Servo7_45--等組合指令

# 藉由Mega透過Serial1或Serial2接收
NodeMCU接收到的指令，然後進行字串分析處理
若是一套邊寫好的動作就執行相對應的Servo控制
如果是組合指令，則先解析出每顆馬達要移動到的角度
再執行解析好的指令

# 組合指令規則1:
/$Servo02_angle000.$Servo01_angle080.$Servo03_angle050
指令從$開始讀到.為完整的一串指令，並分別存入指令快取
剛開始出現 / 是因為WIFI板會把請求的連結丟出來
所以之後APP指令的合成就是依照這個規則

# 組合指令規則2:
Servo02_angle000這樣為一個符合規範的指令
字串的長度為16
而已訂好的指令都規定為(Mega板上已寫好的預設功能)
command001、command002、command003......
字串長度為10