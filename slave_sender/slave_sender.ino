// Wire Slave Sender
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Sends data as an I2C/TWI slave device
// Refer to the "Wire Master Reader" example for use with this

// Created 29 March 2006

// This example code is in the public domain.


#include <Wire.h>

#define SDA_PIN 17
#define SCL_PIN 16
#define SLAVE_ADDR 8

int led = LED_BUILTIN;

void setup()
{
  pinMode(led, OUTPUT);
  Wire.setSDA(SDA_PIN);
  Wire.setSCL(SCL_PIN);
  Wire.begin(SLAVE_ADDR);                // join i2c bus with address #8
  Wire.onRequest(requestEvent); // register event
  Serial.begin(9600);           // start serial for output
}

void loop()
{
  delay(100);
}

// function that executes whenever data is requested by master
// this function is registered as an event, see setup()
void requestEvent()
{
  digitalWrite(led, HIGH);  // briefly flash the LED
  Wire.write("hello ");     // respond with message of 6 bytes
                            // as expected by master
  digitalWrite(led, LOW);
}
