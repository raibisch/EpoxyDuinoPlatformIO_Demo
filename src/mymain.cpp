#include <Arduino.h>
int i=0;
void setup() {
  Serial.println("***START***");
}

void loop() {
  Serial.printf("Hello %d\r\n",i);
  i++;
  delay(500);
}
