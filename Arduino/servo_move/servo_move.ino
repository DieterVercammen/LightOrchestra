
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
boolean asynchA = false;
boolean chordDown = false;
boolean strummingBool = false;

int strumstate = LOW; 
long LeftTime = 450;           
long RightTime = 450;



Servo myservo;  
Servo myservoC;
Servo myservoF;
Servo myservoG;
Servo myservoD;
Servo myservoA;


unsigned long previousMillis = 0;        
const long interval = 500; 

void setup() {
    Serial.begin(9600);
    SerialBT.begin(9600);

    SerialBT.print("AT");
    waitForResponse();

    
SerialBT.print("AT+VERSION");
waitForResponse();


SerialBT.print("AT+PIN1234");
waitForResponse();


SerialBT.print("AT+NAMEBLU");
waitForResponse();

SerialBT.print("AT+BAUD9");
waitForResponse();

Serial.println("Finished!");

   pinMode(13,OUTPUT);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  myservoC.attach(6); // straight up = 110 --> pressing = 20
  myservoF.attach(5); // straight up = 20 --> pressing = 11
  myservoG.attach(10); // straight up = 50 --> pressing = 180
  myservoD.attach(11); // straight up = 180 --> pressing = 50
  myservoA.attach(7); // straight up = 70 --> pressing = 180
  myservoC.write(110);
  myservoF.write(20);
  myservoG.write(50);
  myservoD.write(190);
  myservoA.write(70);
  
  
}

void waitForResponse() {

}

void CChord() {

  if (asynchC && !chordDown){
     
     myservoC.write(20);
     
  }
   if(!asynchC){
    
     myservoC.write(110);
         
   }

}
void FChord() {

  if (asynchF && !chordDown){
     
     myservoF.write(110);
     
  }
   if(!asynchF){
        
     myservoF.write(20);
         
   }
}
void AChord() {

  if (asynchA && !chordDown){
     
     myservoA.write(180);
     
  }
   if(!asynchA){
         
     myservoA.write(70);
     
   }
}
void GChord() {

  if (asynchG && !chordDown){
     
     myservoG.write(190);
    
  }
   if(!asynchG){
        
     myservoG.write(50);

   }
}
void DChord() {

  if (asynchD && !chordDown){
     
     myservoD.write(50);
     
  }
   if(!asynchD){
        
     myservoD.write(180);

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
}




void loop() {
  
 Serial.println(Number);

 while (SerialBT.available()) {

  char character = SerialBT.read(); 
        Data.concat(character); 
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
              case 6000:
                asynchA = true;
                asynchF = true;
                
                break;
              case 6001:
               asynchA = false;
               asynchF = false;
               
                break;
              case 9000:
               strummingBool = true;
               
                break;
              case 9001:
               strummingBool = false;
               
                break;
              default:
                break;
            }
           
              CChord();
              FChord();
              GChord();
              DChord();
              AChord();
              if (strummingBool) {
                strumming();
              } else {
                 myservo.write(Number);
              }
              if (asynchC || asynchD || asynchF || asynchG || asynchA) {
                chordDown = true;
              } else {
                chordDown = false;
              }
              
            Data = "";
            Number = Number;
            NumberC = NumberC;
            Serial.println(NumberC);
            delay(0);
            
        }
 }
}
