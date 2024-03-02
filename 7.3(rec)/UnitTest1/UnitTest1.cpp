#include "pch.h"
#include "CppUnitTest.h"
#include "../7.3(rec)/Source.cpp" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:
        TEST_METHOD(TestCountPositiveElementsInRow)
        {
            std::vector<int> row = { 1, -2, 3, 0 };
            int expectedCount = 2;
            Assert::AreEqual(expectedCount, CountPositiveElementsInRow(row));
        }

        TEST_METHOD(TestLongestSeriesLengthInColumn)
        {
            std::vector<std::vector<int>> matrix = {
                {1, 2, 3},
                {1, 2, 2},
                {3, 4, 3}
            };
            int colNo = 1;
            int expectedLength = 2;
            Assert::AreEqual(expectedLength, LongestSeriesLengthInColumn(matrix, colNo));
        }
    };
}
