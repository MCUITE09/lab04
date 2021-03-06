#include "SevSeg.h"
SevSeg sevseg;
int Hour=0,Min=0,Step=1;
int Pin10,Pin11; 
void setup() {
  pinMode(A4,INPUT_PULLUP);
  pinMode(A5,INPUT_PULLUP);
  
  byte numDigits = 4;
  byte digitPins[] = {13,10,9,2};
  byte segmentPins[] = {12, 8, 4, 6, 7, 11, 3, 5};
  sevseg.begin(COMMON_CATHODE, numDigits, digitPins,segmentPins);

}

void loop() {
  Pin10= digitalRead(A4);
  Pin11= digitalRead(A5);
  sevseg.setNumber( Hour*100+Min, 4);
  if(Pin10==0)
    Min = Hour =0;
  if(Pin11==0)
    Step = -1;
   else Step =1;

   Min = Min + Step;
     if(Min == 60)
       { Min = 0;
         Hour = Hour+1;
       if(Hour == 24)
           Hour=0;
       }
       if(Min == -1)
        { Min=59;
          Hour = Hour-1;
          if(Hour == -1)
             Hour=23;
        }
      for(int i=0;i<30000;i++)
     {
      sevseg.refreshDisplay();
     } 
         
}
