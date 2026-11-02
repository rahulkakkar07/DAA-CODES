#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int last[256];
    int start = 0, maxStart = 0, maxLen = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    str[strcspn(str, "\n")] = '\0';

    // Initialize all character positions to -1
    for (int i = 0; i < 256; i++)
        last[i] = -1;

    for (int i = 0; str[i] != '\0'; i++) {
        unsigned char ch = str[i];

        // If character is already present in current substring
        if (last[ch] >= start)
            start = last[ch] + 1;

        last[ch] = i;

        // Update longest substring
        if (i - start + 1 > maxLen) {
            maxLen = i - start + 1;
            maxStart = start;
        }
    }

    printf("Longest substring: ");

    for (int i = maxStart; i < maxStart + maxLen; i++)
        printf("%c", str[i]);

    printf("\nLength: %d\n", maxLen);

    return 0;
}