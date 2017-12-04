#include <Servo.h>
#include <EEPROM.h>


#define SPEAKER_PIN 2
#define RED  7
#define GREEN 6
#define BLUE  5

Servo servo;

bool detect = false;
int tempo = 200;
char notes[] = "eeeeeeegcde fffffeeeeddedg";
int duration[] = {1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2};
void playTheShit(char note, int duration) 
{
  char notesName[] = { 'c', 'd', 'e', 'f', 'g' };
  int tones[] = { 261, 293, 329, 349, 392 };
  for (int i = 0; i < sizeof(tones); i++)
  {
    // Bind the note took from the char array to the array notesName
    if (note == notesName[i])
    {
      // Bind the notesName to tones
      tone(SPEAKER_PIN, tones[i], duration);
    }
  }
}

//http://blog.giacomocerquone.com/jingle-bell-with-an-arduino-and-a-buzzer/
void playJingle()
{
  int size = sizeof(notes)-1;
  for (int i = 0, c = 5; i < size; i++)
  {
    if (notes[i] == ' ') 
      // If find a space it rests
      delay(duration[i] * tempo);
    else
      playTheShit(notes[i], duration[i] * tempo);
    // Pauses between notes
    if(c > 7)
      c = 5;
    analogWrite(c, 255);
    
    delay((tempo*2)*duration[i]);
    analogWrite(c, 0);
    c++;
  }
}

void setup()
{
  // put your setup code here, to run once:
  pinMode(SPEAKER_PIN, OUTPUT);
  pinMode(RED, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(A0, INPUT);

  servo.attach(9);
  servo.write(0);
  Serial.begin(9600);
  delay(5000);
}

void loop()
{
  Serial.println(analogRead(A0));
  if(analogRead(A0) < 700 && !detect)
  {
    detect = true;
    servo.writeMicroseconds(1900);
  }

  if(detect)
    playJingle();
}
