/*Peter Rhoades:
Folder TurnTable_Lights_Nrf24:
*/

#include  <SPI.h>
#include "RF24.h"
#include <Wire.h>
int data[4] = {0, 0, 0, 0}; //Only Use 0 & 1:
RF24 radio(7,8);               
const byte address[6] = "00051"; //Pipe Number same as nRF Sender:
// Phase1 Lights
  int enA = 9; //PWM to Lights 255:
  int in1 = 5;
  int in2 = 6;
// Phase2 Motor
 int enB = 3; //PWM to Motor 30 to 255
 int in1B = 4;
 int in2B = 2;

void setup()
{
   Serial.begin(115200);
   Serial.println("In Setup");
   radio.begin();
   radio.openReadingPipe(1,address);
   radio.startListening();
   Wire.begin();
   pinMode(enA, OUTPUT); //Set all Lights Pins to Outputs:
   pinMode(in1, OUTPUT);
   pinMode(in2, OUTPUT);
   pinMode(enB, OUTPUT); //Set all Motor Pins to Outputs:
   pinMode(in1B, OUTPUT);
   pinMode(in2B, OUTPUT);
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
  Serial.println("08-10-23 Baud Rate 9600 to 115200");
  Serial.println("10-10-23 TurnTable Control Added");
  Serial.println("12-11-23 if (data[0] == 14 now Lights on/off");
  Serial.println("Completed Setup");
  Serial.println("Code 081020231826\n\n\n");
 }

void loop()
{
  if ( radio.available() )
 {
 radio.read(data, sizeof(data));

if (data[0] == 14 && data[1] == 1) //Lights Data On:
  {
  Serial.print(data[0]);
  Serial.print("    ");
  Serial.print(data[1]);
  Serial.print("    ");
  Serial.print(data[1]);
  analogWrite(enA, 255); //Send PWM data[1] to Lights:
 digitalWrite(in1, HIGH);
 digitalWrite(in2, LOW);
  Serial.println(" Street lights On"); 
   }
   if (data[0] == 14 && data[1] == 0) //Lights Data Off: 
  {
   Serial.print(data[0]);
  Serial.print("    ");
  Serial.print(data[1]);
  Serial.print("    ");
  Serial.print(data[1]);
  analogWrite(enA, 0); //Send PWM data[1] to Lights:
 digitalWrite(in1, LOW);
 digitalWrite(in2, LOW);
  Serial.println(" Street lights Off");
  }
  if (data[0] == 17 && data[2] ==0) //Motor & PWM data[1] Direction PWM data[2] CCW:
 {
  Serial.print("CCW  ");
  Serial.print(data[0]);
  Serial.print("    ");
  Serial.print(data[1]);
  Serial.print("    ");
  Serial.println(data[2]);
  analogWrite(enB, data[1]); //Send Speed data[1] PWM to Motor:
 digitalWrite(in1B, HIGH);
 digitalWrite(in2B, LOW);
 }
if (data[0] == 17 && data[2] ==1) //Motor & PWM data[1] Direction PWM data[2] CW:
{
  Serial.print("CW ");
  Serial.print(data[0]);
  Serial.print("    ");
  Serial.print(data[1]);
  Serial.print("    ");
  Serial.println(data[2]);
  analogWrite(enB, data[1]); //Send Speed data[2] PWM to Motor:
 digitalWrite(in1B, LOW);
 digitalWrite(in2B, HIGH);
  } 
  if (data[0] == 18) //Motor Stop:
{
  Serial.print("Stop Button ");
  Serial.print(data[0]);
  Serial.print("    ");
  Serial.print(data[1]);
  Serial.print("    ");
  Serial.println(data[2]);
  analogWrite(enB, 0); //Send PWM to Motor:
 digitalWrite(in1B, HIGH);
 digitalWrite(in2B, HIGH);
  }
 }
}
