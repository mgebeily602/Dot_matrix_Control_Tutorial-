/*
  Animated letter C
 Displays a letter C which shifts from right to left

 */
//Pin connected to ST_CP of 74HC595
int latchPin = 8;
//Pin connected to SH_CP of 74HC595
int clockPin = 12;
//Pin connected to DS of 74HC595
int dataPin = 11; 
//Column pattern of letter C:
byte Cols[]={0x66, 0xA5,0xC3,0x18,0x18,0xC3,0xA5,0x66};

void setup() {
  //set pins to output
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

void loop() 
  {
    int sh_col;
    for (int j=0;j<=16;j++){
      //time cycle to allow enough time for the allusion of a printed pattern
      for (int t=0;t<200;t++){ 
        for(int i=0;i<=7;i++){
          if (j<=8){
            sh_col=Cols[i]>>(8-j)|0xFF<<j; //disable columns to the left of the shifted column pattern
          }
          else{
            sh_col=Cols[i]<<(j-8)|(1<<j-8)-1; //disable columns to the right of the shifted column pattern
          } 
          shiftOut(dataPin,clockPin,MSBFIRST,sh_col); // column pattern for row number i
          shiftOut(dataPin,clockPin,LSBFIRST,1<<i); //row number i
          digitalWrite(latchPin,HIGH); 
          digitalWrite(latchPin, LOW);
        }
      }
    }
  }
