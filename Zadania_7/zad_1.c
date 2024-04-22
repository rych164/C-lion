#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to map word representation of numbers to digits.
int wordToDigit(const char *word) {
    const char *digits[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int digitLengths[] = {4, 3, 3, 5, 4, 4, 3, 5, 5, 4}; // Length of each word

    for (int i = 0; i < 10; i++) {
        if (strncmp(word, digits[i], digitLengths[i]) == 0 && strlen(word) == digitLengths[i]) {
            return i;
        }
    }
    return -1; // Return -1 if no match found.
}

void extractDigits(char *line, char *firstDigit, char *lastDigit) {
    char temp[7];
    int lineLength = strlen(line);
    int firstWordIndex = -1, lastWordIndex = -1;
    char firstWordFound = '\0', lastWordFound = '\0';

    for (int start = 0; start < lineLength; start++) {
        // Check for single digit characters
        if (isdigit(line[start])) {
            if (firstWordIndex == -1 && firstWordFound == '\0') {
                firstWordFound = line[start];
            }
            lastWordFound = line[start];
        }

        // Check for numeric words of length 3 to 6
        for (int len = 3; len <= 6; len++) {
            if (start + len <= lineLength) {
                strncpy(temp, line + start, len);
                temp[len] = '\0';
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

    *firstDigit = firstWordFound;
    *lastDigit = lastWordFound;
}

int main() {
    FILE *file;
    char *filename = "input1.txt";
    char line[1000];
    char firstDigit, lastDigit;
    int sum = 0;

    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    while (fgets(line, sizeof(line), file)) {
        extractDigits(line, &firstDigit, &lastDigit);
        if (firstDigit != '\0' && lastDigit != '\0') {
            int value = (firstDigit - '0') * 10 + (lastDigit - '0');
            sum += value;
        }
    }

    printf("Total sum: %d\n", sum);
    fclose(file);
    return 0;
}
