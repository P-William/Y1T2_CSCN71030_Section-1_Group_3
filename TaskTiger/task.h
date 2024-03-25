#pragma once

#include <stdbool.h>

#include "date.h"

#define TASK_TITLE_LENGTH 128
#define TASK_DESCRIPTION_LENGTH 512

#define TASK_EMPTY_DESCRIPTION_PLACEHOLDER "EMPTY_TASK_DESCRIPTION"

typedef enum Status {
	UNSET_STATUS,
	IN_PROGRESS,
	ON_HOLD,
	BLOCKED,
	COMPLETED
} Status;

typedef enum Priority {
	UNSET_PRIORITY,
	LOW,
	MEDIUM,
	HIGH,
	URGENT
} Priority;

typedef struct Task {
	char title[TASK_TITLE_LENGTH];
	char description[TASK_DESCRIPTION_LENGTH];
	Status status;
	Priority priority;
	Date date;
} Task;

Task createTask(const char* title);

bool equalTask(Task, Task);

Task copyTask(Task src);
bool copyTaskInPlace(Task* dest, Task src);

void printStatus(Status, bool newLine);
void printStatusT(Task, bool newLine);
void printPriority(Priority, bool newLine);
void printPriorityT(Task, bool newLine);

void debugPrintTask(Task);