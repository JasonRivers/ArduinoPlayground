#include <Wire.h>

// Setup Stuff

int LED6 = 7;
int PushButton = 2;
int I2CSlaveAddress = 10;
int POTPin = A3;
int threshold = 255;

void setup ()
{
  // start the Serial connection
  Serial.begin(9600);
  pinMode(LED6, OUTPUT);
  digitalWrite(LED6, LOW);  
  
  // Start I2C
  Wire.begin(I2CSlaveAddress);
  Wire.onRequest(onI2CRequest);
}

void onI2CRequest()
{
  Serial.print("Got I2C Request\r\n");
  Serial.print("Sending POT Data\r\n");
      int potVal = analogRead(POTPin);
  Serial.println(potVal);
  Wire.write(potVal);
}


void loop ()
{
  int potVal = analogRead(POTPin);
  if (potVal > 255)
  {
   digitalWrite(LED6, HIGH);   // turn the LED on (HIGH is the voltage level)
  }else{
    digitalWrite(LED6, LOW);    // turn the LED off by making the voltage LOW
  }
  
  delay(50); // much more reliable results
  
  
}
