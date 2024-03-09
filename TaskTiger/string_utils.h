#pragma once

#include <stdbool.h>

/**
 * strcmp wrapper that returns a bool
 */
bool stringCompare(const char*, const char*);
/**
 * Compare two strings case-insensitively.
 *
 * @param str1 Pointer to the first null-terminated string to be compared.
 * @param str2 Pointer to the second null-terminated string to be compared.
 * @return Returns `true` if the strings are equal (ignoring case); otherwise, returns `false`.
 */
bool stringCompareI(const char*, const char*);

/**
 * Converts the input string to uppercase in place.
 * @param str The input string to be converted to uppercase
 */
void stringToUpper(char*);
/**
 * Copies the input string and converts the copy to uppercase.
 * @param input The input string to be copied and converted to uppercase
 * @param output The output string where the converted uppercase string will be stored
 */
void stringToUpperCopy(const char* input, char* output);
/**
 * Converts the input string to lowercase in place.
 * @param str The input string to be converted to lowercase
 */
void stringToLower(char*);
/**
 * Copies the input string and converts the copy to lowercase.
 * @param input The input string to be copied and converted to lowercase
 * @param output The output string where the converted lowercase string will be stored
 */
void stringToLowerCopy(const char* input, char* output);

/**
 * Prints a string enclosed by a specified symbol on both sides.
 * @param symbol        The character used to enclose the string.
 * @param symbolPerSide The number of symbols to print on each side of the string.
 * @param string        The format string for the variable arguments.
 * @param ...           Variable arguments to be formatted into the string. (Same as printf)
 */
void printEnclosedText(char symbol, int symbolPerSide, const char* string, ...);
/**
 * Prints a string enclosed by a specified symbol on both sides with an optional newline.
 * @param symbol        The character used to enclose the string.
 * @param symbolPerSide The number of symbols to print on each side of the string.
 * @param newLine       Flag to indicate whether to print a newline after the enclosed string.
 * @param string        The format string for the variable arguments.
 * @param ...           Variable arguments to be formatted into the string. (Same as printf)
 */
void printEnclosedTextNL(char symbol, int symbolPerSide, bool newLine, const char* string, ...);

typedef enum TextColor {
	NO_COLOR,
	BLACK,
	RED,
	GREEN,
	ORANGE,
	BLUE,
	PURPLE,
	CYAN,
	WHITE,
	YELLOW,
	GREY,
	PINK,
	B_GREY,
	B_RED,
	B_GREEN,
	B_BLUE,
	B_CYAN
} TextColor;

typedef enum BackgroundColor {
	NO_BG,
	BG_BLACK,
	BG_RED,
	BG_GREEN,
	BG_ORANGE,
	BG_BLUE,
	BG_PURPLE,
	BG_CYAN,
	BG_B_GREY
} BackgroundColor;

typedef enum TextTools {
	NO_TOOL,
	BOLD,
	ITALIC,
	UNDERLINE,
	STRIKETHROUGH
} TextTools;

/**
 * Prints a colored and formatted string using ANSI escape codes.
 * @param color  The color of the text.
 * @param bgColor The background color of the text.
 * @param tool   The text formatting tool (e.g., bold, italic).
 * @param string The format string for the variable arguments.
 * @param ...    Variable arguments to be formatted into the string. (Same as printf)
 */
void printColoredString(TextColor, const char* string, ...);
/**
 * Prints a colored string without background color or text formatting.
 * @param color  The color of the text.
 * @param string The format string for the variable arguments.
 * @param ...    Variable arguments to be formatted into the string. (Same as printf)
 */
void printColoredStringAdvanced(TextColor, BackgroundColor, TextTools, const char* string, ...);