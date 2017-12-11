/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

/* Bluetooth (HC-05) to Arduino Uno wiring:
 * VCC - 5V
 * RX  - 3
 * TX  - 2
 * GND - GND
 */

#define PC_BAUDRATE 115200
#define BLUETOOTH_BAUDRATE 38400


#include <SoftwareSerial.h>

SoftwareSerial SerialBT(2, 3); // RX, TX
char data = 0; 
#include <Wire.h>
#include <UnoWiFiDevEd.h>
#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
    Serial.begin(PC_BAUDRATE);
    SerialBT.begin(BLUETOOTH_BAUDRATE);
   pinMode(13,OUTPUT);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  // for (pos = 0; pos <= 90; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
   // myservo.write(pos);              // tell servo to go to position in variable 'pos'
    //delay(0 );                       // waits 15ms for the servo to reach the position
  //}
  //for (pos = 90; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
  //  myservo.write(pos);              // tell servo to go to position in variable 'pos'
   // delay(0);                       // waits 15ms for the servo to reach the position
  //}
  //myservo.write(100);

  if (SerialBT.available()) {

      Serial.print("Available");
      data = SerialBT.read();        //Read the incoming data & store into data
      Serial.print(SerialBT.read());  
      
        //Serial.write(SerialBT.read());
        //digitalWrite(LED_PIN, LOW);
    }

    if (Serial.available()) {
        //digitalWrite(LED_PIN, HIGH);
        
        SerialBT.write(Serial.read());
        //Serial.println("Dieter");
        //digitalWrite(LED_PIN, LOW);
    }

  
}
