
#define LED 2
const int trigPin = 4;
const int echoPin = 5;
long duration;
int distance;

void setup() 
{
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(LED, OUTPUT);

  //digitalWrite(echoPin, HIGH);
}

void loop() 
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  //int distance = pulseIn(echoPin, HIGH, 26000);
  //distance = distance/58;

  duration = pulseIn(echoPin, HIGH);
  distance = duration*0.035/2;

  Serial.print("Distance : ");
  Serial.println(distance);
  delay(200);

  if(distance>20 && distance<40)
  {
    digitalWrite(LED , HIGH);
  }
  else
  {
    digitalWrite(LED , LOW);
  }
}
