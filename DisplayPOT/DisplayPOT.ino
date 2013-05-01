#include <Wire.h>

// Setup Stuff
int LED = 7;
int BLED = 13;
int PushButton = 2;
int I2CSlaveAddress = 10;
int POTPin = A3;

void setup ()
{
  // start the Serial connection
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(BLED, OUTPUT);
  digitalWrite(LED, HIGH);  
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
  digitalWrite(LED, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(BLED, LOW);   
  delay(1000);               // wait for a second
  digitalWrite(LED, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(BLED, HIGH);
  delay(1000);               // wait for a second

}
