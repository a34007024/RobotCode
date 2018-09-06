# RobotCode
# 高三專題的程式碼存放區

# start working in 【MainProject】 folder
# SoftwareSerial不如內建Serial快速，容易丟失字元
Not Needed at all => NodeMCU 與 Arduino 通訊:利用SoftwareSerial()

#網路上說藍芽與ESP8266模組與板子的RX TX 要交錯接
RX -> TX    TX -> RX
但在嘗試SoftwareSerial 並經過測試後發現，NodeMCU的通訊腳似乎是相反的
只有RX -> RX  TX -> TX 才可正常通訊

#接線說明(左側為NodeMCU,右側為Mega)
G   ->  GND
VIN ->  5V
RX  ->  RX1
TX  ->  TX1