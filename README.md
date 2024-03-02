# Projet Systèmes Embarqués Smart Home Domotique

Ce projet de systèmes embarqués utilise la carte Arduino Mega 2560 pour créer un système domotique intelligent visant à améliorer la sécurité et le confort d'une maison connectée. Le dépôt GitHub associé à ce projet contient les programmes Arduino correspondants, des simulations sur Proteus, et des diagrammes pour faciliter la compréhension du code.

## Fonctionnalités

### 1. Ouverture de Portail par Mot de Passe

- Utilisation d'un écran LCD et d'un clavier (keypad) pour saisir le mot de passe.
- Contrôle d'un relais pour l'ouverture/fermeture du portail.
- LEDs indicatrices signalant l'état du portail (ouvert/fermé).

### 2. Allumage de la Lampe Maison à la Détection d'Obscurité

- Utilisation de LED comme lampe maison.
- Intégration d'un capteur de lumière (LDR) pour détecter l'obscurité.
- Affichage d'informations sur l'état de la lumière sur l'écran LCD.

### 3. Détection de Gaz avec le Capteur MQ2

- Intégration d'un capteur de gaz MQ2 pour la détection de gaz potentiellement dangereux.
- Affichage d'alertes sur l'écran LCD en cas de détection.

### 4. Déclenchement du Ventilateur (9110 Fan Control Module) par Bouton

- Utilisation d'un bouton pour activer/désactiver le ventilateur.
- Contrôle du ventilateur via le module de commande du ventilateur 9110.
- Affichage de l'état du ventilateur sur l'écran LCD.

### 5. Détection de Présence d'un Individu avec le Capteur PIR

- Utilisation d'un capteur de mouvement PIR pour détecter la présence d'un individu.
- Affichage d'alertes ou de notifications sur l'écran LCD en cas de détection.

## Structure du Dépôt

- **/Arduino_scénario**: Contient les programmes Arduino correspondant à chaque scénario.
- **/Proteus_Simulation_**: Comprend les fichiers de simulation Proteus pour une partie du projet.
- **/Diagrams**: Contient des diagrammes pour faciliter la compréhension du code.

## Configuration et Utilisation

1. Connectez le matériel conformément au schéma de câblage fourni dans les diagrammes.
2. Chargez le programme Arduino approprié pour le scénario que vous souhaitez tester.

## Remarques Importantes

- Une partie de la simulation est effectuée sur Proteus, tandis qu'une autre partie utilise du matériel réel.
- Assurez-vous de suivre toutes les précautions de sécurité nécessaires, en particulier lors de l'utilisation de capteurs de gaz.

Explorez et personnalisez le code pour répondre à vos besoins spécifiques en matière de maison intelligente. Bonne exploration !
