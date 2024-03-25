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

/**
 * Creates a new task with the given title.
 * @param title The title of the task to create.
 * @return The newly created task.
 */
Task createTask(const char* title);

/**
 * Checks if two tasks are equal.
 * @param t1 The first task.
 * @param t2 The second task.
 * @return true if the tasks are equal, false otherwise.
 */
bool equalTask(Task, Task);

/**
 * Creates a copy of a task.
 * @param src The task to copy.
 * @return The copy of the task.
 */
Task copyTask(Task src);
/**
 * Copies a task into a destination task pointer.
 * @param dest Pointer to the destination task.
 * @param src The source task to copy.
 * @return true if the copy was successful, false if dest is NULL.
 */
bool copyTaskInPlace(Task* dest, Task src);

/**
 * Prints the status to the standard output.
 * @param s The status to print.
 * @param newLine Flag indicating whether to print a newline character.
 */
void printStatus(Status, bool newLine);
/**
 * Prints the status of a task to the standard output.
 * @param t The task whose status to print.
 * @param newLine Flag indicating whether to print a newline character.
 */
void printStatusT(Task, bool newLine);
/**
 * Prints the priority to the standard output.
 * @param p The priority to print.
 * @param newLine Flag indicating whether to print a newline character.
 */
void printPriority(Priority, bool newLine);
/**
 * Prints the priority of a task to the standard output.
 * @param t The task whose priority to print.
 * @param newLine Flag indicating whether to print a newline character.
 */
void printPriorityT(Task, bool newLine);

void debugPrintTask(Task);