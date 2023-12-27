
#include <stdio.h>
long int multiplyNumbers(int n);
int main()
{
    int n = 6;
    printf("Factorial of %d = %ld", n, multiplyNumbers(n));
    return 0;
}
long int multiplyNumbers(int n)
{
    if (n >= 1)
    {
        long int factorial = n * multiplyNumbers(n - 1);
        return factorial;
    }
    else
        return 1;
}