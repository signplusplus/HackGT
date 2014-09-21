int flexSensorPin = A0;
int flexSensorPin2 = A1;
int flexSensorPin3 = A3;                                          
int flexSensorPin4 = A4;
int flexSensorPin5 = A5;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly: 
  int flexSensorReading = analogRead(flexSensorPin);
  int flexSensorReading2 = analogRead(flexSensorPin2);
  int flexSensorReading3 = analogRead(flexSensorPin3);
  int flexSensorReading4 = analogRead(flexSensorPin4);
  int flexSensorReading5 = analogRead(flexSensorPin5);
  
  Serial.print("1st: ") ; Serial.println(flexSensorReading);
  Serial.print("2nd: ") ; Serial.println(flexSensorReading2);
  Serial.print("3rd: ") ; Serial.println(flexSensorReading3);
  Serial.print("4th: ") ; Serial.println(flexSensorReading4);
  Serial.print("5th: ") ; Serial.println(flexSensorReading5);
  delay(1000);
}                                                                                                                                                                                                     
