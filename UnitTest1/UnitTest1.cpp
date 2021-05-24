#include "pch.h"
#include "CppUnitTest.h"
#include "../lab1.8/Account.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(TestMethod1)
		{
			Account x;
			x.SetName("Solomia");
			Assert::AreEqual("Solomia", x.GetName().c_str());
		}
	};
}