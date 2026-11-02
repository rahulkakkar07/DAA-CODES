#include <stdio.h>
#include <string.h>

int isAnagramSubstring(char main[], char sub[])
{
    int n = strlen(main);
    int m = strlen(sub);

    if (m > n)
        return 0;

    // Check every substring of length m
    for (int i = 0; i <= n - m; i++)
    {
        int freq1[256] = {0};
        int freq2[256] = {0};

        // Frequency of characters in sub
        for (int j = 0; j < m; j++)
        {
            freq1[(unsigned char)sub[j]]++;
        }

        // Frequency of current substring
        for (int j = i; j < i + m; j++)
        {
            freq2[(unsigned char)main[j]]++;
        }

        // Compare frequencies
        int same = 1;

        for (int j = 0; j < 256; j++)
        {
            if (freq1[j] != freq2[j])
            {
                same = 0;
                break;
            }
        }

        if (same)
            return 1;
    }

    return 0;
}

int main()
{
    char main[] = "hello";
    char sub[] = "oll";

    if (isAnagramSubstring(main, sub))
        printf("An anagram substring exists.");
    else
        printf("An anagram substring does not exist.");

    return 0;
}