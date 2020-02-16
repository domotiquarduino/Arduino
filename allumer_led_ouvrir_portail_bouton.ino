// -------------------------------------
// --- Allumer des Led avec 1 bouton ---
// -------------------------------------

// Déclaration bibliothèque
 #include <Servo.h>
 
// Déclaration des variables
int Etat_led=0;
int Led_pin06=6;
int Led_pin07=7;
int Led_pin08=8;
int Led_pin11=11;
int Bouton_led=4;
int bouton_led_nouveau;
int bouton_led_ancien=1;

Servo servo01; //servo moteur 1
Servo servo02; //servo moteur 2
int Etat_portail=0;
int Bouton_portail=5;
int bouton_portail_nouveau;
int bouton_portail_ancien=1;

void setup() 
{
  // Fonction d'initialisation de la carte
  Serial.begin(9600);
  pinMode(Led_pin06, OUTPUT);
  pinMode(Led_pin07, OUTPUT);
  pinMode(Led_pin08, OUTPUT);
  pinMode(Led_pin11, OUTPUT);
  pinMode(Bouton_led, INPUT); 
  pinMode(Bouton_portail, INPUT); 
  servo01.attach(9);  //broche 9 Arduino
  servo02.attach(10);  //broche 10 Arduino 
  servo01.write(177);
  delay(100); 
}

void loop() 
{
  // Fonction principale qui se répète (s’exécute) à l'infini
  bouton_led_nouveau=digitalRead(Bouton_led);

 if(bouton_led_ancien==0 && bouton_led_nouveau==1)
 {
  if(Etat_led==0)
  {
    Led_allumees();
    Etat_led=1;
  }
  else
  {
    Led_eteintes();   
    Etat_led=0;
  }
 }
 bouton_led_ancien=bouton_led_nouveau;




  bouton_portail_nouveau=digitalRead(Bouton_portail);

 if(bouton_portail_ancien==0 && bouton_portail_nouveau==1)
 {
  if(Etat_portail==0)
  {
    Ouvrir_portail01();
    Ouvrir_portail02();
    Etat_portail=1;
  }
  else
  {
    Fermer_portail01();
    Fermer_portail02();   
    Etat_portail=0;
  }
 }
 bouton_portail_ancien=bouton_portail_nouveau;


 
}

// Déclaration des fonctions
void Led_allumees()
{
    digitalWrite(Led_pin06,HIGH);
    Serial.print("Led 06 allumée. ");
    digitalWrite(Led_pin07,HIGH);
    Serial.print("Led 07 allumée. ");
    digitalWrite(Led_pin08,HIGH);
    Serial.print("Led 08 allumée. ");
    digitalWrite(Led_pin11,HIGH);
    Serial.println("Led 11 allumée.");
}

void Led_eteintes()
{
    digitalWrite(Led_pin06, LOW);
    Serial.print("Led 06 éteinte. ");
    digitalWrite(Led_pin07, LOW);
    Serial.print("Led 07 éteinte. ");
    digitalWrite(Led_pin08, LOW); 
    Serial.print("Led 08 éteinte. ");
    digitalWrite(Led_pin11, LOW);
    Serial.println("Led 11 éteinte."); 
}



void Fermer_portail01()
{
  // Fait bouger le bras de 0° à 180°
  for (int position = 100; position <= 186; position++) 
  {
    servo01.write(position);
    Serial.print("servo1 fermeture : ");
    Serial.println(position);
    delay(45);
  }
}
void Ouvrir_portail01()
{  
  // Fait bouger le bras de 180° à 10°
  for (int position = 185; position >= 101; position--) 
  {
    servo01.write(position);
    Serial.print("servo1 ouverture : ");
    Serial.println(position);
    delay(45);
  }
}
void Ouvrir_portail02()
{
  // Fait bouger le bras de 0° à 180°
  for (int position = 81; position <= 172; position++) 
  {
    servo02.write(position);
    Serial.print("servo2 ouverture : ");    
    Serial.println(position);
    delay(45);
  }
}
void Fermer_portail02()
{  
  // Fait bouger le bras de 180° à 10°
  for (int position = 171; position >= 82; position--) 
  {
    servo02.write(position);
    Serial.print("servo2 fermeture : ");     
    Serial.println(position);
    delay(45);
  }
}
