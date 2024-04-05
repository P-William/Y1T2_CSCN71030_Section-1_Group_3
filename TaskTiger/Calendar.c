#include <stdio.h>
#include "date.h"
#include "string_utils.h"
#include "userAPI.h"
#include <time.h>


void print_calendar(User user, const Date date) {
    int daysInMonth;
    int dayOfWeek;
    int calendar[6][7] = { 0 }; // 6 rows and 7 columns for the calendar

    struct tm first_day = { 0 };
    first_day.tm_year = date.year - 1900;
    first_day.tm_mon = date.month - 1;
    first_day.tm_mday = 1;

    mktime(&first_day);

    daysInMonth = (date.month == 2 && ((date.year % 4 == 0 && date.year % 100 != 0) || (date.year % 400 == 0))) ? 29 :
        (date.month == 2) ? 28 :
        (date.month == 4 || date.month == 6 || date.month == 9 || date.month == 11) ? 30 :
        31;

    dayOfWeek = first_day.tm_wday;

    int day = 1;
    for (int row = 0; row < 6; row++) {
        for (int col = dayOfWeek; col < 7 && day <= daysInMonth; col++) {
            calendar[row][col] = day;
            day++;
        }
        dayOfWeek = 0; // Reset dayOfWeek for the next row
    }

    printf("Sun Mon Tue Wed Thu Fri Sat\n");

    for (int row = 0; row < 6; row++) {
        for (int col = 0; col < 7; col++) {
            if (calendar[row][col] == 0) {
                printf("    ");
            }
            else {
                if (DateHasTask(&user, createDate(calendar[row][col], date.month, date.year))) {
                    printColoredStringAdvanced(GREEN, NO_BG, NO_TOOL, "%3d ", calendar[row][col]);
                }
                else {
                    printf("%3d ", calendar[row][col]);
                }
            }
        }
        printf("\n");
    }
}