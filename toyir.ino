#include <IRremote.h>
#include "StringSplitter.h"
int datacount=0;
int readline(int readch, char *buffer, int len)
{
  static int pos = 0;
  int rpos;

  if (readch > 0) {
    switch (readch) {
      case '\n': // Ignore new-lines
        break;
      case '\r': // Return on CR
        rpos = pos;
        pos = 0;  // Reset position index ready for next time
        return rpos;
      default:
        if (pos < len-1) {
          buffer[pos++] = readch;
          buffer[pos] = 0;
        }
    }
  }
  // No end of line has been found, so return -1.
  return -1;
}
static char buffer[40];
IRsend irsend;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("hello");

}

void loop() {
  const char *hexstring = "0xabcdef0";
   if (Serial.available())
          
    {
  if (readline(Serial.read(), buffer, 80) > 0) {
        Serial.print("You entered: >");
      Serial.print(buffer);
        Serial.println("<");
        StringSplitter *splitter = new StringSplitter(buffer, ',', 3);  // new StringSplitter(string_to_split, delimiter, limit)
  int itemCount = splitter->getItemCount();
      Serial.println(itemCount);

     }
  }
  // put your main code here, to run repeatedly:
   for ( int i =0;i<3;i++)
   {
   // irsend.sendSony(0xa90,20);
    //irsend.sendNEC(0x807F18E7, 32);
  //  irsend.sendNEC(0x00FFA15E,32);
   // irsend.sendNEC(0x00FF6897,32); 16
    //irsend.sendNEC(0x00FF4ab5,32);
  //  irsend.sendNEC(0x00FF6996,32);    96

    //  irsend.sendNEC(0x00FF6A95,32);    56

   //     irsend.sendNEC(0xFFE01F,32);     // 07
   //     irsend.sendNEC(0xFFA857,32);     // 15
     //   irsend.sendNEC(0xFF906F,32);       //09 // syory
        
     //   irsend.sendNEC(0xFF6897,32);     //16 . //flow 
        
       //   irsend.sendNEC(0xFF9867,32);      //19  //frog
          
     //   irsend.sendNEC(0xFFB04F,32);    //0d . //abc
        
   //   irsend.sendNEC(0xFF30CF,32);    //0c
   //   irsend.sendNEC(0xFF18E7,32);      //18
     //   irsend.sendNEC(0xFF7A85,32);        //5e
        
     //  irsend.sendNEC(0xFF10EF,32);    //08

    //  irsend.sendNEC(0xFF38C7,32);    //1c
    //  irsend.sendNEC(0xFF5AA5,32);       //5a

   //    irsend.sendNEC(0xFF42BD,32);   //42

     //  irsend.sendNEC(0xFF4AB5,32);    //52

  
      long number = (long)strtol("0xFF4AB5", NULL, 0);
     // irsend.sendNEC(number,32);
      
     // Serial.println("numbe=");
     //  Serial.println(number,HEX);
    
      //  irsend.sendNEC(0xFF52AD,32);     //4a

        long number11=datacount;
        long number12=255-number11;
        long  datanumber=0xff0000+(number11<<8)+number12;

        datanumber=0xff20DF;
        irsend.sendNEC(datanumber,32);
       
        Serial.println(datanumber,HEX);
    
   // irsend.sendNEC(0x004e3371, 32);
    
    delay(10000);
   // datacount=datacount+16;
   }
}
