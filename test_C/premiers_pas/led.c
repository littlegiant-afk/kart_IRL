#include <stdlib.h>
#include <stdio.h>
#include <wiringPi.h>

int main(int argc, char **argv)
{
	int GPIO_BUTTUN = 24; //GPIO19
	int GPIO_LED_B0 = 25; //GPIO26 bleu
	int GPIO_LED_B2 = 26; //GPIO12 jaune
	int GPIO_LED_B1 = 27; //GPIO16 rouge
	
	int compteur = 0;
	
	wiringPiSetup();
	
	pinMode(GPIO_BUTTUN, INPUT);
	pinMode(GPIO_LED_B0, OUTPUT);
	pinMode(GPIO_LED_B1, OUTPUT);	
	pinMode(GPIO_LED_B2, OUTPUT);	

	while (1) {
		
		if (!digitalRead(GPIO_BUTTUN)){
			compteur++;
			delay(250);
		}
		
		switch (compteur) {
			case 0:
				digitalWrite(GPIO_LED_B0, LOW);
				digitalWrite(GPIO_LED_B1, LOW);
				digitalWrite(GPIO_LED_B2, LOW);
				break;
				
			case 1:
				digitalWrite(GPIO_LED_B0, HIGH);
				digitalWrite(GPIO_LED_B1, LOW);
				digitalWrite(GPIO_LED_B2, LOW);
				break;

			case 2:
				digitalWrite(GPIO_LED_B0, LOW);
				digitalWrite(GPIO_LED_B1, HIGH);
				digitalWrite(GPIO_LED_B2, LOW);
				break;
				
			case 3:
				digitalWrite(GPIO_LED_B0, HIGH);
				digitalWrite(GPIO_LED_B1, HIGH);
				digitalWrite(GPIO_LED_B2, LOW);
				break;

			case 4:
				digitalWrite(GPIO_LED_B0, LOW);
				digitalWrite(GPIO_LED_B1, LOW);
				digitalWrite(GPIO_LED_B2, HIGH);
				break;

			case 5:
				digitalWrite(GPIO_LED_B0, HIGH);
				digitalWrite(GPIO_LED_B1, LOW);
				digitalWrite(GPIO_LED_B2, HIGH);
				break;

			case 6:
				digitalWrite(GPIO_LED_B0, LOW);
				digitalWrite(GPIO_LED_B1, HIGH);
				digitalWrite(GPIO_LED_B2, HIGH);
				break;

			case 7:
				digitalWrite(GPIO_LED_B0, HIGH);
				digitalWrite(GPIO_LED_B1, HIGH);
				digitalWrite(GPIO_LED_B2, HIGH);
				break;
	
			default:
				digitalWrite(GPIO_LED_B0, LOW);
				digitalWrite(GPIO_LED_B1, LOW);
				digitalWrite(GPIO_LED_B2, LOW);
				compteur = 0;
				break;

		}
	}
	
	return 0;
}
