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

   //Boucle d'initialisation des modes et mise à 0V
  for (int i = 0; i < 8; i++) // i va nous servir pour parcourir le tableau
  {
    pinMode(l[i], OUTPUT); //on utilise les valeurs du tableau, déclare les broches en sortie
    digitalWrite(l[i], LOW); // l'une après l'autre éteinte au démarrage
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
    Serial.print("led ");
    if(l[i]==4)Serial.print("1");
    if(l[i]==5)Serial.print("2");
    if(l[i]==6)Serial.print("3");
    if(l[i]==7)Serial.print("4");
    if(l[i]==8)Serial.print("5");
    if(l[i]==9)Serial.print("6");
    if(l[i]==10)Serial.print("7");
    if(l[i]==11)Serial.print("8");
    Serial.println(" allumée");
    delay(tempsDePause2);
  }
 Serial.println("Tout allumer");
 Serial.println("-------------");
 delay(tempsDePause2); //pause du programme pendant 1000ms, soit 1 seconde
  for (int i = 8; i >= 0; i--) // i va nous servir pour parcourir le tableau
  {
    digitalWrite(l[i], LOW); // leds éteintes
    Serial.print("led ");
    if(l[i]==4)Serial.print("1");
    if(l[i]==5)Serial.print("2");
    if(l[i]==6)Serial.print("3");
    if(l[i]==7)Serial.print("4");
    if(l[i]==8)Serial.print("5");
    if(l[i]==9)Serial.print("6");
    if(l[i]==10)Serial.print("7");
    if(l[i]==11)Serial.print("8");
    Serial.println(" éteinte");
    delay(tempsDePause2);
  }
 Serial.println("Tout éteindre");
 Serial.println("-------------");
 delay(tempsDePause2); //pause du programme pendant 1000ms, soit 1 seconde 
}
