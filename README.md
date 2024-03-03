# Communication Série entre un Capteur de pH Atlas Scientific et une carte Arduino

Ce projet permet d'afficher chaque seconde la mesure du pH à l'aide d'un capteur EZO™ pH Circuit de chez Atlas Scientific connecté à un microcontrôleur Arduino. Le capteur peut être configuré pour communiquer via UART ou I2C.

## Composants

Voici la liste des composants utilisés dans ce projet :

- Arduino UNO ou équivalent
- Capteur de pH Atlas Scientific EZO™ pH Circuit
- Câble USB
- Ordinateur avec l'IDE Arduino installé

## Installation

1. Clonez ce projet depuis GitHub.
2. Branchez le capteur de pH au microcontrôleur Arduino selon les spécifications du fabricant.
3. Ouvrez le fichier `EZO-PH-UART-FR.ino` dans l'IDE Arduino.
4. Sélectionnez votre carte Arduino dans le menu `Outils > Type de carte`.
5. Sélectionnez le port série de votre Arduino dans le menu `Outils > Port`.
6. Chargez le programme sur votre Arduino en appuyant sur le bouton "Téléverser".

## Configuration

Vous pouvez choisir le mode de communication (UART ou I2C) en modifiant les paramètres dans le code ou en envoyant des commandes via le moniteur série de l'IDE Arduino. Vous pouvez également utiliser le moniteur série pour lancer d'autres commandes, telles que l'étalonnage du capteur.

## Utilisation du Code

1. Une fois le code téléversé sur votre Arduino, ouvrez le moniteur série de l'IDE Arduino.
2. Les mesures de pH seront affichées chaque seconde dans le moniteur série.

## Licence

Ce projet est sous licence MIT. Veuillez consulter le fichier `LICENSE.md` pour plus d'informations.

## Auteur

Ce projet a été créé par Richedor (Adecola) Laleye. Pour toute question ou suggestion, n'hésitez pas à le contacter à adecolalaleye@gmail.com.
