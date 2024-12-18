const int PLS = 34;
const int IN1 = 33;
const int IN2 = 32;


void setup() {
  pinMode(PLS, OUTPUT);  // 34番ピンをOUTPUTに指定
  pinMode(IN1, OUTPUT);  // 33番ピンをOUTPUTに指定
  pinMode(IN2, OUTPUT);  // 32番ピンをOUTPUTに指定
}

void loop() {
  digitalWrite(PLS, HIGH);
  int wait = 220;
  while (1) {
    ExchageTone(195,wait);
    ExchageTone(220,wait);
    ExchageTone(246,wait);
    ExchageTone(261,wait);
    ExchageTone(293,wait);
    ExchageTone(329,wait);
    ExchageTone(349,wait);
    ExchageTone(391,wait); 
//    ExchageTone(261,1000);
//    ExchageTone(293,1000);
//    ExchageTone(329,1000);
//    ExchageTone(349,1000);
//    ExchageTone(391,1000);
//    ExchageTone(440,1000);
//    ExchageTone(493,1000);
//    ExchageTone(523,1000);
    delay(3000);
  }
  /*digitalWrite(LED, HIGH);  // LED ON
    delay(1);
    digitalWrite(LED, LOW);  // LED OFF
    delay(1);*/
}

void ExchangeC4()
{
  for (int i = 0; i < 261; i++) {
    digitalWrite(IN1, HIGH);  // IN1 OFF
    digitalWrite(IN2, LOW);  // IN2 ON
    delayMicroseconds(1909);
    digitalWrite(IN1, LOW);  // IN1 OFF
    digitalWrite(IN2, HIGH);  // IN2 ON
    delayMicroseconds(1909);
  }
}

void ExchageTone(int hertz, int Milliseconds){
  unsigned long long hz = 1000000/hertz/2;
  unsigned long long int i=0;
  unsigned long long int microsecond=Milliseconds*1000;
  
  while(i < microsecond){
    digitalWrite(IN1, HIGH);  // IN1 OFF
    digitalWrite(IN2, LOW);  // IN2 ON
    delayMicroseconds(hz);
    digitalWrite(IN1, LOW);  // IN1 OFF
    digitalWrite(IN2, HIGH);  // IN2 ON
    delayMicroseconds(hz);
    i+=hz;
    }
    digitalWrite(IN1, LOW);  // IN1 OFF
    digitalWrite(IN2, LOW);  // IN2 OFF
  }
void tonedo()
{
  tone(IN2, 261);
  delay(1000);
  noTone(IN2);
  delay(1000);
}
