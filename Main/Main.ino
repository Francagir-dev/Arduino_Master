const int estela1 = 3;
const int estela2 = 4;
const int estela3 = 5;
const int nube1 = 6;
const int nube2 = 7;
const int nube3 = 8;
const int buzzer = 9;
const int gohan1 = 10;
const int gohan2 = 11;
const int gohan3 = 12;
const int gohan4 = 13;
const int delayEstela = 100;
const int delayNube = 250;
const int delayGohan = 10;
void setup() {
  setUpLEDS();
  pinMode(buzzer, OUTPUT);
}

void loop() {
  estelaLEDS();
  nubeLEDS();
  bolaLEDS();
}


void setUpLEDS() {
  pinMode(estela1, OUTPUT);
  pinMode(estela2, OUTPUT);
  pinMode(estela3, OUTPUT);
  pinMode(nube1, OUTPUT);
  pinMode(nube2, OUTPUT);
  pinMode(nube3, OUTPUT);
  pinMode(gohan1, OUTPUT);
  pinMode(gohan2, OUTPUT);
  pinMode(gohan3, OUTPUT);
  pinMode(gohan4, OUTPUT);
}
void estelaLEDS() {
  digitalWrite(estela3, LOW);
  digitalWrite(estela1, HIGH);
  delay(delayEstela);
  digitalWrite(estela1, LOW);
  digitalWrite(estela2, HIGH);
  delay(delayEstela);
  digitalWrite(estela2, LOW);
  digitalWrite(estela3, HIGH);
  delay(delayEstela);
}

void nubeLEDS() {
  digitalWrite(nube3, LOW);
  digitalWrite(nube1, HIGH);
  delay(delayNube);
  digitalWrite(nube1, LOW);
  digitalWrite(nube2, HIGH);
  delay(delayNube);
  digitalWrite(nube2, LOW);
  digitalWrite(nube3, HIGH);
  delay(delayNube);
}

void bolaLEDS() {
  digitalWrite(gohan1, HIGH);
  digitalWrite(gohan2, HIGH);
  digitalWrite(gohan3, HIGH);
  digitalWrite(gohan4, HIGH);
  delay(delayGohan);
  digitalWrite(gohan1, LOW);
  digitalWrite(gohan2, LOW);
  digitalWrite(gohan3, LOW);
  digitalWrite(gohan4, LOW);
  delay(delayGohan * 10);
}