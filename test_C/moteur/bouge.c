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
	pinMode(GPIO_ENABLE1, PWM_OUTPUT);//Enable 1
	pinMode(GPIO_IN1, OUTPUT);//IN1
	pinMode(GPIO_IN2, OUTPUT);//IN2
	pinMode(GPIO_ENABLE2, PWM_OUTPUT);//Enable 2
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

void tournerGauche() {
	digitalWrite(GPIO_IN1, HIGH);
	digitalWrite(GPIO_IN2, LOW);
	digitalWrite(GPIO_IN3, LOW);
	digitalWrite(GPIO_IN4, HIGH);
}

int main(int argc, char **argv) {
	
	wiringPiSetup();
	
	init();
	
	char direction;
	int vitesse = 100;
	
	//mise à zéro


	while(1){

		//scanf("%d", &vitesse);
		scanf("%s", &direction);
		pwmWrite(GPIO_ENABLE1, (vitesse*1024)/100);
		pwmWrite(GPIO_ENABLE2, (vitesse*1024)/100);
		
		switch (direction) {
			case 'z' :
				avancer();
				break;
				
			case 's':
				reculer();
				break;
				
			case 'q':
				tournerGauche();
				break;

			case 'd':
				tournerDroite();
				
			default:
				stopper();
				break;
		}


		
	}
}
