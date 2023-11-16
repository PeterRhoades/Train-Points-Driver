/*
Peter Rhoades©:
Reciver NRF24 With Nine Servo Mega®:
Folder Reciver_NRF24_With_Five_Servo:
Button_State_Reciver_NRF24_With_Nine_Servo_Mega:
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

  PWM Pins 3,5,6,9,10
*/


#include <VarSpeedServo.h> //Variable Speed Serco Driver:
 VarSpeedServo myservo1; 
  VarSpeedServo myservo2; 
  VarSpeedServo myservo3; 
 VarSpeedServo myservo4; 
VarSpeedServo myservo5; 
VarSpeedServo myservo6; 
VarSpeedServo myservo7;
VarSpeedServo myservo8;
VarSpeedServo myservo9;
VarSpeedServo myservo10;
VarSpeedServo myservo11;
  
#include  <SPI.h>
#include "RF24.h"
#include <Wire.h>
int data[4] = {0, 0, 0, 0}; //Only Use 0 & 1:
RF24 radio(22,24);               
const byte address[6] = "00051"; //Pipe Number same as nRF Sender:
int servoPin3 = 3; 
int servoPin4 = 4;
int servoPin5 = 5; //Servo Pins PWM:
int servoPin6 = 6;
int servoPin7 = 7;
int servoPin8 = 8;
int servoPin9 = 9;
int servoPin10 = 10;
int servoPin11 = 11;
int pos; //Servo Poss:

void setup()
{
  Serial.begin(115200);
  Serial.println("In Setup");
radio.begin();
 radio.openReadingPipe(1,address);
radio.startListening();
 Wire.begin();
// Servo Pins Attached:
myservo3.attach(servoPin3); //Button 3:
 myservo4.attach(servoPin4); //Button 4:
  myservo5.attach(servoPin5); //Button 5:
   myservo6.attach(servoPin6); //Button 6:
    myservo7.attach(servoPin7); //Button 7:
   myservo8.attach(servoPin8); //Used on Button_State_Reciver_NRF24_With_Two_Servo_NANO Point No8:
  myservo9.attach(servoPin9); //Button 1:
 myservo10.attach(servoPin10); //Button 2:
myservo11.attach(servoPin11); //Used on Button_State_Reciver_NRF24_With_Two_Servo_NANO Point No9:
//Servo Presets:
myservo9.write(118,15); delay(100); //Button 1:
 myservo10.write(95,15); delay(100); //Button 2:
  myservo3.write(60,15); delay(100); //Button 3:
   myservo4.write(105,15); delay(100); //Button 4:
   myservo5.write(70,15); delay(100); //Button 6:
  myservo6.write(90,15); delay(100); //Button 7:
 myservo7.write(102,15); delay(100); //Button 8:
nRF24(); 
 }
void nRF24()
{
Serial.println("nRF Tranciver"); 
Serial.println("1 = GRN  Black");   
Serial.println("2 = 3.3v Red");
Serial.println("3 = CE   Pin 7  Blue");
Serial.println("4 = CSN  Pin 8  Breen");
Serial.println("5 = SCK  Pin 13 Yellow");
Serial.println("6 = MOSI Pin 11 White");
Serial.println("7 = MISO Pin 12 Orange");
Serial.println(" _______________________");
Serial.println("| 1 | 2 |              |");
Serial.println("| 3 | 4 |              |");
Serial.println("| 5 | 6 |              |");
Serial.println("|_7_|___|______________|"); 
Serial.println("26-03-23 if (data[0] = 16 etc) Now used to reset points 1-7 Start possision."); 
Serial.println("(pos,?,true) Now Changed to (pos,?)");
Serial.println("File Name Reciver_NRF24_With_Nine_Servo_MEGA.");
Serial.println("16-05-23 Baud Rate 9600 to 115200");
Serial.println("13-11-23 16, 8, 9, Data feeds removed.");
Serial.println("Completed Setup");
Serial.println("Code 131120230906\n");
}
 
void loop()
{
if ( radio.available() )
{
radio.read(data, sizeof(data));
 
if (data[0] == 1 && data[1] == 0) 
{
pos = 74;
Serial.print(" Button=");
Serial.print(data[0]);
Serial.print("  ");
Serial.print(data[1]); 
Serial.print(" Received Point Open Servo 1 to ");
Serial.println(pos);
myservo9.write(pos,15);
}
if (data[0] == 1 && data[1] == 1) 
{
pos = 118;
Serial.print(" Button=");
Serial.print(data[0]);
Serial.print("  ");
Serial.print(data[1]); 
Serial.print(" Received Point Open Servo 1 to ");
Serial.println(pos);
myservo9.write(pos,15);
}
//--------------------------------------------------
if (data[0] == 2 && data[1] == 0) 
{
pos = 58;//66
Serial.print(" Button=");
Serial.print(data[0]);
Serial.print("  ");
Serial.print(data[1]); 
Serial.print(" Received Point Open Servo 2 to ");
Serial.println(pos);
myservo10.write(pos,15);
}
if (data[0] == 2 && data[1] == 1) 
{
pos = 95;//66
Serial.print(" Button=");
Serial.print(data[0]);
Serial.print("  ");
Serial.print(data[1]); 
Serial.print(" Received Point Open Servo 2 to ");
Serial.println(pos);
myservo10.write(pos,15);
//--------------------------------------------------
}
if (data[0] == 3 && data[1] == 0) //Servo One:
{
pos = 60;//66
Serial.print(" Button=");
Serial.print(data[0]);
Serial.print("  ");
Serial.print(data[1]); 
Serial.print(" Received Point Open Servo 3 to ");
Serial.println(pos);
myservo3.write(pos,15);
}
if (data[0] == 3 && data[1] == 1) 
{
pos = 99;//98
Serial.print(" Button=");
   Serial.print(data[0]);
   Serial.print("  ");
   Serial.print(data[1]); 
   Serial.print(" Received Point Closed Servo 3 to ");
   Serial.println(pos);
   myservo3.write(pos,15);
   //--------------------------------------------------
   }
   if (data[0] == 4 && data[1] == 0) //Servo Two:
  {
   pos = 70;
   Serial.print(" Button=");
   Serial.print(data[0]);
   Serial.print("  ");
   Serial.print(data[1]); 
   Serial.print(" Received Point Open Servo 4 to ");
   Serial.println(pos);
   myservo4.write(pos,15);
   }
   if (data[0] == 4 && data[1] == 1) 
  {
   pos = 105;
   Serial.print(" Button=");
   Serial.print(data[0]);
   Serial.print("  ");
   Serial.print(data[1]); 
   Serial.print(" Received Point Closed Servo 4 to ");
   Serial.println(pos);
   myservo4.write(pos,15);
   }
   //--------------------------------------------------
   if (data[0] == 5 && data[1] == 0) //Servo Three:
  {
   pos = 70;
   Serial.print(" Button=");
   Serial.print(data[0]);
   Serial.print("  ");
   Serial.print(data[1]); 
   Serial.print(" Received Point Open Servo 5 to ");
   Serial.println(pos);
   myservo5.write(pos,15);
   }
   if (data[0] == 5 && data[1] == 1) 
  {
   pos = 106;
   Serial.print(" Button=");
   Serial.print(data[0]);
   Serial.print("  ");
   Serial.print(data[1]); 
   Serial.print(" Received Point Closed Servo 5 to ");
   Serial.println(pos);
   myservo5.write(pos,15);
  }
   //--------------------------------------------------
   if (data[0] == 6 && data[1] == 0) //Servo Four:
  {
   pos = 54;
   Serial.print(" Button=");
   Serial.print(data[0]);
   Serial.print("  ");
   Serial.print(data[1]); 
   Serial.print(" Received Point Open Servo 6 to ");
   Serial.println(pos);
   myservo6.write(pos,15);
   }
   if (data[0] == 6 && data[1] == 1) 
  {
   pos = 92;
   Serial.print(" Button=");
   Serial.print(data[0]);
   Serial.print("  ");
   Serial.print(data[1]); 
   Serial.print(" Received Point Closed Servo 6 to ");
   Serial.println(pos);
   myservo6.write(pos,15);
  }
   //--------------------------------------------------
    if (data[0] == 7 && data[1] == 0) //Servo Five:
  {
   pos = 62;
   Serial.print(" Button=");
   Serial.print(data[0]);
   Serial.print("  ");
   Serial.print(data[1]); 
   Serial.print(" Received Point Open Servo 7 to ");
   Serial.println(pos);
   myservo7.write(pos,15);
   }
   if (data[0] == 7 && data[1] == 1) 
  {
   pos = 102;
   Serial.print(" Button=");
   Serial.print(data[0]);
   Serial.print("  ");
   Serial.print(data[1]); 
   Serial.print(" Received Point Closed Servo 7 to ");
   Serial.println(pos);
   myservo7.write(pos,15);
  }
   /*//Not Used--------Not Used-----------Not Used------------Not Used---
   if (data[0] == 8 && data[1] == 0) 
  {
   pos = 72;
   Serial.print(" Button=");
   Serial.print(data[0]);
   Serial.print("  ");
   Serial.print(data[1]); 
   Serial.print(" Received Point Open Servo 8 to ");
   Serial.println(pos);
   myservo8.write(pos,15,true);
   }
   if (data[0] == 8 && data[1] == 1) 
  {
   pos = 96;
   Serial.print(" Button=");
   Serial.print(data[0]);
   Serial.print("  ");
   Serial.print(data[1]); 
   Serial.print(" Received Point Open Servo 8 to ");
   Serial.println(pos);
   myservo8.write(pos,15,true);
  }
 //Not Used--------Not Used-----------Not Used------------Not Used---
    if (data[0] == 9 && data[1] == 0) 
  {
    pos = 50;//66
   Serial.print(" Button=");
   Serial.print(data[0]);
   Serial.print("  ");
   Serial.print(data[1]); 
   Serial.print(" Received Point Open Servo 9 to ");
   Serial.println(pos);
   myservo11.write(pos,15,true);
   }
   if (data[0] == 9 && data[1] == 1) 
   {
   pos = 89;//98
   Serial.print(" Button=");
   Serial.print(data[0]);
   Serial.print("  ");
   Serial.print(data[1]); 
   Serial.print(" Received Point Closed Servo 9 to ");
   Serial.println(pos);
   myservo11.write(pos,15,true);*/
  }
  }

