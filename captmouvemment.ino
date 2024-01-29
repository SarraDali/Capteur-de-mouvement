const int capm = 12;  
const int but = 4;            
const int led = 13;              

// Variables
int etatPrecedent = LOW;  
int etatActuel = LOW;     
int etatLED = LOW;        

void setup() {
  pinMode(capm, INPUT);  
  pinMode(but, INPUT);     
  pinMode(led, OUTPUT);    
  
  Serial.begin(9600);  
}

void loop() {
  
  int etatCapteur = digitalRead(capm);
  
  
  
  etatActuel = digitalRead(but);
  
  if (etatCapteur == HIGH) {
    Serial.println("Mouvement détecté !");
    etatLED = HIGH;
    delay(5000);
     
  if (etatActuel == LOW && etatPrecedent == HIGH) {
    Serial.println("Bouton pressé !");
    etatLED = !etatLED;  
  }
  } else {
    etatLED = LOW;
  }
  
 
  
  
  digitalWrite(led, etatLED);
  
  
  etatPrecedent = etatActuel;
  
  delay(100);}  
