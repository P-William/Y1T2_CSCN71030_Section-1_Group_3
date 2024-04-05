#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#include "taskAPI.h"
#include "user.h"

Task CreateTaskFromUser()
{
	Task newTask = createTask("");

	// Get task title
	RenameTask(&newTask);

	// Get optional data
	bool settingUp = true;
	while (SetOptional(&newTask)) {}

	return newTask;
}

bool SetOptional(Task* task) {
	printColoredStringAdvanced(YELLOW, NO_BG, BOLD, "\nEdit Task | ");
	printColoredStringAdvanced(ORANGE, NO_BG, ITALIC, task->title);
	printf("\n");

	printf("a) Rename\n");

	if (stringCompare(task->description, TASK_EMPTY_DESCRIPTION_PLACEHOLDER)) {
		printf("b) Add description\n");
	}
	else {
		printf("b) Change description | ");
		printColoredStringAdvanced(GREY, NO_BG, ITALIC, task->description);
		printf("\n");
	}

	printf("c) Set status | ");
	printStatusT(*task, true);

	printf("d) Set priority | ");
	printPriorityT(*task, true);

	printf("e) Set Date\n");

	printColoredStringAdvanced(B_GREY, NO_BG, ITALIC, "w) Back\n\n");

	char selection;
	while (!getCharFromUser(&selection, "Please make a selection:")) {}

	switch (selection)
	{
	case 'a':
		RenameTask(task);
		break;
	case 'b':
		SetDescription(task);
		break;
	case 'c':
		SetStatus(task);
		break;
	case 'd':
		SetPriority(task);
		break;
	case 'e':
		SetDateFromUser(task);
		break;
	case 'w':
		return false;
	default:
		return true;
	}
}

void RenameTask(Task* task) {
	if (stringCompare(task->title, "")) {
		printColoredStringAdvanced(YELLOW, NO_BG, BOLD, "\nSet Task Title");
	}
	else {
		printColoredStringAdvanced(YELLOW, NO_BG, BOLD, "\nSet Task Title | ");
		printColoredStringAdvanced(ORANGE, NO_BG, ITALIC, task->title);
	}

	getStringFromUser(TASK_TITLE_LENGTH, task->title, "\nPlease enter a title:");
}

void SetDescription(Task* task) {
	printColoredStringAdvanced(YELLOW, NO_BG, BOLD, "\nSet Description | ");
	printColoredStringAdvanced(ORANGE, NO_BG, ITALIC, task->title);
	getStringFromUser(TASK_DESCRIPTION_LENGTH, task->description, "\nPlease enter a description:");
}

void SetStatus(Task* task) {
	char selection = 'z';
	printf("\n");

	// while < a || > e || != w
	while ((selection < 97 || selection > 101) && selection != 'w') {
		printColoredStringAdvanced(YELLOW, NO_BG, BOLD, "Set Status | ");
		printColoredStringAdvanced(ORANGE, NO_BG, ITALIC, task->title);
		printf("\na) Remove Status\n");
		printf("b) In Progress\n");
		printf("c) On Hold\n");
		printf("d) Blocked\n");
		printf("e) Completed\n");
		printColoredStringAdvanced(B_GREY, NO_BG, ITALIC, "w) Back\n\n");

		getCharFromUser(&selection, "Please make a selection:");
		selection = tolower(selection);
	}

	switch (selection)
	{
	case 'a':
		task->status = UNSET_STATUS;
		break;
	case 'b':
		task->status = IN_PROGRESS;
		break;
	case 'c':
		task->status = ON_HOLD;
		break;
	case 'd':
		task->status = BLOCKED;
		break;
	case 'e':
		task->status = COMPLETED;
		break;
	default:
		break;
	}
}

void SetPriority(Task* task)
{
	char selection = 'z';
	printf("\n");

	// while < a || > e || != w
	while ((selection < 97 || selection > 101) && selection != 'w') {
		printColoredStringAdvanced(YELLOW, NO_BG, BOLD, "Set Priority | ");
		printColoredStringAdvanced(ORANGE, NO_BG, ITALIC, task->title);
		printf("\na) Remove Priority\n");
		printf("b) Low\n");
		printf("c) Medium\n");
		printf("d) High\n");
		printf("e) Urgent\n");
		printColoredStringAdvanced(WHITE, NO_BG, ITALIC, "w) Back\n\n");

		getCharFromUser(&selection, "Please make a selection:");
		selection = tolower(selection);
	}

	switch (selection)
	{
	case 'a':
		task->priority = UNSET_PRIORITY;
		break;
	case 'b':
		task->priority = LOW;
		break;
	case 'c':
		task->priority = MEDIUM;
		break;
	case 'd':
		task->priority = HIGH;
		break;
	case 'e':
		task->priority = URGENT;
		break;
	default:
		break;
	}
}

void SetDateFromUser(Task* task) {
	printColoredStringAdvanced(YELLOW, NO_BG, BOLD, "Set Date\n");
	
	Date newDate = createDateBlank();

	getIntFromUser(&newDate.day, "Day: ");
	getIntFromUser(&newDate.month, "Month: ");
	getIntFromUser(&newDate.year, "Year: ");

	task->date = newDate;
}

Task* searchTask(const List* list) {
	char taskTitle[TASK_TITLE_LENGTH];
	getStringFromUser(TASK_TITLE_LENGTH, taskTitle, "Enter the name of the task you wish to find:");

	if (list == NULL) {
		fprintf(stderr, "Cannot check null list\n");
		return NULL;
	}
	for (size_t i = 0; i < list->size; i++) {
		bool match = stringCompare(list->arr[i].title, taskTitle);
		if (match) {
			return &(list->arr[i]);
		}
	}
	return NULL;
}

void PrintTasks(List tasks) {
	for (int i = 0; i < tasks.size; i++) {
		printf("Task: %s\n", tasks.arr[i].title);
	}
}

//find and remove task of user's choice
void deleteTask(List* list) {
	char taskTitle[TASK_TITLE_LENGTH];
	getStringFromUser(TASK_TITLE_LENGTH, taskTitle, "Enter the name of the task you wish to delete:");

	if (list == NULL) {
		fprintf(stderr, "Cannot check null list\n");
		return;
	}
	for (size_t i = 0; i < list->size; i++) {
		bool match = stringCompare(list->arr[i].title, taskTitle);
		if (match) {
			removeTask(list, list->arr[i]);
		}
	}

}

void markTaskAsComplete(User* user, List* list) {
	char taskTitle[TASK_TITLE_LENGTH];
	getStringFromUser(TASK_TITLE_LENGTH, taskTitle, "Enter the name of the task you wish to mark completed:");

	if (list == NULL) {
		fprintf(stderr, "Cannot check null list\n");
		return;
	}
	for (size_t i = 0; i < list->size; i++) {
		bool match = stringCompare(list->arr[i].title, taskTitle);
		if (match) {
			taskCompleted(user, list->arr[i]);
		}
	}
}