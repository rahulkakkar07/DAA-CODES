#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char str[100];
    int len, k;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    str[strcspn(str, "\n")] = '\0';

    len = strlen(str) - 1;
    k = 0;

    while (len > k)
    {
        if (str[len] != str[k])
        {
            printf("%s is not a palindrome\n", str);
            return 0;
        }

        len--;
        k++;
    }

    printf("%s is a palindrome\n", str);

    return 0;
}