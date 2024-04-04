#pragma once

#define TIGER_HUNGER_INC 15
#define TIGER_HUNGER_DEC 20
#define POINT_COST 100

Tiger CreateTiger();

void FeedTiger(User* user);
void UpdateTigerHunger(Tiger* tiger);
int GetTigerHunger(Tiger* tiger);
void DetermineTigerMood(User* user);