
// notes in the melody:
int melody[] = {
660,660,660,510,660,770,380,510,380,320,440,480,450,430,380,660,760,860,700,760,660,520,580,480,510,380,320,440,480,
450,430,380,660,760,860,700,760,660,520,580,480,500,760,720,680,620,650,380,430,500,430,500,570,500,760,720,680,620,
650,1020,1020,1020,380,500,760,720,680,620,650,380,430,500,430,500,570,500,760,720,680,620,650,1020,1020,1020,380,
500,760,720,680,620,650,380,430,500,430,500,570,585,550,500,380,500,500,500,500,500,500,500,580,660,500,430,380,
500,500,500,500,580,660,870,760,500,500,500,500,580,660,500,430,380,660,660,660,510,660,770,380,440,440
};

int noteDurations[] = {
  100,100,100,100,100,100,100,100,100,100,100,80,100,100,100,80,50,100,80,50,80,80,80,80,100,100,100,100,80,100,
  100,100,80,50,100,80,50,80,80,80,80,100,100,100,100,150,150,100,100,100,100,100,100,100,100,100,100,150,200,80,
  80,80,100,100,100,100,100,150,150,100,100,100,100,100,100,100,100,100,100,150,200,80,80,80,100,100,100,100,100,
  150,150,100,100,100,100,100,100,100,100,100,100,100,100,100,60,80,60,80,80,80,80,80,80,60,80,60,80,80,80,80,80,
  60,80,60,80,80,80,80,80,80, 100,100,100,100,100,100,100,200,400
};

int pause[] = {
  150,150,50,150,275,287,225,200,250,150,165,75,150,100,100,75,150,75,175,150,75,75,175,275,200,250,150,165,75,
  150,100,100,75,150,75,175,150,75,75,250,150,50,75,75,150,150,75,75,150,75,50,110,150,50,75,75,150,150,150,75,
  150,150,150,50,75,75,150,150,75,75,150,75,50,110,150,50,75,75,150,150,150,75,150,150,150,50,75,75,150,150,75,
  75,150,75,50,210,275,210,180,150,150,75,150,75,150,175,75,175,75,150,75,300,75,150,175,75,75,225,162,300,75,
  150,175,75,175,75,150,75,300,75,150,150,50,150,225,1000,200,200,200,200,5000
};    

void setup() {

}

void loop() {
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 139; thisNote++) {
    tone(8, melody[thisNote], noteDurations[thisNote]);

    delay(pause[thisNote]);
  }
  
  delay(200);
  delay(200);
  delay(5000);
}
