#include <stdio.h>
#include <math.h>

const int INF = 1e5+2;

// problem 1
void powerOfNum()
{// tested
    int base, exp;
    long double result = 1.0;
    printf("Enter a base number and exponent\n");
    scanf("%d %d", &base, &exp);
    while (exp != 0) {
        result *= base;
        --exp;
    }
    printf("Answer = %.0Lf\n", result);
}

// problem 2
void factorsOfNum()
{//  tested
    int n;
    printf("Give the input number\n");
    scanf("%d", &n);
    printf("Factors are\n");
    for(int i = 1; i<=n; i++){
        if(n%i == 0)
            printf("%d ",i);
    }
    printf("\n");
}

// problem 3
int factorial(int n)
{// tested
    if(n==0||n==1)
        return 1;
    return n*factorial(n-1);
}
void factorialCalc(){
    int n;
    printf("supply the input for calculating the factorial\n");
    scanf("%d", &n);
    printf("factorial is %d\n", factorial(n));
}

// problem 4
void GCD()
{// tested
    int n1,n2;
    printf("Give the input numbers\n");
    scanf("%d %d", &n1, &n2);
    int gcd = 1;
    for(int i = 1; i<=n1 && i<=n2; i++){
        if(n1%i == 0 && n2%i == 0)
            gcd=i;
    }
    printf("gcd = %d\n", gcd);
}

// problem 5
void LCM()
{// tested
    int n1,n2;
    printf("Give the input numbers\n");
    scanf("%d %d", &n1, &n2);
    int gcd = 1;
    for(int i = 1; i<=n1 && i<=n2; i++){
        if(n1%i == 0 && n2%i == 0)
            gcd=1;
    }
    int lcm = (n1*n2)/(gcd);
    printf("lcm = %d\n", lcm);
}

// problem 6
void binaryToDecimal()
{// tested
    long long int n;
    printf("input the length of the binary string\n");
    scanf("%lld", &n);
    printf("Binary string is \n");
    int decimal =0, index = 0;
    while(n>0){
        int binVal = n%10;
        decimal+=(pow(2,index))*binVal;
        index++;
        n/=10;
    }
    printf("%d\n", decimal);
}

// problem 7
void decimalToBinary()
{// tested
    int n, binaryNum=0, power = 0;
    printf("Give the decimal input\n");
    scanf("%d", &n);
    printf("Binary string is \n");
    while(n>0){
        int rem = n%2;
        long long int tens = pow(10,power);
        binaryNum += rem*tens;
        power++;
        n/=2;
    }
    printf("%d\n", binaryNum);

    
}

// problem 8
void fibonacciSeries()
{// tested
    int n;
    printf("supply the input for calculating the fib\n");
    scanf("%d", &n);
    //tabulation
    int dp[n+1];
    dp[0] = 0;
    dp[1] = 0;
    dp[2]=1;
    for (int i = 3; i<=n; i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    printf("fibonacci is %d\n", dp[n]);
}

// problem 9
void addAndSquare()
{// tested
    int choice;
    while (1)
    {
        int n1,n2;
        printf("give suitable inputs\n");
        scanf("%d %d", &n1,&n2);
        printf("square of addition is %d\n", (n1+n2)*(n1+n2));

        printf("enter 0 to exit and a non zero number to continue\n");
        scanf("%d", &choice);
        if(!choice){
            break;
        }
    }
    
}

int main()
{
    binaryToDecimal();

    return 0;
}
