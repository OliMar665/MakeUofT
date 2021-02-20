const int motorPin = 3;

const int pirSensorPin = 4;
bool pirSensor_State = false;

const int irSensorPin = 5;
bool irSensor_State = false;

const int buzzerPin = 6;

void setup()
{
  pinMode(motorPin, OUTPUT);
  pinMode(pirSensorPin, INPUT);
  pinMode(irSensorPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop()
{
  
  pirSensor_State = digitalRead(pirSensorPin);

  if(pirSensor_State)
  {
    irSensor_State = digitalRead(irSensor_State);
    
    if(irSensor_State)
    {
      digitalWrite(motorPin, HIGH);
      delay(5000);
      digitalWrite(motorPin, LOW);
    }
    
    else if(irSensor_State == false)
    {
      digitalWrite(motorPin, LOW);
      tone(buzzerPin, 440);
      delay(400);
      noTone(buzzerPin);
    }
  } 
}
