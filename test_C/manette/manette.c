#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/joystick.h>

int main() {
    int js = open("/dev/input/js0", O_RDONLY);

    if (js < 0) {
        perror("Impossible d'ouvrir /dev/input/js0");
        return 1;
    }

    fcntl(js, F_SETFL, O_NONBLOCK);

    struct js_event e;

    printf("Lecture des directions de la manette Xbox...\n");

    while (1) {
        // Lecture non bloquante
        while (read(js, &e, sizeof(e)) > 0) {
            if (e.type == JS_EVENT_AXIS) {
                if (e.number == 0) {          // Axe gauche gauche/droite
                    if (e.value < -10000) printf("GAUCHE\n");
                    else if (e.value > 10000) printf("DROITE\n");
                }

                if (e.number == 1) {          // Axe gauche haut/bas
                    if (e.value < -10000) printf("HAUT\n");
                    else if (e.value > 10000) printf("BAS\n");
                }

                if (e.number == 6) {          // Croix directionnelle gauche/droite
                    if (e.value == -1) printf("CROIX GAUCHE\n");
                    if (e.value ==  1) printf("CROIX DROITE\n");
                }

                if (e.number == 7) {          // Croix directionnelle haut/bas
                    if (e.value == -1) printf("CROIX HAUT\n");
                    if (e.value ==  1) printf("CROIX BAS\n");
                }
            }
        }

        usleep(5000);
    }

    close(js);
    return 0;
}
