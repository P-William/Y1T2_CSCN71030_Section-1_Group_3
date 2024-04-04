#pragma once

#include <stdio.h>
#include <stdbool.h>

#include "list.h"
#include "task.h"

#define FOLDER_NAME_LENGTH 128


typedef struct Folder {
	char name[FOLDER_NAME_LENGTH];
	List* list;
} Folder;


/**
 * Creates a new folder with the given name.
 * @param name The name of the folder to create.
 * @return The newly created folder.
 * @note The caller is responsible for calling destroyFolder
 */
Folder createFolder(const char* name);

/**
 * Checks if two folders are equal.
 * @param f1 The first folder.
 * @param f2 The second folder.
 * @return true if the folders are equal, false otherwise.
 */
bool equalFolder(Folder, Folder);

/**
 * Creates a copy of a folder.
 * @param src The folder to copy.
 * @return The copy of the folder.
 * @note The caller is responsible for calling destroyFolder
 */
Folder copyFolder(Folder src);

/**
 * @Sets the name of a folder.
 * @param folder Pointer to the folder whose name to set.
 * @param newName The new name for the folder.
 * @return true if the name was successfully set, false if folder or newName is NULL.
 */
bool setName(Folder*, const char* newName);

/**
 * Destroys a folder and frees its resources.
 * @param folder The folder to destroy.
 */
void destroyFolder(Folder);

/**
 * Saves a folder to a file.
 *
 * @param fp Pointer to the FILE object to write to.
 * @param folder The Folder structure to be saved.
 * @return True if the folder was successfully saved, false otherwise.
 */
bool saveFolder(FILE* fp, Folder folder);
/**
 * Loads a folder from a file.
 *
 * @param fp Pointer to the FILE object to read from.
 * @return The Folder structure loaded from the file.
 */
Folder loadFolder(FILE* fp);


void debugPrintFolder(Folder);