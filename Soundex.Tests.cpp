#include <gtest/gtest.h>
#include "Soundex.h"
 
TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits) {
//AAA
  char soundex[5];
  generateSoundex("AX", soundex);
  ASSERT_STREQ(soundex,"A200");
  generateSoundex("manjusri", soundex);
  ASSERT_STREQ(soundex,"M522");
 
  generateSoundex("good", soundex);
  ASSERT_STREQ(soundex,"G300");
 
  generateSoundex("hwyaeiou", soundex);
  ASSERT_STREQ(soundex,"H000");
 
  generateSoundex("qwertyuiop", soundex);
  ASSERT_STREQ(soundex,"Q631");
 
  generateSoundex("abcde", soundex);
  ASSERT_STREQ(soundex,"A123");
  generateSoundex("dessert", soundex);
  ASSERT_STREQ(soundex,"D263");
}
TEST(SoudexTestsuite, ReturnsZerosForDigitOnlyInput) {
  char soundex[5];
  generateSoundex("63619156", soundex);
  EXPECT_STREQ(soundex,"6000");
}
