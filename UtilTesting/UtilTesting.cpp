#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#define CHARS_FOR_INT 12


extern "C" bool stringToInt(const char* string, int* output);
extern "C" bool intToString(int integer, char* outputString, size_t outputSize);
extern "C" bool stringCompare(const char*, const char*);
extern "C" bool stringCompareI(const char*, const char*);
extern "C" void stringToUpper(char*);
extern "C" void stringToUpperCopy(const char* input, char* output);
extern "C" void stringToLower(char*);
extern "C" void stringToLowerCopy(const char* input, char* output);

namespace UtilTesting {
	TEST_CLASS(UtilTesting) {
	public:
		
		TEST_METHOD(StringToInt_Test) {
			const char* string1 = "12345";
			const char* string2 = "512";
			const char* string3 = "999999";

			int int1;
			int int2;
			int int3;
			bool result1 = stringToInt(string1, &int1);
			bool result2 = stringToInt(string2, &int2);
			bool result3 = stringToInt(string3, &int3);

			Assert::IsTrue(result1);
			Assert::IsTrue(result2);
			Assert::IsTrue(result3);
			Assert::AreEqual(int1, 12345);
			Assert::AreEqual(int2, 512);
			Assert::AreEqual(int3, 999999);
		}
		TEST_METHOD(StringToInt_Negative_Test) {
			const char* string1 = "-12345";
			const char* string2 = "-512";
			const char* string3 = "-999999";

			int int1;
			int int2;
			int int3;
			bool result1 = stringToInt(string1, &int1);
			bool result2 = stringToInt(string2, &int2);
			bool result3 = stringToInt(string3, &int3);

			Assert::IsTrue(result1);
			Assert::IsTrue(result2);
			Assert::IsTrue(result3);
			Assert::AreEqual(int1, -12345);
			Assert::AreEqual(int2, -512);
			Assert::AreEqual(int3, -999999);
		}
		TEST_METHOD(StringToInt_MINMAX_Test) {
			const char* maxIntString = "2147483647";
			const char* minIntString = "-2147483648";

			int int1;
			int int2;
			bool result1 = stringToInt(minIntString, &int1);
			bool result2 = stringToInt(maxIntString, &int2);

			Assert::IsTrue(result1);
			Assert::IsTrue(result2);
			Assert::AreEqual(int1, INT_MIN);
			Assert::AreEqual(int2, INT_MAX);
		}
		TEST_METHOD(StringToInt_NULL_Test) {
			const char* string = "1234";
			int int1;
			bool result1 = stringToInt(NULL, &int1);
			bool result2 = stringToInt(string, NULL);
			
			Assert::IsFalse(result1);
			Assert::IsFalse(result2);
		}
		TEST_METHOD(StringToInt_NonNumber_Test) {
			const char* string1 = "abc123";
			const char* string2 = "colin";
			int int1;
			int int2;

			bool result1 = stringToInt(string1, &int1);
			bool result2 = stringToInt(string2, &int2);

			Assert::IsFalse(result1);
			Assert::IsFalse(result2);
		}


		TEST_METHOD(IntToString_Test) {
			char string1[CHARS_FOR_INT];
			char string2[CHARS_FOR_INT];
			int int1 = 1234;
			int int2 = 512;

			bool result1 = intToString(int1, string1, CHARS_FOR_INT);
			bool result2 = intToString(int2, string2, CHARS_FOR_INT);

			Assert::IsTrue(result1);
			Assert::IsTrue(result2);
			Assert::IsTrue(stringCompare(string1, "1234"));
			Assert::IsTrue(stringCompare(string2, "512"));
		}
		TEST_METHOD(IntToString_NULL_Test) {
			int int1 = 1234;

			bool result1 = intToString(int1, NULL, CHARS_FOR_INT);

			Assert::IsFalse(result1);
		}
		TEST_METHOD(IntToString_InvalidBufferSize_Test) {
			int int1 = 1234;

			bool result1 = intToString(int1, NULL, 5);

			Assert::IsFalse(result1);
		}


		TEST_METHOD(StringCompare_Test) {
			const char* string1 = "TestString";
			const char* string2 = "TestString";

			bool result1 = stringCompare(string1, string2);

			Assert::IsTrue(result1);
		}
		TEST_METHOD(StringCompare_False_Test) {
			const char* string1 = "TestString";
			const char* string2 = "APIE";

			bool result1 = stringCompare(string1, string2);

			Assert::IsFalse(result1);
		}

		TEST_METHOD(StringCompareI_Test) {
			const char* string1 = "TestString";
			const char* string2 = "TESTSTRING";

			bool result1 = stringCompareI(string1, string2);

			Assert::IsTrue(result1);
		}
		TEST_METHOD(StringCompareI_False_Test) {
			const char* string1 = "TestString";
			const char* string2 = "APIE";

			bool result1 = stringCompareI(string1, string2);

			Assert::IsFalse(result1);
		}

		TEST_METHOD(StringToUpper_Test) {
			char string1[] = "TestString";
			char string2[] = "TESTSTRING";

			stringToUpper(string1);

			Assert::IsTrue(stringCompare(string1, string2));
		}
		TEST_METHOD(StringToUpperCopy_Test) {
			char string1[] = "TestString";
			char string2[] = "TESTSTRING";
			char output[20];

			stringToUpperCopy(string1, output);

			Assert::IsTrue(stringCompare(output, string2));
		}
		TEST_METHOD(StringToLower_Test) {
			char string1[] = "TESTSTRING";
			char string2[] = "teststring";

			stringToLower(string1);

			Assert::IsTrue(stringCompare(string1, string2));
		}
		TEST_METHOD(StringToLowerCopy_Test) {
			char string1[] = "TESTSTRING";
			char string2[] = "teststring";
			char output[20];

			stringToLowerCopy(string1, output);

			Assert::IsTrue(stringCompare(output, string2));
		}
	};
}
