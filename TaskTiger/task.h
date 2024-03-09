#pragma once

#include <stdbool.h>

#define TASK_TITLE_LENGTH 128
#define TASK_DESCRIPTION_LENGTH 512

typedef enum Status {
	NONE,
	IN_PROGRESS,
	ON_HOLD,
	BLOCKED,
	COMPLETED
} Status;

typedef enum Priority {
	NONE,
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
	// TODO: Tags
	// TODO: Date
} Task;

Task createTask(const char* title);

bool equalTask(Task, Task);

Task copyTask(Task src);
bool copyTaskInPlace(Task* dest, Task src);

void printStatus(Status);
void printStatusT(Task);
void printPriority(Priority);
void printPriorityT(Task);

void debugPrintTask(Task);