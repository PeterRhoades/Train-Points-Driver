
#include <VarSpeedServo.h> 
VarSpeedServo myservoA;
VarSpeedServo myservoB;
#include  <SPI.h>
#include "RF24.h"
#include <Wire.h>
int data[4] = {0, 0, 0, 0}; //Only Use 0 & 1:
RF24 radio(A0,A1);               
const byte address[6] = "00051"; //Pipe Number same as nRF Sender:
int lightON = 0; //Light status:
int pos;//Servo Poss:
int signalLights = 6; //Signal Pin:
int stationLights = 5; //Lights Pin:
//int sigNal = 60; //PWM to Signal:
//int staTion = 4; //PWM to Lights:
int reD = 4; //RGB Red Pin:
int greeN = 7; //RGB Green Pin:


void setup() {
  Serial.begin(115200);
  Serial.println("Setup_Begin");
 radio.begin();
 radio.openReadingPipe(1,address);
 radio.startListening();
 Wire.begin();
    myservoA.attach(9); //Servo1
    myservoB.attach(3); //Servo2
    myservoA.write(0);
    myservoB.write(0);
  pinMode (signalLights, OUTPUT);
  pinMode (stationLights, OUTPUT);
  pinMode (reD, OUTPUT);
  pinMode (greeN, OUTPUT);
  analogWrite(signalLights, 1); //Signal Lights:
Serial.println("File Name Slow_Servo_Two_Signal_Nrf24_One_RBG.");
Serial.println("10-04-23 Servo2 Data[1] Value Swapped");
Serial.println("16-05-23 Baud Rate 9600 to 115200");
Serial.println("30-10-23 Station Lights Addes and linked to Street Lights.");
Serial.println("12-11-23 60% re-coded full points reset removed 14 control station lights.");
Serial.println("Signal A now using PWM from Pin 6");
Serial.println("Completed Setup");
Serial.println("Code 0811131836\n\n\n");
}

void loop() 
 {
if ( radio.available() )
 {
 radio.read(data, sizeof(data));
 
if (data[0] == 11 && data[1] == 0) //Servo One:
 {
  pos = 0; //Signal Red Stop:
  Serial.print("Signal A RED STOP Servo Pos ");
  myservoA.write(pos,5);
  digitalWrite(greeN, HIGH); //Green on Red Off:
  digitalWrite(reD, LOW);
  analogWrite(signalLights, 2); 
  Serial.println(pos);
 }
if (data[0] == 11 && data[1] == 1) //Servo One:
{
  pos = 10; //Signal Green Go:
  Serial.print("Signal A GREEN GO Servo Pos ");
  myservoA.write(pos,5);
  digitalWrite(greeN, LOW); //Green on Red Off:
  digitalWrite(reD, HIGH);
  analogWrite(signalLights, 2); 
  Serial.println(pos);
  } 
if (data[0] == 13 && data[1] == 1) //Servo One:
 {
  pos = 0; //Signal Red Stop:
  Serial.print("Signal B GREEN GO Servo Pos ");
  myservoB.write(pos,5);
  Serial.println(pos);
 }
if (data[0] == 13 && data[1] == 0) //Servo One:
{
  pos = 10; //Signal Green Go:
  Serial.print("Signal B RED STOP Servo Pos ");
  myservoB.write(pos,5);
  Serial.println(pos);
  } 
  if (data[0] == 14 && data[1] == 1) //Lights Data On:
  {
  analogWrite(stationLights, 4); //Send PWM data[1] to Lights:
  Serial.println("Station lights ON"); 
  }
  if (data[0] == 14 && data[1] == 0) //Lights Data Off: 
  {
  analogWrite(stationLights, 0); //Send PWM data[1] to Lights:
  Serial.println("Station lights OFF");        
 }
}
 }
