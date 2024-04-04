#include "user.h"
#include "date.h"

#include "tigerAPI.h"

#define TIGER_HUNGER_INC 15
#define TIGER_HUNGER_DEC 20

Tiger CreateTiger() {
	Tiger newTiger;

	newTiger.hunger = 100;
	newTiger.lastChecked = getCurrentDate();
	newTiger.lastFed = getCurrentDate();
	
	/*
	GRUMPY,
	STRESSED,
	SAD,
	HUNGRY,
	ANXIOUS,
	HAPPY
	*/

	newTiger.moodValues[GRUMPY] = 0;
	newTiger.moodValues[STRESSED] = 0;
	newTiger.moodValues[SAD] = 0;
	newTiger.moodValues[HUNGRY] = 0;
	newTiger.moodValues[HAPPY] = 100;
}

void UpdateTigerHunger(Tiger* tiger) {
	// If last checked on today, don't update
	if (dateDifference(tiger->lastChecked, getCurrentDate()) == 0) return;

	if (dateDifference(tiger->lastFed, getCurrentDate()) == 1)
		tiger->hunger -= TIGER_HUNGER_DEC;

	// decrease hunger by last date fed
	for (int i = 0; i < 4; i++) {
		if (dateDifference(tiger->lastFed, getCurrentDate()) == i)
			tiger->hunger -= TIGER_HUNGER_DEC * i;
	}

	// Make sure hunger doesn't go negative
	if (tiger->hunger < 0) tiger->hunger = 0;

	if (dateDifference(tiger->lastFed, getCurrentDate()) >= 5)
		tiger->hunger = 0;
}

int GetTigerHunger(Tiger* tiger) {
	UpdateTigerHunger(tiger);

	return tiger->hunger;
}

void DetermineTigerMood(User* user, Tiger* tiger) {
	UpdateTigerHunger(tiger);

	tiger->lastChecked = getCurrentDate();

	/*
	GRUMPY,
	STRESSED,
	SAD,
	HUNGRY,
	ANXIOUS,
	HAPPY
	*/

	TigerStatus strongestMood = GRUMPY;
	for (int i = 1; i < 6; i++) {
		if (strongestMood < tiger->moodValues[i])
			strongestMood = (TigerStatus)i;
	}

	tiger->tigerMood = strongestMood;
}