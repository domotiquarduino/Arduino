//DOMOTIQUARDUINO : Faire clignoter 8 leds avec un arduino utilisation de boucles for

int  l[8] = {4, 5, 6, 7, 8, 9, 10, 11}; //déclaration et initialisation du tableau avec les valeurs des pins arduino

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

  //boucle d'initialisation des modes et mise à 0V
  for (int i = 0; i < 8; i++) // i va nous servir pour parcourir le tableau
  {
    pinMode(l[i], OUTPUT); //on utilise les valeurs du tableau, déclare les broches en sortie
    digitalWrite(l[i], LOW); //l'une après l'autre éteinte au démarrage
  }
 
 Serial.println(" ");
 Serial.print("Domotiquarduino : ");
 Serial.println("Bienvenue");
 delay(tempsDePause6); //pause du programme pendant 3000ms, soit 3 secondes
}

void loop() //fonction principale qui se répète à l'infini
{
  for (int i = 0; i < 8; i++) // i va nous servir pour parcourir le tableau
  {
    digitalWrite(l[i], HIGH); // leds allumées
  }
 Serial.println("-------------");
 Serial.println("Tout allumer");
 delay(tempsDePause2); //pause du programme pendant 1000ms, soit 1 seconde
  for (int i = 0; i < 8; i++)
  {
    digitalWrite(l[i], LOW); // leds éteintes
  }
 Serial.println("-------------");
 Serial.println("Tout éteindre");
 delay(tempsDePause2);
}
