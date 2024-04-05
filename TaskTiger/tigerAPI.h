#pragma once

#include "tiger.h"

#define TIGER_HUNGER_INC 15
#define TIGER_HUNGER_DEC 20
#define POINT_COST 100

bool FeedTiger(User* user);
bool UpdateTigerHunger(Tiger* tiger);
int GetTigerHunger(Tiger* tiger);
void DetermineTigerMood(User* user);
void petTiger();