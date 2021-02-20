const int motorPin = 3;

const int irSensorPin = 5;
bool irSensor_State = false;

float duration_us, distance_cm;

const int TRIG   = 12; 
const int ECHO   = 11; 
const int BUZZER = 13; 
const int DISTANCE_THRESHOLD = 200; // cm

void setup()
{
  Serial.begin (9600);
  pinMode(motorPin, OUTPUT);

  pinMode(irSensorPin, INPUT);
            
  pinMode(TRIG, OUTPUT);  
  pinMode(ECHO, INPUT);    
  pinMode(BUZZER, OUTPUT); 
}

void loop()
{

  digitalWrite(TRIG, LOW); 
  delayMicroSeconds(2);
  
  /* I tried adding the two above back in
  Let's see if that doesn't make a difference */
  
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  
  

  
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
      // delay(400); -  LET'S SEE IF THIS ALSO MAKES A DIFFERENCE
    }
  

   
  duration_us = pulseIn(ECHO, HIGH);
  // calculate the distance
  distance_cm = 0.017 * duration_us;

  if(distance_cm < DISTANCE_THRESHOLD)

    digitalWrite(BUZZER, HIGH); 
  else
      digitalWrite(BUZZER, LOW); 


  delay(500);
}
