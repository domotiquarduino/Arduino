// Variable pour stocker la requête HTTP
String header;

//Ttitre à modifier selon vos attentes des 8 sorties
String Titre1 = "Broche 1";
String Titre2 = "Broche 2";
String Titre3 = "Broche 3";
String Titre4 = "Broche 4";
String Titre5 = "Broche 5";
String Titre6 = "Broche 6";
String Titre7 = "Broche 7";
String Titre8 = "Broche 8";

String TitreEtat1 = "GPIO 4 ";
String TitreEtat2 = "GPIO 5 ";
String TitreEtat3 = "GPIO 6 ";
String TitreEtat4 = "GPIO 7 ";
String TitreEtat5 = "GPIO 8 ";
String TitreEtat6 = "GPIO 9 ";
String TitreEtat7 = "GPIO 10 ";
String TitreEtat8 = "GPIO 11 ";

// Variables auxiliaires pour stocker l'état actuel de la sortie
String EtatPin1 = "off";
String EtatPin2 = "off";
String EtatPin3 = "off";
String EtatPin4 = "off";
String EtatPin5 = "off";
String EtatPin6 = "off";
String EtatPin7 = "off";
String EtatPin8 = "off";

// |ESP8266| ESP32 |  Pin  |
// |   D3  | IO0   |   0   |
// |   D2  | IO4   |   4   |
// |  DT06 | TX    |   1   |
// |  DT06 | RX    |   3   |


void def_setup()
{
  // Initialise les variables en tant que sorties
  //pinMode(4, INPUT); //RX
  //pinMode(0, OUTPUT); //TX
  
  pinMode(3, INPUT);  //RX
  pinMode(1, OUTPUT); //TX
}
