#include "stdafx.h"
#include "CppUnitTest.h"
#include "DatabaseConnection.h"	
#include "login.hpp"
#include "main.cpp"
#include <string>
#include <QtTest\qtest.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{		
	TEST_CLASS(BaseTest)
	{
	public:
		
		TEST_METHOD(SinglePerson)
		{
			DatabaseConnection base;
			Assert::AreEqual(base.connect(), SQLITE_OK, 0);
			Assert::AreEqual(base.dropTabAccounts(), SQLITE_OK, 0);
			Assert::AreEqual(base.dropTabDetails(), SQLITE_OK, 0);
			Assert::AreEqual(base.dropTabNumbers(), SQLITE_OK, 0);
			Assert::AreEqual(base.dropTabNotify(), SQLITE_OK, L"sada");
			Assert::AreEqual(base.createTabAccounts(), SQLITE_OK, 0);
			Assert::AreEqual(base.createTabDetails(), SQLITE_OK, 0);
			Assert::AreEqual(base.createTabNumbers(), SQLITE_OK, L"sada");
			Assert::AreEqual(base.createTabNotify(), SQLITE_OK, L"sada");
			

			Person a;
			a.setLogin("log");
			a.setPassword("pas");
			a.setFirstName("as");
			a.setSecondName("karo");
			a.setLastName("kierowski");
			a.generateID(&base);
			a.generateAccountNumber(&base);
			Assert::AreEqual(a.insertIntoDb(&base), SQLITE_OK, L"s");

			Person b;
			Assert::AreEqual(0, b.getPersonFromDataBase(a.getLogin(), a.getPassword(), &base), L"no co jest");
			Assert::AreEqual(a.getLogin().c_str(), b.getLogin().c_str(),L"czek fajled");
			Assert::AreEqual(a.getPassword().c_str(), b.getPassword().c_str(), L"czek fajled");
			Assert::AreEqual(a.getID(), b.getID(), L"czek fajled");
			Assert::AreEqual(a.getFirstName().c_str(), b.getFirstName().c_str(), L"czek fajled");
			Assert::AreEqual<unsigned long long>(a.getAccountNumber(), b.getAccountNumber(), L"czek fajled");

			Person c;
			Assert::AreNotEqual(0, c.getPersonFromDataBase("wrong", a.getPassword(), &base), L"no co jest");
			Assert::AreNotEqual(a.getLogin().c_str(), c.getLogin().c_str() , L"czek fajled");
			Assert::AreNotEqual(a.getPassword().c_str(), c.getPassword().c_str(), L"czek fajzcczled");
			Assert::AreNotEqual(a.getID(),c.getID(), L"czek fajled");
		}
	};
}