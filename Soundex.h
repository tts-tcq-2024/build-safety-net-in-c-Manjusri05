#ifndef SOUNDEX_H
#define SOUNDEX_H
 
#include <ctype.h>
#include <string.h>
 
/* Lookup table for Soundex codes for 'A' to 'Z' */
char soundexMap[26] = {
    '0', '1', '2', '3', '0', '1', '2', '0', '0', '2', // A,B,C,D,E,F,G,H,I,J
    '2', '4', '5', '5', '0', '1', '2', '6', '2', '3', // K,L,M,N,O,P,Q,R,S,T
    '0', '1', '0', '2', '0', '2'                      // U,V,W,X,Y,Z
};
 
int isUpperCaseLetter(char c) {
    return c >= 'A' && c <= 'Z';
}
 
char toUpperCase(char c) {
    return toupper(c);
}
 
char getSoundexCode(char c) {
    c = toUpperCase(c);
    if (isUpperCaseLetter(c)) {
        return soundexMap[c - 'A'];  /* It Return's mapped code from lookup table */
    }
    return '0'; /* For non-alphabet characters returns Zero */
}
 
 
int isSuoundxCode(char code, char previousCode) {
    return code != '0' && code != previousCode;
}
 
/* If valid, this helper function to add a character to the Soundex code */
void addToSoundex(char *soundex, char code, int *sIndex) {
    if (isSuoundxCode(code, soundex[*sIndex - 1])) {
        soundex[(*sIndex)++] = code;
    }
}
 
void initializeSoundex(const char *name, char *soundex, int *sIndex) {
    soundex[0] = toUpperCase(name[0]);  
    *sIndex = 1;  /* Initialize the index to the second character */
}
 
void padSoundex(char *soundex, int *sIndex) {
    while (*sIndex < 4) {
        soundex[(*sIndex)++] = '0';
    }
    soundex[4] = '\0'; /* If null-terminate the Soundex code */ 
}
 
/* Supporting function to check if Soundex code length is sufficient */
int isSoundexComplete(int sIndex) {
    return sIndex >= 4;
}
 
int isIndexWithinBounds(int i, int len) {
    return i < len;
}
 
int canContinueProcessing(const char *name, int i, int len, int *sIndex) {
    return isIndexWithinBounds(i, len) && !isSoundexComplete(*sIndex);
}
 
/* Function to process characters and generate Soundex code */
void processSoundex(const char *name, char *soundex, int *sIndex, int len) {
    int i = 1;  /* Start from the second character of the input */
 
    while (canContinueProcessing(name, i, len, sIndex)) {
        char code = getSoundexCode(name[i]);
        addToSoundex(soundex, code, sIndex);  
        i++; 
    }
}
 
 
/* Function to generate the Soundex code */
void generateSoundex(const char *name, char *soundex) {
    int len = strlen(name);
    int sIndex = 0;
 
    initializeSoundex(name, soundex, &sIndex);  
 
    processSoundex(name, soundex, &sIndex, len);  /* Process the characters and generate Soundex code */
 
    padSoundex(soundex, &sIndex);  /* Pad with '0's to make it of length 4 */
}
 
#endif // SOUNDEX_H
