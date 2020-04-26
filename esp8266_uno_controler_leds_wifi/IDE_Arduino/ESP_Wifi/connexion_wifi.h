const char* ssid     = "VOTRE RESEAU WIFI";  // A remplacer par le SSID (nom) du réseau WiFi de votre fournisseur d'accès à internet
const char* password = "MOT DE PASSE RESEAU WIFI"; // A remplacer par votre mot de passe de votre réseau Wi-Fi

// Définir le numéro de port du serveur Web sur 80
WiFiServer server(80);

IPAddress local_IP(192,168,1,54); //Attribuer une adresse IP fixe dans la fourchette attribuée par votre fournisseur d'accès à internet
IPAddress gateway(192,168,1,254); //Passerelle par défaut
IPAddress subnet(255,255,255,0);  //Masque de sous-réseau


void affichage_wifi()
{
  // Configuration de l'adresse IP statique
  if (!WiFi.config(local_IP,gateway,subnet)) 
  {
    Serial.println("Configuration STA Impossible");
  }
  
  // Connectez-vous au réseau Wi-Fi avec SSID et mot de passe
  Serial.print("Connexion à ");
  Serial.println(ssid);
  WiFi.begin(ssid,password);
  while (WiFi.status()!=WL_CONNECTED) 
  {
    delay(300);
    Serial.print(".");
  }
  // Afficher l'adresse IP locale et démarrer le serveur Web
  Serial.println("");
  Serial.println("WiFi connecté.");
  Serial.println("Adresse IP : ");
  Serial.println(WiFi.localIP());
  server.begin(); 

  // Afficher l'adresse ESP MAC
  Serial.println("Adresse MAC : ");
  Serial.println(WiFi.macAddress());
}
