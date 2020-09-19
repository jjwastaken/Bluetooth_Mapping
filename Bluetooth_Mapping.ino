char Incoming_value = 0;   
const int trigPin = 11;
const int echoPin = 12; 

void setup() 
{ 
  Serial.begin(9600);//Sets the baud rate for serial data       
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);   
}

void loop()
{
  if(Serial.available() > 0) 
  {
    char cmd = Serial.read(); 
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    long duration = pulseIn(echoPin, HIGH);
    double distance = (double)duration * 345 / 2 / 1000000;
    if (cmd == 's')
    {
      Serial.println(distance);
      delay(100);
    }
  }
}
