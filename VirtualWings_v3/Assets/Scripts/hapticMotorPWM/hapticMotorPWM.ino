// 触覚提示：振動(偏心モータ)

void setup() {
  // シリアル通信のbps
  Serial.begin(115200);

  // モータ用
  pinMode( IN1, OUTPUT );
  pinMode( IN2, OUTPUT );
  pinMode( ST, OUTPUT );
}

void loop() {
  // 筋電計測
      // MyoWareの値を読む
      int EMG = analogRead(A0);
      
      // 読み取った値をUnityへ送信(シリアル通信)
      Serial.println(EMG);
      delay(100);

  // 触覚提示
       /*
       * 筋電値(EMG)に応じた(比例した)値の触覚を出力
       * 振動に関しては計測と提示をごちゃっても良い
       */

      // とりあえず正転
      analogWrite( IN1, 255 );
      analogWrite( IN2, 0 );
      analogWrite( ST, 255 );
}
