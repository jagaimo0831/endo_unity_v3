/*
 * 使用パーツ
 * - モータドライバ: TOSHIBA TA8429HQ, https://toshiba.semicon-storage.com/jp/semiconductor/product/motor-driver-ics/brushed-dc-motor-driver-ics/detail.TA8429HQ.html
 * - DCモータ(ブラシ付きモータ): PS4用振動モータ(左右), https://www.amazon.co.jp/KESOTO-PS4%E3%82%B3%E3%83%B3%E3%83%88%E3%83%AD%E3%83%BC%E3%83%A9%E7%94%A8-%E5%B7%A6-%E6%8C%AF%E5%8B%95%E3%83%A2%E3%83%BC%E3%82%BF%E3%83%BC-3D%E3%83%A9%E3%83%B3%E3%83%96%E3%83%AB%E3%83%A2%E3%83%BC%E3%82%BF-%E4%BA%A4%E6%8F%9B%E9%83%A8%E5%93%81/dp/B07KDV8HGT
 * - モータ用電源: UNIFIVE Model No:US300620, https://jp.rs-online.com/web/p/ac-dc-adapters/5248780
 * - ブレッドボード用電源モジュール: MB102, https://ht-deko.com/arduino/breadboard_power.html
 */

// 参考 Arduino電子工作の基本⑤ モータを動かす, https://deviceplus.jp/hobby/arduino_f05/

const int IN1 = 5;
const int IN2 = 6;
const int ST = 3;

void setup() {
  pinMode( IN1, OUTPUT );
  pinMode( IN2, OUTPUT );
  pinMode( ST, OUTPUT );
}

void loop() {
  // とりあえず正転
  analogWrite( IN1, 255 );
  analogWrite( IN2, 0 );
  analogWrite( ST, 255 );

  
  // 停止状態から，モータの速度が徐々に速くなり，最大に達したら徐々に遅くなり，停止するプログラム
  /*
  int speed;
  
  analogWrite( IN1, 255 );
  analogWrite( IN2, 255 );

  speed = 0;
  while( speed <= 255 ){
      analogWrite( ST, speed );
      delay(100);
      speed = speed + 5;
  }

  delay(5000);

  speed = 255;
  while(speed >= 0){
      analogWrite(ST, speed);
      delay(100);
      speed = speed - 5;
  }
  
  delay(5000);
  */
}
