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
int NumberC;
boolean asynchC = false;
boolean asynchF = false;
boolean asynchG = false;
boolean asynchD = false;
boolean chordDown = false;
boolean strummingBool = false;

int strumstate = LOW; 
long LeftTime = 300;           
long RightTime = 300;


//Servo myservoF;
Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards
Servo myservoC;
Servo myservoF;
Servo myservoG;
Servo myservoD;
//unsigned long previousMillis = 0;        // will store last time LED was updated
//const long chordsInterval = 2000;           // interval at which to blink (milliseconds)

unsigned long previousMillis = 0;        
const long interval = 1000; 

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
SerialBT.print("AT+BAUD9");
waitForResponse();

Serial.println("Finished!");

   pinMode(13,OUTPUT);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  myservoC.attach(6); // straight up = 110 --> pressing = 20
  myservoF.attach(5); // straight up = 20 --> pressing = 11
  myservoG.attach(10); // straight up = 50 --> pressing = 180
  myservoD.attach(11); // straight up = 180 --> pressing 90
  myservoC.write(110);
  myservoF.write(20);
  myservoG.write(50);
  myservoD.write(190);
  
  
}


// Function to pass BlueTooth output through to serial port output
void waitForResponse() {

}

void CChord() {

  if (asynchC && !chordDown){
     
     myservoC.write(20);
     //chordDown = true;
     
     
    
  }
   if(!asynchC){
         myservoC.write(110);
         //chordDown = false;
        
         
         
   }


}
void FChord() {

  if (asynchF && !chordDown){
     
     myservoF.write(110);
     //chordDown = true;
     
     
  }
   if(!asynchF){
        
         myservoF.write(20);
         //chordDown = false;
         

   }
}
void GChord() {

  if (asynchG && !chordDown){
     
     myservoG.write(180);
     //chordDown = true;
    
  }
   if(!asynchG){
        
         myservoG.write(50);
         //chordDown = false;
         

   }
}
void DChord() {

  if (asynchD && !chordDown){
     
     myservoD.write(90);
     //chordDown = true;
     
  }
   if(!asynchD){
        
         myservoD.write(180);
         //chordDown = false;
         

   }
}
void strumming() {

  
  unsigned long currentMillis = millis();

if((strumstate == HIGH) && (currentMillis - previousMillis >= LeftTime))
  {
    strumstate = LOW;  
    previousMillis = currentMillis;  
    myservo.write(50);     
  }
  else if ((strumstate == LOW) && (currentMillis - previousMillis >= RightTime))
  {
    strumstate = HIGH; 
    previousMillis = currentMillis;  
    myservo.write(150);       
  }


  
  /*if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis; 
      
  } 
  if (currentMillis2 - previousMillis >= interval) {
      previousMillis = currentMillis2;
      //myservo.write(180);
  }*/
}




void loop() {
  


 Serial.println(Number);

 while (SerialBT.available()) {

  char character = SerialBT.read(); // Receive a single character from the software serial port
        Data.concat(character); // Add the received character to the receive buffer
        if (character == '\n')
        {
          
            switch (Data.toInt()) {
            
              case -10:
                //Number = 0;
                Number = 54;
                break;
              case -9:
                //Number = 9;
                Number = 54;
                break;
              case -8:
                //Number = 18;
                Number = 54;
                break;
              case -7:
                //Number = 27;
                Number = 54;
                break;
              case -6:
                //Number = 36;
                Number = 54;
                break;
              case -5:
                //Number = 45;
                Number = 54;
                break;
              case -4:
                //Number = 54;
                Number = 54;
                break;
              case -3:
                //Number = 63;
                Number = 54;
                break;
              case -2:
                //Number = 72;
                Number = 54;
                break;
              case -1:
                //Number = 81;
                Number = 54;
                break;
              case 0:
                //Number = 90;
                Number = 150;
                break;
              case 1:
                //Number = 99;
                Number = 150;
                break;
              case 2:
                //Number = 108;
                Number = 150;
                break;
              case 3:
                //Number = 117;
                Number = 150;
                break;
              case 4:
                Number = 150;
                break;
              case 5:
                //Number = 135;
                 Number = 150;
                break;
              case 6:
                //Number = 144;
                 Number = 150;
                break;
              case 7:
                //Number = 153;
                 Number = 150;
                break;
              case 8:
                //Number = 162;
                 Number = 150;
                break;
              case 9:
               // Number = 171;
                Number = 150;
                break;
              case 10:
               Number = 150;
                //Number = 180;
                break;
              case 2000:
                asynchC = true;
                
                break;
              case 2001:
               asynchC = false;
               
                break;
              case 3000:
                asynchF = true;
                
                break;
              case 3001:
               asynchF = false;
              
                break;
              case 4000:
                asynchG = true;
                
                break;
              case 4001:
               asynchG = false;
              
                break;
              case 5000:
                asynchD = true;
                
                break;
              case 5001:
               asynchD = false;
               
                break;
              case 9000:
               strummingBool = true;
               
                break;
              case 9001:
               strummingBool = false;
               
                break;
              default:
                break;
                //NumberC = 100;
            }
           
            
             
            
              CChord();
              FChord();
              GChord();
              DChord();
              if (strummingBool) {
                strumming();
              } else {
                 myservo.write(Number);
              }
              if (asynchC || asynchD || asynchF || asynchG)
              {
                chordDown = true;
              } else {
                chordDown = false;
              }
              
            
            Serial.println(Number);

            // Add your code to parse the received line here....

            // Clear receive buffer so we're ready to receive the next line

            Data = "";
            Number = Number;
            NumberC = NumberC;
             Serial.println(NumberC);
            delay(0);
            
        }
 }
}
