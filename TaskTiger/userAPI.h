#pragma once

#include "user.h"
#include "date.h"
#include "string_utils.h"
#include "input_handler.h"
#include "list.h"
#include "folder_list.h"

int GetPointsFromUser(User* user);

void SetUsernameFromUser(User* user);
void SetPasswordFromUser(User* user);

List* GetTasksFromDate(User* user, Date date);