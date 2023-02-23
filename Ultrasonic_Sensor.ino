
const int trigPin = 9;
const int echoPin = 8;
long duration;
int distance, distanceInch;

void setup() 
{
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() 
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(1000);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration*0.034/2;
  distanceInch = duration*0.0133/2;

  Serial.println(" CM");
  Serial.print(distance);
  delay(100);

}
