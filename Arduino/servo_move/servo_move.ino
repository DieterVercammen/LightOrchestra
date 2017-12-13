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

String Data = "";
int Number;
Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards


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
 
}


// Function to pass BlueTooth output through to serial port output
void waitForResponse() {

}





void loop() {
  

  
 Serial.println(Number);

 while (SerialBT.available()) {

  char character = SerialBT.read(); // Receive a single character from the software serial port
        Data.concat(character); // Add the received character to the receive buffer
        if (character == '\n')
        {
            if(Data.toInt() > 0) {
              Number = 130;
            } else {
              Number = 80;
            }
          
            /*switch (Data.toInt()) {
              case -10:
                Number = 0;
                break;
              case -9:
                Number = 9;
                break;
              case -8:
                Number = 18;
                break;
              case -7:
                Number = 27;
                break;
              case -6:
                Number = 36;
                break;
              case -5:
                Number = 45;
                break;
              case -4:
                Number = 54;
                break;
              case -3:
                Number = 63;
                break;
              case -2:
                Number = 72;
                break;
              case -1:
                Number = 81;
                break;
              case 0:
                Number = 90;
                break;
              case 1:
                Number = 99;
                break;
              case 2:
                Number = 108;
                break;
              case 3:
                Number = 117;
                break;
              case 4:
                Number = 126;
                break;
              case 5:
                Number = 135;
                break;
              case 6:
                Number = 144;
                break;
              case 7:
                Number = 153;
                break;
              case 8:
                Number = 162;
                break;
              case 9:
                Number = 171;
                break;
              case 10:
                Number = 180;
                break;
              default:
                Number = 0;
            }*/
            //Number = Data.toInt() * 19;
            
            myservo.write(Number);
            Serial.println(Number);

            // Add your code to parse the received line here....

            // Clear receive buffer so we're ready to receive the next line

            Data = "";
            Number = Number;
            delay(100);
            
        }
 }
}
