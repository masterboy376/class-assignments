#include <stdio.h>

// helper functions

// problem 1
void prob1()
{
    int n;
    scanf("%d", &n);
    int a[n];
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    printf("%d %f", sum, (float)sum / n);
}

// problem 2
void prob2()
{
    int n;
    scanf("%d", &n);
    int a[n];
    int mx = -999999999, mn = 999999999;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        if (a[i] > mx)
            mx = a[i];
        if (a[i] < mn)
            mn = a[i];
    }
    printf("%d %d", mx, mn);
}

// problem 3
void prob3()
{
    int n;
    scanf("%d", &n);
    int a[n];
    int odds = 0, evens = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        if (a[i] & 1)
            odds++;
        else
            evens++;
    }
    printf("%d %d", odds, evens);
}

// problem 4
void prob4()
{
    int m, n;
    scanf("%d %d", &m, &n);
    int a[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    int at[n][m];
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            at[j][i] = a[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d\t", at[i][j]);
        }
        printf("\n");
    }
}

// problem 5
void prob5()
{
    int m1, n1;
    int m2, n2;
    scanf("%d %d", &m1, &n1);
    scanf("%d %d", &m2, &n2);
    int a1[m1][n1], a2[m2][n2], sumRes[m1][n1], mulRes[m1][n2];
    for (int i = 0; i < m1; i++)
    {
        for (int j = 0; j < n1; j++)
        {
            scanf("%d", &a1[i][j]);
        }
    }
    for (int i = 0; i < m2; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            scanf("%d", &a2[i][j]);
        }
    }
    // sum
    if (m1 != m2 || n1 != n2)
        printf("sum not possible");
    else
    {
        for (int i = 0; i < m1; i++)
        {
            for (int j = 0; j < n1; j++)
            {
                sumRes[i][j] = a1[i][j] + a2[i][j];
            }
        }
        printf("sum : \n");
        for (int i = 0; i < m1; i++)
        {
            for (int j = 0; j < n1; j++)
            {
                printf("%d ", sumRes[i][j]);
            }
            printf("\n");
        }
    }
    // multiply
    if (n1 != m2)
        printf("multiplication not possible");
    else
    {
        for (int i = 0; i < m1; i++)
        {
            for (int j = 0; j < n2; j++)
            {
                mulRes[i][j]=0;
            }
        }
        for (int i = 0; i < m1; i++)
        {
            for (int j = 0; j < n2; j++)
            {
                for(int k = 0; k<n1; k++){
                    mulRes[i][j] += a1[i][k]*a2[k][j];
                }
            }
        }
        printf("mul : \n");
        for (int i = 0; i < m1; i++)
        {
            for (int j = 0; j < n2; j++)
            {
                printf("%d ", mulRes[i][j]);
            }
            printf("\n");
        }
    }
}

// problem 6
void prob6()
{
    int n;
    scanf("%d", &n);
    int a[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    int l = 0, r = 0;
    for (int i = 0; i < n; i++)
    {
        l += a[i][i];
        r += a[i][n - 1 - i];
    }
    printf("%d %d", l, r);
}

// problem 7
void prob7()
{
    int n = 3;
    int a[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    int ans = a[0][0] * (a[1][1] * a[2][2] - a[1][2] * a[2][1]) - a[0][1] * (a[1][0] * a[2][2] - a[1][2] * a[2][0]) + a[0][2] * (a[1][0] * a[2][1] - a[1][1] * a[2][0]);
    printf("%d", ans);
}

// problem 8
void prob8()
{
    int n, x;
    scanf("%d %d", &n, &x);
    int a[n];
    int ans = -1;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
        {
            ans = i;
            break;
        }
    }
    if (ans != -1)
        printf("%d", ans);
    else
        printf("not found");
}

// problem 9
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

void prob9()
{
    int n, x = -1;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    bubbleSort(a, n);
    printf("Sorted array: \n");
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

// problem 10
void prob10()
{
    int m, n;
    scanf("%d %d", &m, &n);
    int a[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    int sum = 0;
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            sum += a[i][j];
        }
    }
    printf("%d\n", sum);
}

// problem 11
void swap(int *xp, int *yp) {
  int temp = *xp;
  *xp = *yp;
  *yp = temp;
}
void bubbleSort(int arr[], int n) {
  int i, j;
  for (i = 0; i < n - 1; i++)
    for (j = 0; j < n - i - 1; j++)
      if (arr[j] > arr[j + 1])
        swap(&arr[j], &arr[j + 1]);
}
void prob11() {
  int i = 0, j = 0, k = 0;
  int n1;
  scanf("%d", &n1);
  int a1[n1];
  for (i = 0; i < n1; i++) {
    scanf("%d", &a1[i]);
  }
  int n2;
  scanf("%d", &n2);
  int a2[n2];
  for (i = 0; i < n2; i++) {
    scanf("%d", &a2[i]);
  }
  int m = n1 + n2;
  int a3[m];
  i=0;
  while (i < n1) {
    a3[k] = a1[i];
    i += 1;
    k += 1;
  }
  while (j < n2) {
    a3[k] = a2[j];
    j += 1;
    k += 1;
  }
  bubbleSort(a3, m);
  for (i = 0; i < m; i++)
    printf("%d ", a3[i]);
  printf("\n");
}

int main()
{
    prob5();

    return 0;
}
