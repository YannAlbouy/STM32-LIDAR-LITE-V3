/*----------------------------------------------------*/
/*-													 -*/
/*-		 Fonction pour mon capteur LIDAR			 -*/
/*-													 -*/
/*----------------------------------------------------*/

#include "i2c-lidar.h"

extern I2C_HandleTypeDef hi2c1;

/*----------Adresse de mon capteur LIDAR sur I2C----------*/
#define LIDAR_ADD 0x62<<1

/*----------DEBUT DE MES FONCTIONS----------*/
void lidar_init(void)
{
	/*----------INIT DU CAPTEUR LIDAR----------*/
	uint8_t cmd[1];
	cmd[0]=0x04;
	HAL_I2C_Mem_Write(&hi2c1, LIDAR_ADD ,0x00, 1, cmd,1,100);

	/*----------CONFIGURATION LIDAR----------*/
	cmd[0]=0xff;
	HAL_I2C_Mem_Write(&hi2c1, LIDAR_ADD,0x02, 1, cmd,1,1000);
	cmd[0]=0x08;
	HAL_I2C_Mem_Write(&hi2c1, LIDAR_ADD,0x04, 1, cmd,1,1000);
	cmd[0]=0x00;
	HAL_I2C_Mem_Write(&hi2c1, LIDAR_ADD,0x1c, 1, cmd,1,1000);
	/*----------FIN DE CONFIGURATION LIDAR----------*/
}
