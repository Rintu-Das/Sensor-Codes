
#define Flame 6
#define Alarm 12
void setup() 
{
  Serial.begin(9600);
  Serial.println("Fire Alarm");
  pinMode(Flame, INPUT);  
  pinMode(Alarm, OUTPUT); 
}

void loop() 
{
  int fire = digitalRead(Flame); 

   if(fire == LOW)
   {
   digitalWrite(Alarm, HIGH);
   Serial.println("Fire! Fire!");
   }

   else
   {
    digitalWrite(Alarm, LOW);
    Serial.println("Peace");
   }

}
