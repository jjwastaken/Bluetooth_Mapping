char Incoming_value = 0;   
const int trigPin1 = 12;
const int echoPin1 = 13; 
const int trigPin2 = 2;
const int echoPin2 = 3;
const int trigPin3 = 4;
const int echoPin3 = 5;
const int trigPin4 = 10;
const int echoPin4 = 11;

//MOTOR 1
const int pin9 = 9;
const int pin8 = 8;
//MOTOR 2
const int pin7 = 7;
const int pin6 = 6;

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
      // set all the motor control pins to outputs
  pinMode(pin9, OUTPUT);
  pinMode(pin8, OUTPUT);
  pinMode(pin7, OUTPUT);
  pinMode(pin6, OUTPUT);  
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

void moveForward(int seconds) // move forward in seconds
{
  digitalWrite(pin9, LOW);
  digitalWrite(pin8, HIGH);  
  digitalWrite(pin7, LOW);
  digitalWrite(pin6, HIGH); 
  delay(seconds * 1000);
}

void moveBackward(int seconds) // move backward in seconds
{
  digitalWrite(pin9, HIGH);
  digitalWrite(pin8, LOW);
  digitalWrite(pin7, HIGH);
  digitalWrite(pin6, LOW);
  delay(seconds * 1000);
}

void turnRight(int seconds) {
  digitalWrite(pin9, HIGH);
  digitalWrite(pin8, LOW);
  digitalWrite(pin7, LOW);
  digitalWrite(pin6, HIGH);
  delay(seconds * 1000);
}

void turnLeft(double seconds) {
  digitalWrite(pin9, LOW);
  digitalWrite(pin8, HIGH);
  digitalWrite(pin7, HIGH);
  digitalWrite(pin6, LOW);
  delay(seconds * 1000);
}

void stopp()
{
  digitalWrite(pin9, LOW);
  digitalWrite(pin8, LOW);
  digitalWrite(pin7, LOW);
  digitalWrite(pin6, LOW);
}

const int avoidDistance = 0.8; // 10cm avoid
void loop()
{
    moveForward(1);
      char cmd = Serial.read();
      double distanceUpLeft = ultraSonic(trigPin1, echoPin1);
      double distanceUpRight = ultraSonic(trigPin2, echoPin2);
      double distanceLeft = ultraSonic(trigPin3, echoPin3);
      double distanceRight = ultraSonic(trigPin4, echoPin4);
      if(cmd == 's') // Scanning area 
      {
        //Serial.print("ultra upLeft: ");
        Serial.print(distanceUpLeft);
        Serial.print(",");
        Serial.print(distanceUpRight);
        Serial.print(",");
        Serial.print(distanceLeft);
        Serial.print(",");
        Serial.println(distanceRight);
        delay(20);
        //Serial.print("ultra upRight: ");
        //Serial.println(distanceUpRight);
        //delay(20);
        //Serial.print("ultra left: ");
        //Serial.println(distanceLeft);
        //delay(20);
        //Serial.print("ultra right: ");
        //Serial.println(distanceRight);
        //delay(20);
      }
        if(distanceUpLeft + 0.05 < distanceUpRight && distanceUpRight < 10) // if left is blocked
        {
          turnRight(1);
        }
        else if(distanceUpLeft - 0.05 > distanceUpRight && distanceUpRight < 10)
        {
          turnLeft(1);
        }
      
}
