#include <stdio.h>
#include <math.h>

// problem 1
void printEvenAndSquare()
{
    int n = 20;
    printf("The output is printed below\n");
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 0)
            printf("%d(%d), ", i, i * i);
    }
    printf("\n");
}

// problem 2
void sumOfFirstNNumbers()
{
    int n;
    printf("Give the suitable input\n");
    scanf("%d", &n);
    printf("The output is printed below\n");
    printf("%d ", (n * (n + 1)) / 2);
    printf("\n");
}

// problem 3
void printArmstrong()
{
    int n = 500, cubeSum;
    printf("The output is printed below\n");
    for (int i = 1; i <= n; i++)
    {
        cubeSum = 0;
        int j = i;
        do
        {
            int temp = j % 10;
            cubeSum += pow(temp / 1.0, 3.0);
            j /= 10;
        } while (j != 0);
        if (cubeSum == i)
        {
            printf("%d, ", cubeSum);
        }
    }
    printf("\n");
}

// problem 4
void printSquareCubeSqRoot()
{
    float n;
    printf("Give the suitable input\n");
    scanf("%f", &n);
    printf("The output is printed below\n");
    for (float i = 1; i <= n; i++)
    {
        printf("%.2f, %.2f, %.2f\n", pow(i, 2.0), pow(i, 3.0), sqrt(i));
    }
}

// problem 5
void sumOfOddNumbers()
{
    int n, sum = 0;
    printf("Give the suitable input\n");
    scanf("%d", &n);
    printf("The output is printed below\n");
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 != 0)
            sum += i;
    }
    printf("%d\n", sum);
}

// problem 6
void countNumberOfDigits()
{
    int n, count = 0;
    printf("Give the suitable input\n");
    scanf("%d", &n);
    do
    {
        n /= 10;
        count++;
    } while (n != 0);
    printf("The output is printed below\n");
    printf("%d\n", count);
}

// problem 7
void printFirstAndLastDigit()
{
    int n;
    printf("Give the suitable input\n");
    scanf("%d", &n);
    int lastDigit = n % 10, firstDigit;
    do
    {
        n /= 10;
    } while (n / 10 != 0);
    firstDigit = n;
    printf("The output is printed below\n");
    printf("first= %d, last: %d\n", firstDigit, lastDigit);
}

// problem 8
void productOfDigits()
{
    int n, prod = 1;
    printf("Give the suitable input\n");
    scanf("%d", &n);
    do
    {
        prod *= n % 10;
        n /= 10;
    } while (n != 0);
    printf("The output is printed below\n");
    printf("%d\n", prod);
}

// problem 9
void reverseOfANumber()
{
    int n, revN = 0;
    printf("Give the suitable input\n");
    scanf("%d", &n);
    while (n != 0)
    {
        int temp = n % 10;
        revN = revN * 10 + (temp);
        n /= 10;
    }
    printf("The output is printed below\n");
    printf("%d\n", revN);
}

// program 10
void printPrimeNumbers()
{
    int n, revN = 0;
    printf("Give the suitable input\n");
    scanf("%d", &n);

    int prime[n];
    int i = 0, j = 0;
    for (i = 0; i < n; i++)
    {
        prime[i] = 1;
    }

    for (i = 2; i * i <= n; i++)
    {
        if (prime[i])
        {
            for (j = i * i; j <= n; j++)
            {
                if (j % i == 0)
                {
                    prime[j] = 0;
                }
            }
        }
    }
    printf("The output is printed below\n");
    for (i = 2; i <= n; i++)
    {
        if (prime[i])
        {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main()
{
    printArmstrong();
    return 0;
}
