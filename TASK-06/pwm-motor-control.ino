const int PWM_PIN = 9;
const int RELAY_PIN = 8;   // active relay, pull-up logic -> LOW = energized/open valve
const int LED_PIN = 7;
const int ESTOP_PIN = 2;   // INT0, pull-up mode

volatile bool eStop = false;
int motorSpeed = 0;

void setup() {
  pinMode(PWM_PIN, OUTPUT);
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(ESTOP_PIN, INPUT_PULLUP);

  digitalWrite(RELAY_PIN, LOW);  // valve open (active LOW relay)
  digitalWrite(LED_PIN, LOW);

  analogWrite(PWM_PIN, 0);

  attachInterrupt(digitalPinToInterrupt(ESTOP_PIN), estopISR, FALLING);

  Serial.begin(9600);
  Serial.println("Send speed 0-255");
}

void estopISR() {
  eStop = true;
}

void loop() {
  if (eStop) {
    analogWrite(PWM_PIN, 0);          // stop motor
    digitalWrite(RELAY_PIN, HIGH);    // close valve (de-energize, active LOW relay)
    digitalWrite(LED_PIN, HIGH);      // E-stop indicator ON
    Serial.println("E-STOP TRIGGERED. Reset to continue.");

    // latch until button released and re-armed via serial
    while (digitalRead(ESTOP_PIN) == LOW) { } // wait for release
    if (Serial.available() && Serial.read() == 'r') {
      digitalWrite(RELAY_PIN, LOW);   // reopen valve
      digitalWrite(LED_PIN, LOW);
      eStop = false;
    }
    return;
  }

  if (Serial.available() > 0) {
    int val = Serial.parseInt();
    if (val >= 0 && val <= 255) {
      motorSpeed = val;
      analogWrite(PWM_PIN, motorSpeed);
      Serial.print("Speed set to: ");
      Serial.println(motorSpeed);
    }
  }
}
