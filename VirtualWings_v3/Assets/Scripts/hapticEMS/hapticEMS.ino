// 触覚提示：電気(EMS機器)

void setup() {
  // シリアル通信のbps
  Serial.begin(115200);

  // リレーのスイッチ用
  pinMonde(2, OUTPUT);

  // EMS可変抵抗制御用
  pinMode(3, OUTPUT);
}

void loop() {
  // 筋電計測
      // MyoWareの値を読む
      int EMG = analogRead(A0);
      
      // 読み取った値をUnityへ送信(シリアル通信)
      Serial.println(EMG);
      delay(100);

  // 触覚提示
      // スイッチON(リレーのスイッチング)
      digitalWrite(2, HIGH);
      delay(100); 
      
      // EMS制御
      /*
       * 筋電値(EMG)に応じた(比例した)値の触覚を出力
       * EMSはMyoWare計測時にOFFにしておく必要あり
       */
      int strength; // 0~5V=0~204, 0~3V=0~204

      anlogWrite(3, 204);
      strength = 0;
      while ( strength <= 204 ) {
          analogWrite(pin, strength );
          delay(100);
          strength = strength + 5;
      }
    
      delay(500);
    
      strength = 204;
      while (strength >= 0) {
        analogWrite(pin, strength);
        delay(100);
        strength = strength - 5;
      }
    
      delay(500);

      // スイッチOFF(リレースイッチング)
      digitalWrite(2, LOW);
      delay(100);  
      
}
