# RobotCode
# 高三專題的程式碼存放區

# start working in 【MainProject】 folder
# SoftwareSerial不如內建Serial快速，容易丟失字元
Not Needed at all => NodeMCU 與 Arduino 通訊:利用SoftwareSerial()

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