#include <Servo.h>

// -------- PIN DEFINITIONS --------
#define FLAME_SENSOR 2

// Motor Driver
#define IN1 5
#define IN2 6
#define IN3 9
#define IN4 10
#define ENA 3
#define ENB 11

// Relay + Pump
#define RELAY_PIN 8

// Servo
#define SERVO_PIN 7

Servo nozzleServo;
int motorSpeed = 150;

void setup() {
  pinMode(FLAME_SENSOR, INPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH); // Pump OFF

  nozzleServo.attach(SERVO_PIN);
  nozzleServo.write(90); // Center position

  Serial.begin(9600);
  Serial.println("🔥 Fire Fighting Robot Initialized");
}

void loop() {
  int flame = digitalRead(FLAME_SENSOR);

  if (flame == LOW) {
    stopRobot();
    delay(300);

    digitalWrite(RELAY_PIN, LOW); // Pump ON
    Serial.println("🚿 Pump ON");

    spraySweep();   
    digitalWrite(RELAY_PIN, HIGH); // Pump OFF
    Serial.println("✅ Fire Extinguished");

    delay(2000);
  } 
  else {
    moveForward();
  }
}

// -------- FUNCTIONS --------

void spraySweep() {
  // Left
  nozzleServo.write(30);
  delay(800);

  // Center
  nozzleServo.write(90);
  delay(800);

  // Right
  nozzleServo.write(150);
  delay(800);

  // Back to center
  nozzleServo.write(90);
}

void moveForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  analogWrite(ENA, motorSpeed);
  analogWrite(ENB, motorSpeed);
}

void stopRobot() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}
