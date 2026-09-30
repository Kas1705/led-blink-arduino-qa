/*
 * LED_Blink.ino
 * Project : LED Blinking using Arduino (QA-documented via GitHub Issues)
 * Version : 1.1.0
 * Purpose : Blink an LED at a fixed interval and log state changes over Serial.
 *
 * QA Issue Log (see GitHub Issues):
 *   #1 Hard-coded pin number        -> named constant
 *   #2 No debug output              -> Serial logging enabled
 *   #3 Blocking delay() in loop()   -> non-blocking millis() timing
 *   #4 Board-dependent pin 13       -> use LED_BUILTIN when available
 *   #5 Serial not ready on some     -> wait for Serial with timeout
 *      boards (e.g., Leonardo) and magic baud rate -> named constant
 */

// Resolved Issue #4: use the board's built-in LED pin, fall back to 13
#ifdef LED_BUILTIN
const uint8_t LED_PIN = LED_BUILTIN;
#else
const uint8_t LED_PIN = 13;
#endif

// Resolved Issue #1: configuration values as named constants
const unsigned long BLINK_INTERVAL_MS = 500;  // ms between toggles
const unsigned long SERIAL_BAUD       = 9600; // Resolved Issue #5

// Resolved Issue #3: state variables for non-blocking timing
bool ledState = false;
unsigned long previousMillis = 0;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);           // known initial state

  Serial.begin(SERIAL_BAUD);            // Resolved Issue #2: debug output
  while (!Serial && millis() < 2000) {  // Resolved Issue #5: wait max 2 s
    ;                                   // needed for native-USB boards
  }
  Serial.println(F("LED_Blink v1.1.0 started"));
}

void loop() {
  unsigned long currentMillis = millis();

  // Resolved Issue #3: no delay(), so loop() stays free for other tasks
  if (currentMillis - previousMillis >= BLINK_INTERVAL_MS) {
    previousMillis = currentMillis;
    ledState = !ledState;

    digitalWrite(LED_PIN, ledState ? HIGH : LOW);
    Serial.println(ledState ? F("LED: ON") : F("LED: OFF"));
  }

  // Other non-blocking tasks (sensor reads, button checks) can go here.
}