#include <tone.h>

// Creamos un objeto "Tone" y lo asignamos al pin 8
Tone myTone(8);

// Definimos las notas de la canción en un arreglo
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

// Definimos los tiempos de cada nota en un arreglo
int beats[] = {
  2, 2, 2, 2,
  2, 2, 4,
  2, 2, 2, 2,
  2, 2, 4,
  2, 2, 2,
  2, 2, 2,
  2, 2, 2,
  2, 2, 2,
  2, 2, 2,
  2, 2, 2,
  2, 2, 2,
  2, 2, 2
};

// Definimos la duración de cada silencio (en milisegundos)
int pause = 500;

// Definimos la duración de cada nota (en milisegundos)
int noteDuration = 250;

void setup() {
  // Inicializamos el parlante
  myTone.begin();
}

void loop() {
  // Recorremos el arreglo de notas y tiempos
  for (int i = 0; i < 30; i++) {
    // Reproducimos la nota actual
    myTone.play(notes[i], noteDuration);

    // Esperamos el tiempo correspondiente
    delay(beats[i] * noteDuration);

    // Reproducimos un silencio
    myTone.play(0, pause);
  }
}
</tone.h>