#define DEBUG

const int LED_PIN = LED_BUILTIN;

void setup() {
  pinMode(LED_PIN, OUTPUT);

  Serial.begin(115200);

#ifdef DEBUG
  Serial.println(F("=== Debug Console Started ==="));
  Serial.println(F("Type ? for help"));
#endif
}

void loop() {

#ifdef DEBUG
  static unsigned long lastPrint = 0;

  if (millis() - lastPrint > 2000) {
    lastPrint = millis();

    Serial.print(F("Uptime(ms): "));
    Serial.println(millis());
  }
#endif

  if (Serial.available()) {

    char cmd = Serial.read();

    switch(cmd) {

      case '?':
        Serial.println(F("Commands:"));
        Serial.println(F("? - Help"));
        Serial.println(F("l - LED ON"));
        Serial.println(F("o - LED OFF"));
        break;

      case 'l':
        digitalWrite(LED_PIN, HIGH);
        Serial.println(F("LED ON"));
        break;

      case 'o':
        digitalWrite(LED_PIN, LOW);
        Serial.println(F("LED OFF"));
        break;

      default:
        Serial.println(F("Unknown Command"));
        break;
    }
  }
}
