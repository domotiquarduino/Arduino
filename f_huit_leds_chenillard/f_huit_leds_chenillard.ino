//DOMOTIQUARDUINO : Chenillard 8 led avec un arduino 

const int l1=4;   //on définit la constante en donnant un nom (l1) et un nombre (4) correspondant à la broche de l'arduino.
const int l2=5;
const int l3=6;
const int l4=7;
const int l5=8;
const int l6=9;
const int l7=10;
const int l8=11;

int tempsDePause1 = 500 ; //déclaration de la variable tempsDePause1 
int tempsDePause2 = 1000;
int tempsDePause3 = 1500;
int tempsDePause4 = 2000;
int tempsDePause5 = 2500;
int tempsDePause6 = 3000;

void setup() //fonction d'initialisation de la carte qui s'exécute une fois
{
 Serial.begin(9600); //moniteur série configuré à 9600 baud
 //contenu de l'initialisation
 pinMode(l1, OUTPUT); //led 1 déclarée comme une broche de sortie
 pinMode(l2, OUTPUT);
 pinMode(l3, OUTPUT);
 pinMode(l4, OUTPUT);
 pinMode(l5, OUTPUT);
 pinMode(l6, OUTPUT);
 pinMode(l7, OUTPUT);
 pinMode(l8, OUTPUT);
 
 digitalWrite(l1, LOW); //led éteinte à l'initialisation de l'Arduino
 digitalWrite(l2, LOW);
 digitalWrite(l3, LOW);
 digitalWrite(l4, LOW);
 digitalWrite(l5, LOW);
 digitalWrite(l6, LOW);
 digitalWrite(l7, LOW);
 digitalWrite(l8, LOW);
 
 Serial.println(" ");
 Serial.print("Domotiquarduino : ");
 Serial.println("Bienvenue");
 delay(tempsDePause6); //pause du programme pendant 3000ms, soit 3 secondes
}

void loop() //fonction principale qui se répète à l'infini
{
 digitalWrite(l1, HIGH); //allumer la led sur la broche 4
 Serial.println("led 1 allumée");
 delay(tempsDePause2); //pause du programme pendant 1000ms, soit 1 seconde
 digitalWrite(l2, HIGH);
 Serial.println("led 2 allumée");
 delay(tempsDePause2);
 digitalWrite(l3, HIGH);
 Serial.println("led 3 allumée");
 delay(tempsDePause2); 
 digitalWrite(l4, HIGH);
 Serial.println("led 4 allumée");
 delay(tempsDePause2); 
 digitalWrite(l5, HIGH);
 Serial.println("led 5 allumée");
 delay(tempsDePause2); 
 digitalWrite(l6, HIGH);
 Serial.println("led 6 allumée");
 delay(tempsDePause2); 
 digitalWrite(l7, HIGH);
 Serial.println("led 7 allumée");
 delay(tempsDePause2); 
 digitalWrite(l8, HIGH);
 Serial.println("led 8 allumée");
 delay(tempsDePause2); //pause du programme pendant 1000ms, soit 1 seconde 
 Serial.println("-------------");

 digitalWrite(l8, LOW); //éteindre la led sur la broche 4
 Serial.println("led 8 éteinte");
 delay(tempsDePause2);
 digitalWrite(l7, LOW);
 Serial.println("led 7 éteinte");
 delay(tempsDePause2);
 digitalWrite(l6, LOW);
 Serial.println("led 6 éteinte");
 delay(tempsDePause2);
 digitalWrite(l5, LOW);
 Serial.println("led 5 éteinte");
 delay(tempsDePause2);
 digitalWrite(l4, LOW);
 Serial.println("led 4 éteinte");
 delay(tempsDePause2);
 digitalWrite(l3, LOW);
 Serial.println("led 3 éteinte");
 delay(tempsDePause2);
 digitalWrite(l2, LOW);
 Serial.println("led 2 éteinte");
 delay(tempsDePause2);
 digitalWrite(l1, LOW);
 Serial.println("led 1 éteinte");
 delay(tempsDePause2); //pause du programme pendant 1000ms, soit 1 seconde 
 Serial.println("-------------");
}
