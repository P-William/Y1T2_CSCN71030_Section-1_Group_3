#pragma once

#include "task.h"

#include "input_handler.h"
#include "string_utils.h"

Task CreateTaskFromUser();
bool SetOptional(Task* task);
void SetDescription(Task* task);
void SetStatus(Task* task);
void SetPriority(Task* task);