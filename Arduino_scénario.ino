//---------------------------------------------
//   Scénaio 1 réalisé avec le vrai matériel
//---------------------------------------------
#include <Servo.h>
//On déclare les variables

// Bouton poussoir
const int BP = 22;    // Connecté à la broche 22
const int led = 24;   // Connecté à la broche 24
int etatBP;            // Variable pour mémoriser l'état du bouton poussoir
bool ventilateurActif = false;  // Variable pour suivre l'état du ventilateur


//Vantilateur
int INA = 9;
int INB = 10;

//LDR_LED
const int ldrPin = A0;    // Broche analogique pour le capteur LDR
const int ledPin = 24;    // Broche numérique pour la LED
int seuilLuminosite = 500; // Ajustez cette valeur selon vos besoins

//servo Porte  avec PIR
const int pirPin = 26;    // Broche du capteur PIR
const int servoPin = 28;   // Broche du servo moteur
Servo monServo;  // Création d'une instance de la classe Servo
int etatPIR = 0;
int etatPrecedent = 0;
int positionServo = 0;  // Position du servo moteur
int delaiRetour = 2000;
int etatPorte = 0;


void setup() {
  // BP LED
  pinMode(BP,INPUT); //Initialisation Broche 4 en Entré
  pinMode(led,OUTPUT); //Initialisation Broche 4 en Entré
  etatBP=LOW; //Initialiser en Etat relaché
  Serial.begin(9600); //Ouvrir le port série à 9600 bauds
  //BP_Ventilateur
   pinMode(BP, INPUT_PULLUP); // Utilise la résistance de tirage interne pour le bouton
  //Vantilateur
  pinMode(INA, OUTPUT);
  pinMode(INB, OUTPUT);

  //LDR-LED
  pinMode(ledPin, OUTPUT);

  //Servo Porte  avec PIR
  pinMode(pirPin, INPUT);
  monServo.attach(servoPin);

  // Position initiale du servo
  monServo.write(positionServo);
  
}

void loop() {
  ldrLED();
//BP_Ventilateur
 etatBP = digitalRead(BP); // Lire l'état du bouton poussoir

  // Si le bouton est appuyé et que le ventilateur n'est pas encore actif, démarrer le ventilateur
  if (etatBP == LOW && !ventilateurActif) {
    digitalWrite(INA, HIGH);
    digitalWrite(INB, LOW);
    digitalWrite(led, HIGH);
    ventilateurActif = true;
    delay(50); // Temporisation pour éviter les rebonds du bouton
  }
  // Si le bouton est relâché et que le ventilateur est actif, ne rien faire (laisser le ventilateur en marche)
  // jusqu'à ce que le bouton soit appuyé à nouveau pour l'arrêter
  else if (etatBP == HIGH && ventilateurActif) {
    // Ne rien faire, laissez le ventilateur en marche
  }
// Si le bouton est appuyé et que le ventilateur est déjà actif, éteindre le ventilateur
  else if (etatBP == LOW && ventilateurActif) {
    digitalWrite(INA, LOW);
    digitalWrite(INB, LOW);
    digitalWrite(led, LOW);
    ventilateurActif = false;
    delay(200); // Temporisation pour éviter les rebonds du bouton
  }

  etatBP=digitalRead(BP); //Mémorisation de l'etat du bouton
//test si niveau logique bas
  
  etatPorte = !etatPorte;
  if (etatPorte == 1) {
      portDetect();
      delay(2000);
    } else {
      {
        portDetect();
    }
  }
}

void ldrLED(){
  int luminosite = analogRead(ldrPin);

  Serial.print("Luminosité: ");
  Serial.println(luminosite);

  if (luminosite < seuilLuminosite) {
    digitalWrite(ledPin, HIGH);
    Serial.println("Obscurité détectée. LED allumée.");
  } else {
    digitalWrite(ledPin, LOW);
    Serial.println("Luminosité normale. LED éteinte.");
  }
  delay(1000);  // Attendez une seconde avant la prochaine lecture
}
void ventilateur(){
  // Tourne dans un seul sens
  analogWrite(INA, 100);
  digitalWrite(INB, LOW);
  delay(5000);
  // Arrêt
  digitalWrite(INA, LOW);
  digitalWrite(INB, LOW);
  delay(200);
}


void portDetect(){
  // Lecture de l'état du capteur PIR
  etatPIR = digitalRead(pirPin);

  // Vérification si le bouton a été appuyé
  if (etatPIR == HIGH && etatPrecedent == LOW) {
    // Inversion de la position du servo
    positionServo = 180 - positionServo;
    monServo.write(positionServo);
     delay(delaiRetour);
    monServo.write(positionServo);
  }
  // Mise à jour de l'état précédent du bouton
  etatPrecedent = etatPIR;
  // Attente pour éviter les rebonds du bouton
  delay(50);
}

//------------------------------------------
//           Fin du scénario 1  
//------------------------------------------
