#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    // n must be a positive value
    do
    {
        printf("Enter the starting value: ");
        scanf("%d", &n);
    } while (n < 0);
    for (int i = n; i >= 1; i--)
    {
        printf("%d\n", i);
    }
    printf("Blast off to the moon!");
    return 0;
}
