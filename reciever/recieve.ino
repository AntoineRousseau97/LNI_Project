#include <SoftwareSerial.h>
#include <Adafruit_GFX.h>    // Core graphics library
#include <MCUFRIEND_kbv.h>   // Hardware-specific library
MCUFRIEND_kbv tft;


#include <Fonts/FreeSans9pt7b.h>
#include <Fonts/FreeSans12pt7b.h>
#include <Fonts/FreeSerif12pt7b.h>
#include <FreeDefaultFonts.h>

#define BLACK   0x0000
#define RED     0xF800
#define GREEN   0x07E0
#define WHITE   0xFFFF
#define GREY    0x8410

SoftwareSerial BTserial(51, 53); // RX | TX
//// Connect the HC-06 TX to Arduino pin 2 RX.
//// Connect the HC-06 RX to Arduino pin 3 TX through a voltage divider.
////
//

String sensor1 = "";
//uint8_t ID;
//
void setup()
{
Serial.begin(9600);
Serial.println("Arduino is ready");
BTserial.begin(9600);

// screen
    uint16_t ID = tft.readID();
    Serial.println("Example: Font_simple");
    Serial.print("found ID = 0x");
    Serial.println(ID, HEX);
    if (ID == 0xD3D3) ID = 0x9481; //force ID if write-only display
    tft.begin(ID);
    tft.setRotation(0);
    tft.fillScreen(WHITE);
}

void loop()
{
String msg1 = "Distance from sensor 1 (cm) : ";
showmsgXY(20, 80, 1, &FreeSans9pt7b,msg1 );
// Keep reading from HC-06 and send to Arduino Serial Monitor
if (BTserial.available())
{  
  
//    c = BTserial.read();
//    c = String(ID);
//    Serial.println(c);
//    Serial.println(BTserial.readString());
//    sensor1 = BTserial.readString();
//    Serial.println(sensor1);
}
// sensor1 = BTserial.readString();
    sensor1 = BTserial.parseInt();
    String sensorValue = String(sensor1);
    tft.fillRect(0,100,300,80,WHITE);
    showmsgXY(20, 160, 1, &FreeSevenSegNumFont,sensor1);
    
    

//    delay(100);

}


void showmsgXY(int x, int y, int sz, const GFXfont *f, String msg)
{
    int16_t x1, y1;
    uint16_t wid, ht;
//    tft.drawFastHLine(0, y, tft.width(), WHITE);
    tft.setFont(f);
    tft.setCursor(x, y);
    tft.setTextColor(RED);
    tft.setTextSize(sz);
    tft.print(msg);
    delay(5);
}
