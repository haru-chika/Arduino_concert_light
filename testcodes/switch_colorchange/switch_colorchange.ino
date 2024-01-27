const int RPIN = 7;
const int GPIN = 4;
const int BPIN = 2;

const int ModeSW = 10;  // モード切替用スイッチ
const int ColorSW = 20; // 色切替用スイッチ

int mode = 0;
int Color = 0;
volatile int modeFLG = 0;
volatile int ColorFLG = 0;

void setup() {
  pinMode(RPIN, OUTPUT);
  pinMode(GPIN, OUTPUT);
  pinMode(BPIN, OUTPUT);

  //pinMode(ModeSW, INPUT_PULLUP);  // プルアップ抵抗を使う
  //pinMode(ColorSW, INPUT_PULLUP); // プルアップ抵抗を使う
  attachInterrupt(digitalPinToInterrupt(ModeSW), swA, FALLING);
  attachInterrupt(digitalPinToInterrupt(ColorSW), swB, FALLING);
  //pinMode(ColorSW, INPUT);
  //Serial.begin(9600);
}

unsigned long lastModeChangeTime = 0;
unsigned long lastColorChangeTime = 0;

void loop() {
  unsigned long currentMillis = millis();

  if (modeFLG && (currentMillis - lastModeChangeTime >= 1000)) {
    noInterrupts();
    modeFLG = 0;
    lastModeChangeTime = currentMillis;

    mode++;
    if (mode >= 2)
      mode = 0;

    interrupts();
  }

  if (ColorFLG && (currentMillis - lastColorChangeTime >= 1000)) {
    noInterrupts();
    ColorFLG = 0;
    lastColorChangeTime = currentMillis;

    Color++;
    if (Color >= 4)
      Color = 0;

    interrupts();
  }

  if (mode == 0) {


    

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
      }
    //Serial.println("mode0");
  } 
  else if (mode == 1) {
    rainbowEffect();
    //Serial.println("mode1");
    
  }
}

void swA(void) {
  Serial.println("A");
  modeFLG = 1;
}

void swB(void) {
  Serial.println("B");
  ColorFLG = 1;
}

void rainbowEffect() {
  const int duration = 1000;  // 変化の周期（ミリ秒）
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
  analogWrite(RPIN, 100);
  analogWrite(GPIN, 0);
  analogWrite(BPIN, 0);
}

void Color_Kotono(void){
  analogWrite(RPIN, 0);
  analogWrite(GPIN, 100);
  analogWrite(BPIN, 0);
}

void Color_Sakura(void){
  analogWrite(RPIN, 0);
  analogWrite(GPIN, 0);
  analogWrite(BPIN, 100);
}

void Color_Rei(void){
  analogWrite(RPIN, 100);
  analogWrite(GPIN, 100);
  analogWrite(BPIN, 0);
}

void Color_Nagisa(void){
  analogWrite(RPIN, 0);
  analogWrite(GPIN, 100);
  analogWrite(BPIN, 100);
}

void Color_Haruko(void){
  analogWrite(RPIN, 100);
  analogWrite(GPIN, 0);
  analogWrite(BPIN, 100);
}

void Color_Saki(void){
  analogWrite(RPIN, 100);
  analogWrite(GPIN, 100);
  analogWrite(BPIN, 0);
}

void Color_Chisa(void){
  analogWrite(RPIN, 224);
  analogWrite(GPIN, 188);
  analogWrite(BPIN, 208);
}

void Color_Suzu(void){
  analogWrite(RPIN, 100);
  analogWrite(GPIN, 0);
  analogWrite(BPIN, 100);
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




