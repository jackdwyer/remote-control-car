#include <Wire.h>
#include <ArduinoNunchuk.h>

#define BAUDRATE 9600
#define BUFFER 50

#define MAX_X     255
#define NEUTRAL_X 130
#define MIN_X     2

#define MAX_Y     255
#define NEUTRAL_Y 129
#define MIN_Y     2

ArduinoNunchuk nunchuk = ArduinoNunchuk();

struct Motor {
    int forward_pin;
    int reverse_pin;
    int enable_pin;
};

struct Motor LM;
struct Motor RM;
bool DEBUG = false;

int led = 13;

void disableMotor(struct Motor LM, struct Motor RM);
void enableMotor(struct Motor LM, struct Motor RM);
void forwardMotor(struct Motor LM, struct Motor RM);
void reverseMotor(struct Motor LM, struct Motor RM);
void leftMotor(struct Motor LM, struct Motor RM);
void rightMotor(struct Motor LM, struct Motor RM);

void disableMotor(struct Motor LM, struct Motor RM) {
  digitalWrite(LM.enable_pin, LOW);
  digitalWrite(RM.enable_pin, LOW);
}

void enableMotor(struct Motor LM, struct Motor RM) {
  digitalWrite(LM.enable_pin, HIGH);
  digitalWrite(RM.enable_pin, HIGH);
}

void forwardMotor(struct Motor LM, struct Motor RM) {
  digitalWrite(LM.reverse_pin, LOW);
  digitalWrite(RM.reverse_pin, LOW);

  digitalWrite(LM.forward_pin, HIGH);
  digitalWrite(RM.forward_pin, HIGH);

  enableMotor(LM, RM);
}

void reverseMotor(struct Motor LM, struct Motor RM) {
  digitalWrite(RM.forward_pin, LOW);
  digitalWrite(LM.forward_pin, LOW);

  digitalWrite(RM.reverse_pin, HIGH);
  digitalWrite(LM.reverse_pin, HIGH);

  enableMotor(LM, RM);
}

void leftMotor(struct Motor LM, struct Motor RM) {
  digitalWrite(LM.reverse_pin, HIGH);
  digitalWrite(LM.forward_pin, LOW);

  digitalWrite(RM.reverse_pin, LOW);
  digitalWrite(RM.forward_pin, HIGH);

  enableMotor(LM, RM);
}

void rightMotor(struct Motor LM, struct Motor RM) {
  digitalWrite(LM.reverse_pin, LOW);
  digitalWrite(LM.forward_pin, HIGH);

  digitalWrite(RM.reverse_pin, HIGH);
  digitalWrite(RM.forward_pin, LOW);

  enableMotor(LM, RM);
}

void setup() {
  Serial.begin(BAUDRATE);
  pinMode(led, OUTPUT);
  Serial.println("[00] inside setup");

  LM.forward_pin = 5;
  LM.reverse_pin = 6;
  LM.enable_pin = 4;

  RM.forward_pin = 9;
  RM.reverse_pin = 10;
  RM.enable_pin = 8;

  pinMode(LM.forward_pin, OUTPUT);
  pinMode(LM.reverse_pin, OUTPUT);
  pinMode(LM.enable_pin, OUTPUT);

  pinMode(RM.forward_pin, OUTPUT);
  pinMode(RM.reverse_pin, OUTPUT);
  pinMode(RM.enable_pin, OUTPUT);

  nunchuk.init();

  Serial.println("[01] nunchuk init called");
}

void log(char* msg) {
  if (DEBUG) {
    Serial.println(msg);
  }
}

void loop() {
  digitalWrite(led, HIGH);
  nunchuk.update();

  if (nunchuk.analogX > (NEUTRAL_X + BUFFER)) {
    leftMotor(LM, RM);   
    log("LEFT");
  }

  if (nunchuk.analogX < (NEUTRAL_X - BUFFER)) {
    rightMotor(LM, RM);
    log("RIGHT");
  }

  if (nunchuk.analogY > (NEUTRAL_Y + BUFFER)) {
    forwardMotor(LM, RM);
    log("FORWARD");
  }
  if (nunchuk.analogY < (NEUTRAL_Y - BUFFER)) {
    reverseMotor(LM, RM);
    log("REVERSE");
  }

  if (nunchuk.zButton == 1) {
    log("Z Pressed");
    disableMotor(LM, RM);
  }
  if (nunchuk.cButton == 1) {
    Serial.print("Current analogX Value: ");
    Serial.println(nunchuk.analogX);

    Serial.print("Current analogY Value: ");
    Serial.println(nunchuk.analogY);
  }
  
  digitalWrite(led, LOW);
}
