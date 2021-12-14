// Arduino(MyoWare)->Unity(WingsMovement)->Arduino(HapticFeedback)
// ※一度Unityを経由してのシステム(UnityとArudinoの相互通信プログラム(未完))

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

  // Unity->Arduino: Unity側から来たシリアルを処理する部分
  if(Serial.available() > 0){ //受信データがあるかどうか
    data = Serial.read();
    if(data == 0x31){ //文字コード0x31, つまり"1"を受信したらif文内を実行する
       
      digitalWrite(gate_pin, HIGH);
      delay(800);
      digitalWrite(gate_pin, LOW);
   }
   delay(1000);
  }
}
