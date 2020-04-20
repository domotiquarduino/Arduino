//DOMOTIQUARDUINO : Contrôler huit leds avec un arduino depuis le moniteur série

const int l1=4; //on définit la constante en donnant un nom (l1) et un nombre (4) correspondant à la broche de l'arduino.
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
int lireDonnees;  //une variable pour lire les données envoyées depuis le moniteur série


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
 Serial.println("Saisir une lettre pour contrôler les leds :");
 Serial.println("a : led 1 On | A : led 1 Off");
 Serial.println("b : led 2 On | B : led 2 Off");
 Serial.println("c : led 3 On | C : led 3 Off");
 Serial.println("d : led 4 On | D : led 4 Off");
 Serial.println("e : led 5 On | E : led 5 Off");
 Serial.println("f : led 6 On | F : led 6 Off");
 Serial.println("g : led 7 On | G : led 7 Off");
 Serial.println("h : led 8 On | H : led 8 Off");
 Serial.println("i : tout On  | I : tout Off ");
 delay(tempsDePause6); //pause du programme pendant 3000ms, soit 3 secondes
}

void loop() //fonction principale qui se répète à l'infini
{
 if (Serial.available() > 0) //condition pour voir s'il y a des données série entrantes:
 {
  //lecture de l'octet le plus ancien dans la mémoire tampon série :
  lireDonnees = Serial.read();
  if (lireDonnees == 'a') //s'il s'agit d'un a miniscule (ASCII 97)
  {
   digitalWrite(l1, HIGH); //allumer la led sur la broche 4
   Serial.println("-------------");
   Serial.println("led 1 allumée");
  }
  if (lireDonnees == 'A') //s'il s'agit d'un a majuscule (ASCII 65)
  {
   digitalWrite(l1, LOW); //éteindre la led sur la broche 4
   Serial.println("-------------");
   Serial.println("led 1 éteinte");
  }
  if (lireDonnees == 'b') 
  {
   digitalWrite(l2, HIGH); 
   Serial.println("-------------");
   Serial.println("led 2 allumée");
  }
  if (lireDonnees == 'B') 
  {
   digitalWrite(l2, LOW); 
   Serial.println("-------------");
   Serial.println("led 2 éteinte");
  }  
  if (lireDonnees == 'c') 
  {
   digitalWrite(l3, HIGH); 
   Serial.println("-------------");
   Serial.println("led 3 allumée");
  }
  if (lireDonnees == 'C') 
  {
   digitalWrite(l3, LOW); 
   Serial.println("-------------");
   Serial.println("led 3 éteinte");
  }  
  if (lireDonnees == 'd') 
  {
   digitalWrite(l4, HIGH); 
   Serial.println("-------------");
   Serial.println("led 4 allumée");
  }
  if (lireDonnees == 'D') 
  {
   digitalWrite(l4, LOW); 
   Serial.println("-------------");
   Serial.println("led 4 éteinte");
  }  
  if (lireDonnees == 'e') 
  {
   digitalWrite(l5, HIGH); 
   Serial.println("-------------");
   Serial.println("led 5 allumée");
  }
  if (lireDonnees == 'E') 
  {
   digitalWrite(l5, LOW); 
   Serial.println("-------------");
   Serial.println("led 5 éteinte");
  } 
  if (lireDonnees == 'f') 
  {
   digitalWrite(l6, HIGH); 
   Serial.println("-------------");
   Serial.println("led 6 allumée");
  }
  if (lireDonnees == 'F') 
  {
   digitalWrite(l6, LOW); 
   Serial.println("-------------");
   Serial.println("led 6 éteinte");
  }   
  if (lireDonnees == 'g') 
  {
   digitalWrite(l7, HIGH); 
   Serial.println("-------------");
   Serial.println("led 7 allumée");
  }
  if (lireDonnees == 'G') 
  {
   digitalWrite(l7, LOW); 
   Serial.println("-------------");
   Serial.println("led 7 éteinte");
  } 
  if (lireDonnees == 'h') 
  {
   digitalWrite(l8, HIGH); 
   Serial.println("-------------");
   Serial.println("led 8 allumée");
  }
  if (lireDonnees == 'H') 
  {
   digitalWrite(l8, LOW); 
   Serial.println("-------------");
   Serial.println("led 8 éteinte");
  } 
  if (lireDonnees == 'i') 
  {
   digitalWrite(l1, HIGH);
   digitalWrite(l2, HIGH);
   digitalWrite(l3, HIGH);
   digitalWrite(l4, HIGH);
   digitalWrite(l5, HIGH);
   digitalWrite(l6, HIGH);
   digitalWrite(l7, HIGH);
   digitalWrite(l8, HIGH);
   Serial.println("-------------");
   Serial.println("tout allumer");
  }
  if (lireDonnees == 'I') 
  {
   digitalWrite(l1, LOW);
   digitalWrite(l2, LOW);
   digitalWrite(l3, LOW);
   digitalWrite(l4, LOW);
   digitalWrite(l5, LOW);
   digitalWrite(l6, LOW);
   digitalWrite(l7, LOW);
   digitalWrite(l8, LOW);
   Serial.println("-------------");
   Serial.println("tout éteindre");
  } 
 }
}
