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
String Data = "";
int Number;
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
 
}


// Function to pass BlueTooth output through to serial port output
void waitForResponse() {

}





void loop() {
  

  /*value = SerialBT.read() ;
  delay(100);
  Serial.write(value);
  //Serial.println((value*18));
      
      //myservo.write((value*18));

      while (SerialBT.available()) {
      Serial.write(SerialBT.read());  //juiste waarden!!!!!!
      value = (SerialBT.read() * 4);
      //myservo.write(SerialBT.read());
       myservo.write(value);
       
      }*/
 Serial.println(Number);

 while (SerialBT.available()) {

  char character = SerialBT.read(); // Receive a single character from the software serial port
        Data.concat(character); // Add the received character to the receive buffer
        if (character == '\n')
        {
            //Serial.print("Received: ");
            
            
            //Serial.println(Data);
            Number = Data.toInt() * 10;
            myservo.write(Number);
            Serial.println(Number);

            // Add your code to parse the received line here....

            // Clear receive buffer so we're ready to receive the next line

            Data = "";
            Number = Number;
            delay(200);
            
        }
   

//Serial.write(SerialBT.read());


//value = (Serial.write(SerialBT.read()));















//value = ( value * 9);
//myservo.write(SerialBT.read() * 9);
 }
 
//value = 0;



      

     

   
  
}
