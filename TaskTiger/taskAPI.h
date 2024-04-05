#pragma once

#include "user.h"
#include "task.h"
#include "list.h"

#include "input_handler.h"
#include "string_utils.h"

Task CreateTaskFromUser();
void RenameTask(Task* );
bool SetOptional(Task* );
void SetDescription(Task* );
void SetStatus(Task* );
void SetPriority(Task* );
void SetDateFromUser(Task* );
Task* searchTask(const List*);
void PrintTasks(List);
void deleteTask(List* );
void markTaskAsComplete(User* , List* );