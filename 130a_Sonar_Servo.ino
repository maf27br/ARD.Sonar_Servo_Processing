#include <Servo.h>.

const int trigPin = 6;
const int echoPin = 7;

long tempo;
int distancia;

Servo servo;

void setup() {

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  servo.attach(12);
}

void loop() {

  for (int i = 15; i <= 165; i++) {
    servo.write(i);
    delay(30);
    distancia = calculoDistancia();
    Serial.print(i);
    Serial.print(",");
    Serial.print(distancia);
    Serial.print(".");
  }

  for (int i = 165; i > 15; i--) {
    servo.write(i);
    delay(30);
    distancia = calculoDistancia();
    Serial.print(i);
    Serial.print(",");
    Serial.print(distancia);
    Serial.print(".");
  }
}

int calculoDistancia() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  tempo = pulseIn(echoPin, HIGH);
  distancia = tempo * 0.034 / 2;
  return distancia;
}