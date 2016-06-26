#include <SPI.h>
#include <RFID.h>

#define SS_PIN 10
#define RST_PIN 9

RFID rfid(SS_PIN, RST_PIN); 

    int serNum0;
    int serNum1;
    int serNum2;
    int serNum3;
    int serNum4;

void setup()
{
  Serial.begin(9600);
  SPI.begin(); 
  rfid.init();
}

void loop()
{   
      if (rfid.isCard()) {
        if (rfid.readCardSerial()) {
            if (rfid.serNum[0] != serNum0
                && rfid.serNum[1] != serNum1
                && rfid.serNum[2] != serNum2
                && rfid.serNum[3] != serNum3
                && rfid.serNum[4] != serNum4
            ) {
                Serial.print("ID:");
                for(int n=0;n<5;n++)
               {
                  Serial.print(tagData[n],DEC);
                 if(n<4)
                 {
                    Serial.print(" ");
                  }
               }
                Serial.print("\r\n>");
            }
        }
    }
}
