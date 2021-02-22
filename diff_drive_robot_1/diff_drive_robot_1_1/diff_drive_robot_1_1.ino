/*
 * Title : diff_drive_robot_1_1
 * Author : ConceptBug
 * 
 * < Description >
 * "STEP #1-1"
 * Simply receive PWM signals from receiver FS-A3 and indicate these values to serial monitor.
 * With this STEP, we can get the minimum, idle, and maximum PWM signal values of each channels.
 * I used pulseIn() function to read 
 */
 
#define recvCH1 9   // PWM signal from receiver CH1: Throttle
#define recvCH2 10  // PWM signal from receiver CH2: Rudder
#define recvCH3 11  // PWM signal from receiver CH3: Toggle Button

#define motorLeft_EN 3    // Left Motor: ENA pin
#define motorLeft_OUT1 2  // Left Motor: IN1 pin
#define motorLeft_OUT2 1  // Left Motor: IN2 pin
#define motorRight_EN 5   // Right Motor: ENB pin
#define motorRight_OUT1 7 // Right Motor: IN3 pin
#define motorRight_OUT2 6 // Right Motor: IN4 pin

#define ACT 4   // Linear Actuator enable signal output pin

unsigned long valueCH1;
unsigned long valueCH2;
unsigned long valueCH3;

void setup()
{
  Serial.begin(9600);
  pinMode(recvCH1, INPUT);
  pinMode(recvCH2, INPUT);
  pinMode(recvCH3, INPUT);
}

void loop()
{
  // receive PWM signals from receiver channel 1 to 3.
  valueCH1 = pulseIn(recvCH1, HIGH);
  valueCH2 = pulseIn(recvCH2, HIGH);
  valueCH3 = pulseIn(recvCH3, HIGH);

  // print the values with serial monitor
  Serial.print("CH1: "); Serial.print(valueCH1); Serial.print("\t");
  Serial.print("CH2: "); Serial.print(valueCH2); Serial.print("\t");
  Serial.print("CH3: "); Serial.println(valueCH3);
}
