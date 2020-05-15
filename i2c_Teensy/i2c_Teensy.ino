/*
 * This example shows how to display bitmaps that are exported from GIMP and
 * compiled into the sketch and stored in the Teensy's Flash memory
 * See more details here:
 * http://docs.pixelmatix.com/SmartMatrix/library.html#smartmatrix-library-how-to-use-the-library-drawing-raw-bitmaps
 *
 * This example uses only the SmartMatrix Background layer
 */
// Boyd: Commented out the following line
/* #include <SmartLEDShieldV4.h>  // comment out this line for if you're not using SmartLED Shield V4 hardware (this line needs to be before #include <SmartMatrix3.h>)  */
#include <Wire.h>

int led = LED_BUILTIN;

void setup()
{
  pinMode(led, OUTPUT);
  Wire.begin(8);                // join i2c bus with address #8
  Wire.onRequest(requestEvent); // register event
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














/*
#include <Wire.h>                       // Wire Library for i2c Teensy(Slave) to communicate with the ESP8266 (Master)

void setup() {
  Serial.begin(9600);     // Serial port to USB at 12Mbit/selectrion
  delay(500);
  Serial.println("Teensy 3.2 Serial Port");

  Wire.setSDA(17);
  Wire.setSCL(16);
  Wire.begin(4);           //Join the i2c bus as slave at address #4
  Wire.onReceive(receiveEvent); // register event
}

void loop() {
  Serial.println("Hello World...");
  delay(1000);  // do not print too fast!
}


// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany)
{
  while(1 < Wire.available()) // loop through all but the last
  {
    char c = Wire.read(); // receive byte as a character
    Serial.print(c);         // print the character
  }
  int x = Wire.read();    // receive byte as an integer
  Serial.println(x);         // print the integer
}
*/
