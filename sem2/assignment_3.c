// problem 1 and 2
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


void reverse(char * s)
{
    int length = strlen(s) ;
    int c, i, j;

    for (i = 0, j = length - 1; i < j; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void findRMin1Complement(char * num, int base, char * RMin1Complement){
    int len = strlen(num);
    while (len--)
    {
        char ch = (char)(48+abs((num[len]-'0')-(base-1)));
        strncat(RMin1Complement, &ch, 1);
    }
    reverse(RMin1Complement);
}

void findRComplement(char * num, int base, char * RComplement) {
    char RMin1Complement[65] = "";
    findRMin1Complement(num , base, RMin1Complement);
    int len = strlen(num);
    int carry = 0;
    while(len--){
        int addRes;
        if(len == strlen(num)-1) addRes = ( (RMin1Complement[len]-'0') + 1 + carry);
        else addRes = ( (RMin1Complement[len]-'0') + carry);
        carry = addRes/base;
        char ch = (char)(addRes%base+48);
        strncat(RComplement, &ch, 1);
    }
    reverse(RComplement);
}

int main() {
    char number[65];
    int base;
    char RMin1Complement[65] = "";
    char RComplement[65] = "";

    printf("Enter the number: ");
    scanf("%s", number);

    printf("Enter the base: ");
    scanf("%d", &base);

    findRMin1Complement(number, base, RMin1Complement);
    findRComplement(number, base, RComplement);

    printf("The %d's complement of %s in base %d is: %s\n", base-1, number, base, RMin1Complement);
    printf("The %d's complement of %s in base %d is: %s\n", base, number, base, RComplement);

    return 0;
}

//----------------------------------------------------------------------------------------------------------------

//problem 3 and 4
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


void reverse(char * s)
{
    int length = strlen(s) ;
    int c, i, j;

    for (i = 0, j = length - 1; i < j; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void findRMin1Complement(char * num, int base, char * RMin1Complement){
    int len = strlen(num);
    while (len--)
    {
        char ch = (char)(48+abs((num[len]-'0')-(base-1)));
        strncat(RMin1Complement, &ch, 1);
    }
    reverse(RMin1Complement);
}

void findRComplement(char * num, int base, char * RComplement) {
    char RMin1Complement[65] = "";
    findRMin1Complement(num , base, RMin1Complement);
    int len = strlen(num);
    int carry = 0;
    while(len--){
        int addRes;
        if(len == strlen(num)-1) addRes = ( (RMin1Complement[len]-'0') + 1 + carry);
        else addRes = ( (RMin1Complement[len]-'0') + carry);
        carry = addRes/base;
        char ch = (char)(addRes%base+48);
        strncat(RComplement, &ch, 1);
    }
    reverse(RComplement);
}

void subRMin1(char* M, char* N, int base){
    char NRMOC[65] = "";
    char sumTemp[65] = "";
    findRMin1Complement(N , base, NRMOC);
    int len = strlen(M);
    int carry = 0;
    while(len--){
        int addRes;
        addRes = ( (M[len]-'0') + (NRMOC[len]-'0') + carry);
        carry = addRes/base;
        char ch = (char)(addRes%base+48);
        strncat(sumTemp, &ch, 1);
    }
    reverse(sumTemp);
    if(carry!=0){
        sumTemp[ (strlen(sumTemp)-1) ] = (char)( ((sumTemp[ (strlen(sumTemp)-1) ]-'0')+carry) + 48 ); 
        printf("substraction by r-1's complement of %s from %s in base %d is %s\n", M, N, base, sumTemp);
    }else{
        char ans[65] = "";
        findRMin1Complement(sumTemp , base, ans);
        printf("substraction by r-1's complement of %s from %s in base %d is negative of %s\n", M, N, base, ans);
    }
}

void subR(char* M, char* N, int base){
    char NRC[65] = "";
    char sumTemp[65] = "";
    findRComplement(N , base, NRC);
    int len = strlen(M);
    int carry = 0;
    while(len--){
        int addRes;
        addRes = ( (M[len]-'0') + (NRC[len]-'0') + carry);
        carry = addRes/base;
        char ch = (char)(addRes%base+48);
        strncat(sumTemp, &ch, 1);
    }
    reverse(sumTemp);
    if(carry!=0){
        printf("substraction by r's complement of %s from %s in base %d is %s\n", M, N, base, sumTemp);
    }else{
        char ans[65] = "";
        findRComplement(sumTemp , base, ans);
        printf("substraction by r's complement of %s from %s in base %d is negative of %s\n", M, N, base, ans);
    }
}

int main() {
    char M[65], N[65];
    int base;
    char NRMOC[65] = "";
    char NRC[65] = "";
    char MRMOC[65] = "";
    char MRC[65] = "";

    printf("Enter the 1st number: ");
    scanf("%s", M);

    printf("Enter the 2st number: ");
    scanf("%s", N);

    printf("Enter the base: ");
    scanf("%d", &base);

    subRMin1(M, N, base);
    subR(M, N, base);

    // printf("The %d's complement of %s in base %d is: %s\n", base-1, number, base, RMin1Complement);
    // printf("The %d's complement of %s in base %d is: %s\n", base, number, base, RComplement);

    return 0;
}
