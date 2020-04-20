//DOMOTIQUARDUINO : Allumer 1 led avec un arduino 

const int l1=4; //on définit la constante en donnant un nom (l1) et un nombre (4) correspondant à la broche de l'arduino.
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
 digitalWrite(l1, LOW); //led éteinte à l'initialisation de l'Arduino
 Serial.println(" ");
 Serial.print("Domotiquarduino : ");
 Serial.println("Bienvenue");
 delay(tempsDePause6); //pause du programme pendant 3000ms, soit 3 secondes
}

void loop() //fonction principale qui se répète à l'infini
{
 digitalWrite(l1,HIGH); //allumer la led sur la broche 4
 Serial.println("-------------");
 Serial.println("Led 1 allumée");
}
