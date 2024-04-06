#include "user.h"
#include "date.h"

#include "tigerAPI.h"

bool FeedTiger(User* user)
{
	// If user has enough points, feed tiger
	if (user->points >= POINT_COST) {
		decreasePoints(user, POINT_COST);
		user->tiger.hunger += TIGER_HUNGER_INC;

		return true;
	}
	printf("Not enough points!\n");
	return false;
}

bool UpdateTigerHunger(Tiger* tiger) {
	// If last checked on today, don't update
	if (dateDifference(tiger->lastChecked, getCurrentDate()) == 0) return false;

	// decrease hunger by last date fed
	for (int i = 1; i < 5; i++) {
		if (dateDifference(tiger->lastFed, getCurrentDate()) == i * -1)
			tiger->hunger -= TIGER_HUNGER_DEC * i;
	}

	// Make sure hunger doesn't go negative
	if (tiger->hunger < 0) tiger->hunger = 0;

	if (dateDifference(tiger->lastFed, getCurrentDate()) <= -5)
		tiger->hunger = 0;

	return true;
}

int GetTigerHunger(Tiger* tiger) {
	UpdateTigerHunger(tiger);

	return tiger->hunger;
}

void DetermineTigerMood(User* user) {
	Tiger* tiger = &(user->tiger);

	UpdateTigerHunger(tiger);

	tiger->lastChecked = getCurrentDate();

	if (tiger->hunger >= 75) {
		tiger->tigerMood = HAPPY;
	}
	else if (tiger->hunger >= 25) {
		tiger->tigerMood = HUNGRY;
	}
	else {
		tiger->tigerMood = SAD;
	}
}

void petTiger() {
	int temp = (rand() % 3) + 1;
	switch(temp){
	case 1:
		printf("Your tiger rolls over and shows you its belly. You rub the tiger's belly.\n");
		break;
	case 2:
		printf("Your tiger is happy :).\n");
		break;
	case 3: 
		printf("Your tiger runs away.\n");
		break;
	}
}