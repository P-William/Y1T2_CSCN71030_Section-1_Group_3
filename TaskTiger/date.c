
#define _CRT_SECURE_NO_WARNINGS

#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <limits.h>

#include "date.h"
#include "file_io.h"
#include "input_handler.h"

#define DATE_STRING_LENGTH 11



Date createDate(int day, int month, int year) {
    Date newDate = {
        .day = day,
        .month = month,
        .year = year
    };
    return newDate;
}
Date createDateBlank() {
    return createDate(-1, -1, -1);
}

bool equalDate(Date dateOne, Date dateTwo) {
    return (
        dateOne.day == dateTwo.day &&
        dateOne.month == dateTwo.month &&
        dateOne.year == dateTwo.year
    );
}

bool emptyDate(Date date) {
    return equalDate(date, createDateBlank());
}

Date copyDate(Date src) {
    Date newDate = {
        .day = src.day,
        .month = src.month,
        .year = src.year
    };
    return newDate;
}
bool copyDateInPlace(Date* dest, Date src) {
    if (dest == NULL) {
        fprintf(stderr, "Null pointer when trying to copy date\n");
        return false;
    }

    dest->day = src.day;
    dest->month = src.month;
    dest->year = src.year;
    return true;
}

Date getCurrentDate() {
    time_t now = time(NULL);
    struct tm* localTime = localtime(&now);
    Date current_date = {
        .day = localTime->tm_mday,
        .month = localTime->tm_mon + 1, // tm_mon is 0-based
        .year = localTime->tm_year + 1900 // tm_year is years since 1900
    };
    return current_date;
}

void printDate(Date date, bool newLine) {
    printf("%d-%d-%d", date.day, date.month, date.year);
    if (newLine) {
        printf("\n");
    }
}

bool stringToDate(Date* output, const char* dateString) {
    if (output == NULL || dateString == NULL) {
        fprintf(stderr, "Cannot convert with null pointer\n");
        return false;
    }

    int day;
    int month;
    int year;

    if (sscanf(dateString, "%d-%d-%d", &day, &month, &year) == 3) {
    }
    else if (sscanf(dateString, "%d/%d/%d", &day, &month, &year) == 3) {
    }
    else {
        fprintf(stderr, "Invalid date format. Accepted formats: DD-MM-YY or DD-MM-YYYY\nDD/MM/YY or DD/MM/YYYY\n");
        return false;
    }

    if (day < 1 || day > 31) {
        fprintf(stderr, "Invalid day: %d\n", day);
        return false;
    }
    if (month < 1 || month > 12) {
        fprintf(stderr, "Invalid month: %d\n", month);
        return false;
    }

    // Date format: DD-MM-YY or DD-MM-YYYY or DD/MM/YY or DD/MM/YYYY
    if (year < 100) {
        // Convert 2-digit year to 4-digit year
        if (year >= 0 && year <= 30)
            year += 2000;
        else
            year += 1900;
    }

    Date date = {
        .day = day,
        .month = month,
        .year = year
    };


    *output = date;
    return true;
}

bool getDateFromUser(Date* output, const char* prompt, ...) {
    va_list args;
    va_start(args, prompt);

    char dateInput[DATE_STRING_LENGTH];
    bool result = getStringFromUser(DATE_STRING_LENGTH, dateInput, prompt, args);
    if (!result) {
        fprintf(stderr, "Invalid Input\n");
        return false;
    }
    va_end(args);

    return stringToDate(output, dateInput);
}

int dateDifference(Date dateOne, Date dateTwo) {
    if (emptyDate(dateOne) || emptyDate(dateTwo)) {
        return INT_MIN;
    }

    // Convert dateOne and dateTwo to time_t format
    struct tm tm1 = {
        .tm_year = dateOne.year - 1900,
        .tm_mon = dateOne.month - 1,
        .tm_mday = dateOne.day
    };
    time_t timeOne = mktime(&tm1);
    struct tm tm2 = {
        .tm_year = dateTwo.year - 1900,
        .tm_mon = dateTwo.month - 1,
        .tm_mday = dateTwo.day
    };
    time_t timeTwo = mktime(&tm2);

    // Check if conversion succeeded
    if (timeOne == -1 || timeTwo == -1) {
        return INT_MIN;
    }

    // Calculate difference in seconds
    double differenceInSeconds = difftime(timeOne, timeTwo);

    // Convert to days
    int differenceInDays = (int)differenceInSeconds / (60 * 60 * 24);

    // Return the difference
    return differenceInDays;
}

int dateDifferenceAbsolute(Date dateOne, Date dateTwo) {
    return abs(dateDifference(dateOne, dateTwo));
}


bool saveDate(FILE* fp, Date date) {
    if (fp == NULL) {
        fprintf(stderr, "Null file pointer passed\n");
        return false;
    }

    writeIntToFile(fp, date.day);
    writeIntToFile(fp, date.month);
    writeIntToFile(fp, date.year);

    return true;
}

Date loadDate(FILE* fp) {
    if (fp == NULL) {
        fprintf(stderr, "Null file pointer passed\n");
        exit(-1);
    }

    int day;
    int month;
    int year;

    getIntFromFile(fp, &day);
    getIntFromFile(fp, &month);
    getIntFromFile(fp, &year);

    return createDate(day, month, year);
}