/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/
#include <Wire.h>
#include <UnoWiFiDevEd.h>
#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
   pinMode(13,OUTPUT);
    Wifi.begin();
    Wifi.println("Web Server is up");
    
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

  while(Wifi.available()){
      process(Wifi);
    }
  delay(50);
}


void process(WifiData client) {
  // read the command
  String command = client.readStringUntil('/');

  // is "digital" command?
  if (command == "webserver") {
    WebServer(client);
  }

  if (command == "digital") {
    digitalCommand(client);
  }
}

void WebServer(WifiData client) {

  client.println("HTTP/1.1 200 OK");
//  client.println("<meta http-equiv=\"refresh\" content=\"5\">");

  client.println("Content-Type: text/html");
  client.println();
  client.println("<html>");

  client.println("<head> </head>");
  client.print("<body>");

  client.print("Click<input type=button onClick=\"var w=window.open('/arduino/digital/9/1','_parent');w.close();\"value='ON'>pin13 ON<br>");
  client.print("Click<input type=button onClick=\"var w=window.open('/arduino/digital/9/0','_parent');w.close();\"value='OFF'>pin13 OFF<br>");

  client.print("</body>");
  client.println("</html>");
  client.print(DELIMITER); // very important to end the communication !!!

}

void digitalCommand(WifiData client) {

  int pin, value = 0;
  myservo.write(0);

  // Read pin number
  pin = client.parseInt();

  // If the next character is a '/' it means we have an URL
  // with a value like: "/digital/13/1"
  if (client.read() == '/') {
    value = client.parseInt();
    //digitalWrite(pin, value);
     //myservo.write(value);
     if (value == 1)
     {
       for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(0 );                       // waits 15ms for the servo to reach the position
      }
      
   } else {
      myservo.write(0); 
   }
  }

  // Send feedback to client
  
  client.println("Status: 200 OK\n");
  client.print(F("Pin D"));
  client.print(pin);
  client.print(F(" set to "));
  client.print(value);
  client.print(EOL);    //char terminator
  

}


