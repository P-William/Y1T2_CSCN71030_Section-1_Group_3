#pragma once

Tiger CreateTiger();

void FeedTiger(Tiger* tiger);
void UpdateTigerHunger(Tiger* tiger);
int GetTigerHunger(Tiger* tiger);
void DetermineTigerMood(User* user, Tiger* tiger);