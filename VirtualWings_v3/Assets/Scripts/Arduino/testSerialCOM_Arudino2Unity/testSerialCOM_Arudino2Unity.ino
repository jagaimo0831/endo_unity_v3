// ref1:(Qiita)UnityとArduinoをシリアル通信, https://qiita.com/yjiro0403/items/54e9518b5624c0030531
// ref2:(HatenaBlog)UnityとArduinoを連携してみた, https://rikoubou.hatenablog.com/entry/2018/01/16/175113

// the setup routine runs once when you press reset:
void setup() {
  /* 
   *  initialize serial communication at 115200 bits per second:
   *  bps: 300, 1200, 2400, 4800, 9600, 14400, 19200, 28800, 38400, 57600, 11520
   */
  Serial.begin(115200);
}

// the loop routine runs over and over again forever:
void loop() {

  /*
  //とりあえず固定値をずっと送るやつ
  Serial.println(700);  //Serial.println(val, format)...ASCII形式でデータをシリアルポートへ出力．データの最後の改行が付けられる．
  delay(100);
  */

  //ぐぐぐって送ってちょっと休むやつ
  int time;
  time = 0;
  while(time <= 5){
    Serial.println(600);
    delay(100);
    time = time + 1;
  }
  delay(2000);
  

  
  //時間によって送る値が変わるやつ  
//  int data; //MyoWareの値を想定(0~Vs[V]の間を出力 Vs:供給電圧)
//  data = 0;
//  
//  while(data <= 750){
//    Serial.println(data);
//    delay(100);
//    data = data + 10;
//  }
//
//  delay(100);
//
//  data = 750;
//  while (data >= 150) {
//    Serial.println(data);
//    delay(50);
//    data = data - 5;
//  }
//
//  delay(100);
//  
}
