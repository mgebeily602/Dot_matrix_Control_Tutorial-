/*
  Controling Led matrix with two 74HC595 Shift Registers
  This code displays a static letter "C"
  by: Mohamed Elguebeily
 */
//Pin connected to ST_CP of 74HC595
int latchPin = 8;
//Pin connected to SH_CP of 74HC595
int clockPin = 12;
//Pin connected to DS of 74HC595
int dataPin = 11;

// C register; cascaded; column patterns for the letter C
byte Cols[]={0xE7, 0xDB,0xBF,0xBF,0xBF,0xBF,0xDB,0xE7}; 



void setup() {
  //define pins as output
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

void loop() 
  {
        for(int i=0;i<=7;i++){
          shiftOut(dataPin,clockPin,MSBFIRST,Cols[i]); // pattern for row i
          shiftOut(dataPin,clockPin,LSBFIRST,1<<i);  // row i
          digitalWrite(latchPin,HIGH); 
          digitalWrite(latchPin, LOW);
        }
  }
