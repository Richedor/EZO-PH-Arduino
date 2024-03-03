
/*
 * Projet : Communication Série entre un Capteur de pH Atlas Scientific et un Arduino
 * Description : Ce projet permet d'afficher chaque seconde la mesure du pH à l'aide d'un capteur EZO™ pH Circuit de chez Atlas Scientific connecté à un microcontrôleur Arduino. Le capteur peut être configuré pour communiquer via UART ou I2C.
 * Auteur : Richedor LALEYE (Adecola)
 * Date : 9 Octobre 2023
 * Version : 2
 * Licence : MIT 
 */


#include <SoftwareSerial.h>                           // nous devons inclure la bibliothèque SoftwareSerial, sinon nous ne pouvons pas l'utiliser
#define rx 2                                          // définir quelle broche rx va être
#define tx 3                                          // définir quelle broche tx va être
 
SoftwareSerial myserial(rx, tx);                      // définir comment le port série logiciel va fonctionner
 
String inputstring = "";                              // une chaîne pour contenir les données entrantes du PC
String sensorstring = "";                             // une chaîne pour contenir les données du produit Atlas Scientific
boolean input_string_complete = false;                // avons-nous reçu toutes les données du PC
boolean sensor_string_complete = false;               // avons-nous reçu toutes les données du produit Atlas Scientific
float pH;                                             // utilisé pour contenir un nombre à virgule flottante qui est le pH
 
 
void setup()
{
  Serial.begin(9600);                                 // définir le débit en bauds pour le port série matériel_0 à 9600
  myserial.begin(9600);                               // définir le débit en bauds pour le port série logiciel à 9600
  inputstring.reserve(10);                            // mettre de côté quelques octets pour recevoir des données du PC
  sensorstring.reserve(30);                           // mettre de côté quelques octets pour recevoir des données du produit Atlas Scientific
}
 
void serialEvent()
{
  inputstring = Serial.readStringUntil(13);           // lire la chaîne jusqu'à ce que nous voyions un <CR>
  input_string_complete = true;                       // définir le drapeau utilisé pour indiquer si nous avons reçu une chaîne complète du PC
}
 
 
void loop()
{
  if (input_string_complete == true)                  // si une chaîne du PC a été reçue dans son intégralité
  {
    myserial.print(inputstring);                      // envoyer cette chaîne au produit Atlas Scientific
    myserial.print('\r');                             // ajouter un <CR> à la fin de la chaîne
    inputstring = "";                                 // effacer la chaîne
    input_string_complete = false;                    // réinitialiser le drapeau utilisé pour indiquer si nous avons reçu une chaîne complète du PC
  }
 
  if (myserial.available() > 0)                       // si nous voyons que le produit Atlas Scientific a envoyé un caractère
  {
    char inchar = (char)myserial.read();              // obtenir le caractère que nous venons de recevoir
    sensorstring += inchar;                           // ajouter le caractère à la variable appelée sensorstring
    if (inchar == '\r')                               // si le caractère entrant est un <CR>
    {
      sensor_string_complete = true;                  // définir le drapeau
    }
  }
 
  if (sensor_string_complete == true)                 // si une chaîne du produit Atlas Scientific a été reçue dans son intégralité
  {
    Serial.println(sensorstring);                     // envoyer cette chaîne au moniteur série du PC
    sensorstring = "";                                // effacer la chaîne
    sensor_string_complete = false;                   // réinitialiser le drapeau utilisé pour indiquer si nous avons reçu une chaîne complète du produit Atlas Scientific
  }
}
