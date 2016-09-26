struct Motor {
    int forward_pin;
    int reverse_pin;
    int enable_pin;
};

struct Motor LM;
struct Motor RM;

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
  Serial.begin(9600);
  pinMode(led, OUTPUT);

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
}

void loop() {
  delay(100);
  digitalWrite(led, HIGH);
  Serial.println("in the loop kid");

  Serial.println("FORWARD\n");
  forwardMotor(LM, RM);

  delay(1000);
  Serial.println("REVERSE\n");
  reverseMotor(LM, RM);

  delay(1000);
  disableMotor(LM, RM);
  Serial.println("DONE\n");

  digitalWrite(led, LOW);
}
