#include "pch.h"
#include "CppUnitTest.h"
#include "../l_12_2_recur/l_12_2_recur.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Elem* start = NULL;
			Elem* last = NULL;
			enqueue(start, last, 0, 10);

			bool x = start != NULL;

			Assert::AreEqual(x, true);
		}
	};
}
