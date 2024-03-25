#pragma once

#include <limits.h>
#include <stdbool.h>

typedef struct Date {
	int day;
	int month;
	int year;
} Date;


/**
 * Creates a Date structure with the given day, month, and year.
 * @param day The day of the month.
 * @param month The month of the year.
 * @param year The year.
 * @return The created Date structure.
 */
Date createDate(int day, int month, int year);
/**
 * Creates a blank Date structure with all values set to -1.
 * @return The created blank Date structure.
 */
Date createDateBlank();

/**
 * Checks if two Date structures are equal.
 * @param dateOne The first Date structure.
 * @param dateTwo The second Date structure.
 * @return True if the two Date structures are equal, otherwise false.
 */
bool equalDate(Date, Date);
/**
 * Checks if a Date structure is blank (all values set to -1).
 * @param date The Date structure to check.
 * @return True if the Date structure is blank, otherwise false.
 */
bool emptyDate(Date);

/**
 * Copies a Date structure.
 * @param src The source Date structure to copy from.
 * @return The copied Date structure.
 */
Date copyDate(Date src);
/**
 * Copies a Date structure into another Date structure.
 * @param dest Pointer to the destination Date structure.
 * @param src The source Date structure to copy from.
 * @return True if the copy operation is successful, otherwise false.
 */
bool copyDateInPlace(Date* dest, Date src);

/**
 * Gets the current date.
 * @return The current date.
 */
Date getCurrentDate();

/**
 * Prints the given date.
 * @param date The date to print.
 * @param newLine If true, prints a newline character after the date.
 */
void printDate(Date date, bool newLine);

/**
 * Converts a string representing a date to a Date structure.
 * @param output Pointer to the Date structure where the result will be stored.
 * @param dateString The string representing the date.
 * @details This function accepts date strings in the formats "DD-MM-YY", "DD-MM-YYYY", "DD/MM/YY", or "DD/MM/YYYY".
 * @return True if the conversion is successful, otherwise false.
 */
bool stringToDate(Date* output, const char* dateString);

/**
 * Prompts the user to input a date and converts it to a Date structure.
 * @param output Pointer to the Date structure where the result will be stored.
 * @param prompt The prompt message to display to the user.
 * @return True if the input and conversion are successful, otherwise false.
 */
bool getDateFromUser(Date* output, const char* prompt, ...);

/**
 * Calculates the difference in days between two dates.
 * @param dateOne The first date.
 * @param dateTwo The second date.
 * @return The difference in days between dateOne and dateTwo.
 *         If dateOne is past dateTwo, the returned value will be negative.
 *         Returns INT_MIN if an error occurs during conversion.
 */
int dateDifference(Date, Date);

/**
 * Calculates the absolute difference in days between two dates.
 * @param dateOne The first date.
 * @param dateTwo The second date.
 * @return The absolute difference in days between dateOne and dateTwo.
 *         Regardless of which date is earlier, the returned value is always positive.
 *         Returns INT_MIN if an error occurs
 */
int dateDifferenceAbsolute(Date, Date);