#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_05_5/Lab_05_5.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Unittest055
{
	TEST_CLASS(Unittest055)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int depth = 0;
			int t;
			t = Fib(5, 1, depth);
			Assert::AreEqual(t, 8);
		}
	};
}
