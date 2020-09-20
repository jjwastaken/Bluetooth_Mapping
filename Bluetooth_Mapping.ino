char Incoming_value = 0;   
const int trigPin1 = 12;
const int echoPin1 = 13; 
const int trigPin2 = 10;
const int echoPin2 = 11;
const int trigPin3 = 2;
const int echoPin3 = 3;
const int trigPin4 = 4;
const int echoPin4 = 5;

void setup() 
{ 
  Serial.begin(9600);//Sets the baud rate for serial data       
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);  
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT); 
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);  
  pinMode(trigPin4, OUTPUT);
  pinMode(echoPin4, INPUT);   
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
      double distanceUpLeft = ultraSonic(trigPin1, echoPin1);
      double distanceUpRight = ultraSonic(trigPin2, echoPin2);
      double distanceLeft = ultraSonic(trigPin3, echoPin3);
      double distanceRight = ultraSonic(trigPin4, echoPin4);
      if(cmd == 's')
      {
        //Serial.print("ultra upLeft: ");
        Serial.println(distanceUpLeft);
        delay(100);
        //Serial.print("ultra upRight: ");
        Serial.println(distanceUpRight);
        delay(100);
        //Serial.print("ultra left: ");
        Serial.println(distanceLeft);
        delay(100);
        //Serial.print("ultra right: ");
        Serial.println(distanceRight);
        delay(100);
      }
  }
}
