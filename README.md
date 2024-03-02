# Projet Systèmes Embarqués Smart Home Domotique

Ce projet de systèmes embarqués utilise la carte Arduino Mega 2560 pour créer un système domotique intelligent pour une maison connectée. Les principales fonctionnalités de ce smart home incluent :

## Fonctionnalités

### 1. Ouverture de Portail par Mot de Passe

- Utilisation d'un écran LCD pour l'affichage d'informations.
- Intégration d'un clavier (keypad) pour la saisie du mot de passe.
- Contrôle d'un relais pour l'ouverture/fermeture du portail.
- Leds indicatrices pour signaler l'état du portail (ouvert/fermé).

### 2. Allumage de la Lampe Maison à la Détection d'Obscurité

- Utilisation d'une LED comme source lumineuse de la lampe maison.
- Intégration d'un capteur de lumière (LDR) pour détecter l'obscurité.
- Affichage des informations sur l'état de la lumière sur l'écran LCD.

### 3. Détection de Gaz avec le Capteur MQ2

- Intégration d'un capteur de gaz MQ2 pour la détection de gaz.
- Réponse appropriée en cas de détection de gaz dangereux.
- Affichage des alertes sur l'écran LCD.

## Matériel Requis

- Carte Arduino Mega 2560
- Écran LCD
- Clavier (Keypad)
- Relais
- LEDs indicatrices
- LED pour la lampe maison
- Capteur de lumière (LDR)
- Capteur de gaz MQ2

## Configuration

1. Connectez le matériel conformément au schéma de câblage fourni dans le dossier "schema_cablage".
2. Chargez le code Arduino "code_arduino.ino" dans la carte Arduino Mega 2560.

## Utilisation

1. Pour l'ouverture du portail, entrez le mot de passe via le clavier.
2. La lampe maison s'allume automatiquement en cas d'obscurité.
3. En cas de détection de gaz, le système affiche une alerte sur l'écran LCD.

## Remarque Importante

Ce projet est destiné à des fins éducatives et expérimentales. Assurez-vous de prendre toutes les précautions nécessaires lors de l'utilisation de capteurs de gaz. Suivez les lois et les réglementations locales liées à la sécurité des systèmes domotiques.

N'hésitez pas à explorer et à personnaliser le code pour répondre à vos besoins spécifiques de maison intelligente. Bonne exploration !
