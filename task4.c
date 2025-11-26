#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to compress a string using RLE
void rle_compress(char* str, char* compressed) {
    int len = strlen(str);
    int count;
    int k = 0;

    for (int i = 0; i < len; i++) {
        count = 1;
        while (i < len - 1 && str[i] == str[i + 1]) {
            count++;
            i++;
        }
        compressed[k++] = str[i];
        k += sprintf(&compressed[k], "%d", count);
    }
    compressed[k] = '\0';
}

// Function to decompress an RLE string
void rle_decompress(char* compressed, char* decompressed) {
    int k = 0;
    for (int i = 0; compressed[i] != '\0'; i++) {
        char ch = compressed[i];
        int count = 0;

        // Extract count (may have more than 1 digit)
        while (compressed[i + 1] >= '0' && compressed[i + 1] <= '9') {
            count = count * 10 + (compressed[i + 1] - '0');
            i++;
        }

        for (int j = 0; j < count; j++) {
            decompressed[k++] = ch;
        }
    }
    decompressed[k] = '\0';
}

// Main function
int main() {
    char str[100];
    char compressed[200];
    char decompressed[100];

    printf("Enter a string to compress: ");
    scanf("%s", str);

    rle_compress(str, compressed);
    printf("Compressed string: %s\n", compressed);

    rle_decompress(compressed, decompressed);
    printf("Decompressed string: %s\n", decompressed);

    return 0;
}
