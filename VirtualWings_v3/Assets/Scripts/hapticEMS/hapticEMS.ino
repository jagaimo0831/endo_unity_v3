// 触覚提示：電気(EMG機器)

void setup() {
  // シリアル通信のbps
  Serial.begin(115200);

  // リレーのスイッチ用
  pinMode(2, OUTPUT);

  // EMG可変抵抗制御用
  pinMode(3, OUTPUT);
}

void loop() {
  // 筋電計測
      // MyoWareの値を読む
      int EMG = analogRead(A0);
      
      // 読み取った値をUnityへ送信(シリアル通信)
      Serial.println(EMG);
      delay(200);

  // 触覚提示
      // スイッチON(リレーのスイッチング)
      digitalWrite(2, HIGH);
      delay(50); 
      
      // EMG制御
      /*
       * 筋電値(EMG)に応じた(比例した)値の触覚を出力
       * EMGはMyoWare計測時にOFFにしておく必要あり
       */
      int strength; // EMG:0~3V→提示:0~153(153がちょうどよい力加減?), (255/5V=51/V)

      if(EMG <= 100){
          analogWrite(3, 0);
      } else if((EMG>100) && (EMG<=150)){ 
          analogWrite(3, 0);
      } else if ((EMG>150) && (EMG<=275)){
          analogWrite(3, 5);
//    } else if((EMG>100) && (EMG<=275)){
//          analogWrite(3, 5);
      } else if((EMG>275) && (EMG<=450)){
          analogWrite(3, 10);
      } else if((EMG>450) && (EMG<=625)){
          analogWrite(3, 15);
      } else if((EMG>625) && (EMG<=800)){
          analogWrite(3, 20);
      } else if((EMG>800) && (EMG<=1024)){
          analogWrite(3, 25);
      }
      delay(3000);


      /* 段々強く，段々弱くのコード
      analogWrite(3, 153);
      strength = 0;
      while ( strength <= 153 ) {
          analogWrite(3, strength );
          delay(100);
          strength = strength + 5;
      }
    
      delay(500);
    
      strength = 153;
      while (strength >= 0) {
        analogWrite(3, strength);
        delay(100);
        strength = strength - 5;
      }
    
      delay(500);
      */

      // スイッチOFF(リレースイッチング)
      analogWrite(3, 0);
      digitalWrite(2, LOW);
      delay(3000);  
      
}
