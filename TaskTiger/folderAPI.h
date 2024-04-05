#pragma once

#include "folder.h"
#include "folder_list.h"

#include "input_handler.h"
#include "string_utils.h"

Folder CreateFolderFromUser();
void RenameFolder(Folder* folder);
void EditFolder(Folder* folder);
void SelectFolder(FolderList* fl, User* user);
Folder* searchFolder(FolderList* fl);
void PrintFolders(FolderList* fl);