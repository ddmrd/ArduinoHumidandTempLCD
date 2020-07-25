#include <LiquidCrystal.h>
#include <SDHT.h>
int Contrast = 11;
int RegisterSelect = 9;
int epin = 12;

int DataPin4  = 4;
int DataPin5  = 5;
int DataPin6 = 6;
int DataPin7  = 7;
SDHT dht;
LiquidCrystal lcd(RegisterSelect,epin,DataPin4,DataPin5,DataPin6,DataPin7);

double Cels;
double Humid;

void layout() {
  Serial.print("   Celsius => ");
  Serial.print(String(double(dht.celsius) / 10, 1));
   Cels = double(dht.celsius) / 10, 1;
  Serial.println(" C");
  Serial.print("   Humdity => ");
  Serial.print(String(double(dht.humidity) / 10, 1));
  Humid = double(dht.humidity) / 10, 1;
  Serial.println("%  "); 
  
}

void setup() {
  // put your setup code here, to run once:
lcd.begin(16,2);
lcd.print("Temp C, Humid");
pinMode(Contrast,OUTPUT);
pinMode(A1,INPUT);




}

void loop() {
  // put your main code here, to run repeatedly:
  if (dht.read(DHT11, A1)) layout();
  lcd.setCursor(0,1);
  lcd.print(Cels);
  lcd.print("  " );
  lcd.print(Humid);
  lcd.print(" %");


}
