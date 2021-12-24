// 触覚提示：振動(偏心モータ)
const int IN1 = 5;
const int IN2 = 6;
const int ST = 3;


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
      //analogWrite( IN1, 255 );
      //analogWrite( IN2, 0 );
      //analogWrite( ST, 255 ); //強さ?

      
      
      if(EMG <= 100){
          analogWrite( IN1, 255 );
          analogWrite( IN2, 0 );
          analogWrite( ST, 0 );
      } else if((EMG>100) && (EMG<=275)){
          analogWrite( IN1, 255 );
          analogWrite( IN2, 0 );
          analogWrite( ST, 60 );
          
          //analogWrite( ST, 100 );
      } else if((EMG>275) && (EMG<=450)){
          analogWrite( IN1, 255 );
          analogWrite( IN2, 0 );
          //analogWrite( ST, 100);
          
          analogWrite( ST, 180 );
      } else if((EMG>450) && (EMG<=625)){
          analogWrite( IN1, 255 );
          analogWrite( IN2, 0 );
          //analogWrite( ST, 150 );
          
          analogWrite( ST, 255 );
      } else if((EMG>625) && (EMG<=800)){
          analogWrite( IN1, 255 );
          analogWrite( IN2, 0 );
          //analogWrite( ST, 200 );
          
          analogWrite( ST, 255 );
      } else if((EMG>800) && (EMG<=1024)){
          analogWrite( IN1, 255 );
          analogWrite( IN2, 0 );
          analogWrite( ST, 255 );
      }
}
