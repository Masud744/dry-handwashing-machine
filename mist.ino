#define TRIG_PIN 7
#define ECHO_PIN 6
#define RELAY_PIN 8

long duration;
int distance;

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);

  if (duration == 0) {
    Serial.println("Ultrasonic sensor error: No echo received.");
    digitalWrite(RELAY_PIN, LOW);
    delay(100);
    return;
  }

  distance = duration * 0.0344 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance > 0 && distance < 10) {
    digitalWrite(RELAY_PIN, HIGH);
    Serial.println("Object detected! Relay ON.");
    delay(10000);
  } else {
    digitalWrite(RELAY_PIN, LOW);
    Serial.println("No object detected. Relay OFF.");
  }

  delay(200);
}