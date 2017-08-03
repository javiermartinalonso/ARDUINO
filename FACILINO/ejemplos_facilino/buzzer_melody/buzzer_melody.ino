long playMelody(int pin, String melody);

void setup()
{
//Play musical notes (whole duration)
playMelody(8,String("261,1500,294,1500,330,1500,349,1500,440,1500,440,1500,493,1500;"));
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
