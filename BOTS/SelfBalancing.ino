#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>

Adafruit_MPU6050 mpu;

// Motor pins
#define IN1 D5  // Left motor +
#define IN2 D6  // Left motor -
#define IN3 D7  // Right motor +
#define IN4 D3  // Right motor -

// PID constants (tune these!)
float Kp = 22.0;
float Ki = 0.0;
float Kd = 1.2;

// PID variables
float error, previous_error = 0;
float integral = 0, derivative = 0;
float setpoint = 0;  // Target angle (upright)
float angle = 0;

// Timing
unsigned long last_time = 0;
float elapsed_time;

void setup() {
  Serial.begin(115200);
  Wire.begin(D2, D1);  // SDA, SCL

  if (!mpu.begin()) {
    Serial.println("MPU6050 not found!");
    while (1);
  }

  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
  delay(100);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  last_time = millis();
}

void loop() {
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  // Calculate pitch angle using complementary filter
  float accel_angle = atan2(a.acceleration.x, a.acceleration.z) * 180 / PI;
  float gyro_rate = g.gyro.y * 180 / PI;

  unsigned long now = millis();
  elapsed_time = (now - last_time) / 1000.0;
  last_time = now;

  angle = 0.98 * (angle + gyro_rate * elapsed_time) + 0.02 * accel_angle;

  // --- PID Control ---
  error = setpoint - angle;
  integral += error * elapsed_time;
  derivative = (error - previous_error) / elapsed_time;
  float output = Kp * error + Ki * integral + Kd * derivative;
  previous_error = error;

  // Limit PWM output
  output = constrain(output, -1023, 1023);
  Serial.print("Angle: "); Serial.print(angle);
  Serial.print("  PID Output: "); Serial.println(output);

  moveMotors(output);
}

void moveMotors(float pwm) {
  int motorSpeed = abs((int)pwm);
  motorSpeed = constrain(motorSpeed, 0, 1023);

  if (pwm > 0) {
    // Move forward
    analogWrite(IN1, motorSpeed);
    analogWrite(IN2, 0);
    analogWrite(IN3, 0);
    analogWrite(IN4, motorSpeed);
  } else if (pwm < 0) {
    // Move backward
    analogWrite(IN1, 0);
    analogWrite(IN2, motorSpeed);
    analogWrite(IN3, motorSpeed);
    analogWrite(IN4, 0);
  } else {
    // Stop
    analogWrite(IN1, 0);
    analogWrite(IN2, 0);
    analogWrite(IN3, 0);
    analogWrite(IN4, 0);
  }
}
