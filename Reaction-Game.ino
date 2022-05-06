const int button1 = 9;
const int button2 = 8;

const int rotLedPin = 4;
const int led1 = 3;
const int led2 = 2;

//Punkte
int pointCounter1 = 0;
int pointCounter2 = 0;

bool gameStarted = false;

void setup() {
  Serial.begin(9600);
  
  randomSeed(analogRead(0));
  
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
 
  pinMode(rotLedPin, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  if(digitalRead(button1) == HIGH && digitalRead(button2) == HIGH && gameStarted == false){        //beide knöpfe drücken um spiel zu starten
       gameStarted = true;
       digitalWrite(led1,HIGH);
       digitalWrite(led2,HIGH);
       delay(150);
       digitalWrite(led1,LOW);
       digitalWrite(led2,LOW);
       Serial.println("");
       Serial.println("GAME START!");
       delay(1000);
       
       int zeit = random(3000, 10000);       //random delay wird generiert
       
       for(int i = 0; i<zeit; i++){         //Buttons dürfen vor dem aufleuchten der roten LED nicht gedrückt werden, kontrolliert jede millisekunde ob ein knopf gedrückt wurde
          delay(1); 
        if(digitalRead(button1)== HIGH && gameStarted == true){
          digitalWrite(led2, HIGH);
          Serial.println("PLAYER1 DISQUALIFIED, PLAYER2 WINS!");
          pointCounter2++;
          Score();        //springt zu dem scoresystem, beendet wegen disqualifizierung
          return;         //Rest von dem Sketch wird nicht ausgeführt
        }
        if(digitalRead(button2) == HIGH && gameStarted == true){
          digitalWrite(led1, HIGH);
          Serial.println("PLAYER2 DISQUALIFIED, PLAYER 1 WINS!");
          pointCounter1++;
          Score();
          return;        //Rest von dem Sketch wird nicht ausgeführt
         }
       }
     }
     if(gameStarted == true){                                       
       digitalWrite(rotLedPin, HIGH);    //rote LED an, bleibt an
     
      while(digitalRead(button2) == LOW && digitalRead(button1)== LOW){} //wartet bis ein Knopf gedrückt wird
       if(digitalRead(button1) == HIGH){    //Payer 1 drückt zuerst
          digitalWrite(led1, HIGH);
          Serial.println("PLAYER1 WINS!");
          pointCounter1++;
          Score();
         }
       else{                        //Player 2 drückt zuerst
          digitalWrite(led2, HIGH);
          Serial.println("PLAYER2 WINS!");
          pointCounter2++;
          Score();
         }
      }
   }
      void Score(){                //Punktesystem
        gameStarted = false;
        delay(800);
        digitalWrite(led1,LOW);   //alle LEDs aus
        digitalWrite(led2, LOW);
        digitalWrite(rotLedPin, LOW);

        Serial.println("");              //druckt Punktestand der beiden Spieler        
        Serial.print("PLAYER1 SCORE: ");                           
        Serial.println(pointCounter1);
                                           
        Serial.print("PLAYER2 SCORE: ");
        Serial.println(pointCounter2);
         
         if(pointCounter1 >= 5 || pointCounter2 >= 5){        // Gewinner bei 5 Punkten
           Winner();
         }
    }
      void Winner(){                                          
          delay(100);
          Serial.println("GAME OVER");
          if(pointCounter1 > pointCounter2){        //Player1 gewinnt
              digitalWrite(led1, HIGH);
              Serial.print("PLAYER1 IS THE WINNER!");
            }
          else{        //Player2 gewinnt
              digitalWrite(led2, HIGH);
              Serial.print("PLAYER2 IS THE WINNER!");
            }
          pointCounter2 = 0;        //reset Counters
          pointCounter1 = 0;
            
        }
       
            
          
          
        
