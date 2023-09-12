#include <Adafruit_GFX.h>     
#include <Adafruit_SSD1306.h>
#include <Adafruit_BMP280.h>

#define SCREEN_WIDTH 128 
#define  SCREEN_HEIGHT 32 

Adafruit_SSD1306 display(SCREEN_WIDTH,  SCREEN_HEIGHT, &Wire, -1);
Adafruit_BMP280  bmp;

void setup() {  

  Serial.begin(9600);

  if (!bmp.begin(0x76)) {
    Serial.println("Could not find a valid BMP280 sensor, check wiring!");
    while (1);
  }

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); 
  display.clearDisplay();
  display.display();
  delay(1000);
}

void  loop() {

    display.clearDisplay();       
    float Pres = (bmp.readPressure())/100;        
    float Alt = bmp.readAltitude(1019.66);      

    display.setCursor(0,0);                   
    display.setTextColor(WHITE);
    display.setTextSize(2); 
    display.print("Pre:");
    display.print(Pres);

    display.setCursor(0,18);
    display.setTextColor(WHITE);
    display.setTextSize(2);   
    display.print("Alt:");
    display.print(Alt);
    display.display();
    delay(2000);
}
