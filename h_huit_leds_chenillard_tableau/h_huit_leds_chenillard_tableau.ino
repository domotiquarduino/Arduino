//DOMOTIQUARDUINO : Chenillard 8 leds avec un arduino utilisation de tableau

int  l[8] = {4, 5, 6, 7, 8, 9, 10, 11}; //déclaration et initialisation du tableau avec les valeurs des pins arduino

//Tableau à double entrée listant l’état (booléen 1 allumé, 0 éteint) des LED à chaque séquence
boolean affichage[17][8]={
   1,1,1,1,1,1,1,1,
   1,0,0,0,0,0,0,0,
   1,1,0,0,0,0,0,0,
   1,1,1,0,0,0,0,0,
   1,1,1,1,0,0,0,0,
   1,1,1,1,1,0,0,0,
   1,1,1,1,1,1,0,0,
   1,1,1,1,1,1,1,0,
   1,1,1,1,1,1,1,1,
   1,1,1,1,1,1,1,0,
   1,1,1,1,1,1,0,0,
   1,1,1,1,1,0,0,0,
   1,1,1,1,0,0,0,0,
   1,1,1,0,0,0,0,0,
   1,1,0,0,0,0,0,0,
   1,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0};

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
  for (int i=0;i<17;i++) // boucle de séquence d'affichage
  {
    Serial.print("[");
    Serial.print(i);
    Serial.print("] -> ");
    if(i==0) Serial.println("tout allumer");
    if(i==1) Serial.println("led 1 allumée"); 
    if(i==2) Serial.println("led 2 allumée");
    if(i==3) Serial.println("led 3 allumée");
    if(i==4) Serial.println("led 4 allumée");
    if(i==5) Serial.println("led 5 allumée");
    if(i==6) Serial.println("led 6 allumée");
    if(i==7) Serial.println("led 7 allumée");
    if(i==8) Serial.println("led 8 allumée");
    if(i==9) Serial.println("led 8 éteinte");
    if(i==10) Serial.println("led 7 éteinte");
    if(i==11) Serial.println("led 6 éteinte");
    if(i==12) Serial.println("led 5 éteinte");
    if(i==13) Serial.println("led 4 éteinte");
    if(i==14) Serial.println("led 3 éteinte");
    if(i==15) Serial.println("led 2 éteinte");
    if(i==16) {Serial.println("led 1 éteinte"); Serial.println("[17] -> tout éteint");}

    for (int p=0;p<8;p++) // boucle pour chaque pin
    {
      boolean etat=affichage[i][p]; // on va chercher l'état pour le pin
      digitalWrite(l[p],etat); // on met le pin concerné à l'état
    }
    //tous les pins sont dans l'état de la séquence en cours
    delay(tempsDePause2); //petite pause d'affichage
    // on passe à la séquence suivante
  }
  // fin des séquences et on repart au début de la loop()
}
