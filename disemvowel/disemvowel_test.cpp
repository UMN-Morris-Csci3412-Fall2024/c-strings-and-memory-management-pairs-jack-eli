#include <gtest/gtest.h>

#include "disemvowel.h"

void assert_removeVowels(const char* input, const char* expected) {
  char* result = disemvowel((char*)input);
  ASSERT_STREQ(expected, result);
  free(result);
}

TEST(Disemvowel, HandleEmptyString) {
  assert_removeVowels("", "");
}

TEST(Disemvowel, HandleNoVowels) {
  assert_removeVowels("pqrst", "pqrst");
}

TEST(Disemvowel, HandleOnlyVowels) {
  assert_removeVowels("aeiouAEIOUOIEAuoiea", "");
}

TEST(Disemvowel, HandleMorrisMinnesota) {
  assert_removeVowels("Morris, Minnesota", "Mrrs, Mnnst");
}

TEST(Disemvowel, HandlePunctuation) {
  assert_removeVowels("An (Unexplained) Elephant!", "n (nxplnd) lphnt!");
}

TEST(Disemvowel, HandleLongString) {
  char *str;
  int size;
  int i;

  size = 50000;
  str = (char*) calloc(size, sizeof(char));
  str[0] = 'x';
  str[1] = 'y';
  str[2] = 'z';
  for (i = 3; i < size-1; ++i) {
    str[i] = 'a';
  }
  str[size-1] = '\0';
  
  assert_removeVowels(str, "xyz");

  free(str);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
