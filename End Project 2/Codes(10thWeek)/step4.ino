const int pwmPin = 9;
const int outputPin = A0;

float setPointVoltage = 2.3;
float D = setPointVoltage/5;
float setPoint = 255*D;
float outputVoltage, err;
float errSum = 0, sigmaErr = 0;
int n = 0;

int Kp = 25, Ki = 25;;

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
    sigmaErr += err;

    D = (err/5)*Kp + (sigmaErr/5)*Ki;

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