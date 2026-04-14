#include <fcntl.h>
#include <unistd.h>
#include <linux/joystick.h>
#include <stdio.h>
#include <stdlib.h>
#include "direction.h"

#define CHEMIN_MANETTE "/dev/input/js0"

Direction pilotage();