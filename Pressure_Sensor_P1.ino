#include "SPFD5408_Adafruit_GFX.h"    // Core graphics library
#include "SPFD5408_Adafruit_TFTLCD.h" // Hardware-specific library
#include "SPFD5408_TouchScreen.h"

// Pin assignments for the TFT touch screen
#define YP    A1
#define XM    A2
#define YM    7
#define XP    6

// Calibrated values for the TFT touch screen  
#define TS_MINX   178
#define TS_MINY   75
#define TS_MAXX   931
#define TS_MAXY   895

// Instantiate the ts object
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);

#define LCD_RD    A0
#define LCD_WR    A1
#define LCD_CD    A2
#define LCD_CS    A3
#define LCD_RESET A4

// Instantiate the tft object
Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);

// Assign human-readable names to some common 16-bit color values:
#define  BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

int c = 0;

const int check = 31;
const int in =27;
const int out = 29;
const int equal = 33;
const int extra = 35;


void setup(void) {
  Serial.begin(9600);
  //Serial.println(F("Paint!"));

  pinMode(23, INPUT);
  pinMode(24, INPUT);

  pinMode(check, OUTPUT);
  pinMode(in, OUTPUT);
  pinMode(out, OUTPUT);
  pinMode(equal, OUTPUT);
  pinMode(extra, OUTPUT);
  
  tft.reset();
  tft.begin(0x8357);      // SPFD5408 compatible
  tft.setRotation(1);     // This settings works for me with correct orientation
                          // tft.setRotation(2);
  tft.fillScreen(BLACK);  //Set Background Color with BLACK

  tft.setTextColor(YELLOW);
  tft.setTextSize(3.5);
  tft.setCursor(20,36);
  tft.println("PRESSURE");
  tft.setCursor(20,66);
  tft.println("REQUIRED");

  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.setCursor(0,112);
  tft.println("--------------------------");

  tft.setTextColor(WHITE);
  tft.setTextSize(3.5);
  tft.setCursor(30,154);
  tft.println("PRESSURE");
  tft.setCursor(20,184);
  tft.println("AVAILABLE");

}

void loop() 
{ 
  int a = digitalRead(23);
  if (a==1)
  {
    c=c+1;
    Serial.println(c);
    delay(300);

  tft.fillRect(200,36,90,50, YELLOW);
  
  tft.setTextColor(RED);
  tft.setTextSize(6);
  tft.setCursor(210,40);
  tft.print(c);
  delay(100);
  }
  
  int b = digitalRead(25);
  if (b==1)
  {
    c=c-1;
    Serial.println(c);
    delay(300);

  tft.fillRect(200,36,90,50, YELLOW);
  
  tft.setTextColor(RED);
  tft.setTextSize(6);
  tft.setCursor(210,40);
  tft.print(c);
  delay(100);
  
  }

 if(c<68 & c>6)
 {
 int sensorVal = analogRead(A8);
 Serial.print("sensor value: ");
 Serial.print(sensorVal);
    
 float voltage = (sensorVal*5.0)/1024.0;
 Serial.print(" Volts : ");
 Serial.print(voltage);
    
  float pressure_pascal = (3.0*((float)voltage-0.475))*1000000.0;                       //calibrate here
  float pressure_bar = pressure_pascal/10e5;
  float pressure_psi = pressure_bar*14.5038;
  int pressure_psi_2 = pressure_bar*14.5038;
    Serial.print(" Pressure = ");
    Serial.print(pressure_bar);
    Serial.print(" bars  ");
    Serial.print ("psi ");
    Serial.print (pressure_psi);
    Serial.print (" psi_2:- ");
    Serial.print (pressure_psi_2);
    Serial.println();
    
  delay(500);

  if(pressure_psi<100)
  {
  tft.fillRect(200,150,90,50, YELLOW);

  tft.setTextColor(RED);
  tft.setTextSize(6);
  tft.setCursor(210,154);
  tft.print(pressure_psi_2);
  delay(100);
  }

  if (pressure_psi<c && pressure_psi>5)
  {
    digitalWrite(in, LOW);
    digitalWrite(check, HIGH);
    delay(2000);
    digitalWrite(out, HIGH);
    digitalWrite(equal, HIGH);
  }

   if (pressure_psi>c)
  {
    digitalWrite(out, LOW);
    digitalWrite(check, LOW);
    digitalWrite(in, HIGH);
    digitalWrite(equal, HIGH);
  }

   if (pressure_psi<=c && pressure_psi>=(c-2))
  {
    digitalWrite(equal, LOW);
    digitalWrite(check, LOW);
    digitalWrite(out, HIGH);
    digitalWrite(in, HIGH);
  }

  else
  {
    digitalWrite(in, HIGH);
    digitalWrite(check, LOW);
    digitalWrite(out, HIGH);
    digitalWrite(equal, HIGH);
  }

  }
 }
