// LED_Blink.ino
const int LED_PIN = 13; // Resolved Issue #1: move LED pin to named constant
const int BLINK_DELAY = 500; // ms
void setup() {
 pinMode(LED_PIN, OUTPUT);
 Serial.begin(9600); // Resolved Issue #2: enable debug output
}
void loop() {
 digitalWrite(LED_PIN, HIGH); // LED ON
 Serial.println("LED: ON");
 delay(BLINK_DELAY);
 digitalWrite(LED_PIN, LOW); // LED OFF
 Serial.println("LED: OFF");
 delay(BLINK_DELAY);
}
