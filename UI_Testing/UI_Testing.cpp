#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#define TASK_TITLE_LENGTH 128
#define TASK_DESCRIPTION_LENGTH 512

#define TASK_EMPTY_DESCRIPTION_PLACEHOLDER "EMPTY_TASK_DESCRIPTION"

#define USERNAME_LENGTH 128
#define MAX_PASSWORD_LENGTH 64

#define MAX_TIGER_NAME 128

#define FOLDER_NAME_LENGTH 128

typedef struct Date {
	int day;
	int month;
	int year;
} Date;

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

typedef struct List {
	size_t size;
	size_t capacity;
	Task* arr;
} List;

typedef struct Folder {
	char name[FOLDER_NAME_LENGTH];
	List* list;
} Folder;

typedef struct FolderNode {
	Folder folder;
	struct FolderNode* next;
} FolderNode, * pFolderNode;

typedef struct FolderList {
	FolderNode* head;
} FolderList;

typedef enum TigerStatus {
	SAD,
	HUNGRY,
	HAPPY
} TigerStatus;

typedef struct tiger {
	char name[MAX_TIGER_NAME];

	TigerStatus tigerMood;
	int hunger;
	Date lastFed;
	Date lastChecked;
} Tiger;

typedef struct User {
	char username[USERNAME_LENGTH];
	char passward[MAX_PASSWORD_LENGTH];
	FolderList folders;
	int points;
	int totalTasksCompleted;
	int tasksCompletedOnTime;
	Date lastTaskCompletedDate;
	Tiger tiger;
} User;

typedef enum SortOrder {
	ASCENDING,
	DESCENDING
} SortOrder;

typedef enum SortKey {
	TITLE,
	STATUS,
	PRIORITY,
	DATE
} SortKey;

extern "C" Date createDate(int day, int month, int year);
extern "C" Date createDate(int day, int month, int year);
extern "C" Date createDateBlank();
extern "C" bool equalDate(Date, Date);
extern "C" bool emptyDate(Date);
extern "C" Date copyDate(Date src);
extern "C" bool copyDateInPlace(Date * dest, Date src);
extern "C" Date getCurrentDate();
extern "C" void printDate(Date date, bool newLine);
extern "C" bool stringToDate(Date * output, const char* dateString);
extern "C" bool getDateFromUser(Date * output, const char* prompt, ...);
extern "C" int dateDifference(Date, Date);
extern "C" int dateDifferenceAbsolute(Date, Date);

extern "C" Task createTask(const char* title);
extern "C" bool equalTask(Task, Task);
extern "C" Task copyTask(Task src);
extern "C" bool copyTaskInPlace(Task * dest, Task src);
extern "C" bool setTitle(Task * task, const char* newName);
extern "C" bool setDescription(Task * task, const char* newDesc);
extern "C" bool setPriority(Task * task, Priority newPriority);
extern "C" bool setStatus(Task * task, Status newStatus);
extern "C" bool setDate(Task * task, Date newDate);

extern "C" User createUser(const char* username, const char* password);
extern "C" bool equalUser(User, User);
extern "C" User copyUser(User);
extern "C" bool copyUserInPlace(User * dest, User src);
extern "C" bool setUsername(User*, const char* newUsername);
extern "C" bool setPassword(User*, const char* newPassword);
extern "C" bool increasePoints(User*, int amount);
extern "C" bool decreasePoints(User*, int amount);
extern "C" bool taskCompleted(User*, Task);
extern "C" bool wipeProfile(User*, bool youSure);


extern "C" List * createList();
extern "C" List * copyList(const List*);
extern "C" bool equalList(const List*, const List*);
extern "C" bool append(List*, Task);
extern "C" bool insert(List*, size_t index, Task);
extern "C" bool removeTask(List*, Task);
extern "C" bool pop(List*, size_t index);
extern "C" bool clear(List*);
extern "C" bool set(List*, size_t index, Task);
extern "C" size_t size(const List*);
extern "C" bool isEmpty(const List*);
extern "C" bool contains(const List*, Task);
extern "C" List * filterByTitle(const List*, const char* title);
extern "C" List * filterByStatus(const List*, Status);
extern "C" List * filterByPriority(const List*, Priority);
extern "C" List * filterByDate(const List*, Date);
extern "C" List * filterByDateTimeRemaining(const List*, int daysRemaining);
extern "C" bool sortList(List*, SortKey, SortOrder);
extern "C" void destroyList(List*);

extern "C" bool stringCompare(const char*, const char*);
extern "C" bool stringCompareI(const char*, const char*);

extern "C" bool writeIntToFile(FILE * fp, int integer);
extern "C" bool getIntFromFile(FILE * fp, int* output);

extern "C" FolderList createFolderList();
extern "C" Folder createFolder(const char* name);
extern "C" bool addFolder(FolderList*, Folder);
extern "C" Folder * searchFolder(FolderList * fl);
extern "C" List * GetTasksFromDate(User * user, Date date);

extern "C" int GetPointsFromUser(User * user);
extern "C" bool DateHasTask(User * user, Date date);

extern "C" Tiger CreateTiger();
extern "C" bool FeedTiger(User * user);
extern "C" bool UpdateTigerHunger(Tiger * tiger);
extern "C" bool equalTiger(Tiger tigerOne, Tiger tigerTwo);
extern "C" Tiger copyTiger(Tiger src);

bool getIntFromUser(int* output, const char* prompt, ...);
bool getIntFromUserWithRange(int min, int max, int* output, const char* prompt, ...);
bool getCharFromUser(char* outputChar, const char* prompt, ...);
bool getStringFromUser(int maxLength, char* output, const char* prompt, ...);
//
//namespace UITesting {
//	TEST_CLASS(UITesting) {
//	public:
//		
//		TEST_METHOD(TakeUserInfo) {
//			User user = createUser("Colin", "password");
//
//			User user2 = TakeUserInfo()
//
//		}
//	};
//}
