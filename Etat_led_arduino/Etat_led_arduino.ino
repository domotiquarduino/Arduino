 // Clignotement de LED.
 // Allume une LED pendant 1 seconde, puis l'éteint pendant 1 seconde
 // puis le programme se répète indéfiniment dans la boucle loop()

// Déclaration des variables :
const int broche13 = 13;
 
void setup() 
{
  // mettez votre code principal ici, pour l'exécuter une fois : 
  // initialise la broche 13 en sortie numérique
  // la broche 13 a une LED déjà connectée sur la plupart des cartes Arduino :
  // configuration de la broche N°13 en sortie (OUTPUT)
  pinMode(broche13, OUTPUT); 
}

void loop() 
{
  // mettez votre code principal ici, pour exécuter à plusieurs reprises :
  digitalWrite(broche13, HIGH);   // allume la LED
  delay(1000);              // ne fait rien pendant 1 seconde
  digitalWrite(broche13, LOW);    // éteint la LED
  delay(1000);              // ne fait rien pendant 1 seconde
}
