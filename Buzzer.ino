//Noten und ihre Frequenzen definieren
#define p   0  //Pause
#define B0  31
#define C1  33
#define CS1 35
#define D1  37
#define DS1 39
#define E1  41
#define F1  44
#define FS1 46
#define G1  49
#define GS1 52
#define A1  55
#define AS1 58
#define B1  62
#define C2  65
#define CS2 69
#define D2  73
#define DS2 78
#define E2  82
#define F2  87
#define FS2 93
#define G2  98
#define GS2 104
#define A2  110
#define AS2 117
#define B2  123
#define C3  131
#define CS3 139
#define D3  147
#define DS3 156
#define E3  165
#define F3  175
#define FS3 185
#define G3  196
#define GS3 208
#define A3  220
#define AS3 233
#define B3  247
#define C4  262
#define CS4 277
#define D4  294
#define DS4 311
#define E4  330
#define F4  349
#define FS4 370
#define G4  392
#define GS4 415
#define A4  440
#define AS4 466
#define B4  494
#define C5  523
#define CS5 554
#define D5  587
#define DS5 622
#define E5  659
#define F5  698
#define FS5 740
#define G5  784
#define GS5 831
#define A5  880
#define AS5 932
#define B5  988
#define C6  1047
#define CS6 1109
#define D6  1175
#define DS6 1245
#define E6  1319
#define F6  1397
#define FS6 1480
#define G6  1568
#define GS6 1661
#define A6  1760
#define AS6 1865
#define B6  1976
#define C7  2093
#define CS7 2217
#define D7  2349
#define DS7 2489
#define E7  2637
#define F7  2794
#define FS7 2960
#define G7  3136
#define GS7 3322
#define A7  3520
#define AS7 3729
#define B7  3951
#define C8  4186
#define CS8 4435
#define D8  4699
#define DS8 4978

//Notenart
#define n1   4 //Ganze
#define n2   2 //Halbe
#define n4   1 //Viertel
#define n8   0.5 //Achtel
#define n16  0.25 //Sechszehntel


int buzzer = 5;
//https://musescore.com/user/16403456/scores/4984153
//https://musescore.com/chlorondria_5/never-gonna-give-you-up_alto-sax
//Array für Noten und Pausen
int notes[] = {FS4,p,A4,CS5,p,A4,p,FS4,
              D4,p,D4,p,D4,p,p,p,p,CS4,
              D4,FS4,A4,CS5,p,A4,p,F4,
              E5,DS5,D5,p,p,
              GS4,p,CS5,FS4,p,CS5,p,GS4,  //5
              
              p,CS5,p,G4,FS4,p,E4,p,
              E4,p,E4,p,E4,p,p,p,p,E4,p,E4,
              p,E4,p,p,p,DS4,D4,
              CS4,p,A4,CS5,p,A4,p,FS4,
              D4,p,D4,p,D4,p,p,E5,p,E5,p,E5,p,p,     //10
              
              p,FS4,A4,CS5,p,A4,p,F4,
              E5,D5,p,p,
              B4,G4,D4,CS4,B4,G4,CS4,
              A4,FS4,C4,B3,F4,D4,B3,
              E4,p,E4,p,E4,p,p,p,        //15
              
              

              A4,B4,D5,B4,
              FS5,FS5,E5,A4,B4,D5,B4,
              E5,E5,D5,CS5,B4,A4,B4,D5,B4,
              D5,E5,CS5,B4,A4,A4,A4,
              E5,D5,A4,B4,D5,B4,
              FS5,FS5,E5,A4,B4,D5,B4,
              A5,CS5,D5,CS5,B4,A4,B4,D5,B4,
              D5,E5,CS5,B4,A4,A4,
              E5,D5,p
              
              };
              

//Array für die Notenarten der einzelnen Noten
float beats[] = {n8,n8,n8,n8,n8,n8,n8,n8,
                n16,n16,n16,n16,n16,n16,n8,n4,n8,n8,
                n8,n8,n8,n8,n8,n8,n8,n8,
                n4+n8,n8,n8,n8,n4,
                n8,n8,n8,n8,n8,n8,n8,n8,     //5
                
                n8,n8,n8,n8,n8,n8,n8,n8,
                n16,n16,n16,n16,n16,n16,n8,n4,n8,n16,n16,n16,
                n16,n16,n16,n4,n4,n4,n8,
                n8,n8,n8,n8,n8,n8,n8,n8,
                n16,n16,n16,n16,n16,n16,n8,n16,n16,n16,n16,n16,n16,n8,     //10
                
                n8,n8,n8,n8,n8,n8,n8,n8,
                n2,n8,n8,n4,
                n8,n8,n8,n4,n8,n8,n8,
                n8,n8,n8,n4,n8,n8,n8,
                n16,n16,n16,n16,n16,n16,n4,n4,    //15
                
                

                n16,n16,n16,n16,
                n8+n16,n8+n16,n4+n8,n16,n16,n16,n16,
                n8+n16,n8+n16,n8+n16,n16,n8+n16,n16,n16,n16,n16,
                n4,n8,n8+n16,n16,n8,n8,n8,
                n4,n2,n16,n16,n16,n16,
                n8+n16,n8+n16,n4+n8,n16,n16,n16,n16,
                n4,n8,n8+n16,n16,n8,n16,n16,n16,n16,
                n4,n8,n8+n16,n16,n4,n8,
                n4,n2,n4
                };
                
int songLenght;
int duration;
float tempo = 114;
float tempMult; //Tempomultiplikator um das Tempo einzubinden

void setup() {
  pinMode(buzzer, OUTPUT);
  tempMult = 60/tempo*1000;  //Berechnung des Tempomultiplikators
  songLenght = sizeof(notes) / sizeof(int); //songLenght ist die Anzahl der Noten in 'notes', sizeof(notes) gibt die Größe des Arrays in Bytes an, 
                                            //sizeof(int) gibt die Größe von einem Integer an, wenn man diese diese dividiert bekommt man die Anzahl von Elementen in einem Array 
}
 
void loop() {
 
    for(int i = 0; i<songLenght; i++){     //springt immer zu der nächsten Note in 'notes' und 'beats'
      duration = beats[i]*tempMult;       //berechnet für jede einzelne Note wie lange sie abgespielt werden soll
      tone(buzzer, notes[i],duration);    //notes[i]....verbindet int i mit dem Array 'notes' 
      delay(duration);  //wartet bis Ton aus ist
      delay(tempo/10);  //delay zwischen noten(musikalisch gesehen ein bisschen ungenau, kann aber vernachlässigt werden)
    }

    delay(15000);   //15 Sekunden Pause bevor die melodie erneut abgespielt wird
    tone(buzzer, 400, 500);
}
