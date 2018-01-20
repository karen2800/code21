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
int buttonApin = 12;

Points pts[]{Points(1,1),Points(9,1),Points(17,1),Points(1,9),Points(9,9),Points(17,9)};



void setup() {

  Serial.begin(9600);

  matrix.begin(ADA_HT1632_COMMON_16NMOS);

  matrix.fillScreen();

  delay(500);

  matrix.clearScreen();

  randomSeed(analogRead(0));

  joyUsed = 0;
  pinMode(buttonApin, INPUT_PULLUP);
  score = 0; 
}

void loop() {
  
  matrix.clearScreen();
     //Serial.println(analogRead(joyX));

    int randomArray[] = {random(0,4), random(0,4), random(0,4), random(0,4), random(0,4), random(0,4)};
    String shapesInSquares[] = {" ", " ", " ", " ", " ", " "};     
    do {

      //TIMER
       if (timeElapsed > 10000)
      {                                                        
          while(true){
            matrix.clearScreen();                   
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

    delay(500);
    } while (digitalRead(buttonApin) == LOW);
    if (shapesInSquares[joyUsed] == "circle"){
      score ++;        
    }
    Serial.println("SCORE");
    Serial.println(score); 
    joyUsed = 0;  
  /*

  matrix.drawPixel(analogRead(A0) % 23, analogRead(A1) % 15, 1);

  matrix.writeScreen();



  delay(10);*/

  

  /*

  //Draw a Square

  matrix.drawRect(pts[0].x, pts[0].y, 6, 6, 1);

    matrix.writeScreen();

  

  //Draw a Rectangle

    matrix.drawRect(pts[1].x, pts[1].y + 2, 6, 3, 1);

      matrix.writeScreen();

  

  // Draw a Circle

     matrix.drawCircle(pts[2].x + 2 , pts[2].y + 3, 3, 1);

       matrix.writeScreen();

  

  // Draw a Triangle

    matrix.drawTriangle(pts[3].x + 5, pts[3].y, pts[3].x, pts[3].y + 5, pts[3].x + 5, pts[3].y + 5, 1);

  matrix.writeScreen();*/

 /*   

  //Rectangle

  matrix.drawRect(17, 1, 6, 6, 1);

  matrix.writeScreen();

  delay(0);

  

  //matrix.fillTriangle(9, 6, 12, 1, 14, 6, 1);

  matrix.drawTriangle(9, 6, 12, 1, 14, 6, 1);

  matrix.writeScreen();

*/

/*

    refX = 0;

  refY = 0;

  matrix.drawTriangle((refX + 9), (refY + 6), (refX + 14), (refY + 1), (refX + 14), (refY + 6), 1);

  matrix.writeScreen();



  refX = -8;

  refY = 0;

  matrix.drawTriangle((refX + 9), (refY + 6), (refX + 14), (refY + 1), (refX + 14), (refY + 6), 1);

  matrix.writeScreen();*/

  



 /* 



  matrix.clearScreen();

   // draw a pixel!

  matrix.drawPixel(0, 0, 1);

  matrix.writeScreen();



  delay(500);

   // clear a pixel!

  matrix.drawPixel(0, 0, 0);

  matrix.writeScreen();



  // draw a big rect on the screen

  matrix.fillRect(matrix.width()/4, matrix.height()/4,

                  matrix.width()/2, matrix.height()/2, 1);

  matrix.writeScreen();

  delay(500);



  // draw an outline

  matrix.drawRect(0, 0, matrix.width(), matrix.height(), 1);

  matrix.writeScreen();

  delay(500);



  // draw an 'X' in red

  matrix.clearScreen();

  matrix.drawLine(0, 0, matrix.width()-1, matrix.height()-1, 1);

  matrix.drawLine(matrix.width()-1, 0, 0, matrix.height()-1, 1);

  matrix.writeScreen();

  delay(500);



  // fill a circle

  matrix.fillCircle(matrix.width()/2-1, matrix.height()/2-1, 7, 1);

  matrix.writeScreen();

  delay(500);



  // draw an inverted circle

  matrix.drawCircle(matrix.width()/2-1, matrix.height()/2-1, 4, 0);

  matrix.writeScreen();

  delay(500);



  matrix.clearScreen();

  // draw some text!

  matrix.setTextSize(1);    // size 1 == 8 pixels high

  matrix.setTextColor(1);   // 'lit' LEDs

  matrix.setTextWrap(true);



  matrix.setCursor(0, 0);   // start at top left, with one pixel of spacing

  matrix.print("AdafruitIndustries");

  matrix.writeScreen();



  delay(2000);



  // whew!*/

}
