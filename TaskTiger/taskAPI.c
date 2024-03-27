#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#include "taskAPI.h"

Task CreateTaskFromUser()
{
	Task newTask = createTask("");

	// Get task title
	while (!getStringFromUser(TASK_TITLE_LENGTH, &(newTask.title), "Enter a title for your new task: ")) {}

	// Get optional data
	bool settingUp = true;
	while (SetOptional(&newTask)) {}

	return newTask;
}

bool SetOptional(Task* task) {
	printColoredStringAdvanced(YELLOW, BG_BLACK, BOLD, "\nEdit Task | ");
	printColoredStringAdvanced(ORANGE, BG_BLACK, ITALIC, task->title);
	printf("\n");

	if (stringCompare(task->description, TASK_EMPTY_DESCRIPTION_PLACEHOLDER)) {
		printf("a) Add description\n");
	}
	else {
		printf("a) Change description | ");
		printColoredStringAdvanced(GREY, BG_BLACK, ITALIC, task->description);
		printf("\n");
	}

	printf("b) Set status | ");
	printStatusT(*task, true);

	printf("c) Set priority | ");
	printPriorityT(*task, true);

	printColoredStringAdvanced(B_GREY, BG_BLACK, ITALIC, "d) Continue\n\n");

	char selection;
	while (!getCharFromUser(&selection, "Please make a selection:")) {}

	switch (selection)
	{
	case 'a':
		SetDescription(task);
		break;
	case 'b':
		SetStatus(task);
		break;
	case 'c':
		SetPriority(task);
		break;
	case 'd':
		return false;
	default:
		return true;
	}
}

void SetDescription(Task* task) {
	printColoredStringAdvanced(YELLOW, BG_BLACK, BOLD, "\nSet Description | ");
	printColoredStringAdvanced(ORANGE, BG_BLACK, ITALIC, task->title);
	getStringFromUser(TASK_DESCRIPTION_LENGTH, task->description, "\nPlease type a description:");
}

void SetStatus(Task* task) {
	char selection = 'z';
	printf("\n");

	// while < a || > e || != w
	while ((selection < 97 || selection > 101) && selection != 'w') {
		printColoredStringAdvanced(YELLOW, BG_BLACK, BOLD, "Set Status | ");
		printColoredStringAdvanced(ORANGE, BG_BLACK, ITALIC, task->title);
		printf("\na) Remove Status\n");
		printf("b) In Progress\n");
		printf("c) On Hold\n");
		printf("d) Blocked\n");
		printf("e) Completed\n");
		printColoredStringAdvanced(B_GREY, BG_BLACK, ITALIC, "w) Back\n\n");

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
		printColoredStringAdvanced(YELLOW, BG_BLACK, BOLD, "Set Priority | ");
		printColoredStringAdvanced(ORANGE, BG_BLACK, ITALIC, task->title);
		printf("\na) Remove Priority\n");
		printf("b) Low\n");
		printf("c) Medium\n");
		printf("d) High\n");
		printf("e) Urgent\n");
		printColoredStringAdvanced(WHITE, BG_BLACK, ITALIC, "w) Back\n\n");

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
