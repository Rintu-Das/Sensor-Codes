#define A0 4

void setup()
{
  pinMode(A0, INPUT);
  Serial.begin(9600);
}
void loop()
{ 
  // Serial.println(analogRead(A0)*(3.3/4095));
  float ACSValue = 0.0, Samples = 0.0, AvgACS = 0.0, BaseVol = 1.48; //Change BaseVol as per your reading in the first step.
  for (int x = 0; x < 500; x++) { //This would take 500 Samples
    ACSValue = analogRead(A0);
    Samples = Samples + ACSValue;
    delay (3);
  }
  AvgACS = Samples/500;
  Serial.println((((AvgACS) * (3.3 / 4095.0)) - BaseVol ) / 0.062 ); //0.066V = 66mVol. This is sensitivity of your ACS module.
}