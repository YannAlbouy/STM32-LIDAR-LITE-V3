/*----------------------------------------------------*/
/*-													 -*/
/*-			Fonctions relative aux boutons			 -*/
/*-													 -*/
/*----------------------------------------------------*/

#include "libBouton.h"
#include "i2c-lcd.h"

/*----VARIABLES GLOBALES----*/
extern int onePush;
extern int onePush2;
extern int onePush3;
extern int buttonDistance;
extern int buttonVitesse;
extern int buttonInterface;
extern int buttonValide;
extern int buttonChoix;
extern int ecranActif;

/*----RETOURNE DISTANCE EN FCT DU NBR DE CLIC----*/
int boutonDistance(int buttonDistance)
{
	/*----DISTANCES EN CM----*/
	int distances[6] = {100, 500, 1000, 2000, 3000, 4000};
	return distances[buttonDistance-1];

}

/*----RETOURNE VITESSE EN FCT DU NBR DE CLIC----*/
int boutonVitesse(int buttonVitesse)
{
	int vitesses[6] = {5,10,30,50,75,100};
	return vitesses[buttonVitesse-1];
}

/*----RETOURNE CHOIX EN FCT DU NBR DE CLIC----*/
/*Réutilisation boutonDistance*/
int boutonChoix(int buttonChoix)
{
	int choix[3] = {1,2,3};
	return choix[buttonChoix-1];
}


void clicBtnDistance(void)
{
	/*LIRE LE PIN ET LE ONEPUSH POUR SAVOIR SI ON CLIC*/
	/*ON A DONC UNE DOUBLE CONTINUE POUR EVITER L'APPUI CONTINU*/
	if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_0) == 1 && onePush == 0)
	{
		lcd_on();
		//lcd_clear();
		/*----RECUPERE VALEUR A MOMENT T----*/
		ecranActif = HAL_GetTick();
		onePush ++;
		buttonDistance = buttonDistance +1;
	}
	else if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_0) == 0){
		onePush = 0;
	}
}
void clicBtnVitesse(void)
{
	/*LIRE LE PIN ET LE ONEPUSH2 POUR SAVOIR SI ON CLIC*/
	/*ON A DONC UNE DOUBLE CLE POUR EVITER L'APPUI CONTINU*/
	if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_1) == 1 && onePush2 == 0)
	{
		lcd_on();
		//lcd_clear();
		/*----RECUPERE VALEUR A MOMENT T----*/
		ecranActif = HAL_GetTick();
		onePush2++;
		buttonVitesse = buttonVitesse +1;
	}
	else if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_1) == 0){
		onePush2 = 0;
	}
}

void clicBtnInterface(void)
{
	/*LIRE LE PIN ET LE ONEPUSH2 POUR SAVOIR SI ON CLIC*/
	/*ON A DONC UNE DOUBLE CLE POUR EVITER L'APPUI CONTINU*/
	if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_0) == 1 && onePush3 == 0)
	{
		lcd_on();
		lcd_clear();
		/*----RECUPERE VALEUR A MOMENT T----*/
		ecranActif = HAL_GetTick();
		onePush3++;
		buttonInterface = buttonInterface +1;
	}
	else if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_0) == 0){
		onePush3 = 0;
	}
}

void clicBtnChoix(void)
{
		/*LIRE LE PIN ET LE ONEPUSH POUR SAVOIR SI ON CLIC*/
		/*ON A DONC UNE DOUBLE CONTINUE POUR EVITER L'APPUI CONTINU*/
		if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_0) == 1 && onePush == 0)
		{
			lcd_on();
			//lcd_clear();
			/*----RECUPERE VALEUR A MOMENT T----*/
			ecranActif = HAL_GetTick();
			onePush ++;
			buttonChoix = buttonChoix +1;
		}
		else if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_0) == 0){
			onePush = 0;
		}
}

void clicBtnValide(void)
{
	/*LIRE LE PIN ET LE ONEPUSH2 POUR SAVOIR SI ON CLIC*/
	/*ON A DONC UNE DOUBLE CLE POUR EVITER L'APPUI CONTINU*/
	if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_1) == 1 && onePush2 == 0)
	{
		lcd_on();
		lcd_clear();
		/*----RECUPERE VALEUR A MOMENT T----*/
		ecranActif = HAL_GetTick();
		onePush2++;
		buttonValide = buttonValide +1;
	}
	else if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_1) == 0){
		onePush2 = 0;
	}
}
