const int photoResistorPin = A0;
const int ledPin = 10;
int lightAmount = 0;
int threshold = 25;

unsigned previousMs = 0;
const long intreval = 250;

void setup() {
  Serial.begin(9600);
  pinMode(10, OUTPUT);
};

void loop() {
  unsigned long currentMs = millis();
  lightAmount = analogRead(photoResistorPin);
  
  if (currentMs - previousMs >= intreval) {
    previousMs = currentMs;
    Serial.print("Light Intesity: ");
    Serial.println(lightAmount);
  }


  if (lightAmount < threshold) {
    digitalWrite(10, HIGH);
    
  } else {
      digitalWrite(10, LOW);
    }

  delay(250);
}

