const int pwmPin = 9;
const int outputPin = A0;

float setPointVoltage = 2.3;
float D = setPointVoltage/5;
float setPoint = 255*D;
float outputVoltage;
float err, errSum = 0;
int n = 0;
int Kp = 25;

void setup()
{
Serial.begin(9600);  
}

void loop()
{
  n++;
  outputVoltage = (float) analogRead(outputPin)/1023*5;
  errSum += (setPointVoltage - outputVoltage);

  if(n == 100) 
  {
    err = errSum/n;
    Serial.println(err);
    
    D = (err/5)*Kp;
    if(D < 0)
      D = 0;
    if(D > 255)
      D = 255;

    setPoint = 255*D;
    analogWrite(pwmPin, setPoint);
    errSum = 0;
    //delay(500);
  }
}

