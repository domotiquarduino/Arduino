//Contrôler des Leds en WIFI depuis un ESP vers un Arduino
//Téléverser ce programme vers l'Arduino :
#include <SoftwareSerial.h>
SoftwareSerial ArduinoSerial(3,2); //RX,TX

void setup() 
{
  Serial.begin(115200);
  ArduinoSerial.begin(4800);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
}

void loop() 
{
  while (ArduinoSerial.available()>0) 
  {
    //float val=ArduinoSerial.parseFloat();
    int val=ArduinoSerial.parseInt();
    
    if (ArduinoSerial.read()=='\n') 
    {
      if (val==11) 
      {
       digitalWrite(4,1);
       Serial.print("Led pin 4 allumée  [");
      } 
      else if (val==10)
      {
       digitalWrite(4,0);
       Serial.print("Led pin 4 éteinte  [");
      }
      else if (val==13) 
      {
       digitalWrite(5,1);
       Serial.print("Led pin 5 allumée  [");
      } 
      else if (val==12)
      {
       digitalWrite(5,0);
       Serial.print("Led pin 5 éteinte  [");
      }
      else if (val==15) 
      {
       digitalWrite(6,1);
       Serial.print("Led pin 6 allumée  [");
      } 
      else if (val==14)
      {
       digitalWrite(6,0);
       Serial.print("Led pin 6 éteinte  [");
      }  
      else if (val==17) 
      {
       digitalWrite(7,1);
       Serial.print("Led pin 7 allumée  [");
      } 
      else if (val==16)
      {
       digitalWrite(7,0);
       Serial.print("Led pin 7 éteinte  [");
      }  
      else if (val==19) 
      {
       digitalWrite(8,1);
       Serial.print("Led pin 8 allumée  [");
      } 
      else if (val==18)
      {
       digitalWrite(8,0);
       Serial.print("Led pin 8 éteinte  [");
      } 
      else if (val==21) 
      {
       digitalWrite(9,1);
       Serial.print("Led pin 9 allumée  [");
      } 
      else if (val==20)
      {
       digitalWrite(9,0);
       Serial.print("Led pin 9 éteinte  [");
      } 
      else if (val==23) 
      {
       digitalWrite(10,1);
       Serial.print("Led pin 10 allumée [");
      } 
      else if (val == 22)
      {
       digitalWrite(10,0);
       Serial.print("Led pin 10 éteinte [");
      } 
      else if (val==25) 
      {
       digitalWrite(11,1);
       Serial.print("Led pin 11 allumée [");
      } 
      else if (val==24)
      {
       digitalWrite(11,0);
       Serial.print("Led pin 11 éteinte [");
      } 
      else if (val==26) 
      {
       digitalWrite(4,1);
       digitalWrite(5,1);
       digitalWrite(6,1);
       digitalWrite(7,1);
       digitalWrite(8,1);
       digitalWrite(9,1);
       digitalWrite(10,1);
       digitalWrite(11,1);
       Serial.print("Tout Allumer       [");
      } 
      else if (val==27)
      {
       digitalWrite(4,0);
       digitalWrite(5,0);
       digitalWrite(6,0);
       digitalWrite(7,0);
       digitalWrite(8,0);
       digitalWrite(9,0);
       digitalWrite(10,0);
       digitalWrite(11,0);
       Serial.print("Tout éteindre      [");      
      } 
      Serial.print(val);
      Serial.println("]");
      Serial.println("-----------------------");
    }
  }
  delay(100);
}
