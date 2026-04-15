from enum import Enum
import pygame

from config.constantes import POINT_MORT

def direction_joystick(event: pygame.event.Event) -> str:


    if event.type == pygame.JOYHATMOTION:
        x, y = event.value
        if x == 0:
            if y == -1:
                print("HAUT")
                return "HAUT"
            elif y == 1:
                print("BAS")
                return "BAS"
            else:
                print("NEUTRE")
                return "NEUTRE"
        elif y == 0:
            if x == 1:
                print("GAUCHE")
                return "GAUCHE"
            elif x == -1:
                print("DROITE")
                return "DROITE"
            else:
                print("NEUTRE")
                return "NEUTRE"

    return "echec"
        