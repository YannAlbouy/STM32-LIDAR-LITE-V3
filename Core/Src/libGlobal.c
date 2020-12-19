/*----------------------------------------------------*/
/*-													 -*/
/*-	     Fonctions ou on adaptera la vitesse		 -*/
/*-	     et la distance en fonction du choix		 -*/
/*-	   			  de l'utilisateur					 -*/
/*-													 -*/
/*----------------------------------------------------*/

/*----INCLUDES----*/
#include "libGlobal.h"
#include <stdio.h>
#include <math.h>

/*----VARIABLES GLOBALES----*/
extern TIM_HandleTypeDef htim3;
extern int distance;


void adaptVitesseDistance(int choixDistance, int choixVitesse)
{
	double diffDistance = 0;
	double nouvVitesse = 0;
	/*----CAS ARRET DU MOTEUR CAR TROP PROCHE----*/
	if( distance <= 80)
	{
			/*----ARRET----*/
		htim3.Instance->CCR1 = 0;
	}
	/*----MISE A LA VITESSE SOUHAITE SI ON PEUT----*/
	if( distance >=choixDistance)
	{
		htim3.Instance->CCR1 = choixVitesse;
	}
	/*----VARIATION VITESSE POUR RALENTIR SI L'OBSTACLE SE RAPPROCHE----*/
	if( distance < choixDistance)
	{
		/*----CALCUL POUR REDUIRE LA VITESSE----*/
		diffDistance = choixDistance - distance;
		/*----ATTENTION SI ECART TROP IMPORTANT VAL NEGATIVE----*/

		/*----GESTION EN CAS DE VALEURS NEGATIVES----*/
		if(diffDistance > 100)
		{
			nouvVitesse = 1-(diffDistance/1000);
		}
		else if(diffDistance > 1000)
		{
			nouvVitesse = 1-(diffDistance/10000);
		}
		else{
			nouvVitesse = 1-(diffDistance/100);
		}
		nouvVitesse = (choixVitesse*nouvVitesse);

		htim3.Instance->CCR1 = nouvVitesse;
	}
}

/* Fonction pour le mode auto, retourne la valeur pour la PWM et prend en entrée la diistance et celle choisie*/
double modeAuto(int distanceLidar, int distanceChoisie)
{
	/* ADAPTER PWM EN FCT DE LA DISTANCE CHOISIE PAR L'UTILISATEUR */
	/* PREND EN COMPTE SI DEVANT CA ACCELERE DONC DISTANCELIDAR AUGMENTE */
	/* OU BIEN SUR LA DISTANCELIDAR REDUIT DONC CA FREINE DEVANT */

	/*---- PWM ENVOYE AU MOTEUR ----*/
	double maPWM;

	if(distanceLidar > distanceChoisie )
	{
		/*---- CAS OU ON A LA PLACE DEVANT NOUS ----*/

		int coeff =log10(distanceChoisie);
		if( (distanceLidar - distanceChoisie) > pow(10,coeff) )
		{
			/*---- SI ON A UNE DISTANCE SUFFISANTE ALORS ON PEUT ACCELERER ----*/
			maPWM = ( ( (distanceLidar - distanceChoisie) / pow(10,coeff) ) - 1 );
		}
	}
	else if(distanceLidar < distanceChoisie )
	{
		int coeff =log10(distanceChoisie) + 1;
		/*---- CAS OU ON EST PLUS PROCHE QUE PREVUS ----*/
		maPWM = ( distanceLidar / pow(10,coeff));
	}

}
