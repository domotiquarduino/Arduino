// ESP32/ESP8266 Wifi page Web allumer Led

//Charge la bibliothèque WiFi
#if defined(ESP8266)
#include <ESP8266WiFi.h> //pour ESP8266
String Titre="ESP8266";
#else
#include <WiFi.h> //pour ESP32
String Titre="ESP32";
#endif

#include "connexion_wifi.h"
#include "definitions_setup.h"
#include <SoftwareSerial.h>
//SoftwareSerial NodeSerial(D2,D3); //RX|TX
SoftwareSerial NodeSerial(3,1); //RX|TX
void setup() 
{
  Serial.begin(115200);
  NodeSerial.begin(4800);
  def_setup();
  affichage_wifi();
}

void loop()
{
  WiFiClient client=server.available();     //consulte les clients entrants

  if (client) 
  { 
    //si un nouveau client se connecte,
    Serial.println("Nouveau Client.");      //affiche un message sur le port série
    String Ligne_actuelle="";               //crée une chaîne pour contenir les données entrantes du client
    while (client.connected()) 
    {            
      //boucle while pour la connexion client
      if (client.available()) 
      {
        //s'il y a des octets à lire du client,
        char c=client.read();               //lit un octet, puis
        Serial.write(c);                    //l'affiche sur le moniteur série
        header+=c;
        if (c=='\n') 
        {                    
          //si l'octet est un caractère de nouvelle ligne
          //si la ligne actuelle est vide, vous avez deux caractères de nouvelle ligne à la suite.
          //fin de la requête HTTP du client, envoie une réponse :
          if (Ligne_actuelle.length()==0) 
          {
            //les en-têtes HTTP commencent toujours par un code de réponse (par exemple, HTTP / 1.1 200 OK)
            //et un type de contenu pour que le client sache ce qui va arriver, puis une ligne vide :
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connexion: fermée");
            client.println();
            
            // Allume et éteint les GPIO
            if (header.indexOf("GET /A")>=0) 
            {
              Serial.println("--------------------------[Led pin 04 éteinte]--------------------------");
              EtatPin1="off";
              NodeSerial.print(10);
              NodeSerial.print("\n");
            } 
            else if (header.indexOf("GET /a")>=0) 
            {
              Serial.println("--------------------------[Led pin 04 allumée]--------------------------");
              EtatPin1="on";
              NodeSerial.print(11);
              NodeSerial.print("\n");
            } 
            else if (header.indexOf("GET /B")>=0) 
            {
              Serial.println("--------------------------[Led pin 05 éteinte]--------------------------");
              EtatPin2="off";
              NodeSerial.print(12);
              NodeSerial.print("\n");
            } 
            else if (header.indexOf("GET /b")>=0) 
            {
              Serial.println("--------------------------[Led pin 05 allumée]--------------------------");
              EtatPin2="on";
              NodeSerial.print(13);
              NodeSerial.print("\n");
            }
             else if (header.indexOf("GET /C")>=0) 
            {
              Serial.println("--------------------------[Led pin 06 éteinte]--------------------------");
              EtatPin3="off";
              NodeSerial.print(14);
              NodeSerial.print("\n");
            } 
            else if (header.indexOf("GET /c")>=0) 
            {
              Serial.println("--------------------------[Led pin 06 allumée]--------------------------");
              EtatPin3="on";
              NodeSerial.print(15);
              NodeSerial.print("\n");
            }
             else if (header.indexOf("GET /D")>=0) 
            {
              Serial.println("--------------------------[Led pin 07 éteinte]--------------------------");
              EtatPin4="off";
              NodeSerial.print(16);
              NodeSerial.print("\n");
            } 
            else if (header.indexOf("GET /d")>=0) 
            {
              Serial.println("--------------------------[Led pin 07 allumée]--------------------------");
              EtatPin4="on";
              NodeSerial.print(17);
              NodeSerial.print("\n");
            }   
             else if (header.indexOf("GET /E")>=0) 
            {
              Serial.println("--------------------------[Led pin 08 éteinte]--------------------------");
              EtatPin5="off";
              NodeSerial.print(18);
              NodeSerial.print("\n");
            } 
            else if (header.indexOf("GET /e")>=0) 
            {
              Serial.println("--------------------------[Led pin 08 allumée]--------------------------");
              EtatPin5="on";
              NodeSerial.print(19);
              NodeSerial.print("\n");
            }  
             else if (header.indexOf("GET /F")>=0) 
            {
              Serial.println("--------------------------[Led pin 09 éteinte]--------------------------");
              EtatPin6="off";
              NodeSerial.print(20);
              NodeSerial.print("\n");
            } 
            else if (header.indexOf("GET /f")>=0) 
            {
              Serial.println("--------------------------[Led pin 09 allumée]--------------------------");
              EtatPin6="on";
              NodeSerial.print(21);
              NodeSerial.print("\n");
            }   
             else if (header.indexOf("GET /G")>=0) 
            {
              Serial.println("--------------------------[Led pin 10 éteinte]--------------------------");
              EtatPin7="off";
              NodeSerial.print(22);
              NodeSerial.print("\n");
            } 
            else if (header.indexOf("GET /g")>=0) 
            {
              Serial.println("--------------------------[Led pin 10 allumée]--------------------------");
              EtatPin7="on";
              NodeSerial.print(23);
              NodeSerial.print("\n");
            } 
             else if (header.indexOf("GET /H")>=0) 
            {
              Serial.println("--------------------------[Led pin 11 éteinte]--------------------------");
              EtatPin8="off";
              NodeSerial.print(24);
              NodeSerial.print("\n");
            } 
            else if (header.indexOf("GET /h")>=0) 
            {
              Serial.println("--------------------------[Led pin 11 allumée]--------------------------");
              EtatPin8="on";
              NodeSerial.print(25);
              NodeSerial.print("\n");
            } 
            else if (header.indexOf("GET /I")>=0) 
            {
              Serial.println("-----------------------------[Tout allumer]-----------------------------");
              EtatPin1="on";
              EtatPin2="on";
              EtatPin3="on";
              EtatPin4="on";
              EtatPin5="on";
              EtatPin6="on";
              EtatPin7="on";
              EtatPin8="on";
              NodeSerial.print(26);
              NodeSerial.print("\n");
            }  
            else if (header.indexOf("GET /i")>=0) 
            {
              Serial.println("-----------------------------[Tout éteindre]----------------------------");
              EtatPin1="off";
              EtatPin2="off";
              EtatPin3="off";
              EtatPin4="off";
              EtatPin5="off";
              EtatPin6="off";
              EtatPin7="off";
              EtatPin8="off";
              NodeSerial.print(27);
              NodeSerial.print("\n");
            }               
            //afficher la page Web HTML
            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");
            //CSS pour styler les boutons ON/OFF
            //modifier les attributs de couleur de fond et la taille de police de la page web pour les adapter selon les préférences
            client.println("<style>html{font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;} body{background-color:#0063B1;} th{background-color:grey;color:white;text-align: left;}");
            client.println("td{height:3px;}");
            client.println(".button{background-color:#00b3ff;border:none;color:white;padding:12px 20px;");
            client.println("text-decoration:none;font-size:11px;margin:2px;cursor:pointer;}");
            client.println(".button2{background-color:#555555;} .couleur_texte{color:white;}</style></head>");
            
            //en-tête de la page Web
            client.println("<body>");
            client.println("<table width=640 align=center border=0>");
            client.println("<tr><td colspan=4><img src=\"https://zupimages.net/up/20/13/7exg.png\"></td></tr>"); //bannière DOMOTIQUARDUINO
            client.println("<tr><td class=\"couleur_texte\"; colspan=4>Contr&ocirc;le des broches Wifi avec un  " + Titre +" et un arduino Web Server</td></tr>");


            //tout Allumer
            client.println("<tr><td width=220> </td>");    
            client.println("<td width=130><a href=\"/I\"><button class=\"button\">Tout Allumer</button></a></td>");
            // Tout Eteindre
            client.println("<td width=130><a href=\"/i\"><button class=\"button button2\">Tout Eteindre</button></a></td>");


            client.println("<tr><th>" + Titre1 + "</th>");
            //si EtatPin1 est désactivé, il affiche le bouton ON       
            if (EtatPin1=="on") 
            {
              client.println("<td width=130><a href=\"/A\"><button class=\"button\">ON</button></a></td>");
              client.println("<td width=60 height=45><img height=\"42\" width=\"42\" src=\"https://zupimages.net/up/19/35/fuyk.png\"></td>");
            } 
            else 
            {
              client.println("<td width=130><a href=\"/a\"><button class=\"button button2\">OFF</button></a></td>");
              client.println("<td width=60 height=45><img height=\"42\" width=\"42\" src=\"https://zupimages.net/up/19/35/ygq2.png\"></td>");
            } 
            //affiche l'état actuel et les boutons ON/OFF pour GPIO4  
             client.println("<td class=\"couleur_texte\">" + TitreEtat1 +" " + EtatPin1 + "</td></tr>");

             
             client.println("<tr><th>" + Titre2 + "</th>");           
            //si EtatPin2 est désactivé, il affiche le bouton ON                 
            if (EtatPin2=="on") 
            {
              client.println("<td width=130><a href=\"/B\"><button class=\"button\">ON</button></a></td>");
              client.println("<td width=60 height=45><img height=\"42\" width=\"42\" src=\"https://zupimages.net/up/19/35/fuyk.png\"></td>");                        
            } 
            else 
            {
              client.println("<td width=130><a href=\"/b\"><button class=\"button button2\">OFF</button></a></td>");
              client.println("<td width=60 height=45><img height=\"42\" width=\"42\" src=\"https://zupimages.net/up/19/35/ygq2.png\"></td>");             
            }
            //affiche l'état actuel et les boutons ON/OFF pour GPIO5   
            client.println("<td class=\"couleur_texte\">" + TitreEtat2 +" " + EtatPin2 + "</td></tr>");

            
            client.println("<tr><th>" + Titre3 + "</th>");
            //si EtatPin3 est désactivé, il affiche le bouton ON                 
            if (EtatPin3=="on") 
            {
              client.println("<td width=130><a href=\"/C\"><button class=\"button\">ON</button></a></td>");
              client.println("<td width=60 height=45><img height=\"42\" width=\"42\" src=\"https://zupimages.net/up/19/35/fuyk.png\"></td>");
            } 
            else 
            {
              client.println("<td width=130><a href=\"/c\"><button class=\"button button2\">OFF</button></a></td>");
              client.println("<td width=60 height=45><img height=\"42\" width=\"42\" src=\"https://zupimages.net/up/19/35/ygq2.png\"></td>");
            }
            //affiche l'état actuel et les boutons ON/OFF pour GPIO6   
            client.println("<td class=\"couleur_texte\">" + TitreEtat3 +" " + EtatPin3 + "</td></tr>");


            
            client.println("<tr><th>" + Titre4 + "</th>");
            //si EtatPin4 est désactivé, il affiche le bouton ON                 
            if (EtatPin4=="on") 
            {
              client.println("<td width=130><a href=\"/D\"><button class=\"button\">ON</button></a></td>");
              client.println("<td width=60 height=45><img height=\"42\" width=\"42\" src=\"https://zupimages.net/up/19/35/fuyk.png\"></td>");             
            } 
            else 
            {
              client.println("<td width=130><a href=\"/d\"><button class=\"button button2\">OFF</button></a></td>");
              client.println("<td width=60 height=45><img height=\"42\" width=\"42\" src=\"https://zupimages.net/up/19/35/ygq2.png\"></td>");
            }
            //affiche l'état actuel et les boutons ON/OFF pour GPIO7   
            client.println("<td class=\"couleur_texte\">" + TitreEtat4 +" " + EtatPin4 + "</td></tr>");


            
            client.println("<tr><th>" + Titre5 + "</th>");
            //si EtatPin5 est désactivé, il affiche le bouton ON                 
            if (EtatPin5=="on") 
            {
              client.println("<td width=130><a href=\"/E\"><button class=\"button\">ON</button></a></td>");
              client.println("<td width=60 height=45><img height=\"42\" width=\"42\" src=\"https://zupimages.net/up/19/35/fuyk.png\"></td>");
            } 
            else 
            {
              client.println("<td width=130><a href=\"/e\"><button class=\"button button2\">OFF</button></a></td>");
              client.println("<td width=60 height=45><img height=\"42\" width=\"42\" src=\"https://zupimages.net/up/19/35/ygq2.png\"></td>");
            }
            //affiche l'état actuel et les boutons ON/OFF pour GPIO8   
            client.println("<td class=\"couleur_texte\">" + TitreEtat5 +" " + EtatPin5 + "</td></tr>");


            
            client.println("<tr><th>" + Titre6 + "</th>");
            //si EtatPin6 est désactivé, il affiche le bouton ON                 
            if (EtatPin6=="on") 
            {
              client.println("<td width=130><a href=\"/F\"><button class=\"button\">ON</button></a></td>");
              client.println("<td width=60 height=45><img height=\"42\" width=\"42\" src=\"https://zupimages.net/up/19/35/fuyk.png\"></td>");
            } 
            else 
            {
              client.println("<td width=130><a href=\"/f\"><button class=\"button button2\">OFF</button></a></td>");
              client.println("<td width=60 height=45><img height=\"42\" width=\"42\" src=\"https://zupimages.net/up/19/35/ygq2.png\"></td>");
            }
            //affiche l'état actuel et les boutons ON/OFF pour GPIO9   
            client.println("<td class=\"couleur_texte\">" + TitreEtat6 +" " + EtatPin6 + "</td></tr>"); 


                       
            client.println("<tr><th>" + Titre7 + "</th>");
            //si EtatPin7 est désactivé, il affiche le bouton ON                 
            if (EtatPin7=="on") 
            {
              client.println("<td width=130><a href=\"/G\"><button class=\"button\">ON</button></a></td>");
              client.println("<td width=60 height=45><img height=\"42\" width=\"42\" src=\"https://zupimages.net/up/19/35/fuyk.png\"></td>");
            } 
            else 
            {
              client.println("<td width=130><a href=\"/g\"><button class=\"button button2\">OFF</button></a></td>");
              client.println("<td width=60 height=45><img height=\"42\" width=\"42\" src=\"https://zupimages.net/up/19/35/ygq2.png\"></td>");
            }
            //affiche l'état actuel et les boutons ON/OFF pour GPIO10   
            client.println("<td class=\"couleur_texte\">" + TitreEtat7 +" " + EtatPin7 + "</td></tr>");


            
            client.println("<tr><th>" + Titre8 + "</th>");
            //si EtatPin8 est désactivé, il affiche le bouton ON                 
            if (EtatPin8=="on") 
            {
              client.println("<td width=130><a href=\"/H\"><button class=\"button\">ON</button></a></td>");
              client.println("<td width=60 height=45><img height=\"42\" width=\"42\" src=\"https://zupimages.net/up/19/35/fuyk.png\"></td>");
            } 
            else 
            {
              client.println("<td width=130><a href=\"/h\"><button class=\"button button2\">OFF</button></a></td>");
              client.println("<td width=60 height=45><img height=\"42\" width=\"42\" src=\"https://zupimages.net/up/19/35/ygq2.png\"></td>");
            }
            //affiche l'état actuel et les boutons ON/OFF pour GPIO11   
            client.println("<td class=\"couleur_texte\">" + TitreEtat8 +" " + EtatPin8 + "</td></tr>");
            //client.println("<tr><td colspan=4><img src=\"https://zupimages.net/up/20/15/q0dv.png\"></td></tr>");   //SCHEMA ESP8266 Wemos Mini D1 et Arduino UNO 
            //client.println("<tr><td colspan=4><img src=\"https://zupimages.net/up/20/15/qktx.png\"></td></tr>");   //SCHEMA ESP8266 NodeMcu Dev Kit et Arduino UNO  
            //client.println("<tr><td colspan=4><img src=\"https://zupimages.net/up/20/16/fpnu.png\"></td></tr>");   //SCHEMA DT-06 ESP8285 et Arduino NANO 
            //client.println("<tr><td colspan=4><img src=\"https://zupimages.net/up/20/17/ui7m.png\"></td></tr>");   //SCHEMA ESP01 et Arduino NANO 
            //client.println("<tr><td colspan=4><img src=\"https://zupimages.net/up/20/16/albf.png\"></td></tr>");   //SCHEMA DT-06 ESP8285 et Arduino UNO  
            client.println("<tr><td colspan=4><img src=\"https://zupimages.net/up/20/18/bhe2.png\"></td></tr>");   //SCHEMA ESP01 et Arduino UNO         
            client.println("</table>");
            client.println("</body></html>");
            
            //la réponse HTTP se termine par une autre ligne vide
            client.println();
            //sortir de la boucle while
            break;
          } 
          else 
          { 
            //si nouvelle ligne, alors efface Ligne_actuelle
            Ligne_actuelle="";
          }
        } 
        else if (c != '\r') 
        {  
          //si autre chose qu'un caractère de retour chariot,
          Ligne_actuelle += c;      //s'ajoute à la fin de la ligne actuelle
        }
      }
    }
    //efface la variable d'en-tête
    header="";
    //ferme la connexion
    client.stop();
    Serial.println("Client déconnecté.");
    Serial.println("");
  }
}
