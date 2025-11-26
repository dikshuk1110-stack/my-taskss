#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 100

// List of keywords
char keywords[][10] = {
    "int", "float", "char", "if", "else", "while", "for", "return", "void"
};
int keywordCount = 9;

// Function to check if a word is keyword
int isKeyword(char *word) {
    for (int i = 0; i < keywordCount; i++) {
        if (strcmp(word, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

// Function to check if character is an operator
int isOperator(char ch) {
    char operators[] = "+-*/=%";
    for (int i = 0; operators[i] != '\0'; i++) {
        if (ch == operators[i]) return 1;
    }
    return 0;
}

int main() {
    FILE *fp;
    char ch, buffer[MAX_LEN];
    int index = 0;

    fp = fopen("input.txt", "r");

    if (fp == NULL) {
        printf("Error: Input file not found!\n");
        return 0;
    }

    while ((ch = fgetc(fp)) != EOF) {

        // If alphanumeric, form a word
        if (isalnum(ch)) {
            buffer[index++] = ch;
        } else {
            // End of a word
            if (index != 0) {
                buffer[index] = '\0';

                if (isKeyword(buffer))
                    printf("Keyword: %s\n", buffer);
                else
                    printf("Identifier: %s\n", buffer);

                index = 0;
            }

            // Check operator
            if (isOperator(ch)) {
                printf("Operator: %c\n", ch);
            }
        }
    }

    fclose(fp);
    return 0;
}
