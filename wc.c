#include <wiringPi.h>
#include <softTone.h>
#define MELODY_PIN 8

int melody[] = {
  NOTE_C4,
  NOTE_A4,
  NOTE_G4,
  NOTE_F4,
  NOTE_C4,
  0,
  NOTE_C4,
  NOTE_A4,
  NOTE_G4,
  NOTE_F4,
  NOTE_D4,
  0,
  NOTE_D4,
  NOTE_AS4,
  NOTE_A4,
  NOTE_G4,
  NOTE_E4,
  0,
  NOTE_C5,
  NOTE_C5,
  NOTE_AS4,
  NOTE_G4,
  NOTE_A4,
  NOTE_F4,
  0,
  NOTE_C4,
  NOTE_A4,
  NOTE_G4,
  NOTE_F4,
  NOTE_C4,
  0,
  NOTE_C4,
  NOTE_A4,
  NOTE_G4,
  NOTE_F4,
  NOTE_D4,
  0,
  NOTE_D4,
  NOTE_AS4,
  NOTE_A4,
  NOTE_G4,
  NOTE_C5,
  NOTE_C5,
  NOTE_C5,
  NOTE_C5,
  NOTE_D5,
  NOTE_C5,
  NOTE_AS4,
  NOTE_G4,
  NOTE_F4,
  0,
  NOTE_A4,
  NOTE_A4,
  NOTE_A4,
  NOTE_A4,
  NOTE_A4,
  NOTE_A4,
  NOTE_A4,
  NOTE_C5,
  NOTE_F4,
  NOTE_G4,
  NOTE_A4,
  0,
  NOTE_AS4,
  NOTE_AS4,
  NOTE_AS4,
  NOTE_AS4,
  NOTE_AS4,
  NOTE_A4,
  NOTE_A4,
  NOTE_A4,
  NOTE_A4,
  NOTE_G4,
  NOTE_G4,
  NOTE_F4,
  NOTE_G4,
  NOTE_C5,
  0,
  NOTE_A4,
  NOTE_A4,
  NOTE_A4,
  NOTE_A4,
  NOTE_A4,
  NOTE_A4,
  NOTE_A4,
  NOTE_C5,
  NOTE_F4,
  NOTE_G4,
  NOTE_A4,
  0,
  NOTE_AS4,
  NOTE_AS4,
  NOTE_AS4,
  NOTE_AS4,
  NOTE_AS4,
  NOTE_A4,
  NOTE_A4,
  NOTE_A4,
  NOTE_C5,
  NOTE_C5,
  NOTE_AS4,
  NOTE_G4,
  NOTE_F4,
  0, 
};

int noteDurations[] = {
  2,2,2,2,6,2,
  2,2,2,2,6,2,
  2,2,2,2,6,2,
  2,2,2,2,4,2,2,
  2,2,2,2,6,2,
  2,2,2,2,6,2,
  2,2,2,2,3,1,2,2,2,2,2,2,6,2,
  2,2,4,2,2,4,2,2,3,1,6,2,
  2,2,3,1,2,2,2,2,2,2,2,2,4,2,2,
  2,2,4,2,2,4,2,2,3,1,6,2,
  2,2,3,1,2,2,2,2,2,2,2,2,6,2,
};

void setup() {
  // put your setup code here, to run once:
  for(int thisNote = 0; thisNote < (sizeof(melody) / sizeof(int)); thisNote++)
  {
    int noteDuration = 125 * noteDurations[thisNote];
    tone(MELODY_PIN, melody[thisNote], noteDuration);

    int pauseBetweenNotes = noteDuration * 1.20;
    delay(pauseBetweenNotes);
    noTone(MELODY_PIN);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}

int main()
{
	wiringPiSetup();
		seyup();
		return 0;
}

