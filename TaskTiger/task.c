

#include <stdio.h>
#include <string.h>

#include "task.h"
#include "string_utils.h"


Task createTask(const char* title) {
	Task newTask;
	strncpy(newTask.title, title, TASK_TITLE_LENGTH);
	strncpy(newTask.description, EMPTY_DESCRIPTION_PLACEHOLDER, TASK_DESCRIPTION_LENGTH);
	newTask.status = UNSET;
	newTask.priority = UNSET;
	return newTask;
}

bool equalTask(Task t1, Task t2) {
	return (
		stringCompare(t1.title, t2.title) &&
		stringCompare(t1.description, t2.description) &&
		t1.status == t2.status &&
		t1.priority == t2.priority
	);
}

Task copyTask(Task src) {
	Task newTask = createTask(src.title);
	strncpy(newTask.description, src.description, TASK_DESCRIPTION_LENGTH);
	newTask.status = src.status;
	newTask.priority = src.priority;
	return newTask;
}
bool copyTaskInPlace(Task* dest, Task src) {
	if (dest == NULL) {
		fprintf(stderr, "Null pointer when trying to copy task\n");
		return false;
	}
	strncpy(dest->title, src.title, TASK_TITLE_LENGTH);
	strncpy(dest->description, src.description, TASK_DESCRIPTION_LENGTH);
	dest->status = src.status;
	dest->priority = src.priority;
	return true;
}


void printStatus(Status s, bool newLine) {
	switch (s) {
	case UNSET:
		printf("Unset");
		break;
	case IN_PROGRESS:
		printf("In Progress");
		break;
	case ON_HOLD:
		printf("On Hold");
		break;
	case BLOCKED:
		printf("Blocked");
		break;
	case COMPLETED:
		printf("Competed");
		break;
	default:
		break;
	}
	if (newLine) {
		printf("\n");
	}
}
void printStatusT(Task t, bool newLine) {
	printStatus(t.status, newLine);
}
void printPriority(Priority p, bool newLine) {
	switch (p) {
	case UNSET:
		printf("Unset");
		break;
	case LOW:
		printf("Low");
		break;
	case MEDIUM:
		printf("Medium");
		break;
	case HIGH:
		printf("High");
		break;
	case URGENT:
		printf("Urgent");
		break;
	default:
		break;
	}
	if (newLine) {
		printf("\n");
	}
}
void printPriorityT(Task t, bool newLine) {
	printPriority(t.priority, newLine);
}

void debugPrintTask(Task t) {
	printf("=== DEBUG PRINT TASK ===\n");
	printf("Title: %s\n", t.title);
	printf("Description: %s\n", t.description);
	printf("Status: ");
	printStatus(t.status, true);
	printf("Priority: ");
	printPriority(t.priority, true);
}