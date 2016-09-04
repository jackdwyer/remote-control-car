import RPi.GPIO as GPIO
import readchar


class Motor(object):
    # swapped reverse and forward as battery pack was making it too front heavy
    def __init__(self, reverse_pin, forward_pin, enable_pin):
        self.forward_pin = forward_pin
        self.reverse_pin = reverse_pin
        self.enabled_pin = enable_pin

    def enabled():
        # return True/False if its running
        return False

# motor_1_forward = 16
# motor_1_reverse = 18
# motor_1_enable = 22

# motor_2_foward = 23
# motor_2_reverse = 21
# motor_2_enable = 19

left = Motor(13, 15, 11)
right = Motor(5, 7, 3)


def init():
    # init the gpio and shit
    GPIO.setmode(GPIO.BOARD)

    GPIO.setup(left.forward_pin, GPIO.OUT)
    GPIO.setup(left.reverse_pin, GPIO.OUT)
    GPIO.setup(left.enabled_pin, GPIO.OUT)

    GPIO.setup(right.forward_pin, GPIO.OUT)
    GPIO.setup(right.reverse_pin, GPIO.OUT)
    GPIO.setup(right.enabled_pin, GPIO.OUT)


def forward():
    GPIO.output(left.reverse_pin, GPIO.LOW)
    GPIO.output(left.forward_pin, GPIO.HIGH)

    GPIO.output(right.reverse_pin, GPIO.LOW)
    GPIO.output(right.forward_pin, GPIO.HIGH)

    GPIO.output(left.enabled_pin, GPIO.HIGH)
    GPIO.output(right.enabled_pin, GPIO.HIGH)


def turn_right():
    GPIO.output(left.forward_pin, GPIO.LOW)
    GPIO.output(left.reverse_pin, GPIO.HIGH)

    GPIO.output(right.reverse_pin, GPIO.LOW)
    GPIO.output(right.forward_pin, GPIO.HIGH)

    GPIO.output(left.enabled_pin, GPIO.HIGH)
    GPIO.output(right.enabled_pin, GPIO.HIGH)


def turn_left():
    GPIO.output(left.reverse_pin, GPIO.LOW)
    GPIO.output(left.forward_pin, GPIO.HIGH)

    GPIO.output(right.forward_pin, GPIO.LOW)
    GPIO.output(right.reverse_pin, GPIO.HIGH)

    GPIO.output(left.enabled_pin, GPIO.HIGH)
    GPIO.output(right.enabled_pin, GPIO.HIGH)


def reverse():
    GPIO.output(left.forward_pin, GPIO.LOW)
    GPIO.output(left.reverse_pin, GPIO.HIGH)
    GPIO.output(left.enabled_pin, GPIO.HIGH)

    GPIO.output(right.forward_pin, GPIO.LOW)
    GPIO.output(right.reverse_pin, GPIO.HIGH)
    GPIO.output(right.enabled_pin, GPIO.HIGH)


def stop():
    GPIO.output(left.enabled_pin, GPIO.LOW)
    GPIO.output(left.reverse_pin, GPIO.LOW)
    GPIO.output(left.forward_pin, GPIO.LOW)

    GPIO.output(right.enabled_pin, GPIO.LOW)
    GPIO.output(right.reverse_pin, GPIO.LOW)
    GPIO.output(right.forward_pin, GPIO.LOW)


def cleanup():
    GPIO.cleanup()


def main():
    init()
    print("Ready?")
    stop()
    try:
        while True:
            k = readchar.readchar()
            if k == 'w':
                print('forward called')
                forward()
            if k == 's':
                print('reverse called')
                reverse()
            if k == 'b':
                print('stop called')
                stop()
            if k == 'a':
                print('left called')
                turn_left()
            if k == 'd':
                print('right_called')
                turn_right()
    except KeyboardInterrupt:
        stop()
        cleanup()
        exit()

    stop()
    cleanup()
    exit(0)


if __name__ == '__main__':
        main()
