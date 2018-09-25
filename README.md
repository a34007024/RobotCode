# RobotCode
# 高三專題的程式碼存放區
# Arduiono IDE esp8266的套件
http://arduino.esp8266.com/stable/package_esp8266com_index.json

# start working in 【MainProject】 folder
# SoftwareSerial不如內建Serial快速，容易丟失字元

# 網路上說藍芽與ESP8266模組與板子的RX TX 要交錯接
RX -> TX    TX -> RX
但在嘗試SoftwareSerial 並經過測試後發現，NodeMCU的通訊腳似乎是相反的
只有RX -> RX  TX -> TX 才可正常通訊

# 180913用義大利副廠的Mega板測試 證實RX TX 要交錯接
看來是大陸版的Mega在布線時交錯了RX、TX的接線

# 接線說明(左側為NodeMCU,右側為Mega大陸版)
+ G   ->  GND
+ VIN ->  5V
+ RX  ->  RX1
+ TX  ->  TX1

# 接線說明(左側為NodeMCU,右側為Mega義大利副廠版)
+ G   ->  GND
+ VIN ->  5V
+ RX  ->  TX1
+ TX  ->  RX1

# 組合指令規則1:
/$Servo02_angle000.$Servo01_angle080.$Servo03_angle050
指令從$開始讀到.為完整的一串指令，並分別存入指令快取
剛開始出現 / 是因為WIFI板會把請求的連結丟出來
所以之後APP指令的合成就是依照這個規則

# 組合指令規則2:
Servo02_angle000這樣為一個符合規範的組合指令
字串的長度為16
而已訂好的指令都規定為(Mega板上已寫好的預設功能)
command001、command002、command003......
字串長度為10