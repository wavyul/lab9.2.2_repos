#include "pch.h"
#include "CppUnitTest.h"
#include "../LB9.2.2/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:
        TEST_METHOD(TestInfoMsg)
        {
            std::stringstream buffer;
            std::streambuf* oldCoutBuffer = std::cout.rdbuf(buffer.rdbuf());

            INFO_MSG();

            std::cout.rdbuf(oldCoutBuffer);
            std::string output = buffer.str();

            Assert::IsTrue(output.find("Compiled File:") != std::string::npos, L"INFO_MSG did not print file information.");
            Assert::IsTrue(output.find("Compiled Date:") != std::string::npos, L"INFO_MSG did not print date information.");
            Assert::IsTrue(output.find("Compiled Time:") != std::string::npos, L"INFO_MSG did not print time information.");
            Assert::IsTrue(output.find("Conforms to C++11 or later:") != std::string::npos, L"INFO_MSG did not check C++ standard.");
        }

        TEST_METHOD(TestErrorMsg)
        {
            std::stringstream buffer;
            std::streambuf* oldCerrBuffer = std::cerr.rdbuf(buffer.rdbuf());

            ERROR_MSG("Test error");

            std::cerr.rdbuf(oldCerrBuffer);
            std::string errorOutput = buffer.str();

            Assert::IsTrue(errorOutput.find("Error: Test error") != std::string::npos, L"ERROR_MSG did not print error message.");
            Assert::IsTrue(errorOutput.find("File:") != std::string::npos, L"ERROR_MSG did not print file information.");
            Assert::IsTrue(errorOutput.find("Line:") != std::string::npos, L"ERROR_MSG did not print line information.");
            Assert::IsTrue(errorOutput.find("Date:") != std::string::npos, L"ERROR_MSG did not print date information.");
            Assert::IsTrue(errorOutput.find("Time:") != std::string::npos, L"ERROR_MSG did not print time information.");
        }
    };
}
