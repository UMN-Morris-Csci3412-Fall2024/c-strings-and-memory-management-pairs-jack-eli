#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "disemvowel.h"

int vowel(char c) {
    int lowercase, uppercase;

    lowercase = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    uppercase = (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');

    if (lowercase || uppercase)
        return true;
    else
        return false;
}

char *disemvowel(char *str) {
  
  
  int constants, len, i;

  len = strlen(str);
  for (i=0; i<len; ++i) {
    if(!vowel(str[i])) {
      constants++;
    }
  }

  char *result;
  result = (char*) calloc(constants+1, sizeof(char));
  int j = 0;
  for (i=0; i<len; ++i) {
    if (!vowel(str[i])) {
      result[j++] = str[i];
    }
  }  

  return result;
}
