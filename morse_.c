#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getInput(char **input) {
    char buffer[100];
    printf("Enter a string: ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = 0;  
    *input = strdup(buffer);
}

void textToMorse(const char *text) {
    const char *morseTable[128] = {NULL};
    morseTable['A'] = ".-";    morseTable['a'] = ".-";
    morseTable['B'] = "-...";  morseTable['b'] = "-...";
    morseTable['C'] = "-.-.";  morseTable['c'] = "-.-.";
    morseTable['D'] = "-..";   morseTable['d'] = "-..";
    morseTable['E'] = ".";     morseTable['e'] = ".";
    morseTable['F'] = "..-.";  morseTable['f'] = "..-.";
    morseTable['G'] = "--.";   morseTable['g'] = "--.";
    morseTable['H'] = "....";  morseTable['h'] = "....";
    morseTable['I'] = "..";    morseTable['i'] = "..";
    morseTable['J'] = ".---";  morseTable['j'] = ".---";
    morseTable['K'] = "-.-";   morseTable['k'] = "-.-";
    morseTable['L'] = ".-..";  morseTable['l'] = ".-..";
    morseTable['M'] = "--";    morseTable['m'] = "--";
    morseTable['N'] = "-.";    morseTable['n'] = "-.";
    morseTable['O'] = "---";   morseTable['o'] = "---";
    morseTable['P'] = ".--.";  morseTable['p'] = ".--.";
    morseTable['Q'] = "--.-";  morseTable['q'] = "--.-";
    morseTable['R'] = ".-.";   morseTable['r'] = ".-.";
    morseTable['S'] = "...";   morseTable['s'] = "...";
    morseTable['T'] = "-";     morseTable['t'] = "-";
    morseTable['U'] = "..-";   morseTable['u'] = "..-";
    morseTable['V'] = "...-";  morseTable['v'] = "...-";
    morseTable['W'] = ".--";   morseTable['w'] = ".--";
    morseTable['X'] = "-..-";  morseTable['x'] = "-..-";
    morseTable['Y'] = "-.--";  morseTable['y'] = "-.--";
    morseTable['Z'] = "--..";  morseTable['z'] = "--..";
    morseTable['0'] = "-----"; morseTable['1'] = ".----";
    morseTable['2'] = "..---"; morseTable['3'] = "...--";
    morseTable['4'] = "....-"; morseTable['5'] = ".....";
    morseTable['6'] = "-...."; morseTable['7'] = "--...";
    morseTable['8'] = "---.."; morseTable['9'] = "----.";
    morseTable[' '] = " ";     morseTable[','] = "--..--";
    morseTable['.'] = ".-.-.-";morseTable['?'] = "..--..";
    morseTable['-'] = "-....-";morseTable['/'] = "-..-.";
    morseTable['('] = "-.--."; morseTable[')'] = "-.--.-";
    morseTable['&'] = ".-..."; morseTable[':'] = "---...";
    morseTable[';'] = "-.-.-.";morseTable['='] = "-...-";
    morseTable['+'] = ".-.-."; morseTable['_'] = "..--.-";
    morseTable['"'] = ".-..-.";morseTable['$'] = "...-..-";
    morseTable['@'] = ".--.-.";morseTable['!'] = "-.-.--";

    size_t outputSize = 1; 
    for (const char *p = text; *p; ++p) {
        if (morseTable[(unsigned char)*p]) {
            outputSize += strlen(morseTable[(unsigned char)*p]) + 1;
        }
    }

    char *output = (char *)malloc(outputSize * sizeof(char));
    if (!output) {
        printf("Memory allocation failed\n");
        return;
    }
    output[0] = '\0';

    for (const char *p = text; *p; ++p) {
        if (morseTable[(unsigned char)*p]) {
            strcat(output, morseTable[(unsigned char)*p]);
            strcat(output, " ");
        }
    }
    printf("Output: %s\n", output);
    free(output);
}

void morseToText(const char *morse) {
    const char *morseTable[128] = {NULL};
    morseTable['A'] = ".-";    morseTable['a'] = ".-";
    morseTable['B'] = "-...";  morseTable['b'] = "-...";
    morseTable['C'] = "-.-.";  morseTable['c'] = "-.-.";
    morseTable['D'] = "-..";   morseTable['d'] = "-..";
    morseTable['E'] = ".";     morseTable['e'] = ".";
    morseTable['F'] = "..-.";  morseTable['f'] = "..-.";
    morseTable['G'] = "--.";   morseTable['g'] = "--.";
    morseTable['H'] = "....";  morseTable['h'] = "....";
    morseTable['I'] = "..";    morseTable['i'] = "..";
    morseTable['J'] = ".---";  morseTable['j'] = ".---";
    morseTable['K'] = "-.-";   morseTable['k'] = "-.-";
    morseTable['L'] = ".-..";  morseTable['l'] = ".-..";
    morseTable['M'] = "--";    morseTable['m'] = "--";
    morseTable['N'] = "-.";    morseTable['n'] = "-.";
    morseTable['O'] = "---";   morseTable['o'] = "---";
    morseTable['P'] = ".--.";  morseTable['p'] = ".--.";
    morseTable['Q'] = "--.-";  morseTable['q'] = "--.-";
    morseTable['R'] = ".-.";   morseTable['r'] = ".-.";
    morseTable['S'] = "...";   morseTable['s'] = "...";
    morseTable['T'] = "-";     morseTable['t'] = "-";
    morseTable['U'] = "..-";   morseTable['u'] = "..-";
    morseTable['V'] = "...-";  morseTable['v'] = "...-";
    morseTable['W'] = ".--";   morseTable['w'] = ".--";
    morseTable['X'] = "-..-";  morseTable['x'] = "-..-";
    morseTable['Y'] = "-.--";  morseTable['y'] = "-.--";
    morseTable['Z'] = "--..";  morseTable['z'] = "--..";
    morseTable['0'] = "-----"; morseTable['1'] = ".----";
    morseTable['2'] = "..---"; morseTable['3'] = "...--";
    morseTable['4'] = "....-"; morseTable['5'] = ".....";
    morseTable['6'] = "-...."; morseTable['7'] = "--...";
    morseTable['8'] = "---.."; morseTable['9'] = "----.";
    morseTable[' '] = " ";     morseTable[','] = "--..--";
    morseTable['.'] = ".-.-.-";morseTable['?'] = "..--..";
    morseTable['-'] = "-....-";morseTable['/'] = "-..-.";
    morseTable['('] = "-.--."; morseTable[')'] = "-.--.-";
    morseTable['&'] = ".-..."; morseTable[':'] = "---...";
    morseTable[';'] = "-.-.-.";morseTable['='] = "-...-";
    morseTable['+'] = ".-.-."; morseTable['_'] = "..--.-";
    morseTable['"'] = ".-..-.";morseTable['$'] = "...-..-";
    morseTable['@'] = ".--.-.";morseTable['!'] = "-.-.--";

    const char *morseArray[] = {
        ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
        "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
        "..-", "...-", ".--", "-..-", "-.--", "--..", "-----", ".----", "..---",
        "...--", "....-", ".....", "-....", "--...", "---..", "----.", " ", NULL
    };
    const char letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 ";
    
    size_t outputSize = strlen(morse) / 2 + 1;
    char *output = (char *)malloc(outputSize * sizeof(char));
    if (!output) {
        printf("Memory allocation failed\n");
        return;
    }
    output[0] = '\0';

    char *inputCopy = strdup(morse);
    if (!inputCopy) {
        printf("Memory allocation failed\n");
        free(output);
        return;
    }

    char *token = strtok(inputCopy, " ");
    while (token != NULL) {
        for (size_t i = 0; morseArray[i] != NULL; ++i) {
            if (strcmp(token, morseArray[i]) == 0) {
                strncat(output, &letters[i], 1);
                break;
            }
        }
        token = strtok(NULL, " ");
    }
    printf("Output: %s\n", output);

    free(output);
    free(inputCopy);
}