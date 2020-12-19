#include "stm32f4xx_hal.h"

/* Fonction pour verifier connection LCD*/
int lcd_isConnected(void);

/* Fonction d'init de mon ecran LCD */
void lcd_init (void);

/* Fonction pour clear le LCD */
void lcd_clear (void);

/* Fonction pour afficher la distance du Lidar */
void lcd_affDistance(int);

/* Fonction affichage distance et vitesse */
void lcd_interfacePrinc(int,int,int);

/* Fonction pour allumer l'ecran LCD */
void lcd_on(void);

/* Fonction pour eteindre l'ecran LCD */
void lcd_off(void);

/* Fonction pour faire une voiture sur le LCD */
void lcd_maVoiture(void);

/* Fonction pour faire LA croix */
void lcd_Croix(void);

/* Fonction pour mettre l'ecran en veille */
void lcd_Veille(int);

/* Fonction pour faire le mode auto de vitesse */
void lcd_ModeAuto(void);

/* Fonction pour naviguer entre mes interfaces */
void lcd_Navig();

/* Fonction qui fera la transition avec le choix de l'utilisateur pour le mode auto */
void lcd_transition(void);
