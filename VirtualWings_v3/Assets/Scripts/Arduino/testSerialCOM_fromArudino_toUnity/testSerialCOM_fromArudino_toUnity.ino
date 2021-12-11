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
  //int v = analogRead(0); //0pinに来る値を読む(MyoWareの値)
  /*
   *  Serial.println(val, format)...ASCII形式でデータをシリアルポートへ出力．データの最後の改行が付けられる．
   */
  Serial.println(700);  
  delay(100);
 
 
}
