
//------------------------------------------
//     Scénaio 2 réalisé sous protéus
//------------------------------------------

//Ouverture de porte et detection d'obscurité
#include <Keypad.h>
#include <LiquidCrystal.h>

// Capteur LDR
const int ldrPin = A3;
const int ledGreenPin = 36;  // Nouvelle broche pour la LED Green
int seuilLuminosite = 10;

const int relayPin = A0;         // Broche de contrôle du relais
const int ledActivePin = 37;     // Broche pour la LED lors de l'activation du relais
const int ledInactivePin = 38;   // Broche pour la LED lors de la désactivation du relais
const char passcode[] = "1";     // Code d'accès pour ouvrir la porte

const int ROW_NUM    = 4; // Quatre lignes
const int COLUMN_NUM = 4; // Quatre colonnes

char keys[ROW_NUM][COLUMN_NUM] = {
  {'7','8','9','A'},
  {'4','5','6','X'},
  {'1','2','3','-'},
  {'C','0','=','+'}
};

byte pin_rows[ROW_NUM] = {29, 28, 27, 26}; // Les broches pour les lignes (Keypad)
byte pin_column[COLUMN_NUM] = {25, 24, 23, 22}; // Les broches pour les colonnes (Keypad)

Keypad keypad = Keypad(makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM);

LiquidCrystal lcd(30, 31, 32, 33, 34, 35);  // Broches RS, E, D4, D5, D6, D7 pour le LCD

bool isLocked = true;
static char enteredPasscode[2];  // Augmenté la taille pour prendre en compte le mot de passe "1"
static int currentIndex = 0;

// Déclaration des fonctions
void setup();
void loop();
void handleKeypadInput(char key);
void checkPasscode(char key);
void unlockDoor();
void resetDoor();
void closeDoor();
void blinkLED(int pin);
void ldrLED();
void requestPasscode();

void setup() {
  pinMode(relayPin, OUTPUT);       // Configuration de la broche du relais en sortie
  pinMode(ledActivePin, OUTPUT);   // Configuration de la broche de la LED lors de l'activation du relais en sortie
  pinMode(ledInactivePin, OUTPUT); // Configuration de la broche de la LED lors de la désactivation du relais en sortie
  pinMode(ledGreenPin, OUTPUT);    // Configuration de la broche de la LED Green en sortie

  lcd.begin(16, 2);                // Initialisation de l'afficheur LCD
  lcd.print("Bienvenue!");

  Serial.begin(9600);
}

void loop() {
  // LED et Capteur LDR
  ldrLED();

  // Keypad_Porte
  char key = keypad.getKey();

  if (key) {
    handleKeypadInput(key);
  }
}

void handleKeypadInput(char key) {
  if (key == 'C') {
    resetDoor();
  } else if (key == 'X') {
    closeDoor();
  } else {
    if (isLocked) {
      checkPasscode(key);
    } else {
      lcd.clear();
      lcd.print("Porte déjà déverrouillée");
      delay(2000);
      lcd.clear();
      lcd.print("Bienvenue!");
      isLocked = true;
    }
  }
}

void checkPasscode(char key) {
  lcd.clear();
  lcd.print("Entrez le code :");

  if (key == '=') {
    enteredPasscode[currentIndex] = '\0';  // Ajouter un caractère de fin de chaîne
    currentIndex = 0;

    if (strcmp(enteredPasscode, passcode) == 0) {
      lcd.clear();
      lcd.print("Code correct!");
      Serial.println("Code correct ! Ouverture de la porte.");
      unlockDoor();
    } else {
      lcd.clear();
      lcd.print("Code incorrect!");
      Serial.println("Code incorrect. Réessayez.");
      delay(2000);
      lcd.clear();
      lcd.print("Bienvenue!");
      requestPasscode();  // Demander à nouveau le mot de passe
    }
  } else {
    // Afficher le caractère entré sur l'écran sous forme d'astérisque
    lcd.setCursor(currentIndex, 1);
    lcd.print('*');
    
    enteredPasscode[currentIndex] = key;
    currentIndex++;

    // Limiter la longueur du code à 1 caractère
    if (currentIndex > 1) {
      currentIndex = 1;
    }
  }
}

void unlockDoor() {
  lcd.clear();
  lcd.print("Porte déverrouillée");
  digitalWrite(relayPin, HIGH);  // Activer le relais pour simuler l'ouverture du portail
  blinkLED(ledActivePin);        // Faire clignoter la LED d'activation
  delay(200);
  lcd.clear();
  lcd.print("Bienvenue!");
  Serial.println("Porte déverrouillée.");
  isLocked = false;
}

void resetDoor() {
  lcd.clear();
  lcd.print("Réinitialisation...");
  digitalWrite(relayPin, LOW);  // Activer le relais pour simuler l'ouverture du portail
  blinkLED(ledInactivePin); 
  delay(200);
  lcd.clear();
  lcd.print("Entrez le code :");
  requestPasscode();  // Demander à nouveau le mot de passe
  isLocked = true;
}

void closeDoor() {
  lcd.clear();
  lcd.print("Fermeture de la porte...");
  digitalWrite(relayPin, LOW);   // Désactiver le relais pour simuler la fermeture du portail
  blinkLED(ledInactivePin);      // Faire clignoter la LED de désactivation
  delay(200);
  lcd.clear();
  lcd.print("Bienvenue!");
  Serial.println("Fermeture de la porte...");
}

void blinkLED(int pin) {
  for (int i = 0; i < 6; i++) {  // Clignoter la LED trois fois
    digitalWrite(pin, HIGH);
    delay(500);
    digitalWrite(pin, LOW);
    delay(300);
  }
}

void ldrLED() {
  int luminosite = analogRead(ldrPin);

  Serial.print("Luminosité: ");
  Serial.println(luminosite);

  if (luminosite <= seuilLuminosite) {
    digitalWrite(ledGreenPin, HIGH);  // Allumer la LED Green en cas d'obscurité
    Serial.println("Obscurité détectée. LED Green allumée.");
  } else {
    digitalWrite(ledGreenPin, LOW);   // Éteindre la LED Green en cas de luminosité normale
    Serial.println("Luminosité normale. LED Green éteinte.");
  }
  delay(1000);  // Attendez une seconde avant la prochaine lecture
}

void requestPasscode() {
  lcd.clear();
  lcd.print("Entrez le code :");
}

//--------------------------------------------------------

// Détection de gaz

#include <LiquidCrystal.h>

const int mq2Pin = 29;         // Broche analogique du capteur MQ-2

LiquidCrystal lcd(23, 24, 25, 26, 27, 28);  // Broches RS, E, D4, D5, D6, D7 pour le LCD

void setup() {
  pinMode(mq2Pin, INPUT);
  
  Serial.begin(9600);
  
  // Initialisation de l'afficheur LCD
  lcd.begin(16, 2);
  lcd.print("Système de Gaz");
  delay(200);
  lcd.clear();
}

void loop() {
  checkMQ2();
  delay(1000);
}

void checkMQ2() {
  int gasValue = digitalRead(mq2Pin);

  if (gasValue == HIGH) {
       displayStatus("Gaz detecte ");
    
  } else {
       displayStatus("Gaz Non detecte ");
    
  }
}

void displayStatus(const char *message) {
  lcd.clear();
  lcd.print(message);
  Serial.println(message);
}

//---------------------------------------------------

