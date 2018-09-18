void debug(){
  for (int i = 0; i < 20; i++) {
    if (commandCache[i] != "") {
      Serial.println(commandCache[i]);
      commandCache[i] = "";
    }
  }
}
