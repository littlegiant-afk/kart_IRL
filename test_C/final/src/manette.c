#include <fcntl.h>
#include <unistd.h>
#include <linux/joystick.h>
#include <stdio.h>
#include <stdlib.h>
#include "direction.h"

#define CHEMIN_MANETTE "/dev/input/js0"

Direction pilotage() {

    int fd = open(CHEMIN_MANETTE, O_RDONLY);

    if (fd < 0) {
        perror("Manette non connectée");
    }

    struct js_event jse;

    while (1) {

        if (read(fd, &jse, sizeof(struct js_event)) != sizeof(struct js_event)) {
            perror("Erreur de lecture de l'événement");
            break; 
        }

        if (jse.type == JS_EVENT_AXIS) {

            if (jse.number == 0) {
                if (jse.value < -30000) {
                    return GAUCHE;
                } else if (jse.value > 30000) 
                {
                    return DROITE;
                } else if (jse.value > -5000 && jse.value < 5000)
                {
                    return CENTRE;
                }
                
                

            }

            if (jse.number == 1) {
                if (jse.value < -30000) {
                    return HAUT;
                } else if (jse.value > 30000) 
                {
                    return BAS;
                } else if (jse.value > -5000 && jse.value < 5000)
                {
                    return CENTRE;
                }
                

            }
        }
    }

    close(fd);
}