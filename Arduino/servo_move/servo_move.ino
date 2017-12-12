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
 /*
  * Yellow - xxx
  * Red - 5V
  * Brown - GDN
  */

#define PC_BAUDRATE 115200
#define BLUETOOTH_BAUDRATE 38400


#include <SoftwareSerial.h>
#include <Wire.h>
#include <UnoWiFiDevEd.h>
#include <Servo.h>

SoftwareSerial SerialBT(2, 3); // RX, TX
char data = 0; 

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
int value = 0;    // variable to hold the analog value


void setup() {
    Serial.begin(9600);
    SerialBT.begin(9600);

    SerialBT.print("AT");
    waitForResponse();

    // Should respond with its version
SerialBT.print("AT+VERSION");
waitForResponse();

// Set pin to 1234
SerialBT.print("AT+PIN1234");
waitForResponse();

// Set the name to BLU
SerialBT.print("AT+NAMEBLU");
waitForResponse();

// Set baudrate from 9600 (default) to 57600
// * Note of warning * - many people report issues after increasing JY-MCU
// baud rate upwards from the default 9,600bps rate (e.g. 'AT+BAUD4')
// so you may want to leave this and not alter the speed!!
SerialBT.print("AT+BAUD7");
waitForResponse();

Serial.println("Finished!");

   pinMode(13,OUTPUT);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo.write(20);
}


// Function to pass BlueTooth output through to serial port output
void waitForResponse() {
delay(1000);
while (SerialBT.available()) {
Serial.write(SerialBT.read());
}
Serial.write("\n");
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
  value = SerialBT.read() ;
  delay(200);
  //Serial.println((value*18));
      
      //myservo.write((value*18));

      while (SerialBT.available()) {
      Serial.write(SerialBT.read());  //juiste waarden!!!!!!
      //myservo.write(SerialBT.read());
       myservo.write(10);
       
      }

     

   if (SerialBT.available()) {
      //value = SerialBT.read() ;
      
      //Serial.println(value); // lees waarden van gsm naar serial monitor
        if(SerialBT.read()){
          // myservo.write(180);
           
        }

        //Serial.write(SerialBT.read());
        
    }

    if (Serial.available()) {
        
        SerialBT.write(Serial.read());
        myservo.write(20);
        Serial.write(Serial.read());
        Serial.write(SerialBT.read());
    }

  
}
