const int RPIN = 2;
const int GPIN = 4;
const int BPIN = 7;

const int modeSW = 8

int mode = 0;
int Color = 0;
volatile int swFLG = 0;

void setup() {
  pinMode(RPIN, OUTPUT);
  pinMode(GPIN, OUTPUT);
  pinMode(BPIN, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(10), swA, FALLING);
  pinMode(modeSW, INPUT);
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

    delay(100);
  }

  if (mode == 0) {

    if (digitalRead(modeSW) == 1){
      Color++;

      while(digitalRead(modeSW) == 1){
        delay(100);
      }
    }

      switch(Color){
        case 0:
          Color_Mana();
          break;
        case 1:
          Color_Kotono();
          break;
        case 2:
          Color_Nagisa();
          break;
        case 3:
          Color_Saki();
          break;
        case 4:
          Color_Suzu();
          break;
        case 5:
          Color_Mei();
          break;
        case 6:
          Color_Sakura();
          break;
        case 7:
          Color_Shizuku();
          break;
        case 8:
          Color_Chisa();
          break;
        case 9:
          Color_Rei();
          break;
        case 10:
          Color_Haruko();
          break;
        case 11:
          Color_Rui();
          break;
        case 12:
          Color_Yu();
          break;
        case 13:
          Color_Sumire();
          break;
        case 14:
          Color_Rio();
          break;
        case 15:
          Color_Aoi();
          break;
        case 16:
          Color_Ai();
          break;
        case 17:
          Color_Kokoro();
          break;
        case 18:
          Color_IIIX();
          break;
        case 19:
          Color = 0;
          break;
      }
    Serial.println("mode0");
  } 
  else if (mode == 1) {
    rainbowEffect();
    Serial.println("mode1");
  }
}

void swA(void) {
  Serial.println("A");
  swFLG = 1;
}

void rainbowEffect() {
  const int duration = 2000;  // 変化の周期（ミリ秒）
  const int steps = 255;      // 色の変化のステップ数

  for (int t = 0; t < duration; t += duration / steps) {
    int red = 128 + 127 * sin(2 * PI * t / duration);
    int green = 128 + 127 * sin(2 * PI * (t + duration / 3) / duration);
    int blue = 128 + 127 * sin(2 * PI * (t + 2 * duration / 3) / duration);

    analogWrite(RPIN, red);
    analogWrite(GPIN, green);
    analogWrite(BPIN, blue);

    delay(duration / steps);
  }
}

// カラーコードはこちらのツイートの画像を参考
// https://twitter.com/idolypride/status/1626748334009352193?ref_src=twsrc%5Etfw%7Ctwcamp%5Etweetembed%7Ctwterm%5E1626748334009352193%7Ctwgr%5Ebe32ccc14b54fdffde1f3f093da06e3d17fb5498%7Ctwcon%5Es1_&ref_url=https%3A%2F%2Fnote.com%2F00_second%2Fn%2Fn1073c022b10a

void Color_Mana(void){
  analogWrite(RPIN, 226);
  analogWrite(GPIN, 92);
  analogWrite(BPIN, 176);
}

void Color_Kotono(void){
  analogWrite(RPIN, 98);
  analogWrite(GPIN, 133);
  analogWrite(BPIN, 214);
}

void Color_Sakura(void){
  analogWrite(RPIN, 237);
  analogWrite(GPIN, 158);
  analogWrite(BPIN, 77);
}

void Color_Rei(void){
  analogWrite(RPIN, 181);
  analogWrite(GPIN, 224);
  analogWrite(BPIN, 238  );
}

void Color_Nagisa(void){
  analogWrite(RPIN, 232);
  analogWrite(GPIN, 117);
  analogWrite(BPIN, 159);
}

void Color_Haruko(void){
  analogWrite(RPIN, 189);
  analogWrite(GPIN, 169);
  analogWrite(BPIN, 224);
}

void Color_Saki(void){
  analogWrite(RPIN, 128);
  analogWrite(GPIN, 205);
  analogWrite(BPIN, 186);
}

void Color_Chisa(void){
  analogWrite(RPIN, 224);
  analogWrite(GPIN, 188);
  analogWrite(BPIN, 208);
}

void Color_Suzu(void){
  analogWrite(RPIN, 243);
  analogWrite(GPIN, 239);
  analogWrite(BPIN, 103);
}

void Color_Mei(void){
  analogWrite(RPIN, 208);
  analogWrite(GPIN, 74);
  analogWrite(BPIN, 84);
}

void Color_Shizuku(void){
  analogWrite(RPIN, 163);
  analogWrite(GPIN, 201);
  analogWrite(BPIN, 158);
}

void Color_Rui(void){
  analogWrite(RPIN, 253);
  analogWrite(GPIN, 251);
  analogWrite(BPIN, 242);
}

void Color_Yu(void){
  analogWrite(RPIN, 179);
  analogWrite(GPIN, 206);
  analogWrite(BPIN, 118);
}

void Color_Sumire(void){
  analogWrite(RPIN, 251);
  analogWrite(GPIN, 229);
  analogWrite(BPIN, 155);
}

void Color_Rio(void){
  analogWrite(RPIN, 165);
  analogWrite(GPIN, 86);
  analogWrite(BPIN, 134);
}

void Color_Aoi(void){
  analogWrite(RPIN, 110);
  analogWrite(GPIN, 118);
  analogWrite(BPIN, 201);
}

void Color_Ai(void){
  analogWrite(RPIN, 141);
  analogWrite(GPIN, 203);
  analogWrite(BPIN, 237);
}

void Color_Kokoro(void){
  analogWrite(RPIN, 240);
  analogWrite(GPIN, 160);
  analogWrite(BPIN, 180);
}

void Color_IIIX(void){
  analogWrite(RPIN, 242);
  analogWrite(GPIN, 241);
  analogWrite(BPIN, 80);
}




