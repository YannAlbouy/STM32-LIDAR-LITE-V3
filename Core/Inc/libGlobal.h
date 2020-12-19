#include "stm32f4xx_hal.h"

/*Fonction qui adaptera la vitesse et la distance en fonction du choix de l'utilisateur*/
void adaptVitesseDistance(int, int);

double modeAuto(int distanceLidar, int distanceChoisie);
