//constants
const int pinLittle = A0; //analog pin 0 for the little finger
const int pinRing = A1; //analog pin 1 for the ring finger
const int pinMiddle = A2; //analog pin 2 for the middle finger
const int pinIndex = A3; //analog pin 3 for the index finger
const int pinThumb = A4; //analog pin 4 for the thumb

const int xPin = 2; //X output of the accelerometer
const int yPin = 3; //y output of the accelerometer


const int pinGreen = 4; //digital pin 4 for the Green LED
const int pinYellow = 5; //digital pin 5 for the Yellow LED
const int pinRed = 6; //digital pin 6 for the Red LED


//variables:
int sensorLittle = 0; //sensor value for the little finger
int sensorRing = 0; //sensor value for the ring finger
int sensorMiddle = 0; //sensor value for the middle finger
int sensorIndex = 0; //sensor value for the index finger
int sensorThumb = 0; //the sensor value for the thumb

int minLittle = 135; //the minimum sensor value for the little finger
int minRing = 135; //the minimum sensor value for the ring finger
int minMiddle = 135; //the minimum sensor value for the middle finger
int minIndex = 135; //the minimum sensor value for the index finger
int minThumb = 135; //the minimum sensor value for the thumb

int maxLittle = 486; //the maximum sensor value for the little finger
int maxRing = 486; //the maximum sensor value for the ring finger
int maxMiddle = 486; //the maximum sensor value for the middle finger
int maxIndex = 486; //the maximum sensor value for the index finger
int maxThumb = 486; //the maximum sensor value for the ring finger


void setup() {
  
  //turn on LED to signal the start of the calibration period:
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(18, OUTPUT);
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  
  digitalWrite(pinYellow, HIGH);
    
  Serial.begin (9600);

  //five second calibration
  while (millis() < 5000) {
      sensorLittle = analogRead(sensorPinLittle);
      sensorRing = analogRead(sensorPinRing);
      sensorMiddle = analogRead(sensorPinMiddle);
      sensorIndex = analogRead(sensorPinIndex);
      sensorThumb = analogRead(sensorPinThumb);
      
    //record max value for little finger
    if (sensorLittle > maxLittle) {
      maxLittle = sensorLittle;
    }
    //record max value for ring finger
    if (sensorRing > maxRing) {
      maxRing = sensorRing;
    }
   //record max value for for middle finger
    if (sensorMiddle > maxMiddle) {
      maxMiddle = sensorMiddle;
    }
    //record max value for index finger
    if (sensorIndex > maxIndex) {
      maxIndex = sensorIndex;
    }
    //record max value for thumb
    if (sensorThumb > maxThumb) {
      maxThumb = sensorThumb;
    }
    //record min value for little finger
    if (sensorLittle < minLittle) {
      minLittle = sensorLittle;
    }
    //record min value for ring finger
    if (sensorRing < minRing) {
      minRing = sensorRing;
    }
    //record min value for middle finger
    if (sensorMiddle < minMiddle) {
      minMiddle = sensorMiddle;
    }
    //record min value for index finger
    if (sensorIndex < minIndex) {
      minIndex = sensorIndex;
    }
    //record min value for thumb
    if (sensorThumb < minThumb) {
      minThumb = sensorThumb;
    }
  }

  //calibration end
  digitalWrite(pinYellow, LOW);
 
  Serial.print ("MinLittle = ");
  Serial.println (minLittle);
  Serial.print ("MaxLittle = ");
  Serial.println (maxLittle);
  
  Serial.println ("             ");
  
  Serial.print ("MinRing = ");
  Serial.println (minRing);
  Serial.print ("MaxRing = ");
  Serial.println (maxRing);
  
  Serial.println ("             "); 
  
  Serial.print ("MinMiddle = ");
  Serial.println (minMiddle);
  Serial.print ("MaxMiddle = ");
  Serial.println (maxMiddle);
  
  Serial.println ("             "); 
  
   Serial.print ("MinIndex = ");
  Serial.println (minIndex);
  Serial.print ("MaxIndex = ");
  Serial.println (maxIndex);
  
  Serial.println ("             "); 
  
  Serial.print ("MinThumb = ");
  Serial.println (minThumb);
  Serial.print ("MaxThumb = ");
  Serial.println (maxThumb);
  
  Serial.println ("             ");
  
  delay (1000);
}

void loop() {

  //read the sensor
  sensorLittle = analogRead(pinLittle);
  sensorRing = analogRead(pinRing);
  sensorMiddle = analogRead(pinMiddle);
  sensorIndex = analogRead(pinIndex);
  sensorThumb = analogRead(pinThumb);

  //map the values
  sensorLittle = map(sensorLittle, minLittle, maxLittle, 0, 255);
  sensorRing = map(sensorRing, minRing, maxRing, 0, 255);
  sensorMiddle = map(sensorMiddle, minMiddle, maxMiddle, 0, 255);
  sensorIndex = map(sensorIndex, minIndex, maxIndex, 0, 255);
  sensorThumb = map(sensorThumb, minThumb, maxThumb, 0, 255);

  //constrain the values
  sensorLittle = constrain(sensorLittle, 1, 255);
  sensorRing = constrain(sensorRing, 1, 255);
  sensorMiddle = constrain(sensorMiddle, 1, 255);
  sensorIndex = constrain(sensorIndex, 1, 255);
  sensorThumb = constrain(sensorThumb, 1, 255);
  
  Serial.println ("-------------------");
  Serial.print ("sensorLittle = ");
  Serial.println (sensorLittle);
  
  Serial.print ("sensorRing = ");
  Serial.println (sensorRing);
  
  Serial.print ("sensorMiddle = ");
  Serial.println (sensorMiddle);
  
  Serial.print ("sensorIndex = ");
  Serial.println (sensorIndex);
  
  Serial.print ("sensorThumb = ");
  Serial.println (sensorThumb);
  
  Serial.println ("   ");
   Serial.println (" ");
  
 

  
 

  
  //--------------------------------LetterA-----------------------------
  
  if (sensorLittle == 1 && sensorRing == 1 && sensorMiddle == 1 && sensorIndex == 1 && sensorThumb > 1) {
    
    Serial.println  ("\n");
    Serial.println ("A"); //Print letter A to serial
    Serial.println  ("        ");
    
  }
  
  else {
    
  }
  
  //--------------------------------LetterB-----------------------------
  
  if (sensorLittle > 200 && sensorRing > 200 && sensorMiddle > 200 && sensorIndex > 200 && sensorThumb == 1) {
    
    Serial.println ("B"); //Print letter B to serial
    Serial.println  ("        ");
    
  }
  
  else {
    
  }
  
  //--------------------------------LetterC-----------------------------
  
  
  if (sensorLittle < 200 && sensorLittle > 20 && sensorRing < 200 && sensorRing > 20 && sensorMiddle < 200 && sensorMiddle > 20 && sensorIndex < 200 && sensorIndex > 20 && sensorThumb < 200 && sensorThumb > 20 && sensorThumb == 1) {
    
    Serial.println ("C"); //Print letter C to serial
    Serial.println  ("        ");
   
  }
  
  else {
   
  }
  
  //--------------------------------LetterD-----------------------------
  
  
  if (sensorLittle == 1 && sensorRing == 1 && sensorMiddle == 1 && sensorIndex > 100 && sensorThumb == 1) {
    
    Serial.println ("D"); //Print letter D to serial
    Serial.println  ("        ");
    
  }
  
  else {
   
  }
  
  //--------------------------------LetterE-----------------------------
  
  
  if (sensorLittle == 1 && sensorRing == 1 && sensorMiddle == 1 && sensorIndex == 1 && sensorThumb == 1) {
    
    Serial.println ("E"); //Print letter E to serial
    Serial.println  ("        ");
    
  }
  
  else {
   
  }
  
  //--------------------------------LetterF-----------------------------
  
  
  if (sensorLittle == 1 && sensorRing > 200 && sensorMiddle > 200 && sensorIndex = 1 && sensorThumb == 1) {
    
    Serial.println ("F"); //Print letter F to serial
    Serial.println  ("        ");
    
  }
  
  else {
   
  }
  
  //--------------------------------LetterG-----------------------------
  
  
  if (sensorLittle == 1 && sensorRing == 1 && sensorMiddle == 1 && sensorIndex > 150  && sensorThumb > 150) {
    
    Serial.println ("G"); //Print letter G to serial
    Serial.println  ("        ");
    
  }
  
  else {
   
  }
    //--------------------------------LetterH-----------------------------
  
  if (sensorLittle > 200 && sensorRing > 200 && sensorMiddle > 200 && sensorIndex > 200 && sensorThumb > 200) {
    
    Serial.println ("H"); //Print letter H to serial
    Serial.println  ("        ");
    
  }
  
  else {
   
  }
  
  
  delay (1000);
  
   

}
