#include <Wire.h>
#include <stdio.h>

// Setup Stuff
int LED1 = 2;
int LED2 = 3;
int LED3 = 4;
int LED4 = 5;
int LED5 = 6;
int LED6 = 7;
int LED7 = 8;
int LED8 = 9;
int LED9 = 10;
int BLED = 13;
int I2CSlaveAddress = 10;
int IRPin = A3;
int SRPin = A2;
int threshold = 255;
int i = 0;
 char buf[32];

void setup ()
{
  // start the Serial connection
  Serial.begin(9600);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  pinMode(LED7, OUTPUT);
  pinMode(LED8, OUTPUT);
  pinMode(LED9, OUTPUT);
  pinMode(BLED, OUTPUT);
  digitalWrite(LED1, LOW);  
  digitalWrite(LED2, LOW);  
  digitalWrite(LED3, LOW);  
  digitalWrite(LED4, LOW);  
  digitalWrite(LED5, LOW);  
  digitalWrite(LED6, LOW);  
  digitalWrite(LED7, LOW);  
  digitalWrite(LED8, LOW);  
  digitalWrite(LED9, LOW);  
  // Start I2C
  Wire.begin(I2CSlaveAddress);
  Wire.onRequest(onI2CRequest);
}

void onI2CRequest()
{

  Serial.print("Got I2C Request\r\n");
  Serial.print("Sending POT Data\r\n");
      int IRVal = analogRead(IRPin);
//      int SRVal = analogRead(SRPin);
sprintf(buf, "IR%u\n", IRVal);
  Serial.println(buf);
  Wire.write(buf);
}


void loop ()
{
  int potVal = analogRead(IRPin);
  if (potVal > 50)
  {
   digitalWrite(LED1, HIGH);   // turn the LED on (HIGH is the voltage level)
  }else{
    digitalWrite(LED1, LOW);    // turn the LED off by making the voltage LOW
  }
  if (potVal > 100)
  {
   digitalWrite(LED2, HIGH);   // turn the LED on (HIGH is the voltage level)
  }else{
    digitalWrite(LED2, LOW);    // turn the LED off by making the voltage LOW
  }
  if (potVal > 150)
  {
   digitalWrite(LED3, HIGH);   // turn the LED on (HIGH is the voltage level)
  }else{
    digitalWrite(LED3, LOW);    // turn the LED off by making the voltage LOW
  }
  if (potVal > 200)
  {
   digitalWrite(LED4, HIGH);   // turn the LED on (HIGH is the voltage level)
  }else{
    digitalWrite(LED4, LOW);    // turn the LED off by making the voltage LOW
  }
  if (potVal > 250)
  {
   digitalWrite(LED5, HIGH);   // turn the LED on (HIGH is the voltage level)
  }else{
    digitalWrite(LED5, LOW);    // turn the LED off by making the voltage LOW
  }
  if (potVal > 300)
  {
   digitalWrite(LED6, HIGH);   // turn the LED on (HIGH is the voltage level)
  }else{
    digitalWrite(LED6, LOW);    // turn the LED off by making the voltage LOW
  }
  if (potVal > 350)
  {
   digitalWrite(LED7, HIGH);   // turn the LED on (HIGH is the voltage level)
  }else{
    digitalWrite(LED7, LOW);    // turn the LED off by making the voltage LOW
  }
  if (potVal > 400)
  {
   digitalWrite(LED8, HIGH);   // turn the LED on (HIGH is the voltage level)
  }else{
    digitalWrite(LED8, LOW);    // turn the LED off by making the voltage LOW
  }
  if (potVal > 450)
  {
   digitalWrite(LED9, HIGH);   // turn the LED on (HIGH is the voltage level)
  }else{
    digitalWrite(LED9, LOW);    // turn the LED off by making the voltage LOW
  }
  
  delay(50); // much more reliable results!
  
  
}
