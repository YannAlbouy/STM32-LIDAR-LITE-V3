/*----------------------------------------------------*/
/*-													 -*/
/*-			Fonction pour mon écran LCD				 -*/
/*-													 -*/
/*----------------------------------------------------*/

/*----INCLUDES----*/
#include "i2c-lcd.h"
#include "libBouton.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*----VARIABLES GLOBALES----*/
extern I2C_HandleTypeDef hi2c1;
extern int buttonDistance;
extern int buttonVitesse;
extern int buttonInterface;
extern int buttonChoix;
extern int buttonValide;
extern int tpsCourant;
extern int distance;
extern int ecranActif;
extern int onePush2;
extern int onePush3;
extern int nb;


/*----------Adresse de mon ecran LCD sur I2C----------*/
#define LCD_ADD 0x00 <<1 //
int prevTaille = 0;

int lcd_isConnected(void)
{
	  int nblcd = 0;
	  if(HAL_I2C_IsDeviceReady(&hi2c1,LCD_ADD, 2,500)== HAL_OK)
	  {
		  nblcd = 1;
	  }
	  return nblcd;
}

void lcd_clear(void)
{
	uint8_t cmdLCDCLEAR[2]={0x1B, 0x43};
	HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,cmdLCDCLEAR,2,100);
	HAL_Delay(15);
}

void lcd_init(void)
{
	/* Motif a afficher sur l'ecran 					   */
	/* Vient de la documentation du LCD 				   */
	/* Le tableau se lit comme une map 					   */
	/* Avec en haut a gacuhe le 0 0 qui donne 0x00  	   */
	/* Et avec le bas a droite qui est 15 15(F) donne 0xFF */
	uint8_t carreNoir[1]={0xFF};
	uint8_t space[1]={0xFE};
/*-----------------------------------------------DEBUT-----------------------------------------------*/
	/*--------------------Premiere ligne--------------------*/
    HAL_I2C_Mem_Write(&hi2c1,LCD_ADD,0x01,1,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);

    /*----------Seconde ligne----------*/
    HAL_I2C_Mem_Write(&hi2c1,LCD_ADD,0x02,1,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
    HAL_Delay(1);

    /*----------Troisième ligne----------*/
    HAL_I2C_Mem_Write(&hi2c1,LCD_ADD,0x03,1,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
    HAL_Delay(1);

    /*----------Quatrième ligne----------*/
    HAL_I2C_Mem_Write(&hi2c1,LCD_ADD,0x04,1,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
    HAL_Delay(4000);
/*-----------------------------------------------FIN-----------------------------------------------*/

/*-----------------------------------------------DEBUT-----------------------------------------------*/
    /*--------------------Premiere ligne--------------------*/
    HAL_I2C_Mem_Write(&hi2c1,LCD_ADD,0x01,1,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
	HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);

    /*----------Seconde ligne----------*/
    HAL_I2C_Mem_Write(&hi2c1,LCD_ADD,0x02,1,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
	HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
    HAL_Delay(1);
    /*-------------Troisieme lignes------------*/
    HAL_I2C_Mem_Write(&hi2c1,LCD_ADD,0x03,1,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
    HAL_Delay(1);
    /*--------------Quatrieme ligne--------------*/
    HAL_I2C_Mem_Write(&hi2c1,LCD_ADD,0x04,1,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
    HAL_Delay(1);
/*-----------------------------------------------FIN-----------------------------------------------*/

/*-----------------------------------------------DEBUT-----------------------------------------------*/

    /*--------------------Premiere ligne----------------------*/
    HAL_I2C_Mem_Write(&hi2c1,LCD_ADD,0x01,1,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
	HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);

    /*--------------------Seconde ligne----------------------*/
    HAL_I2C_Mem_Write(&hi2c1,LCD_ADD,0x02,1,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
	HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);

    /*--------------------Troisieme ligne--------------------*/
    HAL_I2C_Mem_Write(&hi2c1,LCD_ADD,0x03,1,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
    HAL_Delay(1);
    /*--------------------Quatrieme ligne--------------------*/
    HAL_I2C_Mem_Write(&hi2c1,LCD_ADD,0x04,1,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
    HAL_Delay(1);

/*-----------------------------------------------FIN-----------------------------------------------*/


/*-----------------------------------------------DEBUT-----------------------------------------------*/

    /*--------------------Premiere ligne----------------------*/
    HAL_I2C_Mem_Write(&hi2c1,LCD_ADD,0x01,1,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
	HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);

    /*--------------------Seconde ligne----------------------*/
    HAL_I2C_Mem_Write(&hi2c1,LCD_ADD,0x02,1,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
	HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);

    /*--------------------Troisieme ligne--------------------*/
    HAL_I2C_Mem_Write(&hi2c1,LCD_ADD,0x03,1,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
	HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);

	/*--------------------Quatrieme ligne--------------------*/
    HAL_I2C_Mem_Write(&hi2c1,LCD_ADD,0x04,1,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
    HAL_Delay(1);


/*-----------------------------------------------FIN-----------------------------------------------*/



/*-----------------------------------------------DEBUT-----------------------------------------------*/

	/*--------------------Premiere ligne----------------------*/
    HAL_I2C_Mem_Write(&hi2c1,LCD_ADD,0x01,1,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
	HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);

	/*--------------------Seconde ligne----------------------*/
    HAL_I2C_Mem_Write(&hi2c1,LCD_ADD,0x02,1,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
	HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);

	/*--------------------Troisieme ligne--------------------*/
    HAL_I2C_Mem_Write(&hi2c1,LCD_ADD,0x03,1,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
	HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);

	/*--------------------Quatrieme ligne--------------------*/
    HAL_I2C_Mem_Write(&hi2c1,LCD_ADD,0x04,1,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
	HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
    HAL_Delay(1);

/*-----------------------------------------------FIN-----------------------------------------------*/

}
void lcd_affDistance(int distance)
{
	/*----Recuperation distance----*/
	uint8_t space[1]={0xFE};
	char mot[4];
	itoa(distance,mot,10);
	int n = log10(distance) + 1;
	HAL_I2C_Mem_Write(&hi2c1,LCD_ADD, 0x01, 1, (uint8_t *)"Distance recue :",16,100);

	HAL_Delay(1);
	HAL_I2C_Mem_Write(&hi2c1,LCD_ADD, 0x10, 1, (uint8_t *)mot,n,100);
	HAL_Delay(10);
	if(n == 1)
	{
		HAL_I2C_Mem_Write(&hi2c1,LCD_ADD, 0x11 , 1, (uint8_t *)space,1,100);
		HAL_Delay(10);
		HAL_I2C_Mem_Write(&hi2c1,LCD_ADD, 0x12 , 1, (uint8_t *)space,1,100);
		HAL_Delay(10);
		HAL_I2C_Mem_Write(&hi2c1,LCD_ADD, 0x13 , 1, (uint8_t *)space,1,100);
		HAL_Delay(10);
		HAL_I2C_Mem_Write(&hi2c1,LCD_ADD, 0x14 , 1, (uint8_t *)space,1,100);
		HAL_Delay(10);
	}
	else if(n == 2)
	{
		HAL_I2C_Mem_Write(&hi2c1,LCD_ADD, 0x12 , 1, (uint8_t *)space,1,100);
		HAL_Delay(10);
		HAL_I2C_Mem_Write(&hi2c1,LCD_ADD, 0x13 , 1, (uint8_t *)space,1,100);
		HAL_Delay(10);
		HAL_I2C_Mem_Write(&hi2c1,LCD_ADD, 0x14 , 1, (uint8_t *)space,1,100);
		HAL_Delay(10);
	}
	else if(n == 3){
		HAL_I2C_Mem_Write(&hi2c1,LCD_ADD, 0x13 , 1, (uint8_t *)space,1,100);
		HAL_Delay(10);
		HAL_I2C_Mem_Write(&hi2c1,LCD_ADD, 0x14 , 1, (uint8_t *)space,1,100);
		HAL_Delay(10);
	}

}

void lcd_interfacePrinc(int tabDistance, int tabVitesse,int tpsActif)
{
	/*-----------------------------------VARIABLES EN ENTREE-----------------------------------*/
	/* tabDistance viens du main et correspond au nombre de clic sur le bouton des distances   */
	/* tabVitesse viens du main et correspond au nombre de clic sur le bouton des vitesses     */
	/* tpsActif viens du main et correspond au temps ou on a cliqué sur le bouton (valeur fixe)*/
	/*-----------------------------------VARIABLES EN SORTIE-----------------------------------*/
	/*				Cette fonction ne retourne rien et ne fait que de l'affichage			   */
	/*				Elle met cependant en veille l'écran au bout de 10s sans actions		   */
	/*-----------------------------------------------------------------------------------------*/

	/*-----BOUTON POUR CHANGER LA DISTANCE----*/
	clicBtnDistance();
	/*----FIN DE LA PARTIE CONCERNANT LE BOUTON POUSSOIR DE LA DISTANCE----*/

	/*-----BOUTON POUR CHANGER LA VITESSE----*/
	clicBtnVitesse();
	/*----FIN DE LA PARTIE CONCERNANT LE BOUTON POUSSOIR DE LA VITESSE----*/

	/*----AFFICHAGE DISTANCE CHOISIE----*/
	char maDistance[4];
	itoa(tabDistance,maDistance,10);
	int tailleDist = log10(tabDistance) + 1;

	/*----AFFICHAGE VALEUR CHOISIE----*/
	HAL_I2C_Mem_Write(&hi2c1,LCD_ADD, 0x01, 1, (uint8_t *)"Distance choisie :",18,100);
	HAL_Delay(1);
	HAL_I2C_Mem_Write(&hi2c1,LCD_ADD, 0x10, 1, (uint8_t *)maDistance,tailleDist,100);
	HAL_Delay(1);
	/*----REMISE A 1 DE L'AFFICHAGE----*/
	if(buttonDistance == 7)
	{
		buttonDistance = 1;
		lcd_clear();
		/*HAL_I2C_Mem_Write(&hi2c1,LCD_ADD, 0x02, 1, (uint8_t *)"--> ",4,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);*/
		lcd_interfacePrinc(buttonDistance, buttonVitesse,tpsActif);
	}

	/*----RECUPERATION VALEUR DU TABLEAU----*/
	int distanceChoisie = 0;
	distanceChoisie = boutonDistance(buttonDistance);

	/*----CALCUL TAILLE ET CONVERSION EN STRING----*/
	int tailleDistChoisie =  log10(distanceChoisie) + 1;
	char convValeur[tailleDistChoisie];
	itoa (distanceChoisie,convValeur,10);

	/*----AFFICHAGE DE LA VALEUR RETOURNER----*/
	HAL_I2C_Mem_Write(&hi2c1,LCD_ADD, 0x02, 1, (uint8_t *)"--> ",4,100);
	HAL_Delay(1);
	HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,(uint8_t *)convValeur,tailleDistChoisie,100);
	HAL_Delay(1);

	/*----------------------------------------------------------------------------------------------------*/
	/*------------------------------------------PARTIE VITESSE--------------------------------------------*/
	/*----------------------------------------------------------------------------------------------------*/

	/*----AFFICHAGE VITESSE CHOISIE----*/
	char maVitesse[4];
	itoa(tabVitesse,maVitesse,10);
	int tailleVit = log10(tabVitesse) + 1;


	/*----AFFICHAGE VALEUR CHOISIE----*/
	HAL_I2C_Mem_Write(&hi2c1,LCD_ADD, 0x03, 1, (uint8_t *)"Vitesse choisie :",17,100);
	HAL_Delay(1);
	HAL_I2C_Mem_Write(&hi2c1,LCD_ADD, 0x10, 1, (uint8_t *)maVitesse,tailleVit,100);
	HAL_Delay(1);

	/*----RECUPERATION VALEUR DU TABLEAU----*/
	int vitesseChoisie = 0;
	vitesseChoisie = boutonVitesse(buttonVitesse);

	/*----CALCUL TAILLE ET CONVERSION EN STRING----*/
	int tailleVitChoisie =  log10(vitesseChoisie) + 1;
	char convVitValeur[tailleVitChoisie];
	itoa (vitesseChoisie,convVitValeur,10);

	/*----AFFICHAGE DE LA VALEUR RETOURNER----*/
	HAL_I2C_Mem_Write(&hi2c1,LCD_ADD, 0x04, 1, (uint8_t *)"--> ",4,100);
	HAL_Delay(1);
	HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,(uint8_t *)convVitValeur,tailleVitChoisie,100);
	HAL_Delay(1);

	/*----REMISE A 1 DE L'AFFICHAGE----*/
	if(buttonVitesse == 7)
	{
		/*----SWITCH VERS TRANSITION POUR MODE AUTO----*/
		buttonValide = 0;
		lcd_clear();
		buttonVitesse = 1;
		buttonInterface = 6;

	}

}

/* Fonction qui vas allumer l'ecran LCD */
void lcd_on(void)
{
	uint8_t cmdON[2]={0x1B, 0x42};
	HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,cmdON,2,100);
	HAL_Delay(1);
}

/*Fonction qui vas eteindre l'ecran LCD */
void lcd_off(void)
{
	uint8_t cmdOFF[2]={0x1B, 0x62};
	HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,cmdOFF,2,100);
	HAL_Delay(1);
}

/* Fonction pour faire une voiture sur le LCD */
void lcd_maVoiture(void)
{
	/*----CARACTERE SPECIAUX UTILE----*/
	uint8_t space[1]={0xFE};

	/*-----PIXEL 1-----*/
	uint8_t cmdPix1[13]={0x1B, 0x44,0x08, 0x00, 0x00, 0x00, 0x0F, 0x10, 0x12, 0x10, 0x12};
	HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,cmdPix1,13,100);
	HAL_Delay(1);
	/*-----PIXEL 2-----*/
	uint8_t cmdPix2[13]={0x1B, 0x44, 0x09, 0x00, 0x00, 0x00, 0x1F, 0x00, 0x1E, 0x00, 0x1E};
	HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,cmdPix2,13,100);
	HAL_Delay(1);
	/*-----PIXEL 3-----*/
	uint8_t cmdPix3[13]={0x1B, 0x44, 0x0A, 0x00, 0x00, 0x00, 0x10, 0x18, 0x1F, 0x18, 0x18};
	HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,cmdPix3,13,100);
	HAL_Delay(1);
	/*-----PIXEL 4-----*/
	uint8_t cmdPix4[13]={0x1B, 0x44, 0x0B, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x18, 0x08};
	HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,cmdPix4,13,100);
	HAL_Delay(1);
	/*-----PIXEL 5-----*/
	uint8_t cmdPix5[13]={0x1B, 0x44, 0x0C, 0x10, 0x17, 0x17, 0x10, 0x17, 0x1D, 0x1F, 0x0F};
	HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,cmdPix5,13,100);
	HAL_Delay(1);
	/*-----PIXEL 6-----*/
	uint8_t cmdPix6[13]={0x1B, 0x44, 0x0D, 0x00, 0x1B, 0x1B, 0x00, 0x00, 0x1F, 0x1F, 0x1F};
	HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,cmdPix6,13,100);
	HAL_Delay(1);
	/*-----PIXEL 7-----*/
	uint8_t cmdPix7[13]={0x1B, 0x44, 0x0E, 0x18, 0x08, 0x10, 0x00, 0x0E, 0x1B, 0x1F, 0x1F};
	HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,cmdPix7,13,100);
	HAL_Delay(1);
	/*-----PIXEL 8-----*/
	uint8_t cmdPix8[13]={0x1B, 0x44, 0x0F, 0x08, 0x18, 0x08, 0x08, 0x18, 0x18, 0x18, 0x10};
	HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,cmdPix8,13,100);
	HAL_Delay(1);

	/*----PIXELS QUE J'AI FAIT----*/
	uint8_t pix1[1]={0x08};
	uint8_t pix2[1]={0x09};
	uint8_t pix3[1]={0x0A};
	uint8_t pix4[1]={0x0B};
	uint8_t pix5[1]={0x0C};
	uint8_t pix6[1]={0x0D};
	uint8_t pix7[1]={0x0E};
	uint8_t pix8[1]={0x0F};

	/*----AFFICHAGE DES PIXELS PERSOS LIGNE 3----*/
	/*
	HAL_I2C_Mem_Write(&hi2c1,LCD_ADD,0x03,1,pix1,1,100);
	HAL_Delay(1);
	HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,pix2,1,100);
	HAL_Delay(1);
	HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,pix3,1,100);
	HAL_Delay(1);
	HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,pix4,1,100);
	HAL_Delay(1);
	*/

	/*----AFFICHAGE DES PIXELS PERSOS LIGNE 4----*/
	/*
	HAL_I2C_Mem_Write(&hi2c1,LCD_ADD,0x04,1,pix5,1,100);
	HAL_Delay(1);
	HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,pix6,1,100);
	HAL_Delay(1);
	HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,pix7,1,100);
	HAL_Delay(1);
	HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,pix8,1,100);
	HAL_Delay(1);
	*/
	for(int i = 0; i<2; i++)
	{
		/*----ARRIVE SMOOTH DE LA VOITURE----*/
		HAL_I2C_Mem_Write(&hi2c1,LCD_ADD,0x03,1,pix1,1,100);
		HAL_Delay(1);
		HAL_I2C_Mem_Write(&hi2c1,LCD_ADD,0x04,1,pix5,1,100);
		HAL_Delay(100);
		/*------------------------------------------------*/
		HAL_I2C_Mem_Write(&hi2c1,LCD_ADD,0x03,1,pix1,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,pix2,1,100);
		HAL_Delay(1);
		HAL_I2C_Mem_Write(&hi2c1,LCD_ADD,0x04,1,pix5,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,pix6,1,100);
		HAL_Delay(100);
		/*------------------------------------------------*/
		HAL_I2C_Mem_Write(&hi2c1,LCD_ADD,0x03,1,pix1,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,pix2,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,pix3,1,100);
		HAL_Delay(1);
		HAL_I2C_Mem_Write(&hi2c1,LCD_ADD,0x04,1,pix5,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,pix6,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,pix7,1,100);
		HAL_Delay(100);
		/*------------------------------------------------*/
		HAL_I2C_Mem_Write(&hi2c1,LCD_ADD,0x03,1,pix1,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,pix2,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,pix3,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,pix4,1,100);
		HAL_Delay(1);
		HAL_I2C_Mem_Write(&hi2c1,LCD_ADD,0x04,1,pix5,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,pix6,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,pix7,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,pix8,1,100);
		HAL_Delay(100);

		/*----ON VAS MAINTENANT FAIRE AVANCER 1 FOIS LA VOITURE----*/

		/*----FAIRE AVANCER LES PIXELS 1-2-3-4 ----*/
		HAL_I2C_Mem_Write(&hi2c1,LCD_ADD,0x03,1,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);

		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,pix1,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,pix2,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,pix3,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,pix4,1,100);
		HAL_Delay(1);

		/*----FAIRE AVANCER LES PIXELS 5-6-7-8 ----*/
		HAL_I2C_Mem_Write(&hi2c1,LCD_ADD,0x04,1,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);

		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,pix5,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,pix6,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,pix7,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,pix8,1,100);
		HAL_Delay(100);

		/*----ON VAS MAINTENANT FAIRE AVANCER 2 FOIS LA VOITURE----*/

		/*----FAIRE AVANCER LES PIXELS 1-2-3-4 ----*/
		HAL_I2C_Mem_Write(&hi2c1,LCD_ADD,0x03,1,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);

		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);

		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,pix1,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,pix2,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,pix3,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,pix4,1,100);
		HAL_Delay(1);

		/*----FAIRE AVANCER LES PIXELS 5-6-7-8 ----*/
		HAL_I2C_Mem_Write(&hi2c1,LCD_ADD,0x04,1,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);

		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);

		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,pix5,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,pix6,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,pix7,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,pix8,1,100);
		HAL_Delay(2000);

		/*----ON VAS MAINTENANT FAIRE AVANCER 3 FOIS LA VOITURE----*/

		/*----FAIRE AVANCER LES PIXELS 1-2-3-4 ----*/
		HAL_I2C_Mem_Write(&hi2c1,LCD_ADD,0x03,1,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);

		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);

		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);

		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,pix1,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,pix2,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,pix3,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,pix4,1,100);
		HAL_Delay(1);

		/*----FAIRE AVANCER LES PIXELS 5-6-7-8 ----*/
		HAL_I2C_Mem_Write(&hi2c1,LCD_ADD,0x04,1,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);

		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);

		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);

		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,pix5,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,pix6,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,pix7,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,pix8,1,100);
		HAL_Delay(100);

		/*----ON VAS MAINTENANT FAIRE AVANCER 4 FOIS LA VOITURE----*/

		/*----FAIRE AVANCER LES PIXELS 1-2-3-4 ----*/
		HAL_I2C_Mem_Write(&hi2c1,LCD_ADD,0x03,1,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);

		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);

		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);

		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);

		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,pix1,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,pix2,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,pix3,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,pix4,1,100);
		HAL_Delay(1);

		/*----FAIRE AVANCER LES PIXELS 5-6-7-8 ----*/
		HAL_I2C_Mem_Write(&hi2c1,LCD_ADD,0x04,1,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);

		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);

		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);

		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);

		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,pix5,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,pix6,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,pix7,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,pix8,1,100);
		HAL_Delay(100);

		/*----DEPART SMOOTH DE LA VOITURE----*/

		/*----FAIRE AVANCER LES PIXELS 1-2-3-4 ----*/
		HAL_I2C_Mem_Write(&hi2c1,LCD_ADD,0x03,1,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);

		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);

		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);

		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);

		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,pix1,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,pix2,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,pix3,1,100);
		HAL_Delay(1);

		/*----FAIRE AVANCER LES PIXELS 5-6-7-8 ----*/
		HAL_I2C_Mem_Write(&hi2c1,LCD_ADD,0x04,1,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);

		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);

		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);

		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);

		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,pix5,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,pix6,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,pix7,1,100);
		HAL_Delay(100);
		/*------------------------------------------------*/

		/*----FAIRE AVANCER LES PIXELS 1-2-3-4 ----*/
		HAL_I2C_Mem_Write(&hi2c1,LCD_ADD,0x03,1,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);

		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);

		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);

		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);

		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,pix1,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,pix2,1,100);
		HAL_Delay(1);


		/*----FAIRE AVANCER LES PIXELS 5-6-7-8 ----*/
		HAL_I2C_Mem_Write(&hi2c1,LCD_ADD,0x04,1,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);

		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);

		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);

		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);

		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,pix5,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,pix6,1,100);
		HAL_Delay(100);
		/*------------------------------------------------*/

		/*----FAIRE AVANCER LES PIXELS 1-2-3-4 ----*/
		HAL_I2C_Mem_Write(&hi2c1,LCD_ADD,0x03,1,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);

		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);

		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);

		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);

		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,pix1,1,100);
		HAL_Delay(1);



		/*----FAIRE AVANCER LES PIXELS 5-6-7-8 ----*/
		HAL_I2C_Mem_Write(&hi2c1,LCD_ADD,0x04,1,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);

		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);

		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);

		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);

		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,pix5,1,100);
		HAL_Delay(1);

		/*------------------------------------------------*/

		/*----FAIRE AVANCER LES PIXELS 1-2-3-4 ----*/
		HAL_I2C_Mem_Write(&hi2c1,LCD_ADD,0x03,1,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);

		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);

		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);

		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);

		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);



		/*----FAIRE AVANCER LES PIXELS 5-6-7-8 ----*/
		HAL_I2C_Mem_Write(&hi2c1,LCD_ADD,0x04,1,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);

		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);

		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);

		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);

		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
		HAL_Delay(1);

	}

}


/* Fonction pour mettre l'ecran en veille */
void lcd_Veille(int tpsActif)
{
	/*----MISE EN VEILLE AU BOUT DE 30S----*/
	/*----     MODIF TEMPS EN MS	   ----*/
	if(tpsCourant - tpsActif >= 30000)
	{
		lcd_off();
	}
}

void lcd_ModeAuto(void)
{

	/*-----BOUTON POUR VALIDER LE CHOIX----*/
	clicBtnValide();
	/*----FIN DE LA PARTIE CONCERNANT LE BOUTON POUSSOIR DE VALIDATION----*/

	/*----CARACTERE SPECIAUX UTILE----*/
	uint8_t carreNoir[1]={0xFF};
	uint8_t space[1]={0xFE};

	/*----CREATION DE MA FLECHE----*/
	uint8_t cmdPixFleche[13]={0x1B, 0x44,0x08, 0x08, 0x04, 0x02, 0x01, 0x01, 0x02, 0x04, 0x08};
	HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,cmdPixFleche,13,100);
	HAL_Delay(1);

	/*----BLOCAGE INTERFACE MODE AUTO----*/
	onePush3 = 1;

	HAL_I2C_Mem_Write(&hi2c1,LCD_ADD,0x01,1,carreNoir,1,100);
	HAL_Delay(1);
	HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
	HAL_Delay(1);
	HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
	HAL_Delay(1);
	HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
	HAL_Delay(1);
	HAL_I2C_Mem_Write(&hi2c1,LCD_ADD, 0x10, 1, (uint8_t *)"MODE  AUTO",10,100);
	HAL_Delay(1);
	HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,space,1,100);
	HAL_Delay(1);
	HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
	HAL_Delay(1);
	HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
	HAL_Delay(1);
	HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
	HAL_Delay(1);
	HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,carreNoir,1,100);
	HAL_Delay(1);


	/*----AJOUT DE LA FLECHE DE SELECTION----*/
	uint8_t cmdTPFleche[5]={0x1B, 0x4C, 0x0C, 0x03, 0x08};
	HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,cmdTPFleche,5,100);
	HAL_Delay(1);

	/*----ECRITURE DU MOT QUITTER----*/
	uint8_t cmdTPQuitter[4]={0x1B, 0x4C, 0x0D, 0x03};
	HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,cmdTPQuitter,4,100);
	HAL_Delay(1);
	HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,(uint8_t *)"QUITTER",7,100);
	HAL_Delay(1);

	/*----CHOIX DE QUITTER LE MODE AUTO----*/
	if(buttonValide == 1)
	{
		/*----A FAIRE----*/
		lcd_clear();
		buttonInterface = 1;
	}

}
void lcd_Navig()
{
	/*----DESACTIVER CURSEUR MOCHE----*/
	uint8_t cmdCursOFF[2]={0x1B, 0x73};
	HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,cmdCursOFF,2,100);
	HAL_Delay(1);

	/*-----BOUTON POUR CHANGER D'INTERFACE----*/
	clicBtnInterface();
	/*----FIN DE LA PARTIE CONCERNANT LE BOUTON POUSSOIR DE L'INTERFACE----*/
	if(buttonInterface == 1 || nb == 1)
	{
		lcd_interfacePrinc(buttonDistance, buttonVitesse,tpsCourant);
		/*----MISE EN VEILLE----*/
		lcd_Veille(ecranActif);
	}
	else if(buttonInterface == 2 || nb == 2)
	{
		lcd_affDistance(distance);
		/*----MISE EN VEILLE----*/
		lcd_Veille(ecranActif);
	}
	else if(buttonInterface == 3 || nb == 3)
	{
		buttonInterface = 1;
	}
	/*----INTERFACE NON VISIBLE PAR SELECTION----*/
	else if(buttonInterface == 6 || nb == 6)
	{
		lcd_transition();
	}
	else if(buttonInterface == 7 || nb == 7)
	{
		lcd_ModeAuto();
	}
}

void lcd_transition(void)
{

	/*-----BOUTON POUR CHANGER LE CHOIX----*/
	clicBtnChoix();
	/*----FIN DE LA PARTIE CONCERNANT LE BOUTON POUSSOIR DES CHOIX----*/

	/*-----BOUTON POUR VALIDER LE CHOIX----*/
	clicBtnValide();
	/*----FIN DE LA PARTIE CONCERNANT LE BOUTON POUSSOIR DE VALIDATION----*/


	/*----BLOCAGE CHANGEMENT D'INTERFACE----*/
	onePush3 = 1;
	HAL_I2C_Mem_Write(&hi2c1,LCD_ADD, 0x01, 1, (uint8_t *)"PASSER EN MODE AUTO?",20,100);
	/*----NE PAS OUBLIER DE REPASSER LE ONEPUSH3 A 0 APRES----*/

	/*----CREATION DE MA FLECHE----*/
	uint8_t cmdPixFleche[13]={0x1B, 0x44,0x08, 0x08, 0x04, 0x02, 0x01, 0x01, 0x02, 0x04, 0x08};
	HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,cmdPixFleche,13,100);
	HAL_Delay(1);

	/*----ECRITURE A L'ECRAN DE OUI ET NON----*/

	/*----JE ME TP A LA POSITION VOULUE POUR LE OUI----*/
	uint8_t cmdTPOui[4]={0x1B, 0x4C, 0x04, 0x02};
	HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,cmdTPOui,4,100);
	HAL_Delay(1);
	HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,(uint8_t *)"OUI",3,100);
	/*----FIN DU TP----*/

	/*----JE ME TP A LA POSITION VOULUE POUR LE NON----*/
	uint8_t cmdTPNon[4]={0x1B, 0x4C, 0x0D, 0x02};
	HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,cmdTPNon,4,100);
	HAL_Delay(1);
	HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,(uint8_t *)"NON",3,100);
	/*----FIN DU TP----*/

	/*----SI JE DIT OUI----*/
	if(buttonChoix == 1)
	{
		/*----METTRE FLECHE A OUI----*/
		uint8_t cmdTPFleche[5]={0x1B, 0x4C, 0x03, 0x02, 0x08};
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,cmdTPFleche,5,100);
		HAL_Delay(1);

		/*----ENLEVER FLECHE A NON----*/
		uint8_t cmdRmFlecheNon[5]={0x1B, 0x4C, 0x0C, 0x02, 0xFE};
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,cmdRmFlecheNon,5,100);
		HAL_Delay(1);

		if(buttonValide == 1)
		{
			lcd_clear();
			/*----IMTERFACE OU ON VA----*/
			buttonInterface = 7;
		}
	}
	/*----SI JE DIT NON----*/
	else if(buttonChoix == 2)
	{
		/*----METTRE FLECHE A NON----*/
		uint8_t cmdTPFleche[5]={0x1B, 0x4C, 0x0C, 0x02, 0x08};
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,cmdTPFleche,5,100);
		HAL_Delay(1);

		/*----ENLEVER FLECHE A OUI----*/
		uint8_t cmdRmFlecheOui[5]={0x1B, 0x4C, 0x03, 0x02, 0xFE};
		HAL_I2C_Master_Transmit(&hi2c1,LCD_ADD,cmdRmFlecheOui,5,100);
		HAL_Delay(1);

		if(buttonValide == 1)
		{
			buttonVitesse = 1;
			buttonInterface = 1;
		}
	}
	else if(buttonChoix == 3)
	{
		buttonChoix = 1;
	}


}
