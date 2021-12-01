const int GATE_PIN = 11;
//const int LED_PIN = 13;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(GATE_PIN, OUTPUT);
  //pinMonde(LED_PIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("HIGH");
  digitalWrite(GATE_PIN, HIGH);
  //digitalWrite(LED_PIN, HIGH);
  delay(3000);

  Serial.println("LOW");
  digitalWrite(GATE_PIN, LOW);
  //digitalWrite(LED_PIN, LOW);
  delay(3000);
}
