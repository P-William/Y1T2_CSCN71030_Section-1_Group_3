#define _CRT_SECURE_NO_WARNINGS

#include "tiger.h"

Tiger CreateTiger() {
	Tiger newTiger;
	
	strncpy(newTiger.name, "DEFAULT_TIGER_NAME", MAX_TIGER_NAME);
	newTiger.tigerMood = HAPPY;
	newTiger.hunger = 100;
	newTiger.lastChecked = getCurrentDate();
	newTiger.lastFed = getCurrentDate();

	return newTiger;
}

void NameTiger(Tiger* tiger) {
	printColoredStringAdvanced(YELLOW, NO_BG, BOLD, "\nSet Tiger Name");
	getStringFromUser(MAX_TIGER_NAME, tiger->name, "\nPlease enter a name:");
}

bool equalTiger(Tiger tigerOne, Tiger tigerTwo) {
	return (
		tigerOne.hunger == tigerTwo.hunger &&
		equalDate(tigerOne.lastChecked, tigerTwo.lastChecked) &&
		equalDate(tigerOne.lastFed, tigerOne.lastFed) &&
		stringCompare(tigerOne.name, tigerTwo.name) &&
		tigerOne.tigerMood == tigerTwo.tigerMood
		);
}

Tiger copyTiger(Tiger src) {
	Tiger newTiger = CreateTiger();

	newTiger.hunger = src.hunger;
	newTiger.tigerMood = src.tigerMood;
	strncpy(newTiger.name, src.name, MAX_TIGER_NAME);
	newTiger.lastChecked = copyDate(src.lastChecked);
	newTiger.lastFed = copyDate(src.lastFed);
	
	return newTiger;
}

bool saveTiger(FILE* fp, Tiger tiger)
{
	if (fp == NULL) {
		fprintf(stderr, "Null file pointer passed\n");
		return false;
	}

	writeStringToFile(fp, tiger.name);
	writeIntToFile(fp, tiger.hunger);
	writeIntToFile(fp, (int)tiger.tigerMood);
	saveDate(fp, tiger.lastChecked);
	saveDate(fp, tiger.lastFed);

	return true;
}

Tiger loadTiger(FILE* fp)
{
	if (fp == NULL) {
		fprintf(stderr, "Null file pointer passed\n");
		exit(-1);
	}

	Tiger newTiger;

	getStringFromFile(fp, newTiger.name, MAX_TIGER_NAME);
	getIntFromFile(fp, &(newTiger.hunger));
	int loadStatus = 0;
	getIntFromFile(fp, &loadStatus);
	newTiger.tigerMood = (TigerStatus)loadStatus;
	newTiger.lastChecked = loadDate(fp);
	newTiger.lastFed = loadDate(fp);

	return newTiger;
}