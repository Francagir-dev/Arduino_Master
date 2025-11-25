//PINES DE LED
const int ledEstela[] = { 3, 4, 5 };
const int sizeEstela = 3;
bool pasoNube = false;

const int ledNube[] = { 6, 7, 8 };
const int sizeNube = 3;

const int ledGohan[] = { 10, 11, 12, 13 };
const int sizeGohan = 4;

//Tiempos
const long delayEstela = 100;
const long delayNube = 250;
const long delayGohan = 10;

//Control interno
unsigned long last1 = 0;


unsigned long last2 = 0;
bool estado2 = LOW;

unsigned long last3 = 0;
int index3 = 0;
void setup() {
  //ESTELA
  for (int i = 0; i < sizeEstela; i++)
    pinMode(ledEstela[i], OUTPUT);

  //NUBE
  for (int i = 0; i < sizeNube; i++)
    pinMode(ledNube[i], OUTPUT);

  //Gohan (BOLA)
  for (int i = 0; i < sizeGohan; i++)
    pinMode(ledGohan[i], OUTPUT);
}

void loop() {

  unsigned long ahora = millis();


  // ========== GRUPO 1: SECUENCIA ==========
  if (ahora - last1 >= delayNube) {

    if (!pasoNube) {
      digitalWrite(ledNube[0], HIGH);
      digitalWrite(ledNube[1], LOW);
      digitalWrite(ledNube[2], LOW);
    } else {
      digitalWrite(ledNube[0], LOW);
      digitalWrite(ledNube[1], HIGH);
      digitalWrite(ledNube[2], HIGH);
    }
    pasoNube = !pasoNube;
    last1 = ahora;
  }



  // ========== GRUPO 2: PARPADEO GENERAL ==========
  if (ahora - last2 >= delayGohan) {
    estado2 = !estado2;

    for (int i = 0; i < sizeGohan; i++)
      digitalWrite(ledGohan[i], estado2);

    last2 = ahora;
  }



  // ========== GRUPO 3: SECUENCIA RÁPIDA ==========
  if (ahora - last3 >= delayEstela) {
    // Apagar todos
    for (int i = 0; i < sizeEstela; i++) digitalWrite(ledEstela[i], LOW);

    // Encender siguiente
    digitalWrite(ledEstela[index3], HIGH);

    // Avanzar índice
    index3 = (index3 + 1) % sizeEstela;

    last3 = ahora;
  }
}
