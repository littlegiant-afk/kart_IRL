import RPi.GPIO as GPIO

from config.constantes import GPIO_ENABLE1, GPIO_IN1, GPIO_IN2, GPIO_ENABLE2, GPIO_IN3, GPIO_IN4, PUISSANCE_MOTEUR_1, PUISSANCE_MOTEUR_2

pwm1 = None
pwm2 = None

def setup_moteurs():
    global pwm1, pwm2
    GPIO.setmode(GPIO.BCM)
    GPIO.setup(GPIO_ENABLE1, GPIO.OUT)
    GPIO.setup(GPIO_IN1, GPIO.OUT)
    GPIO.setup(GPIO_IN2, GPIO.OUT)
    GPIO.setup(GPIO_ENABLE2, GPIO.OUT)
    GPIO.setup(GPIO_IN3, GPIO.OUT)
    GPIO.setup(GPIO_IN4, GPIO.OUT)

    pwm1 = GPIO.PWM(GPIO_ENABLE1, 1000)
    pwm2 = GPIO.PWM(GPIO_ENABLE2, 1000)
    pwm1.start(0)
    pwm2.start(0)

def avancer():
    GPIO.output(GPIO_IN1, GPIO.HIGH)
    GPIO.output(GPIO_IN2, GPIO.LOW)
    GPIO.output(GPIO_IN3, GPIO.HIGH)
    GPIO.output(GPIO_IN4, GPIO.LOW)

def reculer():
    GPIO.output(GPIO_IN1, GPIO.LOW)
    GPIO.output(GPIO_IN2, GPIO.HIGH)
    GPIO.output(GPIO_IN3, GPIO.LOW)
    GPIO.output(GPIO_IN4, GPIO.HIGH)

def tourner_gauche():
    GPIO.output(GPIO_IN1, GPIO.HIGH)
    GPIO.output(GPIO_IN2, GPIO.LOW)
    GPIO.output(GPIO_IN3, GPIO.LOW)
    GPIO.output(GPIO_IN4, GPIO.HIGH)

def tourner_droite():
    GPIO.output(GPIO_IN1, GPIO.LOW)
    GPIO.output(GPIO_IN2, GPIO.HIGH)
    GPIO.output(GPIO_IN3, GPIO.HIGH)
    GPIO.output(GPIO_IN4, GPIO.LOW)

def arreter():
    GPIO.output(GPIO_IN1, GPIO.LOW)
    GPIO.output(GPIO_IN2, GPIO.LOW)
    GPIO.output(GPIO_IN3, GPIO.LOW)
    GPIO.output(GPIO_IN4, GPIO.LOW)

def regler_vitesse(moteur, vitesse):
    if moteur == 1 and pwm1 is not None:
        GPIO.output(GPIO_ENABLE1, GPIO.HIGH)
        pwm1.ChangeDutyCycle(vitesse)
    elif moteur == 2 and pwm2 is not None:
        GPIO.output(GPIO_ENABLE2, GPIO.HIGH)
        pwm2.ChangeDutyCycle(vitesse)