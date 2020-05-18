// Wire Slave Receiver
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Receives data as an I2C/TWI slave device
// Refer to the "Wire Master Writer" example for use with this

// Created 29 March 2006

// This example code is in the public domain.


#include <Wire.h>

#define SDA_PIN 17
#define SCL_PIN 16
#define SLAVE_ADDR 8
int led = LED_BUILTIN;
char char_msg[5];


void setup()
{
  pinMode(led, OUTPUT);
  Wire.setSDA(SDA_PIN);
  Wire.setSCL(SCL_PIN);
  Wire.begin(SLAVE_ADDR);                // join i2c bus with address #8
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(9600);           // start serial for output
}

void loop()
{
  delay(5000);
  Serial.print(SDA_PIN);
  Serial.print(SCL_PIN);
  Serial.println(SLAVE_ADDR);
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany)
{
  digitalWrite(led, HIGH);       // briefly flash the LED
  byte index = 0;  //character counter

  while(Wire.available() > 1) {  // loop through all but the last
    char_msg[index++] = Wire.read();        // receive byte as a character
//    Serial.print(c);             // print the character
  }
  Serial.print("Teensy3.2..Slave Reader");
  Serial.print(char_msg);             // print the character
  int x = Wire.read();           // receive byte as an integer
  Serial.println(x);             // print the integer
  digitalWrite(led, LOW);
}
