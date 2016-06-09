#include "stdafx.h"
#include "CppUnitTest.h"
#include "tes.h"
#include "DatabaseConnection.h"	
#include "login.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			tes h;
			Assert::AreEqual(25, h.i, 0);
			h.set(26);
			Assert::AreEqual(26, h.i, 0);
			// TODO: Your test code here
		}

		TEST_METHOD(NotSoObvious)
		{
			DatabaseConnection y;

			y.connect();

			Login z;

		}	
	};
}