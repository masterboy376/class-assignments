#include<stdio.h>
#include<math.h>

void prob1(){
    int n;
    printf("kindly enter month\n");
    scanf("%d",&n);
    switch(n)
    {
        case 1: 
            printf("31 days\n");
            break;
        case 2: 
            printf("28/29 days\n");
            break;
        case 3: 
            printf("31 days\n");
            break;
        case 4: 
            printf("30 days\n");
            break;
        case 5: 
            printf("31 days\n");
            break;
        case 6: 
            printf("30 days\n");
            break;
        case 7: 
            printf("31 days\n");
            break;
        case 8: 
            printf("31 days\n");
            break;
        case 9: 
            printf("30 days\n");
            break;
        case 10: 
            printf("31 days\n");
            break;
        case 11: 
            printf("30 days\n");
            break;
        case 12: 
            printf("31 days\n");
            break;
        default: 
            printf("Err: Invalid input!\n");
    }
}

void prob2(){
    float a,b;
    char ch;
    printf("kindly enter two numbers and an operator\n");
    scanf("%f %f %c",&a,&b, &ch);
    switch (ch)
    {
    case '+':
        printf("%f\n", (a+b));
        break;

    case '-':
        printf("%f\n", (a-b));
        break;

    case '*':
        printf("%f\n", (a*b));
        break;

    case '/':
        if(b!=0)
            printf("%f\n", (a/b));
        else
            printf("Exception: Cannot divide number by zero!\n");
        break;
    
    default:
        printf("Err: Unrecognized character!\n");
        break;
    }
}

void prob3(){
    char ch;
    printf("kindly enter the character\n");
    scanf("%c",&ch);
    switch (ch)
    {
    case 'a':
        printf("%c is a vowel.\n", (ch));
        break;
    case 'e':
        printf("%c is a vowel.\n", (ch));
        break;
    case 'i':
        printf("%c is a vowel.\n", (ch));
        break;
    case 'o':
        printf("%c is a vowel.\n", (ch));
        break;
    case 'u':
        printf("%c is a vowel.\n", (ch));
        break;
    case 'A':
        printf("%c is a vowel.\n", (ch));
        break;
    case 'E':
        printf("%c is a vowel.\n", (ch));
        break;
    case 'I':
        printf("%c is a vowel.\n", (ch));
        break;
    case 'O':
        printf("%c is a vowel.\n", (ch));
        break;
    case 'U':
        printf("%c is a vowel.\n", (ch));
        break;
    default:
        printf("%c is a consonant.\n",ch);
        break;
    }
}

void prob4(){
    int per;
    printf("kindly enter the percentage of a student\n");
    scanf("%d",&per);
    switch (per)
    {
    case 90 ... 100:
        printf("S\n");
        break;
    case 80 ... 89:
        printf("A\n");
        break;
    case 70 ... 79:
        printf("B\n");
        break;
    case 60 ... 69:
        printf("C\n");
        break;
    case 50 ... 59:
        printf("D\n");
        break;
    case 40 ... 49:
        printf("E\n");
        break;
    case 0 ... 39:
        printf("FAIL\n");
        break;
    default:
        printf("Err: Range overflow/underflow!\n");
        break;
    }
}

void prob5(){
    int type;
    printf("1-> one variable calculation, 2-> multiple variable calculation\n");
    scanf("%d",&type);
    switch (type)
    {
    case 1:
        int subType1;
        printf("1-> circle, 2-> square\n");
        scanf("%d",&subType1);
        switch (subType1)
        {
        case 1:
            float r1;
            printf("Enter radius: \n");
            scanf("%f",&r1);
            printf("area: %.2f, parimeter: %.2f \n", (3.14*r1*r1), (2*3.14*r1) );
            break;
        
        case 2:
            float r2;
            printf("Enter side length: \n");
            scanf("%f",&r2);
            printf("area: %.2f, parimeter: %.2f \n", (r2*r2), (4*r2) );
            break;
        default:
            printf("Err: Invalid input!\n");
            break;
        }
        break;
    case 2:
        int subType2;
        printf("1-> triangle, 2-> rectangle\n");
        scanf("%d",&subType2);
        switch (subType2)
        {
        case 1:
            float a,b,c;
            printf("Enter 3 sides: \n");
            scanf("%f %f %f",&a, &b, &c);
            float s = (a+b+c)/2;
            float area = sqrt((s * (s-a) * (s-b) * (s-c)));
            printf("area: %.2f, parimeter: %.2f \n", area, (a+b+c) );
            break;
        
        case 2:
            float l,br;
            printf("Enter length and breadth: \n");
            scanf("%f %f",&l, &br);
            printf("area: %.2f, parimeter: %.2f \n", (l*br), (2*(l+br)) );
            break;
        default:
            printf("Err: Invalid input!\n");
            break;
        }
        break;
    default:
        printf("Err: Invalid input!\n");
        break;
    }
}


int main(){
    prob5();
    return 0;
}
