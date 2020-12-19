#include "stm32f4xx_hal.h"

/* Fonction pour connaitre la distance choisie */
/* Prend en IN un entier */
/* Retourne un entier */
int boutonDistance(int);

/* Fonction pour connaitre la vitesse choisie */
/* Prend en IN un entier */
/* Retourne un entier */
int boutonVitesse(int);

/* Fonction pour connaitre le choix utilisateur */
int boutonChoix(int);

/* Fonction pour choisir  la distance avec le bouton */
void clicBtnDistance(void);

/* Fonction pour choisir  la vitesse avec le bouton */
void clicBtnVitesse(void);

/* Fonction pour choisir  l'interface avec le bouton */
void clicBtnInterface(void);

/* Fonction pour choisir la reponse avec le bouton */
void clicBtnChoix(void);

/* Fonction pour valider le choix fait par l'utilisateur */
void clicBtnValide();
