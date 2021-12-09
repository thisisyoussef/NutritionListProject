#include "User.h"

float User::calculateBMR(int AGE, int actLev, float WEIGHT, float HEIGHT) {
	float BMR = 655.0f + (4.35f * (float)WEIGHT) + (4.7f * (float)HEIGHT) - (4.7f * (float)AGE);
	switch (actLev)
	{
	case 0: //low activity
		BMR *= 1.2;
		break;
	case 1: //1-3 times per week
		BMR *= 1.375;
		break;
	case 2: //3-5 times per week
		BMR *= 1.55;
		break;
	case 3: //6-7 times per week
		BMR *= 1.725;
		break;
	}
	return BMR;
}

float User::giveMaxCarb() {
	return this->maxCarbs;
}

float User::giveMaxProt() {
	return this->maxProt;
}

float User::giveMaxFat() {
	return this->maxFat;
}