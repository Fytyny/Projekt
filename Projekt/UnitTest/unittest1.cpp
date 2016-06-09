#include "stdafx.h"
#include "CppUnitTest.h"
#include "tes.h"
#include "DatabaseConnection.h"	
#include "login.hpp"
#include "main.cpp"
#include <QtTest\qtest.h>

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
		}

		TEST_METHOD(baseTest)
		{
			DatabaseConnection base;
			Assert::AreEqual(base.connect(), SQLITE_OK, 0);
			Assert::AreEqual(base.dropTabAccounts(), SQLITE_OK, 0);
			Assert::AreEqual(base.dropTabDetails(), SQLITE_OK, 0);
			Assert::AreEqual(base.dropTabNumbers(), SQLITE_OK, 0);
			Assert::AreEqual(base.createTabAccounts(), SQLITE_OK, 0);
			Assert::AreEqual(base.createTabDetails(), SQLITE_OK, 0);
			Assert::AreEqual(base.createTabNumbers(), SQLITE_OK, 0);

			Person a;
			a.setLogin("log");
			a.setPassword("pas");
			a.setFirstName("as");
			a.setSecondName("karo");
			a.setLastName("kierowski");
			a.generateID(&base);
			a.generateAccountNumber(&base);
			
			a.insertIntoDb(&base);
		}
	};
}