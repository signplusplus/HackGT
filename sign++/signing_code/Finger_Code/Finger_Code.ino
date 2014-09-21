//constants
const int pinLittle = A0; //analog pin 0 for the little finger
const int pinRing = A2; //analog pin 1 for the ring finger
const int pinMiddle = A1; //analog pin 2 for the middle finger
const int pinIndex = A3; //analog pin 3 for the index finger
const int pinThumb = A4; //analog pin 4 for the thumb

//variables:
int sensorLittle = 0; //sensor value for the little finger
int sensorRing = 0; //sensor value for the ring finger
int sensorMiddle = 0; //sensor value for the middle finger
int sensorIndex = 0; //sensor value for the index finger
int sensorThumb = 0; //the sensor value for the thumb

int minLittle = 300; //the minimum sensor value for the little finger
int minRing = 265; //the minimum sensor value for the ring finger
int minMiddle = 435; //the minimum sensor value for the middle finger
int minIndex = 219; //the minimum sensor value for the index finger
int minThumb = 315; //the minimum sensor value for the thumb

int maxLittle = 514; //the maximum sensor value for the little finger
int maxRing = 515; //the maximum sensor value for the ring finger
int maxMiddle = 507; //the maximum sensor value for the middle finger
int maxIndex = 430; //the maximum sensor value for the index finger
int maxThumb = 390; //the maximum sensor value for the ring finger


void setup() {

  //turn on LED to signal the start of the calibration period: 
  //  digitalWrite(pinYellow, HIGH);

  Serial.begin (11520);
}

void loop() {

  //read the sensor
  sensorLittle = analogRead(pinLittle);
  sensorRing = analogRead(pinRing);
  sensorMiddle = analogRead(pinMiddle);
  sensorIndex = analogRead(pinIndex);
  sensorThumb = analogRead(pinThumb);

  //map the values
  sensorLittle = map(sensorLittle, minLittle, maxLittle, 0, 100);
  sensorRing = map(sensorRing, minRing, maxRing, 0, 100);
  sensorMiddle = map(sensorMiddle, minMiddle, maxMiddle, 0, 100);
  sensorIndex = map(sensorIndex, minIndex, maxIndex, 0, 100);
  sensorThumb = map(sensorThumb, minThumb, maxThumb, 0, 100);

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

  if (sensorLittle < 50 && sensorRing < 50 && sensorMiddle < 50 && sensorIndex < 50 && sensorThumb > 50) {

    Serial.println  ("\n");
    Serial.println ("A"); //Print letter A to serial
    Serial.println  ("        ");
    delay(1000);

  }

  else {
    //--------------------------------LetterB-----------------------------

    if (sensorLittle > 45 && sensorRing > 75 && sensorMiddle > 75 && sensorIndex > 75 && sensorThumb > 75) {

      Serial.println ("B"); //Print letter B to serial
      Serial.println  ("        ");
     delay(1000);
    }

    else {


      //--------------------------------LetterC-----------------------------


      if (sensorLittle < 50 && sensorLittle > 5 && sensorRing > 20 && sensorMiddle > 50 && sensorIndex > 75 && sensorThumb > 55 && sensorThumb < 80) {
        Serial.println ("C"); //Print letter C to serial
        Serial.println  ("        ");
        delay(1000);
      }

      else {


        //--------------------------------LetterD-----------------------------


        if (sensorLittle < 65 && sensorRing < 65 && sensorMiddle < 65 && sensorIndex > 80 && (sensorThumb < 70 || sensorThumb > 110)) {

          Serial.println ("D"); //Print letter D to serial
          Serial.println  ("        ");
          delay(1000);
        }

        else {


          //--------------------------------LetterE-----------------------------


          if (sensorLittle <50 && sensorRing <50 && sensorMiddle <50 && sensorIndex <50 && sensorThumb <50) {

            Serial.println ("E"); //Print letter E to serial
            Serial.println  ("        ");
            delay(1000);
          }

          else {


            //--------------------------------LetterF-----------------------------


            if (sensorLittle <20 && sensorRing > 85 && sensorMiddle > 75 && sensorIndex > 80 && sensorThumb > 50) {

              Serial.println ("F"); //Print letter F to serial
              Serial.println  ("        ");
              delay(1000);
            }

            else {


              //--------------------------------LetterG-----------------------------


              if (sensorLittle > 25 && sensorLittle < 65 && sensorRing < 25 && sensorMiddle < 35 && sensorIndex < 65  && (sensorThumb < 65 || sensorThumb > 100)) {

                Serial.println ("G"); //Print letter G to serial
                Serial.println  ("        ");
                delay(1000);
              }

              else {


                //--------------------------------LetterH-----------------------------

               if (sensorLittle > 25 && sensorLittle < 70 && sensorRing < 48 && sensorMiddle > 90 && sensorIndex < 65  && (sensorThumb < 65 || sensorThumb > 100)) {

                  Serial.println ("H"); //Print letter H to serial
                  Serial.println  ("        ");
                  delay(1000);
                }

                else {


                  //--------------------------------LetterL-----------------------------


                  if (sensorLittle < 70 && sensorRing < 40 && sensorMiddle < 65 && sensorIndex < 75 && (sensorThumb < 40  || sensorThumb > 65)) {

                    Serial.println ("L"); //Print letter L to serial
                    Serial.println  ("        ");
                    delay(1000);
                  }

                  else {

                    //--------------------------------LetterW-----------------------------


                    if (sensorLittle > 45 && sensorRing > 90 && sensorMiddle > 85 && sensorIndex < 75  && sensorThumb >50 && sensorThumb < 75) {

                      Serial.println ("W"); //Print letter W to serial
                      Serial.println  ("        ");
                      delay(1000);
                    }

                    else {

                      //--------------------------------LetterO-----------------------------


                      if (sensorLittle <15 && sensorRing > 50 && sensorMiddle > 50 && sensorIndex > 50 && sensorThumb > 50) {

                        Serial.println ("O"); //Print letter O to serial
                        Serial.println  ("        ");
                        delay(1000);
                      }

                      else {

                        //--------------------------------LetterR-----------------------------


                        if (sensorLittle < 75 && sensorLittle > 40 && sensorRing > 50 && sensorMiddle < 75 && sensorIndex > 55 ) {

                          Serial.println ("R"); //Print letter R to serial
                          Serial.println  ("        ");
                          delay(1000);
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }  
    }
  }

}

