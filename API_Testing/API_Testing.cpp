#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace APITesting
{
	TEST_CLASS(APITesting)
	{
	public:
		
		TEST_METHOD(TestMethod1) {
			Assert::IsTrue(true);
		}
	};
}
