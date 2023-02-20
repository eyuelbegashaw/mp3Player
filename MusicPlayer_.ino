#include <SD.h>
#include <SPI.h>
#include "TMRpcm.h"
#include <LiquidCrystal.h>

#define sm Serial
#define play_pause 2
#define next 3
#define prev 4
#define speaker 6

TMRpcm tmrpcm;

int temp = 0;
int temp1;

void setup() {

 pinMode(play_pause, INPUT); 
 pinMode(next, INPUT);
 pinMode(prev, INPUT);
 pinMode(speaker, OUTPUT);

 tmrpcm.speakerPin = speaker;
 tmrpcm.setVolume(4);
  
  sm.begin(9600);

   if (!checkSD())
   {
      sm.println("SD card failed"); 
      while(1){};
   }     
   else
    sm.println("SD card works");  

  lcdMessage("Music Player");
    
}

void loop() {

if(digitalRead(play_pause) == true)
{
  if(temp == 0)
  {
    tmrpcm.play("song1.wav");
    lcdMessage("playing song 1");
  }
  else if (temp == 1)
  {
    tmrpcm.play("song2.wav");
    lcdMessage("playing song 2");
  }
  else if (temp == 2)
  {
    tmrpcm.play("song3.wav");
    lcdMessage("playing song 3");
  }
  else if (temp == 3)
  {
    tmrpcm.play("song4.wav");
    lcdMessage("playing song 4");
  }

  if(digitalRead(next) == true)
  {
    if(temp < 3)    
      temp++;    
    else    
      temp = 0;    
  }

  if(digitalRead(prev) == true)
  {
    if (temp > 0)
      temp--;
    else
     temp = 3;
  }

}
else
{  
  sm.println("not playing");
  tmrpcm.pause();
}
}
