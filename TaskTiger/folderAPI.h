#pragma once

#include "folder.h"

#include "input_handler.h"
#include "string_utils.h"

Folder CreateFolderFromUser();
void RenameFolder(Folder* folder);
void EditFolder(Folder* folder);