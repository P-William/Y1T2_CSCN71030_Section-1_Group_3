#pragma once

#include "date.h"
#include "string_utils.h"
#include "string.h"
#include "input_handler.h"
#include "file_io.h"

#define MAX_TIGER_NAME 128

typedef enum TigerStatus {
	SAD,
	HUNGRY,
	HAPPY
} TigerStatus;

typedef struct tiger {
	char name[MAX_TIGER_NAME];

	TigerStatus tigerMood;
	int hunger;
	Date lastFed;
	Date lastChecked;
} Tiger;

Tiger CreateTiger();
void NameTiger(Tiger* tiger);
bool equalTiger(Tiger tigerOne, Tiger tigerTwo);
Tiger copyTiger(Tiger src);

bool saveTiger(FILE* fp, Tiger tiger);
Tiger loadTiger(FILE* fp);