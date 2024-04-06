#pragma once

#include "user.h"
#include "folder.h"
#include "folder_list.h"

#include "input_handler.h"
#include "string_utils.h"

Folder CreateFolderFromUser();
void RenameFolder(Folder* );
void EditFolder(Folder* );
void SelectFolder(User* , FolderList* );
Folder* searchFolder(FolderList* );
void PrintFolders(FolderList* );
void EditExistingFolder(User* user, FolderList* fl);
void DeleteExistingFolder(User* user, FolderList* fl);