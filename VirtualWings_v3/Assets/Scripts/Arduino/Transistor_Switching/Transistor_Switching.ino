const int gate_pin = 11;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(gate_pin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("HIGH");
  digitalWrite(gate_pin, HIGH);
  delay(3000);

  Serial.println("LOW");
  digitalWrite(gate_pin, LOW);
  delay(3000);
}
