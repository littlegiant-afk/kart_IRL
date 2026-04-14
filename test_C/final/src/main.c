#include <stdio.h>
#include "mouvement.h"
#include <wiringPi.h>
#include "manette.h"

int main(int argc, char **argv)
{
	wiringPiSetup();
	
	init();
	
	Direction direct;
	//int vitesse = 100;
	
	while(1){
		//stopper();
		//scanf("%s", &direction);
		//pwmWrite(GPIO_ENABLE1, (vitesse*1024)/100);
		//pwmWrite(GPIO_ENABLE2, (vitesse*1024)/100);
		
		digitalWrite(GPIO_ENABLE1, HIGH);
		digitalWrite(GPIO_ENABLE2, HIGH);

		direct = pilotage();


		switch (direct) {
			case HAUT :
				avancer();
				break;
				
			case BAS:
				reculer();
				break;
				
			case GAUCHE:
				tournerGauche();
				break;

			case DROITE:
				tournerDroite();
				break;

			case CENTRE:
				stopper();
				break;

		}
	}
	
	return 0;
}
