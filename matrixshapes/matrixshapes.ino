#include <elapsedMillis.h>



//DOWNLOAD LIBRARY FOR TIMER

//http://www.thearduinomakerman.info/blog/2016/4/8/tutorial-delay-vs-timer

class Points {



  public:



    int x;



    int y; 



    Points(int x, int y) {



      this->x = x;



      this->y = y;



    }



};



#include <elapsedMillis.h>



#include "Adafruit_GFX.h"



#include "Adafruit_HT1632.h"



#include "time.h"



#include "stdio.h"







#define HT_DATA 2



#define HT_WR   3



#define HT_CS   4



#define HT_CS2  5







// use this line for single matrix



//Adafruit_HT1632LEDMatrix matrix = Adafruit_HT1632LEDMatrix(HT_DATA, HT_WR, HT_CS);



// use this line for two matrices!



Adafruit_HT1632LEDMatrix matrix = Adafruit_HT1632LEDMatrix(HT_DATA, HT_WR, HT_CS, HT_CS2);







int num = 0;



int joyUsed; 

int joyX = A0;

int score; 

int joyY = A1;

elapsedMillis timeElapsed; 
elapsedMillis timeElapsedOneRound;
int buttonApin = 12;

int buttonBpin = 13;



Points pts[]{Points(1,1),Points(9,1),Points(17,1),Points(1,9),Points(9,9),Points(17,9)};



boolean start = true;



void setup() {


pinMode(9, OUTPUT);
  Serial.begin(9600);



  matrix.begin(ADA_HT1632_COMMON_16NMOS);



  matrix.fillScreen();



  delay(500);



  matrix.clearScreen();



  randomSeed(analogRead(0));



  joyUsed = 0;

  pinMode(buttonApin, INPUT_PULLUP);

  pinMode(buttonBpin, INPUT_PULLUP);

  score = 0; 

  //matrix.print("Play");

  //matrix.writeScreen();

  //delay(1000);

  boolean start = true;

}



void loop() {

  if (start) {

    matrix.print("Play");

    matrix.writeScreen();

    delay(1000);

    start = false;

  }

  matrix.clearScreen();

     //Serial.println(analogRead(joyX));



    int randomArray[] = {random(0,4), random(0,4), random(0,4), random(0,4), random(0,4), random(0,4)};

    String shapesInSquares[] = {" ", " ", " ", " ", " ", " "};     

    do {



      //TIMER

       if (timeElapsed > 30000)

      {                                                        

         matrix.clearScreen();

         matrix.setCursor(0, 0);

         matrix.println("SCR");

          matrix.writeScreen();

          //matrix.print("Score: "); 

          matrix.println(score);

          matrix.writeScreen();  

          while(true){

                

          }

      }





      

    matrix.clearScreen();

    Serial.println("in the for loop");

      Serial.println("After for loop to 6");

      Serial.println(joyUsed); 

      if(analogRead(joyX) > 700){ //moving right

      joyUsed++;

      if (joyUsed == 3){

        joyUsed = 0;   

        

      }

      if(joyUsed == 6) {

        joyUsed = 3; 

      }

      if (joyUsed > 5){

        joyUsed = 0;   

        

      }

    }

    if(analogRead(joyX) < 400){ //moving left

      joyUsed--;

      if (joyUsed < 0){

        joyUsed = 2;   

        

      }

      if(joyUsed == 2) {

        joyUsed = 5; 

      }

    }



    if(analogRead(joyY) < 400){ //moving down

      joyUsed = joyUsed + 3;

      if (joyUsed > 5){

        joyUsed = 0;   

        

      }

    }



    if(analogRead(joyY) > 700){ //moving up

      if (joyUsed > 2){

        joyUsed = joyUsed - 3; 

      } else {

        joyUsed = joyUsed + 3; 

      }

      if (joyUsed > 5){

        joyUsed = 0;   

      }

    }



      Serial.println("before switch statement");

      Serial.println(joyUsed);



       

    for (int i = 0; i < 6; i++) { 

      

      switch(randomArray[i]){



        case 0:

          shapesInSquares[i] = "square"; 

          if(joyUsed == i){ 



            matrix.fillRect(pts[i].x, pts[i].y, 6, 6, 1);



            matrix.writeScreen();



          } else {



            matrix.drawRect(pts[i].x, pts[i].y, 6, 6, 1);



            matrix.writeScreen();



          }



          break;



        case 1:

          shapesInSquares[i] = "rectangle";

          if(joyUsed == i){



            matrix.fillRect(pts[i].x, pts[i].y + 2, 6, 3, 1);



            matrix.writeScreen();



          } else {



            matrix.drawRect(pts[i].x, pts[i].y + 2, 6, 3, 1);



            matrix.writeScreen();



          }



          break;



        case 2:

          shapesInSquares[i] = "circle";

          if(joyUsed == i){



            matrix.fillCircle(pts[i].x + 2 , pts[i].y + 3, 3, 1);



            matrix.writeScreen();



          } else {



            matrix.drawCircle(pts[i].x + 2 , pts[i].y + 3, 3, 1);



            matrix.writeScreen();



          }



          break;



        case 3:

          shapesInSquares[i] = "triangle";

          if(joyUsed == i){



          matrix.fillTriangle(pts[i].x + 5, pts[i].y, pts[i].x, pts[i].y + 5, pts[i].x + 5, pts[i].y + 5, 1);



          matrix.writeScreen();



          } else {



          matrix.drawTriangle(pts[i].x + 5, pts[i].y, pts[i].x, pts[i].y + 5, pts[i].x + 5, pts[i].y + 5, 1);



          matrix.writeScreen();



          }



          break;



      }



      //matrix.clearScreen();



    } 


    if (digitalRead(buttonApin) == HIGH){
      beep(100);
    }

    delay(500);

    } while (timeElapsedOneRound < 5000);

    if (shapesInSquares[joyUsed] == "circle"){

      score ++;        

    }

    timeElapsedOneRound = 0;

    Serial.println("SCORE");

    Serial.println(score); 

    joyUsed = 0;  
}

void beep(unsigned char delayms){
  analogWrite(9, 180);      // Almost any value can be used except 0 and 255
                           // experiment to get the best tone
  delay(delayms);          // wait for a delayms ms
  analogWrite(9, 0);       // 0 turns it off
  delay(delayms);          // wait for a delayms ms  
}  
