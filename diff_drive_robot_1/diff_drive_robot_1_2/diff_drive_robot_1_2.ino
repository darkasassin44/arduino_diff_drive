/*
 * Title : diff_drive_robot_1_2
 * Author : ConceptBug
 * 
 * < Description >
 * "STEP #1-2" 
 * Get an average from received PWM values to reduce the noise.
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

int getAvg(int channel, int count) {
  int sum = 0;
  int cnt = 0;
  int avg;

  while(cnt < count) {
    sum = sum + pulseIn(channel, HIGH, 50000);
    cnt++;
  }

  avg = sum / count;

  Serial.print("Ch: "); Serial.print(channel);
  Serial.print("\tsum: "); Serial.print(sum);
  Serial.print("\tAvg: "); Serial.println(avg);

  return avg;
}

void setup()
{
  Serial.begin(115200);
  pinMode(recvCH1, INPUT);
  pinMode(recvCH2, INPUT);
  pinMode(recvCH3, INPUT);
}

void loop()
{
  // receive PWM signals from receiver channel 1 to 3.
  valueCH1 = getAvg(recvCH1, 10);
  valueCH2 = getAvg(recvCH2, 10);
  valueCH3 = getAvg(recvCH3, 10);
}#define recvCH1 9   // PWM signal from receiver CH1: Throttle
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

int getAvg(int channel, int count) {
  int sum = 0;
  int cnt = 0;
  int avg;

  while(cnt < count) {
    sum = sum + pulseIn(channel, HIGH, 50000);
    cnt++;
  }

  avg = sum / count;

  Serial.print("Ch: "); Serial.print(channel);
  Serial.print("\tsum: "); Serial.print(sum);
  Serial.print("\tAvg: "); Serial.println(avg);

  return avg;
}

void setup()
{
  Serial.begin(115200);
  pinMode(recvCH1, INPUT);
  pinMode(recvCH2, INPUT);
  pinMode(recvCH3, INPUT);
}

void loop()
{
  // receive PWM signals from receiver channel 1 to 3.
  valueCH1 = getAvg(recvCH1, 10);
  valueCH2 = getAvg(recvCH2, 10);
  valueCH3 = getAvg(recvCH3, 10);
}
