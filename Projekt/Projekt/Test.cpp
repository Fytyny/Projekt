#include <qdebug.h>
#include <string>
#include <CppUnitTest.h>
#include <CppUnitTestAssert.h>
#include <login.hpp>
#include <DatabaseConnection.h>
#include <projekt.h>
#include <registration.hpp>
using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

TEST_MODULE_INITIALIZE(ModuleInitialize)
{
	Logger::WriteMessage("In Module Initialize");
}

TEST_MODULE_CLEANUP(ModuleCleanup)
{
	Logger::WriteMessage("In Module Cleanup");
}

TEST_CLASS(Classname)
{

public:
	Classname()
	{
		Logger::WriteMessage("In Class1");
	}
	TEST_CLASS_INITIALIZE(ClassInitialize)
	{
		Logger::WriteMessage("In Class Initialize");
	}
	TEST_METHOD(nazwa)
	{
		Logger::WriteMessage("In Class Initialize");
		Assert::AreEqual(1, 1, 0);
	}
};

