#include <iostream>
#include <fstream>
#include <string>
#include <cctype>  // For isdigit function
#include <cstring> // For strncpy

// Function to map word representation of numbers to digits.
int wordToDigit(const std::string& word) {
    const char* digits[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int digitLengths[] = {4, 3, 3, 5, 4, 4, 3, 5, 5, 4}; // Length of each word

    for (int i = 0; i < 10; ++i) {
        if (word == digits[i]) {
            return i;
        }
    }
    return -1; // Return -1 if no match found.
}

void extractDigits(const std::string& line, char& firstDigit, char& lastDigit) {
    std::string temp;
    int firstWordIndex = -1, lastWordIndex = -1;
    char firstWordFound = '\0', lastWordFound = '\0';

    for (size_t start = 0; start < line.length(); ++start) {
        // Check for single digit characters
        if (isdigit(line[start])) {
            if (firstWordIndex == -1 && firstWordFound == '\0') {
                firstWordFound = line[start];
            }
            lastWordFound = line[start];
        }

        // Check for numeric words of length 3 to 6
        for (int len = 3; len <= 6; ++len) {
            if (start + len <= line.length()) {
                temp = line.substr(start, len);
                int num = wordToDigit(temp);
                if (num != -1) {
                    char digit = '0' + num;
                    if (firstWordIndex == -1) { // If this is the first numeric word found
                        firstWordIndex = start;
                        if (firstWordFound == '\0') {
                            firstWordFound = digit;
                        }
                    }
                    lastWordIndex = start;
                    lastWordFound = digit;
                    start += len - 1; // Move start index past this word
                    break;
                }
            }
        }
    }

    firstDigit = firstWordFound;
    lastDigit = lastWordFound;
}

int main() {
    std::ifstream file;
    std::string filename = "input1.txt";
    std::string line;
    char firstDigit, lastDigit;
    int sum = 0;

    file.open(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return EXIT_FAILURE;
    }

    while (getline(file, line)) {
        extractDigits(line, firstDigit, lastDigit);
        if (firstDigit != '\0' && lastDigit != '\0') {
            int value = (firstDigit - '0') * 10 + (lastDigit - '0');
            sum += value;
        }
    }

    std::cout << "Total sum: " << sum << std::endl;
    file.close();
    return 0;
}
