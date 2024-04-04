#pragma once

#include "task.h"
#include "list.h"

#include "input_handler.h"
#include "string_utils.h"

Task CreateTaskFromUser();
void RenameTask(Task* task);
bool SetOptional(Task* task);
void SetDescription(Task* task);
void SetStatus(Task* task);
void SetPriority(Task* task);

Task* searchTask(const List* list);
void PrintTasks(List tasks);