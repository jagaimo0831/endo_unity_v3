#define gate_pin 11 //13は内臓のLED
char data;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(gate_pin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  /*//test
  digitalWrite(gate_pin, HIGH);
  delay(5000);
  digitalWrite(gate_pin, LOW);
*/
  
  if(Serial.available() > 0){ //受信データがあるか
    data = Serial.read();
    if(data == 0x31){ //文字コード0x31, つまり"1"を受信したらLEDを光らせる
      digitalWrite(gate_pin, HIGH);
      delay(1000);
      digitalWrite(gate_pin, LOW);
      delay(1000);
    }
  }
  
}
