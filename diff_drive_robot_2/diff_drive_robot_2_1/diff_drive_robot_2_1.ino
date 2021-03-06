/*
   Title : diff_drive_robot_2_1
   Author : ConceptBug

   < Description >
   "STEP #2-1"
   Before operating the motors, we must check the motor wiring and soldering first.
   Through this step, we can assure the motor direction relative to motor wiring(or soldering).

   When I assemble the chassis, I did not consider and check the wiring between motor and motor drive.
   The motors should spin forward direction if we put HIGH at IN1(or IN3), and LOW at IN2(or IN4).
   But, even if we put the HIGH in IN1(or IN3) and the LOW in IN2(or IN4), the result cannot be guaranteed
   if the connection between wires from motor and motor driver is incorrect, or soldered wires with motor itself is wrong.
   
   By calling motorTest() function, we would know the actual spinning direction of motor according to the parameter 'Direction' we give.
   As a result, I coud know that the right motor connection should be opposite.
   Changing the motor soldering and connection on motor drive results same effect.
*/

#define recvCH1 9   // PWM signal from receiver CH1: Throttle
#define recvCH2 10  // PWM signal from receiver CH2: Rudder
#define recvCH3 11  // PWM signal from receiver CH3: Toggle Button
#define motorLeft_EN 3    // Left Motor: ENA(PWM) pin
#define motorLeft_OUT1 2  // Left Motor: IN1 pin
#define motorLeft_OUT2 4  // Left Motor: IN2 pin
#define motorRight_EN 5   // Right Motor: ENB(PWM) pin
#define motorRight_OUT1 7 // Right Motor: IN3 pin
#define motorRight_OUT2 6 // Right Motor: IN4 pin
#define ACT 4   // Linear Actuator enable signal output pin

unsigned long valueCH1;
unsigned long valueCH2;
unsigned long valueCH3;

void motorTest(bool Side, bool Direction, int Speed, int Duration) {
  /*
    bool Side : select which motor to run. {false: Left; true: Right}
    bool Direction : select the direction of motor.
    int Speed : speed value to run motor. {0 <= Speed <256}
    int Duration : time to run. [msec]
  */
  int pwmPin = 0;
  if (Side == false)
  {
    digitalWrite(motorLeft_OUT1, Direction);
    digitalWrite(motorLeft_OUT2, !Direction);
    pwmPin = motorLeft_EN;
    Serial.print("LEFT selected.\t");
  }
  else
  {
    digitalWrite(motorRight_OUT1, Direction);
    digitalWrite(motorRight_OUT2, !Direction);
    pwmPin = motorRight_EN;
    Serial.print("RIGHT selected.\t");
  }
  Serial.print("motor RUN,   ");
  Serial.print("for "); Serial.print(Duration); Serial.println(" msec.");
  analogWrite(pwmPin, Speed);
  delay(Duration);
}

void motorStop(bool Side, int Duration) {
  if (Side == false) {
    //analogWrite(motorLeft_EN, 0);
    digitalWrite(motorLeft_OUT1, HIGH);
    digitalWrite(motorLeft_OUT2, HIGH);
    Serial.print("Left ");
  }
  else {
    //analogWrite(motorRight_EN, 0);
    digitalWrite(motorRight_OUT1, HIGH);
    digitalWrite(motorRight_OUT2, HIGH);
    Serial.print("Right ");
  }
  Serial.println("motor STOP");
  delay(Duration);
}

void setup() {
  Serial.begin(19200);
  pinMode(recvCH1, INPUT);
  pinMode(recvCH2, INPUT);
  pinMode(recvCH3, INPUT);
  pinMode(motorLeft_EN, OUTPUT);
  pinMode(motorLeft_OUT1, OUTPUT);
  pinMode(motorLeft_OUT2, OUTPUT);
  pinMode(motorRight_EN, OUTPUT);
  pinMode(motorRight_OUT1, OUTPUT);
  pinMode(motorRight_OUT2, OUTPUT);
}

void loop() {
  // Left motor, direction: false, with 50 speed, for 3 sec.
  motorTest(false, false, 100, 2000); // for left motor, Side; 'false' was forward.
  motorStop(false, 1000);
  // Left motor, direction: true, with 50 speed, for 3 sec.
  motorTest(false, true, 100, 2000);  // for left motor, Side; 'true' was backward.
  motorStop(false, 1000);
  // Right motor, direction: false, with 50 speed, for 3 sec.
  motorTest(true, false, 100, 2000);  // for left motor, Side; 'false' was backward.
  motorStop(true, 1000);
  // Right motor, direction: true, with 50 speed, for 3 sec.
  motorTest(true, true, 100, 2000);   // for left motor, Side; 'true' was forward.
  motorStop(true, 1000);
}
