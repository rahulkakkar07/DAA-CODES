#include <stdio.h>

int main()
{
    int n, digit, sum = 0;
    
    printf("Enter the number: ");
    scanf("%d", &n);

    while(n > 0)
    {
        digit = n % 10;     // get last digit
        sum = sum + digit;  // add digit to sum
        n = n / 10;         // remove last digit
    }

    printf("Missing digit = %d", 45 - sum);

    return 0;
}