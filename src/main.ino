#include <Servo.h>

const int trigPin = 9;
const int echoPin = 10;

const int motor1Pin1 = 2;
const int motor1Pin2 = 3;
const int motor2Pin1 = 4;
const int motor2Pin2 = 5;
const int enable1Pin = 6;
const int enable2Pin = 7;

const int servoPin = 8;

const int distanceThreshold = 20;

const int smokeSensorPin = A0;
const int relayPin = 11;

const int smokeThreshold = 300;

Servo myServo;

void setup() {
  Serial.begin(9600);

  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  pinMode(enable1Pin, OUTPUT);
  pinMode(enable2Pin, OUTPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  myServo.attach(servoPin);
  myServo.write(90); // Set servo to face forward

  pinMode(smokeSensorPin, INPUT);

  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW); // Turn off the motor pump initially
}

void loop() {
  // Obstacle avoiding logic
  int distance = getDistance();

  if (distance < distanceThreshold) {
    stopCar();
    myServo.write(0); // Look left
    delay(500);
    int distanceLeft = getDistance();
    myServo.write(180); // Look right
    delay(500);
    int distanceRight = getDistance();
    myServo.write(90); // Face forward

    if (distanceLeft > distanceRight) {
      turnLeft();
    } else {
      turnRight();
    }
  } else {
    moveForward();
  }

  int smokeLevel = analogRead(smokeSensorPin);
  Serial.println(smokeLevel);

  if (smokeLevel > smokeThreshold) {
    digitalWrite(relayPin, HIGH); // Turn on the motor pump
  } else {
    digitalWrite(relayPin, LOW); // Turn off the motor pump
  }

  delay(100);
}

int getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2;

  return distance;
}

void moveForward() {
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
  analogWrite(enable1Pin, 255);
  analogWrite(enable2Pin, 255);
}

void turnLeft() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
  analogWrite(enable1Pin, 255);
  analogWrite(enable2Pin, 255);
}

void turnRight() {
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);
  analogWrite(enable1Pin, 255);
  analogWrite(enable2Pin, 255);
}

void stopCar() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
}
