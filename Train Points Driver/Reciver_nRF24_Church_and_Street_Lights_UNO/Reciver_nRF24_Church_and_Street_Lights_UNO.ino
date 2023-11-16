/*Peter Rhoades:
Friday 12/03/22:
Folder Church_and_Street_Lights_Railway:
Light and Church display using PWM®
03/09/21 Pin 6 added to Run Grave Yard Lights:
*/

#include  <SPI.h>
#include "RF24.h"
#include <Wire.h>
int data[4] = {0, 0, 0, 0}; //Only Use 0 & 1:
RF24 radio(7,8);               
const byte address[6] = "00051"; //Pipe Number same as nRF Sender:
int BLUE = 6;
int GREEN = 9;
int RED = 10;
int STREET = 5;



void setup()
{
   Serial.begin(115200);
   Serial.println("In Setup");
   radio.begin();
   radio.openReadingPipe(1,address);
   radio.startListening();
   Wire.begin();
pinMode(RED, OUTPUT);
pinMode(GREEN, OUTPUT);
pinMode(BLUE, OUTPUT);
pinMode(STREET, OUTPUT);
digitalWrite (RED, LOW); // choose a value between 1 and 255 to change the color.
digitalWrite (GREEN, LOW);
digitalWrite (BLUE, LOW);
 Serial.println("16-05-23 Baud Rate 9600 to 115200");
Serial.println("Completed Setup");
 Serial.println("1-04-23 Folder Reciver_Church_and_Street_Lights_nRF24.\n\n\n");
 
}

void loop()
{
  if ( radio.available() )
 {
 radio.read(data, sizeof(data));

if (data[0] == 14 && data[1] == 1) //Lights Data On:
  {
   analogWrite(STREET, 50);
   analogWrite (RED, 50); // choose a value between 1 and 255 to change the color.
analogWrite (GREEN, 0);
analogWrite (BLUE, 255);
   Serial.println("Street & Church lights On");
   }
   if (data[0] == 14 && data[1] == 0) //Lights Data Off:
  {
   digitalWrite(STREET, LOW);
   digitalWrite (RED, LOW); // choose a value between 1 and 255 to change the color.
   digitalWrite (GREEN, LOW);
   digitalWrite (BLUE, LOW);
   Serial.println("Street & Church lights Off");
  }
 }
}
