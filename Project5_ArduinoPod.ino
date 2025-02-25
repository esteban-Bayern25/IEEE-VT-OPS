#include "pitches.h"

#define SPEAKER 3
#define POT_PIN A4
int NOTE_DUR = 137;

// Helper function to play a note for a certain duration
void play(int note, int dur) {
  tone(SPEAKER, note);        // Start tone at the specified frequency
  delay(dur * NOTE_DUR);      // Hold the tone for the duration
  noTone(SPEAKER);            // Stop tone
  delay(dur * NOTE_DUR / 3);  // Short rest between notes
}

// Simple song using predefined notes from pitches.h
void playSong1() {
  NOTE_DUR = 58;  // Set tempo to be faster
  play(NOTE_D4, 1);
  play(NOTE_FS4, 1);
  play(NOTE_B4, 1);
  play(NOTE_D5, 1);
  play(NOTE_CS5, 1);
  play(NOTE_B4, 1);
  play(NOTE_AS4, 1);
  play(NOTE_B4, 16);  //m2
  delay(NOTE_DUR * 6);
  play(NOTE_B4, 6);
  play(NOTE_CS5, 6);
  play(NOTE_D5, 6);
  play(NOTE_E5, 6);  //m3
  play(NOTE_FS5, 7);
  play(NOTE_D5, 7);
  play(NOTE_FS5, 8);
  play(NOTE_D5, 8);
  play(NOTE_FS5, 22);
  delay(NOTE_DUR * 4);
  play(NOTE_FS4, 2);  //m4
  play(NOTE_D5, 6);
  play(NOTE_E4, 2);
  play(NOTE_CS5, 6);
  play(NOTE_D4, 2);
  play(NOTE_B4, 4);  //m5
  play(NOTE_D4, 2);
  play(NOTE_FS4, 4);
  play(NOTE_B4, 2);
  play(NOTE_D4, 4);
  play(NOTE_B4, 4);
  play(NOTE_D4, 2);
  play(NOTE_FS4, 2);
  play(NOTE_D5, 2);
  play(NOTE_CS5, 2);
  play(NOTE_B4, 2);
  play(NOTE_A4, 2);
  play(NOTE_B4, 4);  //m6
  play(NOTE_D4, 2);
  play(NOTE_G4, 4);
  play(NOTE_B4, 2);
  play(NOTE_D4, 4);
  play(NOTE_B4, 4);
  play(NOTE_D4, 2);
  play(NOTE_G4, 2);
  play(NOTE_D5, 2);
  play(NOTE_CS5, 2);
  play(NOTE_B4, 2);
  play(NOTE_A4, 2);
  play(NOTE_D5, 4);  //m7
  play(NOTE_FS4, 2);
  play(NOTE_A4, 4);
  play(NOTE_D5, 2);
  play(NOTE_FS4, 4);
  play(NOTE_D5, 4);
  play(NOTE_FS4, 2);
  play(NOTE_A4, 2);
  play(NOTE_D5, 2);
  play(NOTE_CS5, 2);
  play(NOTE_B4, 2);
  play(NOTE_A4, 2);
  play(NOTE_E5, 12);  //m8
  delay(NOTE_DUR * 2);
  play(NOTE_FS4, 2);
  play(NOTE_D5, 6);
  play(NOTE_E4, 2);
  play(NOTE_CS5, 6);
  play(NOTE_D4, 2);
  play(NOTE_B4, 10);  //m9
}
void playSong2() {
  play(NOTE_C4, 4);  // Middle C for 4 durations
  play(NOTE_G3, 8);  // G below middle C for 8 durations
  play(NOTE_G3, 8);
  play(NOTE_A3, 4);  // A
  play(NOTE_G3, 4);  // G
  play(NOTE_B3, 4);  // B
  play(NOTE_A3, 8);  // A
  play(NOTE_G3, 4);  // G
  play(NOTE_C4, 8);  // C
  play(NOTE_G3, 4);  // G
}

void playSong3() {
play(NOTE_C5, 4);   // C5
  play(NOTE_E5, 4);   // E5
  play(NOTE_G5, 4);   // G5
  play(NOTE_C5, 4);   // C5
  delay(300);

  // Repeat melody
  play(NOTE_C5, 4);   // C5
  play(NOTE_E5, 4);   // E5
  play(NOTE_G5, 4);   // G5
  play(NOTE_C5, 4);   // C5
  delay(300);
}

void setup() {
  pinMode(SPEAKER, OUTPUT);  // Set the speaker pin as an output
                             // Play the song once on startup
}

void loop() {
  // Read voltage for potentiometer
  int potValue = analogRead(POT_PIN);

  int lastPotValue = 0;  // Store the last potentiometer value
  int threshold = 50;    // Define a threshold to detect significant changes

  // Check if the potentiometer value has changed significantly (exceed threshold)
  if (abs(potValue - lastPotValue) > threshold) {
    // Depending on the value of the potentiometer, play one of the 3 songs
    int songToPlay = map(potValue, 0, 1023, 1, 3);  // Map potentiometer value to 1-3

    // Play the corresponding song based on potentiometer value
    if (songToPlay == 1) {
      playSong1();  // Play first song
    } else if (songToPlay == 2) {
      playSong2();  // Play second song
    } else if (songToPlay == 3) {
      playSong3();  // Play third song
    }

    // Update last potentiometer value to the new one
    lastPotValue = potValue;
  }
}
