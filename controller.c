#include <stdio.h>
#include <wiringPi.h>

struct Motor {
    int forward_pin;
    int reverse_pin;
    int enable_pin;
};

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

int main(void) {
    wiringPiSetupPhys();

    struct Motor LM;
    struct Motor RM;

    LM.forward_pin = 18;
    LM.reverse_pin = 16;
    LM.enable_pin = 22;

    RM.forward_pin = 13;
    RM.reverse_pin = 15;
    RM.enable_pin = 11;

    pinMode(LM.forward_pin, OUTPUT);
    pinMode(LM.reverse_pin, OUTPUT);
    pinMode(LM.enable_pin, OUTPUT);

    pinMode(RM.forward_pin, OUTPUT);
    pinMode(RM.reverse_pin, OUTPUT);
    pinMode(RM.enable_pin, OUTPUT);

    printf("FORWARD\n");
    forwardMotor(LM, RM);
    delay(1000);
    printf("REVERSE\n");
    reverseMotor(LM, RM);
    delay(1000);
    disableMotor(LM, RM);
    printf("DONE\n");
    return 0;
}
