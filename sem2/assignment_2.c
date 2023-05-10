B.Sc II Sem 2023 (Computer Science)
CS102P
Assignment-2Assignment details
Assignment-2
Ankita Vaish
•
3 May (Edited 4 May)
Due Tomorrow, 23:59
1. Write a program in C that converts a decimal number to any other base (binary, octal, and hexadecimal).


2. Write a program in C that converts a number given in any other base (binary, octal, and hexadecimal) to decimal.


3. Write a program in C that converts an octal number to binary and hexadecimal.

4. Write a program in C that converts a hexadecimal number to binary and octal.


5. Write a program in C that performs addition of two numbers given in any base (consider the base 2, 8, 10, 16).

6. Write a program in C that performs subtraction of two numbers given in any base (consider the base 2, 8, 10, 16).
Class comments
Your work
Handed in

assignment_2.c
Text

assignment_2_output.png
Image
Private comments
#include <stdio.h>
#include <math.h>
#include <string.h>

//---------------------------------------------------------------------------------------------------------

// problem 1
void decimalToBinary(int decimalNum);
void decimalToOctal(int decimalNum);
void decimalToHexadecimal(int decimalNum);
void prob1() {
    int decimalNum;
    printf("Enter a decimal number: ");
    scanf("%d", &decimalNum);
    decimalToBinary(decimalNum);
    decimalToOctal(decimalNum);
    decimalToHexadecimal(decimalNum);
}
void decimalToBinary(int decimalNum) {
    int binaryNum[32];
    int i = 0;
    while (decimalNum > 0) {
        binaryNum[i] = decimalNum % 2;
        decimalNum = decimalNum / 2;
        i++;
    }
    printf("Binary number: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binaryNum[j]);
    }
    printf("\n");
}
void decimalToOctal(int decimalNum) {
    int octalNum[32];
    int i = 0;
    while (decimalNum > 0) {
        octalNum[i] = decimalNum % 8;
        decimalNum = decimalNum / 8;
        i++;
    }
    printf("Octal number: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", octalNum[j]);
    }
    printf("\n");
}
void decimalToHexadecimal(int decimalNum) {
    char hexNum[32];
    int i = 0;
    while (decimalNum > 0) {
        int remainder = decimalNum % 16;
        if (remainder < 10) {
            hexNum[i] = remainder + 48;
        } else {
            hexNum[i] = remainder + 55;
        }
        decimalNum = decimalNum / 16;
        i++;
    }
    printf("Hexadecimal number: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hexNum[j]);
    }
    printf("\n");
}

//---------------------------------------------------------------------------------------------------------

// problem 2
int convertToDecimal(char num[], int base);
void prob2() {
    char num[100];
    int base;
    printf("Enter a number: ");
    scanf("%s", num);
    printf("Enter its base (2, 8, or 16): ");
    scanf("%d", &base);
    printf("%s in base %d = %d in decimal\n", num, base, convertToDecimal(num, base));
}
int convertToDecimal(char num[], int base) {
    int decimalNum = 0;
    int power = 0;
    for (int i = strlen(num) - 1; i >= 0; i--) {
        int digit;
        if (num[i] >= '0' && num[i] <= '9') {
            digit = num[i] - '0';
        } else if (num[i] >= 'A' && num[i] <= 'F') {
            digit = num[i] - 'A' + 10;
        } else if (num[i] >= 'a' && num[i] <= 'f') {
            digit = num[i] - 'a' + 10;
        } else {
            printf("Invalid number!\n");
            return 0;
        }
        decimalNum += digit * pow(base, power);
        power++;
    }
    return decimalNum;
}

//---------------------------------------------------------------------------------------------------------

// problem 3
void octalToBinary(char num[]);
void octalToHex(char num[]);
void prob3() {
    char num[100];
    printf("Enter an octal number: ");
    scanf("%s", num);
    octalToBinary(num);
    octalToHex(num);
}
char *strrev(char *str)
{
    char *end, *wrk = str;
    {
        if(str && *str)
        {
            end = str + strlen(str) - 1;
            while(end > wrk)
            {
                char temp;

                temp = *wrk;
                *wrk++ = *end;
                *end-- = temp;
            }
        }
    }
    return str;
}
void octalToBinary(char num[]) {
    int decimalNum = 0, i = 0;
    char binaryNum[100];
    while (num[i]) {
        int digit = num[i] - '0';
        decimalNum = decimalNum * 8 + digit;
        i++;
    }
    i = 0;
    while (decimalNum > 0) {
        binaryNum[i] = decimalNum % 2 + '0';
        decimalNum /= 2;
        i++;
    }
    binaryNum[i] = '\0';
    strrev(binaryNum);
    printf("%s in binary = %s\n", num, binaryNum);
}
void octalToHex(char num[]) {
    int decimalNum = 0, i = 0;
    char hexNum[100];
    while (num[i]) {
        int digit = num[i] - '0';
        decimalNum = decimalNum * 8 + digit;
        i++;
    }
    i = 0;
    while (decimalNum > 0) {
        int rem = decimalNum % 16;
        if (rem < 10) {
            hexNum[i] = rem + '0';
        } else {
            hexNum[i] = rem - 10 + 'A';
        }
        decimalNum /= 16;
        i++;
    }
    hexNum[i] = '\0';
    strrev(hexNum);
    printf("%s in hexadecimal = %s\n", num, hexNum);
}

//---------------------------------------------------------------------------------------------------------

// problem 4
void prob4() {
   char hex[17]; 
    unsigned int num, mask, bit;
    int i;

    // Prompt the user to enter a hexadecimal number
    printf("Enter a hexadecimal number: ");
    scanf("%x", &num);

    // Convert the hexadecimal number to binary
    printf("Binary equivalent: ");
    for (mask = 0x80000000; mask != 0; mask >>= 1) {
        bit = (num & mask) ? 1 : 0;
        printf("%d", bit);
    }
    printf("\n");

    // Convert the hexadecimal number to octal
    printf("Octal equivalent: ");
    for (i = 10; i >= 0; i--) {
        bit = (num >> (i * 3)) & 0x7;
        printf("%d", bit);
    }
    printf("\n");
}

//---------------------------------------------------------------------------------------------------------

// problem 5
int convertToDecimalForSum(char num[], int base);
void convertToBaseForSum(int num, int base);
void prob5() {
    char num1[100], num2[100];
    int base;
    printf("Enter the base of the numbers: ");
    scanf("%d", &base);
    printf("Enter the first number: ");
    scanf("%s", num1);
    printf("Enter the second number: ");
    scanf("%s", num2);
    int decimalNum1 = convertToDecimalForSum(num1, base);
    int decimalNum2 = convertToDecimalForSum(num2, base);
    int sum = decimalNum1 + decimalNum2;
    printf("Sum of %s and %s in base %d = ", num1, num2, base);
    convertToBaseForSum(sum, base);
}
int convertToDecimalForSum(char num[], int base) {
    int decimalNum = 0;
    int power = 1;
    int len = strlen(num);
    int i;
    for (i = len - 1; i >= 0; i--) {
        int digit;
        if (num[i] >= '0' && num[i] <= '9') {
            digit = num[i] - '0';
        } else if (num[i] >= 'A' && num[i] <= 'F') {
            digit = num[i] - 'A' + 10;
        } else if (num[i] >= 'a' && num[i] <= 'f') {
            digit = num[i] - 'a' + 10;
        }
        decimalNum += digit * power;
        power *= base;
    }
    return decimalNum;
}
void convertToBaseForSum(int num, int base) {
    if (num == 0) {
        printf("0");
        return;
    }
    int rem;
    char result[100];
    int i = 0;
    while (num != 0) {
        rem = num % base;
        if (rem < 10) {
            result[i] = rem + '0';
        } else {
            result[i] = rem - 10 + 'A';
        }
        num = num / base;
        i++;
    }
    result[i] = '\0';
    int len = strlen(result);
    for (i = len - 1; i >= 0; i--) {
        printf("%c", result[i]);
    }
  printf("\n");
}

//---------------------------------------------------------------------------------------------------------

// problem 6
int convertToDecimalForDiff(char num[], int base);
void convertToBaseForDiff(int num, int base);
void prob6() {
    char num1[100], num2[100];
    int base;
    printf("Enter the base of the numbers: ");
    scanf("%d", &base);
    printf("Enter the first number: ");
    scanf("%s", num1);
    printf("Enter the second number: ");
    scanf("%s", num2);
    int decimalNum1 = convertToDecimalForDiff(num1, base);
    int decimalNum2 = convertToDecimalForDiff(num2, base);
    int diff = decimalNum1 - decimalNum2;
    printf("Difference of %s and %s in base %d = ", num1, num2, base);
    convertToBaseForDiff(diff, base);
}
int convertToDecimalForDiff(char num[], int base) {
    int decimalNum = 0;
    int power = 1;
    int len = strlen(num);
    int i;
    for (i = len - 1; i >= 0; i--) {
        int digit;
        if (num[i] >= '0' && num[i] <= '9') {
            digit = num[i] - '0';
        } else if (num[i] >= 'A' && num[i] <= 'F') {
            digit = num[i] - 'A' + 10;
        } else if (num[i] >= 'a' && num[i] <= 'f') {
            digit = num[i] - 'a' + 10;
        }
        decimalNum += digit * power;
        power *= base;
    }
    return decimalNum;
}
void convertToBaseForDiff(int num, int base) {
    if (num == 0) {
        printf("0");
        return;
    }
    int rem;
    char result[100];
    int i = 0;
    while (num != 0) {
        rem = num % base;
        if (rem < 10) {
            result[i] = rem + '0';
        } else {
            result[i] = rem - 10 + 'A';
        }
        num = num / base;
        i++;
    }
    result[i] = '\0';
    int len = strlen(result);
    for (i = len - 1; i >= 0; i--) {
        printf("%c", result[i]);
    }
  printf("\n");
}

//---------------------------------------------------------------------------------------------------------

int main(){
  printf("\n----------problem 1----------:\n");
  prob1();
  printf("\n----------problem 2----------:\n");
  prob2();
  printf("\n----------problem 3----------:\n");
  prob3();
  printf("\n----------problem 4----------:\n");
  prob4();
  printf("\n----------problem 5----------:\n");
  prob5();
  printf("\n----------problem 6----------:\n");
  prob6();
  return 0;
}
assignment_2.c
Displaying assignment_2.c.
