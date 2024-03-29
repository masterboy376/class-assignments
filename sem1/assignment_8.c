#include <stdio.h>

int customStrLen(char s[]){
    int len = 0 ;
    while(s[len]!='\0'){
        len++;
    }
    return len;
}

void prob1()
{
    char string1[20];
    int i, length;
    int flag = 0;

    printf("Enter a string:\n");
    gets(string1);

    length = customStrLen(string1);

    for (i = 0; i < length / 2 + 1; i++)
    {
        if (string1[i] != string1[length - i - 1])
        {
            flag = 1;
            break;
        }
    }

    if (flag)
    {
        printf("%s is not a palindrome\n", string1);
    }
    else
    {
        printf("%s is a palindrome\n", string1);
    }
}

void prob2()
{
    char s[200];
    int wCount = 0, cCount = 0, i;

    printf("Enter the string:\n");
    gets(s);
    for (i = 0; s[i] != '\0'; i++)
    {
        cCount++;
        if (s[i] == ' ' && s[i + 1] != ' ')
            wCount++;
    }
    printf("Number of words in given string are: %d\n, Number of characters in string are: %d\n", wCount + 1, cCount);
}

void prob3()
{
    char string1[20];
    int i, length;
    int alphabets = 0, digits = 0, specials = 0, annony = 0;

    printf("Enter a string:\n");
    gets(string1);

    length = customStrLen(string1);

    for (i = 0; i < length; i++)
    {
        if ((string1[i] <= 90 && string1[i] >= 65) || (string1[i] <= 122 && string1[i] >= 97))
        {
            alphabets++;
        }
        else if ((string1[i] <= 47 && string1[i] >= 21) || (string1[i] <= 64 && string1[i] >= 58) || (string1[i] <= 96 && string1[i] >= 91) || (string1[i] <= 126 && string1[i] >= 123))
        {
            specials++;
        }
        else if ((string1[i] <= 57 && string1[i] >= 48))
        {
            digits++;
        }
        else
        {
            annony++;
        }
    }
    printf("%d %d %d\n", alphabets, digits, specials);
}

void prob4()
{
    char string1[20];
    int i, length;

    printf("Enter a string:\n");
    gets(string1);

    length = customStrLen(string1);
    char string2[length];

    for (i = 0; i < length; i++)
    {
        string2[i] = string1[i];
    }
    printf("%s is a copied string\n", string2);
}

void prob5()
{
    char string1[20], string2[20];
    int i, length1, length2, flag = 1;

    printf("Enter two strings:\n");
    gets(string1);
    gets(string2);

    length1 = customStrLen(string1);
    length2 = customStrLen(string2);

    if (length1 != length2)
        flag = 0;
    for (i = 0; i < length1; i++)
    {
        if (string2[i] != string1[i] || flag == 0)
        {
            flag = 0;
            break;
        }
    }
    if (flag)
    {
        printf("similar strings.\n");
    }
    else
    {
        printf("strings not similar.\n");
    }
}

void prob6()
{
    char string1[20];
    int i, length, vowels = 0, consonants = 0;

    printf("Enter a string:\n");
    gets(string1);

    length = customStrLen(string1);

    for (i = 0; i < length; i++)
    {
        if ((string1[i] <= 90 && string1[i] >= 65) || (string1[i] <= 122 && string1[i] >= 97))
        {
            switch (string1[i])
            {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                vowels++;
                break;
            default:
                consonants++;
                break;
            }
        }
    }
    printf("%d %d\n", vowels, consonants);
}

void prob7()
{
    char string[200];
    printf("Enter a string:\n");
    gets(string);
    int i, j, max, length = customStrLen(string);
    char maxChar = string[0];
    int freq[length];

    for (i = 0; i < length; i++)
    {
        freq[i] = 1;
        for (j = i + 1; j < length; j++)
        {
            if (string[i] == string[j] && string[i] != ' ' && string[i] != '0')
            {
                freq[i]++;

                string[j] = '0';
            }
        }
    }

    max = freq[0];
    for (i = 0; i < length; i++)
    {
        if (max < freq[i])
        {
            max = freq[i];
            maxChar = string[i];
        }
    }

    printf("Maximum occurring character: %c\n", maxChar);
}

void prob8()
{
    char string[200];
    printf("Enter a string:\n");
    gets(string);
    int length = customStrLen(string);
    char a;
    int i, j;

    for (i = 0; i < length; ++i)
    {
        for (j = i + 1; j < length; ++j)
        {
            if (string[i] > string[j])
            {
                a = string[i];
                string[i] = string[j];
                string[j] = a;
            }
        }
    }
    printf("subStr: %s\n", string);
}

void prob9()
{
    char string[200];
    printf("Enter a string:\n");
    gets(string);
    int st, en, length = customStrLen(string);
    printf("Enter start and end index:\n");
    scanf("%d", &st);
    scanf("%d", &en);

    if (en >= length || st > en || st < 0)
    {
        printf("invalid index!");
        return;
    }

    char subStr[en - st + 1 + 1];
    int i, j;

    for (i = st, j = 0; i <= en; i++, j++)
    {
        subStr[j] = string[i];
    }
    subStr[en - st + 1] = '\0';

    printf("subStr: %s\n", subStr);
}

void prob10()
{
    char string[200];
    printf("Enter a string:\n");
    gets(string);
    int ans = 0, length = customStrLen(string);
    int i;

    for (i = 0; i <= length - 3; i++)
    {
        int t = (string[i] == 't' || string[i] == 'T');
        int h = (string[i + 1] == 'h' || string[i + 1] == 'H');
        int e = (string[i + 2] == 'e' || string[i + 2] == 'E');
        int spc = (string[i - 1] == ' ' || string[i + 3] == ' ');
        if (length > 3)
        {
            if (t && h && e && spc)
                ans++;
        }
        else if (length == 3)
        {
            if (t && h && e)
                ans++;
        }
        else
        {
            ans = 0;
            break;
        }
    }

    printf("ans: %d\n", ans);
}

void prob11()
{
    char string1[200], string2[200];
    printf("Enter strings:\n");
    gets(string1);
    gets(string2);
    int length2 = customStrLen(string2), length1 = customStrLen(string1);
    int i, j = 0;
    char res[length1 + length2 + 1];

    for (i = 0; i < length1; i++)
    {
        res[j++] = string1[i];
    }
    for (i = 0; i < length2; i++)
    {
        res[j++] = string2[i];
    }
    res[j] = '\0';

    printf("ans: %s\n", res);
}

void prob12()
{
    char string1[200];
    printf("Enter string:\n");
    gets(string1);
    int length1 = customStrLen(string1);
    int i;

    for (i = 0; i < length1; i++)
    {
        if ((string1[i] <= 122 && string1[i] >= 97))
            string1[i] = string1[i] - 32;
    }

    printf("upper-case : %s\n", string1);
}

void prob13()
{
    char string1[200], ch;
    printf("Enter string:\n");
    gets(string1);
    printf("Enter character:\n");
    scanf("%c", &ch);
    int length1 = customStrLen(string1);
    int i;

    for (i = 0; i < length1; i++)
    {
        if (string1[i] == ' ')
            string1[i] = ch;
    }

    printf("replaced : %s\n", string1);
}

int main()
{
    prob8();
    return 0;
}
