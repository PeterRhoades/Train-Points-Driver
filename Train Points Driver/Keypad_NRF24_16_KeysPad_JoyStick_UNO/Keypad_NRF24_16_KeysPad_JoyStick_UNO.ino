#include <Wire.h>
#include  <SPI.h>
#include "RF24.h"
const byte address[6] = "00051";
int data[4] = {0, 0, 0, 0}; //Data Array to be Sent:
RF24 radio(7,8);
#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'} //Keys (Number) Action:
                    //Button 0 (10) Point Reset:
                    //Button 1 to 9 Point Open-Close:
                    //Button A (11) Signal Tunnel:
                    //Button B (13) Signal Goods Yard:
                    //Button D (12) Street Lights on-off:
                    //Button C (14) Not Used:
                    //Button * (15) Not Used:
                    //Button # (16)  Not Used:
                    //JoyStick (17) Joystick Left/Right Turn Table:
                    //JoyStick (18) Button Stop Turn Table Stop: 
};
byte rowPins[ROWS] = {A0, A1, A2, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 9}; //connect to the column pinouts of the keypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 
int buttonstate1 = 1, buttonstate2 = 1, buttonstate3 = 0, buttonstate4 = 1, buttonstate5 = 0, buttonstate6 = 1;
int buttonstate7 = 1, buttonstate8 = 0, buttonstate9 = 0, buttonstate10 = 0, buttonstateA = 1, buttonstateB = 0;
int buttonstateC = 0, buttonstateD = 0, buttonstateE = 0, buttonstateF = 0;
int SWL = 2;
int DL = 50; //Delay:

void setup(){
  Serial.begin(115200);
  delay(100);
  Serial.println("In Setup");
  Wire.begin();
  radio.begin();
  radio.openWritingPipe(address);
  pinMode(SWL, INPUT_PULLUP);
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
  Serial.println("11-04-23 Button B Now '13' Button C Now '12'.");
  Serial.println("15-05-23 JoyStick & SWL Added");
  Serial.println("16-05-23 Baud Rate 9600 to 115200");
  Serial.println("23-05-23 JoyStick (A3) data[2] Added to Print Out");
  Serial.println("27-09-23 Pin2 and Pin9 Swapped");
  Serial.println("04-10-23 data[1] = map(*** 70, 255 to (data[1] = map(*** 30, 255");
  Serial.println("04-10-23 Button # (16) now Button 0 (16) Point Reset");
  Serial.println("12-11-23 Point Reset (16) Removed, Sketch tidied Up. Button 0 = 10");
  Serial.println("13-11-23 int joystick removed not required.");
  Serial.println("Completed Setup\n");
  Serial.println("Code 131120231700");
 }
 
void loop(){
  char customKey = customKeypad.getKey();
  
  if (customKey =='1')
  {
    buttonstate1 = !buttonstate1;
    data[0] = 1; 
    data[1] = buttonstate1;
   radio.write( data, sizeof(data) );
   Serial.print("Button 1 ");  
   Serial.print("  Data [0]= "); 
   Serial.print(data[0]);
   Serial.print("  Data [1]= "); 
   Serial.print(data[1]); 
   Serial.println(" Sent ");
  delay(DL);
    
  }
  if (customKey =='2')
  {
    buttonstate2 = !buttonstate2;
    data[0] = 2; 
    data[1] = buttonstate2;
   radio.write( data, sizeof(data) );
   Serial.print("Button 2 ");  
   Serial.print("  Data [0]= "); 
   Serial.print(data[0]);
   Serial.print("  Data [1]= "); 
   Serial.print(data[1]); 
   Serial.println(" Sent ");
  delay(DL);
  } 
    if (customKey =='3')
  {
    buttonstate3 = !buttonstate3;
    data[0] = 3; 
    data[1] = buttonstate3;
   radio.write( data, sizeof(data) );
   Serial.print("Button 3 ");  
   Serial.print("  Data [0]= "); 
   Serial.print(data[0]);
   Serial.print("  Data [1]= "); 
   Serial.print(data[1]); 
   Serial.println(" Sent ");
   delay(DL);
  }
  if (customKey =='4')
  {
   buttonstate4 = !buttonstate4;
    data[0] = 4; 
    data[1] = buttonstate4;
   radio.write( data, sizeof(data) );
   Serial.print("Button 4 ");  
   Serial.print("  Data [0]= "); 
   Serial.print(data[0]);
   Serial.print("  Data [1]= "); 
   Serial.print(data[1]); 
   Serial.println(" Sent ");
  delay(DL);
  }
  if (customKey =='5')
  {
     buttonstate5 = !buttonstate5;
    data[0] = 5; 
    data[1] = buttonstate5;
   radio.write( data, sizeof(data) );
   Serial.print("Button 5 ");  
   Serial.print("  Data [0]= "); 
   Serial.print(data[0]);
   Serial.print("  Data [1]= "); 
   Serial.print(data[1]); 
   Serial.println(" Sent ");
  delay(DL);
  }
  if (customKey =='6')
  {
    buttonstate6 = !buttonstate6;
    data[0] = 6; 
    data[1] = buttonstate6;
   radio.write( data, sizeof(data) );
   Serial.print("Button 6 ");  
   Serial.print("  Data [0]= "); 
   Serial.print(data[0]);
   Serial.print("  Data [1]= "); 
   Serial.print(data[1]); 
   Serial.println(" Sent ");
  delay(DL);
  }
  if (customKey =='7')
  {
    buttonstate7 = !buttonstate7;
    data[0] = 7; 
    data[1] = buttonstate7;
   radio.write( data, sizeof(data) );
   Serial.print("Button 7 ");  
   Serial.print("  Data [0]= "); 
   Serial.print(data[0]);
   Serial.print("  Data [1]= "); 
   Serial.print(data[1]); 
   Serial.println(" Sent ");
  delay(DL);
  }
  if (customKey =='8')
  {
    buttonstate8 = !buttonstate8;
    data[0] = 8; 
    data[1] = buttonstate8;
   radio.write( data, sizeof(data) );
   Serial.print("Button 8 ");  
   Serial.print("  Data [0]= "); 
   Serial.print(data[0]);
   Serial.print("  Data [1]= "); 
   Serial.print(data[1]); 
   Serial.println(" Sent ");
  delay(DL);
  }
  if (customKey =='9')
  {
     buttonstate9 = !buttonstate9;
    data[0] = 9; 
    data[1] = buttonstate9;
   radio.write( data, sizeof(data) );
   Serial.print("Button 9 ");  
   Serial.print("  Data [0]= "); 
   Serial.print(data[0]);
   Serial.print("  Data [1]= "); 
   Serial.print(data[1]); 
   Serial.println(" Sent ");
  delay(DL);
  }
  if (customKey =='0')
  {
     buttonstate10 = !buttonstate10;
    data[0] = 10; 
    data[1] = buttonstate10;
   radio.write( data, sizeof(data) ); //Point Reset (16) Removed
   Serial.print("Button 0 ");  
   Serial.print("  Data [0]= "); 
   Serial.print(data[0]);
   Serial.print("  Data [1]= "); 
   Serial.print(data[1]); 
   Serial.println(" Sent ");
  delay(DL);
  }
  if (customKey =='A')
  {
    buttonstateA = !buttonstateA;
    data[0] = 11; 
    data[1] = buttonstateA;
   radio.write( data, sizeof(data) );
   Serial.print("Button A ");  
   Serial.print("  Data [0]= "); 
   Serial.print(data[0]);
   Serial.print("  Data [1]= "); 
   Serial.print(data[1]); 
   Serial.println(" Sent ");
  delay(DL);
  }
  if (customKey =='B')
  {
    buttonstateB = !buttonstateB;
    data[0] = 13; //Button B Now '13' Not '12'
    data[1] = buttonstateB;
   radio.write( data, sizeof(data) );
   Serial.print("Button B ");  
   Serial.print("  Data [0]= "); 
   Serial.print(data[0]);
   Serial.print("  Data [1]= "); 
   Serial.print(data[1]); 
   Serial.println(" Sent ");
  delay(DL);
  }
  if (customKey =='C')
  {
    buttonstateC = !buttonstateC;
    data[0] = 12; //Button C Now '12' Not '13'
    data[1] = buttonstateC;
   radio.write( data, sizeof(data) );
   Serial.print("Button C "); 
   Serial.print("  Data [0]= "); 
   Serial.print(data[0]);
   Serial.print("  Data [1]= "); 
   Serial.print(data[1]); 
   Serial.println(" Sent ");
  delay(DL);
  }
  if (customKey =='D')
  {
    buttonstateD = !buttonstateD;
    data[0] = 14; 
    data[1] = buttonstateD;
   radio.write( data, sizeof(data) );
   Serial.print("Button D "); 
   Serial.print("  Data [0]= "); 
   Serial.print(data[0]);
   Serial.print("  Data [1]= "); 
   Serial.print(data[1]); 
   Serial.println(" Sent ");
  delay(DL);
  }
  if (customKey =='*')
  {
    buttonstateE = !buttonstateE;
    data[0] = 15; 
    data[1] = buttonstateE;
   radio.write( data, sizeof(data) );
   Serial.print("Button * "); 
    Serial.print("  Data [0]= "); 
   Serial.print(data[0]);
   Serial.print("  Data [1]= "); 
   Serial.print(data[1]); 
   Serial.println(" Sent ");
  delay(DL);
  }
  if (customKey =='#')
  {
     buttonstateF = !buttonstateF;
    data[0] = 16; 
    data[1] = buttonstateF;
   //radio.write( data, sizeof(data) );
   Serial.print("Button # ");  
   Serial.print("  Data [0]= "); 
   Serial.print(data[0]);
   Serial.print("  Data [1]= "); 
   Serial.print(data[1]); 
   Serial.println(" Sent ");
  delay(DL);
  }
  if (analogRead(A3) > 550) //Joystick CW:
 {
int CW = (analogRead(A3));
 data[0] = 17;
 data[1] = map(CW, 550, 1023, 30, 255); 
 data[2] = 0;
   radio.write( data, sizeof(data) );
   Serial.print("  Data [0]= "); 
   Serial.print(data[0]);
   Serial.print("  Data [1]= "); 
   Serial.print(data[1]); 
   Serial.print(" data[2] ");
   Serial.print(data[2]);
   Serial.println(" Sent ");
  delay(DL);
 }
 if (analogRead(A3) < 450) //Joystick CCW: 
 {
int CCW = (analogRead(A3));
 data[0] = 17; 
 data[1] = map(CCW, 450, 0, 30, 255);
 data[2] = 1;
   radio.write( data, sizeof(data) );
   Serial.print("  Data [0]= "); 
   Serial.print(data[0]);
   Serial.print("  Data [1]= "); 
   Serial.print(data[1]); 
   Serial.print(" data[2] ");
   Serial.print(data[2]);
   Serial.println(" Sent ");
  delay(DL);
 }
 if (digitalRead(SWL) == LOW) //Top Button Clossed Serial.print(digitalRead(SW_pin))
 {
 data[0] = 18;
 data[1] = 0;
 data[2] = data[2]; 
 radio.write( data, sizeof(data) );
   Serial.print("  Data [0]= "); 
   Serial.print(data[0]);
   Serial.print("  Data [1]= "); 
   Serial.print(data[1]); 
   Serial.println(" Sent ");
  delay(DL);
 }
}
