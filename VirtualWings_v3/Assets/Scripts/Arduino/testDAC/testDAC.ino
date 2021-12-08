const int pin = 3;

void setup() {
  // put your setup code here, to run once:
  pinMode(pin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // 提示強さを1つ指定
  //analogWrite(pin, 1);


  // 停止状態から，徐々に強くなり，最大に達したら徐々に弱くなり，停止するプログラム
  
  int strength; // 0~5V=0~255, 0~3V=0~153
  
  analogWrite(pin,153);

  strength = 0;
  while( strength <= 153 ){
      analogWrite(pin, strength );
      delay(100);
      strength = strength + 5;
  }

  delay(500);

  strength = 153;
  while(strength >= 0){
      analogWrite(pin, strength);
      delay(100);
      strength = strength - 5;
  }
  
  delay(500);
  
}
