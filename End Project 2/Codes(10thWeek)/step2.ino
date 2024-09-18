int pwmPin = 9;
int outputPin = A0;
float setPointVoltage = 2.3;
float D = setPointVoltage/5;
float setPoint = 255*D;

void setup()
{
Serial.begin(9600);  
}

void loop()
{
  analogWrite(pwmPin, setPoint);
  //delay(500);
}

