//MOTOR 1
const int pin9 = 9;
const int pin8 = 8;
//MOTOR 2
const int pin7 = 7;
const int pin6 = 6;

void setup()
{
  // set all the motor control pins to outputs
  pinMode(pin9, OUTPUT);
  pinMode(pin8, OUTPUT);
  pinMode(pin7, OUTPUT);
  pinMode(pin6, OUTPUT);
}
void demoOne()
{
  // this function will run the motors in both directions at a fixed speed
  // turn on motor A
  digitalWrite(pin9, HIGH);
  digitalWrite(pin8, LOW);
  // turn on motor B
  digitalWrite(pin7, HIGH);
  digitalWrite(pin6, LOW);
  // run for 2 seconds
  delay(2000);
  // now change motor directions
  digitalWrite(pin9, LOW);
  digitalWrite(pin8, HIGH);  
  digitalWrite(pin7, LOW);
  digitalWrite(pin6, HIGH); 
  delay(2000);
  // now turn off motors
  digitalWrite(pin9, LOW);
  digitalWrite(pin8, LOW);  
  digitalWrite(pin7, LOW);
  digitalWrite(pin6, LOW);
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

void stopp()
{
  digitalWrite(pin9, LOW);
  digitalWrite(pin8, LOW);
  digitalWrite(pin7, LOW);
  digitalWrite(pin6, LOW);
}

void loop()
{
  demoOne();
  moveForward(1); // move forward 1 sec
  moveBackward(2); // move backward 2 sec
  stopp();
  delay(1000);
}
