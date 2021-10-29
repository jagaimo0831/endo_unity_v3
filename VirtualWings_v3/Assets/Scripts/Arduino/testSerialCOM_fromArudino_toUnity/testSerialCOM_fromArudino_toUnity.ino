// 参考: https://qiita.com/yjiro0403/items/54e9518b5624c0030531
// ref2: https://rikoubou.hatenablog.com/entry/2018/01/16/175113

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(115200);
}

// the loop routine runs over and over again forever:
void loop() {
  //int v = analogRead(0); //0pinに来る値を読む(MyoWareの値)
  Serial.println(700);
  delay(100);
 
 
}
