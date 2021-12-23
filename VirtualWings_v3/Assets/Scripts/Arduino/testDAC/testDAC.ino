const int pin = 3;

void setup() {
  // put your setup code here, to run once:
  pinMode(pin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // 提示強さを1つ指定
  //analogWrite(pin, 80);


  // 停止状態から，徐々に強くなり，最大に達したら徐々に弱くなり，停止するプログラム
  
  int strength; // 0~5V=0~204, 0~3V=0~204?

  analogWrite(pin, 204);

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

  
}
