#include <Wire.h>
#include <ArduinoNunchuk.h>

#define BAUDRATE 19200
#define NEUTRAL_X 133
#define NEUTRAL_Y 129

int led_forward = 9;
int led_reverse = 10;
int led_right = 11;

int forward_brightness = 0;
int reverse_brightness = 0;
int right_brightness = 0;

ArduinoNunchuk nunchuk = ArduinoNunchuk();

void setup()
{
  pinMode(led_forward, OUTPUT);
  pinMode(led_reverse, OUTPUT);
  pinMode(led_right, OUTPUT);
  Serial.begin(BAUDRATE);
  nunchuk.init();
}

void loop()
{
  nunchuk.update();

  if (nunchuk.analogX > NEUTRAL_X) {
    Serial.print("RIGHT | val: ");
    int val = nunchuk.analogX - NEUTRAL_X;
    Serial.print(val, DEC);
    Serial.println(" ");
    right_brightness = val * 2;
    analogWrite(led_right, right_brightness);
  } else {
    analogWrite(led_right, 0);
  }

  if (nunchuk.analogX < NEUTRAL_X) {
    Serial.print("LEFT | val: ");
    int val = abs(nunchuk.analogX - NEUTRAL_X);
    Serial.print(val, DEC);
    Serial.println(" ");
  }

  if (nunchuk.analogY > NEUTRAL_Y) {
    Serial.print("FORWARD | val: ");
    int val = nunchuk.analogY - NEUTRAL_Y;
    Serial.print(val, DEC);
    Serial.println(" ");
    forward_brightness = val * 2;
    analogWrite(led_forward, forward_brightness);
  } else {
    analogWrite(led_forward, 0);
  }
  if (nunchuk.analogY < NEUTRAL_Y) {
    Serial.print("REVERSE | val: ");
    int val = abs(nunchuk.analogY - NEUTRAL_Y);
    Serial.print(val, DEC);
    Serial.println(" ");
    reverse_brightness = val * 2;
    analogWrite(led_reverse, reverse_brightness);
  } else {
    analogWrite(led_reverse, 0);
  }

  if (nunchuk.zButton == 1) {
    Serial.println("Z Pressed");
  }
  if (nunchuk.cButton == 1) {
    Serial.println("C Pressed");
  }

}
