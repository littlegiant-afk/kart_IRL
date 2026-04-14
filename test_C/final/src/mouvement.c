#include <wiringPi.h>
#include <stdio.h>

#define GPIO_ENABLE1 23 //gpio 13
#define GPIO_IN1 29 //gpio 21
#define GPIO_IN2 25 // gpio 26
#define GPIO_ENABLE2 26 //gpio 12
#define GPIO_IN3 0 //gpio 17
#define GPIO_IN4 1 //gpio 18

void init() {
	
	pwmSetMode(PWM_MODE_MS);
	pwmSetClock(500); //50 hertz

	pinMode(GPIO_ENABLE1, OUTPUT);//Enable 1
	pinMode(GPIO_IN1, OUTPUT);//IN1
	pinMode(GPIO_IN2, OUTPUT);//IN2
	pinMode(GPIO_ENABLE2, OUTPUT);//Enable 2
	pinMode(GPIO_IN3, OUTPUT);//IN3
	pinMode(GPIO_IN4, OUTPUT);//IN4
}

void stopper() {
	
	digitalWrite(GPIO_IN1, LOW);
	digitalWrite(GPIO_IN2, LOW);
	digitalWrite(GPIO_IN3, LOW);
	digitalWrite(GPIO_IN4, LOW);
}

void avancer() {
	digitalWrite(GPIO_IN1, LOW);
	digitalWrite(GPIO_IN2, HIGH);
	digitalWrite(GPIO_IN3, LOW);
	digitalWrite(GPIO_IN4, HIGH);
}

void reculer() {
	digitalWrite(GPIO_IN1, HIGH);
	digitalWrite(GPIO_IN2, LOW);
	digitalWrite(GPIO_IN3, HIGH);
	digitalWrite(GPIO_IN4, LOW);
}

void tournerDroite() {
	digitalWrite(GPIO_IN1, HIGH);
	digitalWrite(GPIO_IN2, LOW);
	digitalWrite(GPIO_IN3, LOW);
	digitalWrite(GPIO_IN4, HIGH);
}

void tournerGauche() {
	digitalWrite(GPIO_IN1, LOW);
	digitalWrite(GPIO_IN2, HIGH);
	digitalWrite(GPIO_IN3, HIGH);
	digitalWrite(GPIO_IN4, LOW);
}
