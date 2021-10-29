// Arduino->Unityのシリアル通信 + Arduino->HapticDeviceの制御

const int gate_pin = 11;
char data;

void setup() {
  Serial.begin(115200); //シリアル通信開始

  pinMode(gate_pin, OUTPUT); //受信用のpinを準備
}

void loop() {
  // Arduino->Unity: MyoWareの値をUnity側へ送る部分
    int v = analogRead(0); //0pinに来る値を読む(MyoWareの値)
    Serial.println(v);
    delay(100);

  // Arudino->HapticDevice
    if(v >= 500){
      digitalWrite(gate_pin, HIGH);
      delay(500);
      digitalWrite(gate_pin, LOW);
   }else if(v < 500){
      digitalWrite(gate_pin, LOW);
  }
    delay(100);
}
