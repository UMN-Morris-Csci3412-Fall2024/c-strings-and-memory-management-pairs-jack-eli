#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "disemvowel.h"

// Function to check if a character is a vowel
int vowel(char c) {
    int lowercase, uppercase;

    // Check if the character is a lowercase vowel
    lowercase = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    // Check if the character is an uppercase vowel
    uppercase = (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');

    // Return true if the character is either a lowercase or uppercase vowel
    return lowercase || uppercase;
}

// Function to remove vowels from a string
char *disemvowel(char *str) {
    int constants = 0, len, i;

    // Get the length of the input string
    len = strlen(str);

    // Count the number of non-vowel characters (consonants)
    for (i = 0; i < len; ++i) {
        if (!vowel(str[i])) {
            constants++;
        }
    }

    // Allocate memory for the result string, including space for the null terminator
    char *result = (char*) calloc(constants + 1, sizeof(char));
    int j = 0;

    // Copy non-vowel characters to the result string
    for (i = 0; i < len; ++i) {
        if (!vowel(str[i])) {
            result[j++] = str[i];
        }
    }

    // Null-terminate the result string
    result[j] = '\0';

    // Return the result string
    return result;
}
