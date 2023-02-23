
int red_led = 12;
int green_led = 11;
int buzzer = 10;
int smokeA0 = A5;
int sensorThres = 500;

void setup() 
{
 pinMode (red_led, OUTPUT);
 pinMode (green_led, OUTPUT);
 pinMode (buzzer, OUTPUT);
 pinMode (smokeA0, INPUT);
 Serial.begin(9600);
}

void loop() 
{
  int analogSensor = analogRead(smokeA0);

  Serial.print("Pin A0 : ");
  Serial.println(analogSensor);

  if (analogSensor > sensorThres)
  {
    digitalWrite(red_led, HIGH);
    digitalWrite(green_led, LOW);
    tone(buzzer, 1000, 200);
  }
  else
  {
    digitalWrite(red_led, LOW);
    digitalWrite(green_led, HIGH);
    noTone(buzzer); 
  }
  delay(100);
}
