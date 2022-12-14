#include <stdio.h>
#include <math.h>
#define PI 3.14

// question no. 1
void simpleInterest()
{ // tested
    float p, r, t;
    scanf("%f %f %f", &p, &r, &t);
    float si = (p * r * t) / 100;
    printf("simple inerest : %.2f\n", si);
}

// question no. 2
void fahrenheitToCelcius()
{ // tested
    float f;
    scanf("%f", &f);
    float c = ((f - 32) * 5) / 9;
    printf("clecius : %.2f\n", c);
}

// question no. 3
void circleAreaAndCircum()
{ // tested
    float r;
    scanf("%f", &r);
    float area = PI * r * r;
    float circum = PI * r * 2;
    printf("area : %.2f and circum : %.2f\n", area, circum);
}

// question no. 4
void areaOfTriangle()
{ // tested
    float a, b, c;
    scanf("%f %f %f", &a, &b, &c);
    float s = (a + b + c) / 2;
    float area = sqrt((s * (s - a) * (s - b) * (s - c)));
    printf("area : %.2f\n", area);
}

// question no. 5
void findRealRoots()
{ // tested
    float a, b, c;
    scanf("%f %f %f", &a, &b, &c);
    float d = (b * b) - (4 * a * c);

    if (d < 0)
    {
        printf("no root exists\n");
    }
    else
    {
        float r1 = ((-b) + sqrt(d)) / (2 * a);
        float r2 = ((-b) - sqrt(d)) / (2 * a);
        printf("root1 : %.2f and root2 : %.2f\n", r1, r2);
    }
}

// question no. 6
void largestOfThree()
{ // tested
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    if (a >= b && a >= c)
    {
        printf("%d is largest\n", a);
    }
    else if (b >= c && b >= a)
    {
        printf("%d is largest\n", b);
    }
    else
    {
        printf("%d is largest\n", c);
    }
}

// question no. 7
void isLeapYear()
{ // tested
    int yr;
    scanf("%d", &yr);

    if (yr % 400 == 0)
    {
        printf("%d is a leap year.", yr);
    }
    else if (yr % 100 == 0)
    {
        printf("%d is not a leap year.", yr);
    }
    else if (yr % 4 == 0)
    {
        printf("%d is a leap year.", yr);
    }
    else
    {
        printf("%d is not a leap year.", yr);
    }
}

// question no. 8
void isAlphabet()
{ // tested
    char c;
    scanf("%c", &c);

    if ((c - '0' <= 90 && c - '0' >= 65) || (c - '0' <= 122 && c - '0' >= 97))
        printf("%c is an alphabet.\n", c);
    else
        printf("%c is not an alphabet.\n", c);
}

// question no. 9
void findSalary()
{
    float basic, gross, da, hra;
    scanf("%f", &basic);

    if (basic <= 10000)
    {
        da = basic * 0.8;
        hra = basic * 0.2;
    }
    else if (basic <= 20000)
    {
        da = basic * 0.9;
        hra = basic * 0.25;
    }
    else
    {
        da = basic * 0.95;
        hra = basic * 0.3;
    }

    gross = basic + hra + da;
    printf("gross salary : %.2f\n", gross);
}

int main()
{
    findSalary();

    return 0;
}
