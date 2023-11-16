/*
Peter Rhoades©:
Button State Reciver NRF24 With Two Servo NANO®:
Folder Button_State_Reciver_NRF24_With_Two_Servo_NANO:
Thanks https://github.com/netlabtoolkit/VarSpeedServo & https://github.com/nRF24/RF24:

  nRF Tranciver 
  1 = GRN  Black   
  2 = 3.3v Red
  3 = CE   Pin D7  Blue
  4 = CSN  Pin D8  Breen
  5 = SCK  Pin D13 Yellow
  6 = MOSI Pin D11 White
  7 = MISO Pin D12 Orange
   _______________________
  | 1 | 2 |              |
  | 3 | 4 |              | 
  | 5 | 6 |              |
  |_7_|___|______________|

  Pins used 3, 4, 6, 7, 8, 9, 11, 12, 13
*/
#include <VarSpeedServo.h> //Variable Speed Serco Driver:
VarSpeedServo myservo8;  //Variable Speed Serco Number:
VarSpeedServo myservo9;  //Variable Speed Serco Number:
VarSpeedServo myservo10; //Variable Speed Serco Number:
   
  
#include  <SPI.h>
#include "RF24.h"
#include <Wire.h>
int data[4] = {0, 0, 0, 0}; //Only Use 0 & 1:
RF24 radio(7,8);               
const byte address[6] = "00051"; //Pipe Number same as nRF Sender:
int servoPin8 = 3; 
int servoPin9 = 6; //Servo Pin Numbers:
int servoPin10 = 9;
int lighT = 5;
int pos; //Servo Poss Variable:


void setup()
{
Serial.begin(115200);
Serial.println("In Setup");
radio.begin();
radio.openReadingPipe(1,address);
radio.startListening();
Wire.begin();
myservo8.attach(servoPin8);
myservo9.attach(servoPin9);
myservo10.attach(servoPin10);
myservo8.write(82,15);
myservo9.write(98,15);
myservo10.write(98,15);
analogWrite (lighT, 155);
Serial.println("Completed Setup");
Serial.println("26-03-23 if (data[0]=16) Now used to reset points 8&9 to Start possision."); 
Serial.println("(pos,5,true) Now Changed to (pos,5). Servo 8&9 Start possision changed.");
Serial.println("Folder Button_State_Reciver_NRF24_With_Two_Servo_NANO.\n");
Serial.println("16-05-23 Baud Rate 9600 to 115200");
Serial.println("Completed Setup");
Serial.println("Code 080520231742\n\n\n");
}
 
void loop()
{
if ( radio.available() )
{
radio.read(data, sizeof(data));
 
if (data[0] == 8 && data[1] == 0) //Servo One:
{
pos = 82;
Serial.print("Point Open Go Servo Pos ");
Serial.println(pos);
myservo8.write(pos,15);
}
if (data[0] == 8 && data[1] == 1) 
{
pos = 125;
Serial.print("Point Closed STOP Servo Pos ");
Serial.println(pos);
myservo8.write(pos,15);
}
if (data[0] == 9 && data[1] == 0) //Servo One:
{
pos = 94;
Serial.print("Point Open Go Servo Pos ");
Serial.println(pos);
myservo9.write(pos,15);
}
if (data[0] == 9 && data[1] == 1) 
{
pos = 130;
Serial.print("Point Closed STOP Servo Pos ");
Serial.println(pos);
myservo9.write(pos,15);
}
if (data[0] == 12 && data[1] == 1) //Servo Ten:
{
pos = 82; //Signal Red Stop:
Serial.print("Signal C Distance Yellow SLOW Servo Pos ");
Serial.println(pos);
myservo10.write(pos,15);
}
if (data[0] == 12 && data[1] == 0) //Servo Ten:
{
pos = 125; //Signal Green Go:
Serial.print("Signal C Distance Green GO Servo Pos ");
Serial.println(pos);
myservo10.write(pos,15);
} 
}
}
  
