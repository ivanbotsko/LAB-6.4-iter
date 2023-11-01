#include "pch.h"
#include "CppUnitTest.h"
#include <vector>
#include "../PR 6.4 iter/PR 6.4 iter.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

TEST_CLASS(GenerateArrayTest) {
public:

    TEST_METHOD(GeneratesArrayWithCorrectSize) {
        int size = 26;
        int min = -20;
        int max = 40;

        std::vector<int> array = generateArray(size, min, max);

        Assert::AreEqual(size, static_cast<int>(array.size()));
    }

    TEST_METHOD(GeneratesArrayWithinSpecifiedRange) {
        int size = 20;
        int min = -20;
        int max = 40;

        std::vector<int> array = generateArray(size, min, max);

        for (int element : array) {
            Assert::IsTrue(element >= min && element <= max);
        }
    }

    TEST_METHOD(GeneratesRandomValues) {
        int size = 100;
        int min = -50;
        int max = 50;

        std::vector<int> array1 = generateArray(size, min, max);
        std::vector<int> array2 = generateArray(size, min, max);

        bool areDifferent = false;

        // Check if two generated arrays are different
        for (int i = 0; i < size; i++) {
            if (array1[i] != array2[i]) {
                areDifferent = true;
                break;
            }
        }

        Assert::IsTrue(areDifferent);
    }
};
