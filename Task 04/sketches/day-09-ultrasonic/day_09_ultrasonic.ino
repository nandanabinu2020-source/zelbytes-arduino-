const uint8_t TRIG = 9, ECHO = 10;

float readCmOnce() {
  digitalWrite(TRIG, LOW); delayMicroseconds(2);
  digitalWrite(TRIG, HIGH); delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  unsigned long us = pulseIn(ECHO, HIGH, 30000);
  if (us == 0) return -1.0;
  return (us * 0.0343f) / 2.0f;
}

float readCmFiltered() {
  float a = readCmOnce(), b = readCmOnce(), c = readCmOnce();
  if (a < 0 || b < 0 || c < 0) return -1.0;
  if ((a <= b && b <= c) || (c <= b && b <= a)) return b;
  if ((b <= a && a <= c) || (c <= a && a <= b)) return a;
  return c;
}

void setup() {
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  Serial.begin(9600);
}

void loop() {
  float cm = readCmFiltered();
  Serial.println(cm < 0 ? F("ERR") : String(cm, 1));
  delay(200);
}
