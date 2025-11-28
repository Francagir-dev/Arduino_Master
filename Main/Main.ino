#include "pitches.h"

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


const int piezo = 9; 
int notes[] = {
  NOTE_G4, NOTE_A4, NOTE_G4, NOTE_F4,
  NOTE_E4, NOTE_D4, NOTE_C4,
  NOTE_G4, NOTE_A4, NOTE_G4, NOTE_F4,
  NOTE_E4, NOTE_D4, NOTE_C4,
  NOTE_C4, NOTE_D4, NOTE_E4,
  NOTE_C4, NOTE_D4, NOTE_E4,
  NOTE_F4, NOTE_G4, NOTE_A4,
  NOTE_F4, NOTE_G4, NOTE_A4,
  NOTE_G4, NOTE_A4, NOTE_B4,
  NOTE_G4, NOTE_A4, NOTE_B4,
  NOTE_C5, NOTE_D5, NOTE_E5,
  NOTE_C5, NOTE_D5, NOTE_E5
};

int beats[] = {
  2,2,2,2,
  2,2,4,
  2,2,2,2,
  2,2,4,
  2,2,2,
  2,2,2,
  2,2,2,
  2,2,2,
  2,2,2,
  2,2,2,
  2,2,2,
  2,2,2
};

int numNotes = sizeof(notes)/sizeof(notes[0]);

// Duración base de cada beat
int beatDuration = 250;


// ---------- VARIABLES DE TIEMPO ----------
unsigned long lastNoteTime = 0;
int currentNote = 0;
bool notePlaying = false;

void playMelody() {
  unsigned long now = millis();

  if (!notePlaying) {
    // Empieza nota
    int duration = beats[currentNote] * beatDuration;
    tone(piezo, notes[currentNote], duration);
    lastNoteTime = now;
    notePlaying = true;
  } else {
    // Si pasó el tiempo de esta nota, pasa a la siguiente
    int duration = beats[currentNote] * beatDuration * 1.3;  // margen
    if (now - lastNoteTime >= duration) {
      currentNote++;

      if (currentNote >= numNotes)
        currentNote = 0; // volver a empezar la canción

      notePlaying = false;
    }
  }
}

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

  playMelody();
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
