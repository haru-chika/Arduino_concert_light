const int RPIN = 2;
const int GPIN = 4;
const int BPIN = 7;

void setup() {
  // put your setup code here, to run once:
  pinMode(RPIN, OUTPUT);
  pinMode(GPIN, OUTPUT);
  pinMode(BPIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 0; i < 256; i++){
    analogWrite(RPIN, i);
    analogWrite(GPIN, i);
    analogWrite(BPIN, i);
    delay(5);
  }


}
