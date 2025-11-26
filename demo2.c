#include <stdio.h>
#include <stdlib.h>

int main() 
{
    FILE *fp;
    char data[100];
    int c;

    // 1. CREATE and WRITE
    fp = fopen("demo.txt", "w");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    printf("Enter text to WRITE into the file:\n");
    fgets(data, sizeof(data), stdin);
    fputs(data, fp);
    fclose(fp);
    printf("Data written successfully.\n\n");

    // Clear input buffer before next fgets
    while ((c = getchar()) != '\n' && c != EOF);

    // 2. APPEND
    fp = fopen("demo.txt", "a");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    printf("Enter text to APPEND to the file:\n");
    fgets(data, sizeof(data), stdin);
    fputs(data, fp);
    fclose(fp);
    printf("Data appended successfully.\n\n");

    // 3. READ
    fp = fopen("demo.txt", "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    printf("Contents of the file:\n");
    while (fgets(data, sizeof(data), fp) != NULL) {
        printf("%s", data);
    }
    fclose(fp);

    return 0;
}