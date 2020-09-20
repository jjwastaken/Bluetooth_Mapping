char Incoming_value = 0;   
const int trigPin1 = 11;
const int echoPin1 = 12; 
const int trigPin2 = 9;
const int echoPin2 = 10;

void setup() 
{ 
  Serial.begin(9600);//Sets the baud rate for serial data       
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);  
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);  
}

double ultraSonic(int trig, int ech)
{
    digitalWrite(trig, LOW);
    delayMicroseconds(2);
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);
    long duration = pulseIn(ech, HIGH);
    double distance = (double)duration * 345 / 2 / 1000000;
    return distance;
}

void loop()
{
  if(Serial.available() > 0) 
  {
      char cmd = Serial.read();
      double distance1 = ultraSonic(trigPin1, echoPin1);
      double distance2 = ultraSonic(trigPin2, echoPin2);
      if(cmd == 's')
      {
        //Serial.print("ultra 1: ");
        Serial.println(distance1);
        delay(100);
        //Serial.print("ultra 2: ");
        Serial.println(distance2);
        delay(100);
      }
  }
}
