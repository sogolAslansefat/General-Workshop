const int outputPin = A0;
float err, outputVoltage;
float setPointVoltage = 2.5;
void setup()
{
Serial.begin(9600);  
}

void loop()
{
  outputVoltage = (float) analogRead(outputPin)/1023*5;
  err = (setPointVoltage - outputVoltage);
  Serial.println(err);
  //delay(500);
}

