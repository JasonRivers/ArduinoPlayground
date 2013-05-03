#include <Wire.h>

int IR = A3; // Infrared Sensor
int LED = 7; // LED (Dah!)
int I2C_ADDRESS = 4; //Address for [this] I2C slave
char buf[10]; //create a binary buffer of 10 bytes


void setup()
{
  Serial.begin(9600); // start a serial monitor
  pinMode(LED, OUTPUT); //LED is an output
  pinMode(IR, INPUT); // IR is an input
  Wire.begin(I2C_ADDRESS); // Start I2C on I2C_ADDRESS
  Wire.onRequest(RequestEvent); // Send data
  Wire.onReceive(ReceiveEvent); // Receive data
}

void RequestEvent()
{
  Serial.println("RequestEvent"); // write RequestEvent on the Serial
  int IRVal = analogRead(IR);
  sprintf(buf, "IR%u\n", IRVal);
  Wire.write(buf); // send the character "1" over I2C
  digitalWrite(LED, LOW); // turn the LED off
}

void ReceiveEvent(int numBytes) // Receive bytes over I2C
{
  Serial.println("ReceiveEvent"); // write ReceiveEvent on the Serial
  //not going to do anything with the data, I don't care, I just want to know we got it.
  digitalWrite(LED, HIGH); // turn on the LED
  Wire.read(); // clear the buffer
}
  
  
void loop () //required for Arduino
{
  delay(10);
}
