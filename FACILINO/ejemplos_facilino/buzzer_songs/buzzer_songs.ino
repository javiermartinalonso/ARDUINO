/***   Global variables   ***/

/***   Function declaration   ***/
long playMelody(int pin, String melody);

void setup()
{
    //Buzzer is connected to pin 8
    //Bethoveen
    playMelody(8,String("0,187,392,187,392,187,392,187,311,750,0,187,349,187,349,187,349,187,294,375;"));
    //I want to break free
    playMelody(8,String("494,187,659,375,740,375,740,375,740,187,831,1312,0,562,494,187,659,375,740,375,880,375,831,937;"));
    //We're the champions
    playMelody(8,String("698,750,659,187,698,187,659,375,523,562,440,187,587,375,440,750,0,562,0,375,523,187,698,750,784,187,880,187,1047,375,880,562,587,187,659,187,587,750;"));
    //Game of thrones
    playMelody(8,String("1568,562,1047,562,1245,93,1397,93,1568,375,1047,375,1245,93,1397,93,1175,1875,1397,562,932,562,1245,93,1175,93,1397,375,932,562,1245,93,1175,93,1047,750;"));
    //Imagine
    playMelody(8,String("440,187,523,187,440,187,523,375,659,187,659,375,587,187,440,750,0,375,494,187,494,562,494,375,523,187,587,937,659,187,784,375,659,93,659,93,523,375;"));
    //Star Wars (imperial march)
    playMelody(8,String("440,375,440,375,440,375,349,250,523,93,440,375,349,250,523,187,440,750,659,375,659,375,659,375,698,250,523,93,415,375,349,250,523,187,440,750;"));
    //Love is in the air
    playMelody(8,String("392,187,392,187,392,187,330,187,392,750,0,375,392,187,392,187,494,187,494,187,523,187,523,187,440,750;"));
    //No woman, no cry
    playMelody(8,String("523,562,494,187,523,187,494,187,494,187,440,562,0,562,659,375,698,187,659,187,698,187,523,187;"));
    //Thriller
    playMelody(8,String("196,187,220,187,262,187,294,187,220,187,0,93,220,93,0,187,220,93;"));
}


void loop()
{


}

/***   Function definition   ***/
long playMelody(int pin, String melody)
{
int first=0;
int second=0;
int note;
int duration;
int go_on=1;
while(go_on)
{
  second=melody.indexOf(',');
  note=melody.substring(first,second).toInt();
  first=second+1;
  melody=melody.substring(first);
  first=0;
  second=melody.indexOf(',');
  if (second==-1)
    go_on=0;
  duration=melody.substring(first,second).toInt();
  first=second+1;
  melody=melody.substring(first);
  first=0;
  tone(pin,note,duration);
  delay(duration);
  noTone(pin);
 }
}
