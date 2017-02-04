/**
 * Keywords in the C programming language
 */


#include <stdbool.h>
#include <string.h>


static const char *KEYWORDS[32] = {
    "auto",
    "break",
    "case",
    "char",
    "const",
    "continue",
    "default",
    "do",
    "double",
    "else",
    "enum",
    "extern",
    "float",
    "if",
    "int",
    "long",
    "register",
    "return",
    "short",
    "signed",
    "sizeof",
    "static",
    "switch",
    "typedef",
    "union",
    "unsigned",
    "void",
    "volatile",
    "while",
};

/*
    Return true is word is keyword in the C programming language, otherwise - false.
 */
static bool
isKeyword(char word[]) {
    for (unsigned int i = 0; i < 32; ++i) {
        printf("%s %s %d\n", word, KEYWORDS[i], i);
        if (strcmp(word, KEYWORDS[i])) return true;
    }
    return false;
}

