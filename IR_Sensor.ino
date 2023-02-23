
#define Obstacle 6
#define Alarm 12

void setup() 
{
  Serial.begin(9600);
  pinMode(Obstacle, INPUT);
   pinMode(Alarm, OUTPUT);
}

void loop() 
{
  int detect = digitalRead(Obstacle);

  if(detect == LOW)
  {
    Serial.println("Obstacle On The Way");
    digitalWrite(Alarm, HIGH);
  }
  else
  {
    Serial.println("All Clear");
    digitalWrite(Alarm, LOW);
  }


}
