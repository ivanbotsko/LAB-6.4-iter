#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

std::vector<int> generateArray(int size, int min, int max) {
    std::vector<int> array;
    for (int i = 0; i < size; i++) {
        array.push_back(rand() % (max - min + 1) + min);
    }
    return array;
}

int calcSumOfOdd(const std::vector<int>& array) {
    int sum = 0;
    for (int i = 1; i < array.size(); i += 2) {
        sum += array[i];
    }
    return sum;
}

int calcFirstNegative(const std::vector<int>& array) {
    for (int i = 0; i < array.size(); i++) {
        if (array[i] < 0) {
            return i;
        }
    }
    return -1; // Якщо від'ємних елементів немає
}

int calcLastNegative(const std::vector<int>& array) {
    int lastNeg = -1;
    for (int i = 0; i < array.size(); i++) {
        if (array[i] < 0) {
            lastNeg = i;
        }
    }
    return lastNeg;
}

int calcSumBetweenNeg(const std::vector<int>& array, int firstNegativeIdx, int lastNegativeIdx) {
    int sum = 0;
    for (int i = firstNegativeIdx + 1; i < lastNegativeIdx; i++) {
        sum += array[i];
    }
    return sum;
}

std::vector<int> compressArray(std::vector<int>& array) {
    int index = 0;
    for (int i = 0; i < array.size(); i++) {
        if (std::abs(array[i]) > 1) {
            array[index] = array[i];
            index++;
        }
    }
    for (int i = index; i < array.size(); i++) {
        array[i] = 0;
    }
    return array;
}

int main() {
    srand(static_cast<unsigned>(time(0)));

    int n;
    std::cout << "n = ";
    std::cin >> n;

    std::vector<int> array = generateArray(n, -5, 5);
    std::cout << "Initial array: ";
    for (int i = 0; i < array.size(); i++) {
        std::cout << array[i];
        if (i < array.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;

    int sumOfOdd = calcSumOfOdd(array);
    std::cout << "The sum of elements with odd indices: " << sumOfOdd << std::endl;

    int firstNegIdx = calcFirstNegative(array);
    int lastNegIdx = calcLastNegative(array);

    if (firstNegIdx != -1 && lastNegIdx != -1) {
        int sumBetweenNeg = calcSumBetweenNeg(array, firstNegIdx, lastNegIdx);
        std::cout << "The sum of the elements between the negative elements: " << sumBetweenNeg << std::endl;
    }
    else {
        std::cout << "There are no negative elements in the array." << std::endl;
    }

    std::vector<int> compressedArray = compressArray(array);
    std::cout << "Compressed array:";
    for (int i = 0; i < compressedArray.size(); i++) {
        std::cout << compressedArray[i];
        if (i < compressedArray.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;

    return 0;
}

