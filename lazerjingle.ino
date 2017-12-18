/*
 * Name: Rittik Verma
 * Student Number: 200383391
 * Course: CS207
 * Assignment: CS207 Final Project
 * University of Regina
 */
 
//including all necessary libraries
#include <Servo.h>
#include <EEPROM.h>

//Pin definitions
#define SPEAKER_PIN 2
#define RED  7
#define GREEN 6
#define BLUE  5

//defining theshold value
#define THRESHOLD 700

//servo object to control the servo motor
Servo servo;

//variable to store number of times the alarm was triggered
int num_trig = 0;

//struct to store custome RGB colors
struct xcolor
{
  byte r;
  byte g;
  byte b;
}xmas[5];

//detection variable
bool detect = false;

//tempo for note
int tempo = 200;
//notes for jingle bells
char notes[] = "eeeeeeegcde fffffeeeeddedg";
//duration of the notes
int duration[] = {1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2};

//function to play the notes
////http://blog.giacomocerquone.com/jingle-bell-with-an-arduino-and-a-buzzer/
void playTheNotes(char note, int duration) 
{
  char notesName[] = { 'c', 'd', 'e', 'f', 'g' };
  int tones[] = { 261, 293, 329, 349, 392 };
  for (int i = 0; i < 5; i++)
  {
    //Bind the note took from the char array to the array notesName
    if (note == notesName[i])
    {
      //Bind the notesName to tones
      tone(SPEAKER_PIN, tones[i], duration);
    }
  }
}

//function play jingle bells tune
////http://blog.giacomocerquone.com/jingle-bell-with-an-arduino-and-a-buzzer/
void playJingle()
{
  int size = sizeof(notes)-1;
  for (int i = 0, c = 0; i < size; i++)
  {
    if (notes[i] == ' ') 
      // If find a space it rests
      delay(duration[i] * tempo);
    else
      playTheNotes(notes[i], duration[i] * tempo);
    
    if(c > 4)
      c = 0;

    //write the color codes to respective pins
    analogWrite(5, xmas[c].r);
    analogWrite(6, xmas[c].g);
    analogWrite(7, xmas[c].b);
    // Pauses between notes
    delay((tempo*2)*duration[i]);
    c++;
  }
}

//function to store RGB colors
void storeRGB()
{
  //red color
  xmas[0].r = 255; 
  xmas[0].g = 0;
  xmas[0].b = 0;

  //green color
  xmas[1].r = 0;
  xmas[1].g = 255;
  xmas[1].b = 0;

  //blue color
  xmas[2].r = 0;
  xmas[2].g = 0;
  xmas[2].b = 255;

  //pink color
  xmas[3].r = 178;
  xmas[3].g = 0;
  xmas[3].b = 255;

  //blue lagoon color
  xmas[4].r = 150;
  xmas[4].g = 100;
  xmas[4].b = 100;
}

//run only once the program starts
void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);

  //set all pin attributes
  pinMode(SPEAKER_PIN, OUTPUT);
  pinMode(RED, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(A0, INPUT);

  //attach servo to pin 9
  servo.attach(9);

  //storing RGB colors
  storeRGB();

  //give this setup time to
  delay(5000);

  //using long term storage to store number of times the system triggered
  EEPROM.get(0, num_trig);

  //printing number of times the alarm triggered
  Serial.println("Number of times the alarm triggered: ");
  Serial.print(num_trig);
  Serial.println("");
}

//infinite iterations
void loop()
{
  //detection mechanism
  if(analogRead(A0) < THRESHOLD && !detect)
  {
    //set detection variable true
    detect = true;

    //storing and incrementing num_trig
    EEPROM.put(0, ++num_trig);

    //shoot rubber band
    servo.write(180);
  }

  //if detected play jingle
  if(detect)
    playJingle();
}
