#include <SPI.h>

int accel = 12;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  SPI.begin();
  digitalWrite(7, HIGH); //set pin 7 to high to enable reading 
  // the data from the accelerometer
  //refered to as Control Sequence or CS in documentation
}

void loop() {
  // put your main code here, to run repeatedly: 
//  int readAccel = digitalRead(12);
  Serial.println(SPI.transfer(accel));
  delay(500);
}
