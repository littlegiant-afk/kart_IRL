from pygame import joystick
import pygame
from bluetooth.controller import direction_joystick

from moteurs.mouvement import setup_moteurs, avancer, reculer, tourner_gauche, tourner_droite, arreter, regler_vitesse
from config.constantes import MOTEUR_1, MOTEUR_2, PUISSANCE_MOTEUR_1, PUISSANCE_MOTEUR_2


joystick.init()
setup_moteurs()

def main():
    if joystick.get_init():
        manette = joystick.Joystick(0)
        print(f"Manette connectée : {manette.get_name()}")
        #joysticks = [joystick.Joystick(x) for x in range(joystick.get_count())]

    screen = pygame.display.set_mode((100, 100))
    running = True
    while running:

        for event in pygame.event.get():

            if event.type == pygame.QUIT:
                running = False

            if event.type == pygame.JOYHATMOTION:

                direction = "DIRECTION"
                direction = direction_joystick(event)
                
                regler_vitesse(MOTEUR_1, PUISSANCE_MOTEUR_1)
                regler_vitesse(MOTEUR_2, PUISSANCE_MOTEUR_2)

                if direction == "HAUT":
                    avancer()
                elif direction == "BAS":
                    reculer()
                elif direction == "GAUCHE":
                    tourner_gauche()
                elif direction == "DROITE":
                    tourner_droite()
                elif direction == "NEUTRE":
                    arreter()



if __name__ == "__main__":
    main()
    pygame.quit()