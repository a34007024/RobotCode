int relay = 30;
//relayPositive & relayNegative must connect to 5V and GND
//Otherwise the power(current) will not be enough for Relay
//繼電器的+、-端一定要接再5V、GND上，不然數位腳輸出的電流不夠驅動繼電器
//驅動一顆5V的Relay需約75ma
void setup() {
  pinMode(relay,OUTPUT);
  digitalWrite(relay,LOW);
}
void loop() {
  digitalWrite(relay,HIGH);
  delay(2000);
  digitalWrite(relay,LOW);
  delay(2000);
}
