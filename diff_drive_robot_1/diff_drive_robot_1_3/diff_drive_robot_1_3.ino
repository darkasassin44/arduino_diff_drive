/*
 * Title : diff_drive_robot_1_3
 * Author : ConceptBug
 * 
 * < Description >
 * "STEP #1-3"
 * There is a map() function which only deals with integer math.
 * So I made custom scaling function getScale() manually which can calculate other type of data.
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

  return avg;
}

float getScale
  (int in_val, int in_min, int in_max, float out_min, float out_max) {
  float result = ((out_max-out_min)/(in_max-in_min)) * (in_val-in_max) + out_max;
  Serial.print(result, 1); Serial.println("%");
  return result;
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
  // get average of 10 times of received PWM signals.
  valueCH1 = getAvg(recvCH1, 10);
  valueCH2 = getAvg(recvCH2, 10);
  valueCH3 = getAvg(recvCH3, 10);

  // call scaler
  getScale(valueCH1, 992, 1981, -100.0, 100.0);
  getScale(valueCH2, 985, 1967, 100.0, -100.0);
  getScale(valueCH3, 992, 1984, -100.0, 100.0);
}
