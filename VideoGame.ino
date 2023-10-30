int butt = 2;
int jump = 1;
int score = 0;
boolean lose = false;
boolean start = false;
int t = 3;
String w;
String tempw;
int c = 0;
// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  pinMode(butt, INPUT_PULLUP);
  w = world();
  tempw = world();
}

String world(){
  String seed = "________________";
  seed[random(0, 15)] = "9";
  return seed;
}

void loop() {
  lcd.setCursor(0, 1);
  lcd.print(w);
  lcd.setCursor(2, jump);
  lcd.print("1");
  if(digitalRead(butt)==LOW){
    start = true;
  }
  if(start){
    if(!lose){
      lcd.setCursor(0, 1);
      for(int i = 0; i < 16; i++){
        w[i] = w[i+1];
      }
      w[15] = tempw[c];
      c++;
      if(c==16){
        tempw = world();
        c = 0;
      }
      lcd.print(w);
    
    
    
    
      lcd.setCursor(2, 0);
      lcd.print(" ");
      if(t==0){
        if(digitalRead(butt)==LOW){
          t = 3;
        }else{
          jump = 1;
        }
      }else if (digitalRead(butt)!=LOW){
        t--;
        jump = 0;
      }
    
      
      lcd.setCursor(2, jump);
      lcd.print("1");
      


      if((jump==1)&&(w[2]!='_')){
        lose = true;
      }
      score++;
      lcd.setCursor(16-String(score).length(), 0);
      lcd.print(String(score));
      delay(100/(score/50 +1));
    }else{
      lcd.clear();
      lcd.setCursor(2, 0);
      lcd.print("GAME LOSE");
      lcd.setCursor(2, 1);
      lcd.print("SCORE:" + String(score));
      delay(1000);
    }
  }
}
