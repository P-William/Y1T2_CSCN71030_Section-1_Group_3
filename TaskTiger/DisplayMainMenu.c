#include <stdio.h>
#include <stdlib.h>
#include "string_utils.h"
#include "user.h"
#include "Calendar.h"
#include "tigerAPI.h"

bool firstPrint = true;

void DisplayMainMenu(User* user) {
	
	if (firstPrint) {
		printColoredStringAdvanced(ORANGE, NO_BG, BOLD, "\n                                 ___..........__                                \n           _,...._           _.\"\'_,.++8n.n8898n.`\"._        _....._             \n         .\'       `\".     _.\'_.\'\" _.98n.68n. `\"88n. `\'.   ,\"       `.           \n        /        .   `. ,\'. \"  -\'\" __.68`\"\"\'\"\"=._`+8.  `.\'     .     `.         \n       .       `   .   `.   ,d86+889\" 8\"\"\"+898n, j8 9 ,\"    .          \        \n      :     \'       .,   ,d\"\'\"   _..d88b..__ `\"868\' .\'  . \'            :        \n      :     .      .    _    ,n8\"\"88\":8\"888.\"8.  \"               \'     :        \n       \     , \'  , . .88\" ,8P\'     ,d8. _   `\"8n  `+.      `.   .     \'        \n        `.  .. .     d89\' \"  _..n689+^\'8n88n.._ `+  . `  .  , \'      ,\'         \n          `.  . , \'  8\'    .d88+\"    j:\"\"\' `886n.    b`.  \' .\' .   .\"           \n           \'       , .j            ,d\'8.         `  .\"8.`.   `.  \':             \n            .    .\' n8    ,_      .f A 6.      ,..    `8b, \'.   .\'_             \n          .\' _    ,88\'   :8\"8    6\'.d`i.`b.   d8\"8     688.  \".    `\'           \n        ,\" .88  .d868  _         ,9:\' `8.`8   \"\'  ` _  8+\"\"      b   `,         \n      _.  d8P  d\'  .d :88.     .8\'`j   ;+. \"     n888b 8  .     ,88.   .        \n     `   :68\' ,8   88     `.   \'   :   l `     .\'   `\" jb  .`   688b.   \',      \n    .\'  .688  6P   98  =+\"\"`.      `   \'       ,-\"`+\"\'+88b \'b.  8689  `   \'     \n   ;  .\'\"888 .8;  .\"+b. : `\" ;               .: \"\' ; ,n  `8 q8, \'88:       \    \n   .   . 898  8:  :    `.`--\"8.              d8`--\' \'   .d\'  ;8  898        \'   \n  ,      689  9:  8._       ,68 .        .  :89    ..n88+\'   89  689,\' `     .  \n  :     ,88\'  88  `+88n  -   . .           .        \" _.     6:  `868     \'   \' \n  , \'  .68h.  68      `\"    . . .        .  . .             ,8\'   8P\'      .   .\n  .      \'88  \'q.    _.f       .          .  .    \'  .._,. .8\"   .889        ,  \n .\'     `898   _8hnd8p\'  ,  . ..           . .    ._   `89,8P    j\"\'  _   `     \n  \  `   .88, `q9868\' ,9      ..           . .  .   8n .8 d8\'   +\'   n8. ,  \'   \n  ,\'    ,+\"88n  `\"8 .8\'     . ..           . .       `8688P\"   9\'  ,d868\'   .  .\n  .      . `86b.    \" .       .            ..          68\'      _.698689;      :\n   . \'     ,889_.n8. ,  ` .   .___      ___.     .n\"  `86n8b._  `8988\'b      .,6\n    \'       q8689\'`68.   . `  `:. `.__,\' .:\'  ,   +   +88 `\"688n  `q8 q8.     88\n    , .   \'  \"     `+8 n    .   `:.    .;\'   . \'    . ,89           \"  `q,    `8\n   .   .   ,        .    + c  ,   `:.,:\"        , \"   d8\'               d8.    :\n    . \'  8n           ` , .         ::    . \' \"  .  .68h.             .8\'`8`.  6\n     ,    8b.__. ,  .n8688b., .    .;:._     .___nn898868n.         n868b \"`   8\n      `.  `6889868n8898886888688898\"\' \"+89n88898868868889\'         688898b    .8\n       :    q68   `\"\"+8688898P ` \" \' . ` \'  \' `+688988P\"          d8+8P\'  `. .d8\n       ,     88b.       `+88.     `   ` \'     .889\"\'           ,.88\'        .,88\n        :    \'988b        \"88b.._  ,_      . n8p\'           .d8\"\'      \'     689\n        \'.     \"888n._,      `\"8\"+88888n.8,88:`8 .     _ .n88P\'   .  `      ;88\'\n         :8.     \"q888.  .            \"+888P\"  \"+888n,8n8\'\"      .  .     ,d986 \n         :.`8:     `88986                          `q8\"           ,      :688\"  \n         ;.  \'8,      \"88b .d                        \'                  ,889\'   \n         :..   `6n      \'8988                                         b.89p     \n         :. .    \'8.      `88b                                        988\'      \n         :. .      8b       `q8.        \'                     . \'   .d89      \' \n         . .        `8:       `86n,.       \" . ,        , \"        ,98P      ,  \n         .. .         \'6n.       +86b.        .      .         _,.n88\'     .    \n           .            `\"8b.      \'q98n.        ,     .  _..n868688\'          .\n          \' . .            `\"98.     `8868.       .  _.n688868898p\"            d\n           . .                \'88.      \"688.       q89888688868\"            ,86\n         mh \'. .                 88.     `8898        \" .889\"\'              .988\n\n\n");

		printColoredStringAdvanced(ORANGE, NO_BG, BOLD, "\nWelcome to Task Tiger!\nNever forget a task again!\n\n");
		printf("User: %s \n", user->username);
		firstPrint = false;
	}

	printf("Your calendar for this month:\n(Days with tasks due will appear green)\n");
	print_calendar(*user, getCurrentDate());

	DetermineTigerMood(user);
	printf("Your tiger is ");
	printTigerStatus(user->tiger.tigerMood, true);

	printf("You have %d points.\n", user->points);




	//DISPLAY PERSONALIZED GREETINGS / 
	//bool firstPrint = true;
	//if(firstView) DisplayGreeting();
	//DisplayGreeting includes logo/drawing, welcome message with name?
	
	//if(newUser) newUser();
	//get username, password

	//DisplayReminders();

	//DisplayTigerStatus();


	printf("-----------------------------------------------\n");
	printf("		Main Menu\n");
	printf("-----------------------------------------------\n");
	printf("a) View Folder Menu\n");
	printf("b) Task Tiger\n");
	printf("c) View Calendar\n");
	printf("d) Settings\n");
	printColoredStringAdvanced(WHITE, NO_BG, ITALIC, "q) Save and Quit\n\n");
}