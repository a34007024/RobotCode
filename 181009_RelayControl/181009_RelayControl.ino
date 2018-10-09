int relayPositive = 30,relayNegative = 31,relay = 32;
void setup() {
  pinMode(relayPositive,OUTPUT);
  pinMode(relayNegative,OUTPUT);
  pinMode(relay,OUTPUT);
  digitalWrite(relayPositive,HIGH);
  digitalWrite(relayNegative,LOW);
  digitalWrite(relay,LOW);
}

void loop() {
  digitalWrite(relay,HIGH);
  delay(2000);
  digitalWrite(relay,LOW);
  delay(2000);
}
