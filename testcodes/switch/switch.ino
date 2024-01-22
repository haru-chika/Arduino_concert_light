const int RPIN = 2;
const int GPIN = 4;
const int BPIN = 7;

int mode = 0;
volatile int swFLG = 0;

void setup() {
  pinMode(RPIN, OUTPUT);
  pinMode(GPIN, OUTPUT);
  pinMode(BPIN, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(9), swA, FALLING);
  Serial.begin(9600);
}

void loop() {
  if (swFLG) {
    noInterrupts();  // 割り込みを一時的に無効化
    swFLG = 0;        // フラグをクリア
    interrupts();     // 割り込みを再度有効化

    mode++;
    if (mode >= 2)
      mode = 0;

    delay(500);
  }

  if (mode == 0) {
    for (int i = 0; i < 128; i++) {
      analogWrite(RPIN, i);
      analogWrite(GPIN, i);
      analogWrite(BPIN, i);
      delay(10);
    }
    Serial.println("mode0");
  } 
  else if (mode == 1) {
    analogWrite(RPIN, 238);
    analogWrite(GPIN, 120);
    analogWrite(BPIN, 0);
    Serial.println("mode1");
  }
}

void swA(void) {
  Serial.println("A");
  swFLG = 1;
}
